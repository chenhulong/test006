#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "sys_types.h"
#include "hi_adp.h"
#include "graphic.h"
#include "database.h"
#include "windows.h"
#include "window.h"
#include "ui_tuner.h"
#include "ui_general.h"

#ifndef __UI_COMMON_H_
#define __UI_COMMON_H_

//#define SUPPORT_PLAY
//#define HOME_TEST

#ifdef HOME_TEST 	//home test
#define FREQUENCY_LOW         211
#define FREQUENCY_HIGH        682
#else							//factory test
#define FREQUENCY_LOW         115	
#define FREQUENCY_HIGH        858 
#endif

#define FREQUENCY_CUSTOM    	0

extern Window MainWnd;
extern Window GeneralWnd;
extern Window TunerWnd;
extern Window PanelWnd;
extern Window UpdateWnd;
extern Window DvbWnd;

#define TITEL_X    (PANEL_X1)
#define TITEL_Y		 (PANEL_Y1 + 30)
#define TITEL_W		 (PANEL_X2 - PANEL_X1)
#define TITEL_H		 (FONT_HEIGHT)

typedef enum
{	
	TEST_NOT,
	TESTING,
	TEST_SUC,
	TEST_FAIL,
}status_info_e;

void ShowTitle(char *p_str);

void Showstatus(status_info_e info, rect_t rect);

void ShowMsg(char *p_str, rect_t rect);

void ui_common_init(void);

void ui_common_deinit(void);

#endif
