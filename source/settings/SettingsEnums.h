#ifndef SETTINGS_ENUMS_H_
#define SETTINGS_ENUMS_H_

#include "libs/libwbfs/wiidisc.h"

enum
{
	INHERIT = -1,
	AUTO = 2
};

enum
{
	TYPE_GAME_WII_IMG		= 0x00,
	TYPE_GAME_WII_DISC		= 0x01,
	TYPE_GAME_GC_IMG		= 0x02,
	TYPE_GAME_GC_DISC		= 0x03,
	TYPE_GAME_GC_EXTRACTED	= 0x04,
	TYPE_GAME_NANDCHAN		= 0x05,
	TYPE_GAME_EMUNANDCHAN	= 0x06
};

enum
{
	MODE_NONE			= 0x00,
	MODE_WIIGAMES		= 0x01,
	MODE_NANDCHANNELS	= 0x02,
	MODE_EMUCHANNELS	= 0x04,
	MODE_GCGAMES		= 0x08,
	MODE_ALL			= 0xFF
};

enum
{
	EMUNAND_OFF,
	EMUNAND_PARTIAL,
	EMUNAND_FULL,
	EMUNAND_NEEK,
	EMUNAND_MAX
};

enum
{
	JAPANESE,
	ENGLISH,
	GERMAN,
	FRENCH,
	SPANISH,
	ITALIAN,
	DUTCH,
	S_CHINESE,
	T_CHINESE,
	KOREAN,
	CONSOLE_DEFAULT,
	MAX_LANGUAGE
};

enum
{
	GC_ENGLISH,
	GC_GERMAN,
	GC_FRENCH,
	GC_SPANISH,
	GC_ITALIAN,
	GC_DUTCH,
	GC_LANG_CONSOLE_DEFAULT,
	GC_MAX_LANGUAGE,
};

enum
{
	VIDEO_MODE_SYSDEFAULT,
	VIDEO_MODE_DISCDEFAULT,
	VIDEO_MODE_PAL50,
	VIDEO_MODE_PAL60,
	VIDEO_MODE_NTSC,
	VIDEO_MODE_PATCH,
	VIDEO_MODE_PAL480P,
	VIDEO_MODE_NTSC480P,
	VIDEO_MODE_MAX
};

enum
{
	VIDEO_PATCH_DOL_OFF,
	VIDEO_PATCH_DOL_REGION,
	VIDEO_PATCH_DOL_ON,
	VIDEO_PATCH_DOL_ALL,
	VIDEO_PATCH_DOL_MAX,
};

enum
{
	ASPECT_FORCE_4_3,
	ASPECT_FORCE_16_9,
	ASPECT_SYSTEM_DEFAULT,
	ASPECT_MAX
};

enum
{
	GAMEWINDOW_BANNER,
	GAMEWINDOW_DISC,
	GAMEWINDOW_BOTH,
	GAMEWINDOW_MAX
};

enum
{
	OFF,
	ON,
	MAX_ON_OFF
};

enum
{
	CLOCK_HR12 = 1, // use OFF for clock off
	CLOCK_HR24,
	CLOCK_MAX
};


enum
{
	WIILIGHT_OFF,
	WIILIGHT_ON,
	WIILIGHT_INSTALL,
	WIILIGHT_MAX

};

enum
{
	GAMEINFO_ID,
	GAMEINFO_REGION,
	GAMEINFO_BOTH,
	GAMEINFO_NONE,
	GAMEINFO_MAX
};

enum
{
	SCREENSAVER_3_MIN = 1,
	SCREENSAVER_5_MIN,
	SCREENSAVER_10_MIN,
	SCREENSAVER_20_MIN,
	SCREENSAVER_30_MIN,
	SCREENSAVER_60_MIN,
	SCREENSAVER_MAX
};

enum
{
	XFLIP_NO,
	XFLIP_YES,
	XFLIP_SYSMENU,
	XFLIP_WTF,
	XFLIP_DISK3D,
	XFLIP_MAX
};

enum
{
	//! Sorting should be used as AND to allow favorite ABC/RANK
	SORT_ABC		= 0x01,
	SORT_PLAYCOUNT  = 0x02,
	SORT_RANKING	= 0x04,
	SORT_FAVORITE   = 0x08,
	SORT_PLAYERS	= 0x10
};
enum
{
	KEYBOARD_QWERTY,
	KEYBOARD_DVORAK,
	KEYBOARD_QWERTZ,
	KEYBOARD_AZERTY,
	KEYBOARD_QWERTY2,
	KEYBOARD_MAX
};

enum
{
	INSTALL_TO_NO_DIR,
	INSTALL_TO_GAMEID_NAME,
	INSTALL_TO_NAME_GAMEID,
	INSTALL_TO_MAX
};

enum
{
	GAMESPLIT_NONE,
	GAMESPLIT_2GB,
	GAMESPLIT_4GB,
	GAMESPLIT_MAX
};

enum
{
	LIST_MODE,
	GRID_MODE,
	CAROUSEL_MODE,
	BANNERGRID_MODE
};

enum
{
	DISCARTS_ORIGINALS_CUSTOMS,
	DISCARTS_CUSTOMS_ORIGINALS,
	DISCARTS_ORIGINALS,
	DISCARTS_CUSTOMS,
	DISCARTS_MAX_CHOICE
};

enum
{
	BANNER_FAVICON_OFF,
	BANNER_FAVICON_CIRC,
	BANNER_FAVICON_SIN,
	BANNER_FAVICON_MULTI_LINE,
	BANNER_FAVICON_SINGLE_LINEA,
	BANNER_FAVICON_SINGLE_LINEB,
	BANNER_FAVICON_MAX_CHOICE
};

enum
{
	COVERSFULL_HQ,
	COVERSFULL_LQ,
	COVERSFULL_HQ_LQ,
	COVERSFULL_LQ_HQ,
	COVERSFULL_MAX_CHOICE
};

enum
{
	PARENTAL_LVL_EVERYONE,
	PARENTAL_LVL_CHILD,
	PARENTAL_LVL_TEEN,
	PARENTAL_LVL_MATURE,
	PARENTAL_LVL_ADULT
};

enum
{
	BLOCK_NONE					= 0x00,
	BLOCK_GLOBAL_SETTINGS		= 0x01,
	BLOCK_GUI_SETTINGS			= 0x02,
	BLOCK_LOADER_SETTINGS		= 0x04,
	BLOCK_PARENTAL_SETTINGS		= 0x08,
	BLOCK_SOUND_SETTINGS		= 0x10,
	BLOCK_CUSTOMPATH_SETTINGS	= 0x20,
	BLOCK_UPDATES				= 0x40,
	BLOCK_RESET_SETTINGS		= 0x80,
	BLOCK_THEME_DOWNLOADER		= 0x0100,
	BLOCK_THEME_MENU			= 0x0200,
	BLOCK_GAME_SETTINGS			= 0x0400,
	BLOCK_HBC_MENU				= 0x0800,
	BLOCK_TITLE_LAUNCHER_MENU	= 0x1000,
	BLOCK_COVER_DOWNLOADS		= 0x2000,
	BLOCK_GAME_INSTALL			= 0x4000,
	BLOCK_GAMEID_CHANGE			= 0x8000,
	BLOCK_CATEGORIES_MOD		= 0x010000,
	BLOCK_FEATURE_SETTINGS		= 0x020000,
	BLOCK_HARD_DRIVE_SETTINGS	= 0x040000,
	BLOCK_CATEGORIES_MENU		= 0x080000,
	BLOCK_SD_RELOAD_BUTTON		= 0x100000,
	BLOCK_PRIILOADER_OVERRIDE	= 0x200000,
	BLOCK_LOADER_MODE_BUTTON	= 0x400000,
	BLOCK_BANNER_SETTINGS   	= 0x800000,
	BLOCK_LOADER_LAYOUT_BUTTON	= 0x1000000,
	BLOCK_ALL					= 0xFFFFFFFF
};

enum
{
	ALT_DOL_OFF,
	ALT_DOL_FROM_GAME,
	ALT_DOL_FROM_SD_USB,
	ALT_DOL_ON_LAUNCH,
	ALT_DOL_DEFAULT,
	ALT_DOL_MAX_CHOICE
};

enum
{
	HOME_MENU_SYSTEM,
	HOME_MENU_FULL,
	HOME_MENU_DEFAULT,
	HOME_MENU_MAX_CHOICE
};

enum
{
	SEARCH_BEGINNING,
	SEARCH_CONTENT,
	SEARCH_MAX_CHOICE
};

enum
{
	BANNER_START_ON_ZOOM,
	BANNER_START_AFTER_ZOOM
};

enum
{
	GC_MODE_MIOS,
	GC_MODE_DEVOLUTION,
	GC_MODE_NINTENDONT,
	CG_MODE_MAX_CHOICE
	
};

enum
{
	GC_SOURCE_MAIN,
	GC_SOURCE_SD,
	GC_SOURCE_AUTO,
	GC_SOURCE_MAIN_SD,
	GC_SOURCE_SD_MAIN,
	CG_SOURCE_MAX_CHOICE
	
};

enum
{
	DEVO_MC_OFF,
	DEVO_MC_ON,
	DEVO_MC_INDIVIDUAL,
	// DEVO_MC_NAND,
	DEVO_MC_MAX_CHOICE
	
};

enum
{
	NIN_MC_OFF,
	NIN_MC_ON,
	NIN_MC_MULTI,
	NIN_MC_MAX_CHOICE
	
};

enum
{
	DML_VIDEO_AUTO,
	DML_VIDEO_FORCE_SYSDEFAULT, // same modes as Wii, +1
	DML_VIDEO_FORCE_DISCDEFAULT,
	DML_VIDEO_FORCE_PAL50,
	DML_VIDEO_FORCE_PAL60,
	DML_VIDEO_FORCE_NTSC,
	DML_VIDEO_FORCE_PATCH, // unused
	DML_VIDEO_FORCE_PAL480P,
	DML_VIDEO_FORCE_NTSC480P,
	DML_VIDEO_NONE,
	DML_VIDEO_MAX_CHOICE
};

enum
{
	PRIVSERV_OFF,
	PRIVSERV_NOSSL,
	PRIVSERV_WIIMMFI,
	PRIVSERV_MAX_CHOICE
	
};

#endif
