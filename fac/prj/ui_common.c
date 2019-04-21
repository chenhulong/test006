#include "ui_common.h"
#include <semaphore.h>

sem_t g_common_sem;

#define UI_COMMON_MAX_MSG_LEN (10)

void ShowTitle(char *p_str)
{
	box_t box = {0};
	
	//paint title
	box.rect.x = TITEL_X;
	box.rect.y = TITEL_Y;
	box.rect.w = TITEL_W;
	box.rect.h = TITEL_H;
	box.cl_fg = CL_WRITE;
	box.b_has_bg = FALSE;
	box.b_middle = TRUE;

	box.list_depth = 1;
	box.p_list[0] = p_str;

	ShowBox(&box);
	HIADP_OSD_Update_GC();
}

void ShowMsg(char *p_str, rect_t rect)
{
	box_t box = {0};

	if(strlen(p_str) > UI_COMMON_MAX_MSG_LEN)
		return;
	
	rect.w = UI_COMMON_MAX_MSG_LEN * FONT_BYTE_WIDTH;
	ShowRect(rect, CL_YELLOW);
	
	box.rect = rect;

	box.p_list[0] = p_str;
	box.cl_bg = CL_YELLOW;
	box.rect.w = strlen(p_str) * FONT_BYTE_WIDTH;
	
	box.cl_fg = CL_BLACK;
	box.b_has_bg = TRUE;
	box.list_depth = 1;

	ShowBox(&box);
	HIADP_OSD_Update_GC();
	
}


void Showstatus(status_info_e info, rect_t rect)
{
	box_t box = {0};
	char str[4][10] = {"Œ¥≤‚", "≤‚ ‘÷–", "≥…π¶", " ß∞‹"}; 

	sem_wait(&g_common_sem); 

	rect.w = FONT_BYTE_WIDTH * UI_COMMON_MAX_MSG_LEN;
	ShowRect(rect, CL_YELLOW);
	
	box.rect = rect;
	switch(info)
	{
	case TEST_NOT:
		box.p_list[0] = str[0];
		box.cl_bg = CL_YELLOW;
		box.rect.w = strlen(str[0]) * FONT_BYTE_WIDTH;
		break;

	case TESTING:
		box.p_list[0] = str[1];
		box.cl_bg = CL_YELLOW;
		box.rect.w = strlen(str[1]) * FONT_BYTE_WIDTH;
		break;
		
	case TEST_SUC:
		box.p_list[0] = str[2];
		box.cl_bg = CL_GREEN;		
		box.rect.w = strlen(str[2]) * FONT_BYTE_WIDTH;
		break;

	case TEST_FAIL:
		box.p_list[0] = str[3];
		box.cl_bg = CL_RED;		
		box.rect.w = strlen(str[3]) * FONT_BYTE_WIDTH;
		break;
	}
	
	box.cl_fg = CL_BLACK;
	box.b_has_bg = TRUE;
	box.list_depth = 1;

	ShowBox(&box);
	HIADP_OSD_Update_GC();
	
	sem_post(&g_common_sem); 
}

void ui_common_init(void)
{
	int res;
	
	res = sem_init(&g_common_sem, 0, 1);
	if (res != 0)
	{
		perror("ui_common_init semaphore init failed");
	} 
}

void ui_common_deinit(void)
{
	int res;
	
	res = sem_destroy(&g_common_sem);
	if (res != 0)
	{
		perror("ui_common_deinit semaphore deinit failed");
	} 
}


