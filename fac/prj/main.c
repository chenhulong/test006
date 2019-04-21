/***********************************************************

    COPYRIGHT 2014 (C) SVA Tech

    MODIFICATION HISTORY
    Date        By     Details
    ----------  -----  -------

 **********************************************************/
#include "ui_common.h"


#define OSD_BUF_PITCH        720
#define OSD_OFFSET_X        40
#define OSD_OFFSET_Y        25

static OSD_GContext_t* gc = NULL;

volatile static unsigned int* m_hide_buf = NULL;

volatile static unsigned int* m_osd_buf = NULL;


void KeyCallBack(UIO_RKey_t *key)
{
	NotifyWindow(key);
}

int main()
{
  HI_S32 ret = HI_FAILURE;
  OSD_Parameter_t param;

  hiAdpTrace(INFO,"<<<<enter factory test ...>>>>\n");
  if (HIADP_Init() != HI_SUCCESS)
  {
    hiAdpTrace(ERROR, "HIADP_Init Init Fail\n");
	return -1;
  }
	
	DbInit();

  param.bpp = 32;
  param.x = 0;
  param.y = 0;
  param.width = HIADP_720P_WIDTH;
  param.height = HIADP_720P_HEIGHT;
  param.typef = OSD_OSD;

	//Create OSD
  ret = HIADP_OSD_Create_GC(param, &gc);
  if (ret == HI_FAILURE)
  {
  	hiAdpTrace(ERROR, "Create GC Fail\n");
    return -1;
  }

  m_osd_buf = (unsigned int*)gc->buffer;
  m_hide_buf = (unsigned int*)gc->buffer; //fjhtest
  HIADP_OSD_SetAlpha(0xFF);

	
	//uio	
  HIADP_Uio_Register_Callback(KeyCallBack);

	//Graphic : pixel, line
	printf("main : width : %d  height:%d\n", HIADP_720P_WIDTH, HIADP_720P_HEIGHT);
  GraphicLibInit((void*)m_hide_buf, HIADP_720P_WIDTH, HIADP_720P_HEIGHT);
	
	WindowInit((void*)m_hide_buf, HIADP_720P_WIDTH, HIADP_720P_HEIGHT);

	ui_common_init();

	UiGeneralInit();
	
	//window
  ShowWindow(&MainWnd, 0, 0);

  while(1)
  {
	  int i;
	  HI_CHAR str[5];
	  
	  for (i=0; i<10; i++)
	  {
	    sprintf(str, "%d%d%d%d", i%10, (i+1)%10, (i+2)%10, (i+3)%10);
	    HIADP_Uio_Display(str);
			usleep(800 * 1000);
	  }
  }

	UiGeneralDeinit();
	ui_common_deinit();
	DbDeinit();
	HIADP_Deinit();

  return 1;
}

