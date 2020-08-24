/***************************************************************************
 * Copyright (C) 2010
 * by Dimok
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you
 * must not claim that you wrote the original software. If you use
 * this software in a product, an acknowledgment in the product
 * documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * for WiiXplorer 2010
 ***************************************************************************/
#include <malloc.h>
#include <string.h>

#include "uncompress.h"
#include "lz77.h"

u8 * uncompressLZ77(const u8 *inBuf, u32 inLength, u32 * size)
{
	if(!inBuf)
		return NULL;

	u8 *buffer = NULL;
	if (*((const u32 *)inBuf) != 0x4C5A3737 /*"LZ77"*/)
		return NULL;

	decompressLZ77content( (u8*)inBuf + 4, inLength - 4, &buffer, size);

	return buffer;
}

//Thanks to _demo_ for this function
//src points to the yaz0 source data (to the "real" source data, not at the header!)
//dst points to a buffer uncompressedSize bytes large (you get uncompressedSize from
//the second 4 bytes in the Yaz0 header).
void uncompressYaz0(const u8* srcBuf, u8* dst, int uncompressedSize)
{
	if(!srcBuf || !dst)
		return;

	const u8 * src = srcBuf;

	if(*((u32*)src) == 'Yaz0')
	{
		src += sizeof(Yaz0_Header);
	}

	int srcPlace = 0, dstPlace = 0; //current read/write positions

	u32 validBitCount = 0; //number of valid bits left in "code" byte
	u8 currCodeByte = 0;

	while(dstPlace < uncompressedSize)
	{
		//read new "code" byte if the current one is used up
		if(validBitCount == 0)
		{
			currCodeByte = src[srcPlace];
			++srcPlace;
			validBitCount = 8;
		}

		if((currCodeByte & 0x80) != 0)
		{
			//straight copy
			dst[dstPlace] = src[srcPlace];
			dstPlace++;
			srcPlace++;
		}
		else
		{
			//RLE part
			u8 byte1 = src[srcPlace];
			u8 byte2 = src[srcPlace + 1];
			srcPlace += 2;

			u32 dist = ((byte1 & 0xF) << 8) | byte2;
			u32 copySource = dstPlace - (dist + 1);

			u32 numBytes = byte1 >> 4;
			if(numBytes == 0)
			{
				numBytes = src[srcPlace] + 0x12;
				srcPlace++;
			}
			else
				numBytes += 2;

			//copy run
			u32 i = 0;
			for(i = 0; i < numBytes; ++i)
			{
				dst[dstPlace] = dst[copySource];
				copySource++;
				dstPlace++;
			}
		}

		//use next bit from "code" byte
		currCodeByte <<= 1;
		validBitCount-=1;
	}
}


u32 CheckIMD5Type(const u8 * buffer, int length)
{
	if(*((u32 *) buffer) != 'IMD5')
	{
		return *((u32 *) buffer);
	}

	const u8 * file = buffer+32;

	if(*((u32 *) file) != 'LZ77')
	{
		return *((u32 *) file);
	}

	u32 uncSize = 0;
	u8 * uncompressed_data = uncompressLZ77(file, length-32, &uncSize);
	if(!uncompressed_data)
		return 0;

	u32 * magic = (u32 *) uncompressed_data;
	u32 Type = magic[0];
	free(uncompressed_data);

	return Type;
}
