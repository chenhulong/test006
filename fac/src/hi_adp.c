/*********************************************************************
    Copyright (c) 2010
    All rights reserved. You are not allowed to copy or distribute
    the code without permission.

 */
//#include "hi_adp.h"
#include "hi_type.h"
static HI_BOOL init_flag = HI_FALSE;

HI_U32 HIADP_Init(HI_VOID)
{
#if 0
	HI_S32 Ret = HI_FAILURE;
    HI_HANDLE hWin;

	if(init_flag)
	{
		return HI_SUCCESS;
	}

	init_flag = HI_TRUE;

#if 1
	HI_SYS_Init();

	Ret = HIADP_Snd_Init();
	if (HI_SUCCESS != Ret)
	{
		hiAdpTrace("call HIADP_Snd_Init failed.\n");
		goto SYS_DEINIT;
	}

	Ret = HIADP_Disp_Init(HI_UNF_ENC_FMT_1080i_50);
	if(HI_SUCCESS != Ret)
	{
		hiAdpTrace(ERROR, "call HIADP_Disp_DeInit failed.\n");
		return SND_DEINIT;
	}
	
	Ret = HIADP_VO_Init(HI_UNF_VO_DEV_MODE_NORMAL);
	//Ret |= HIADP_VO_CreatWin(HI_NULL,&hWin);
	if (HI_SUCCESS != Ret)
	{
		hiAdpTrace("call HIADP_VO_Init failed.\n");
		goto DISP_DEINIT;
	}

    Ret = HI_UNF_DMX_Init();
    //Ret |= HIADP_DMX_AttachTSPort(4, Tuner);
    if (Ret != HI_SUCCESS)
    {
        hiAdpTrace("call HIADP_Demux_Init failed.\n");
        goto VO_DEINIT;
    }	

	Ret = HIADP_Tuner_Init();
	if (HI_SUCCESS != Ret)
	{
		hiAdpTrace("call HIADP_Demux_Init failed.\n");
		goto DMX_DEINIT;
	}

	//Ret = HIADP_Tuner_Connect(Tuner, TunerFreq, TunerSrate, ThirdParam);
	//if (HI_SUCCESS != Ret)
	//{
	//	hiAdpTrace("call HIADP_Tuner_Connect failed.\n");
	//	goto TUNER_DEINIT;
	//}


TUNER_DEINIT:
	//HIADP_Tuner_DeInit();

DMX_DEINIT:
	//HI_UNF_DMX_DetachTSPort(4);
	HI_UNF_DMX_DeInit();

VO_DEINIT:
	//HI_UNF_VO_DestroyWindow(hWin);
	HIADP_VO_DeInit();

DISP_DEINIT:
	HIADP_Disp_DeInit();

SND_DEINIT:
	HIADP_Snd_DeInit();

SYS_DEINIT:
	HI_SYS_DeInit();

#else
	HI_SYS_Init();
	HI_SYS_PreAV(HI_NULL);

	HI_SYS_SetLogLevel(HI_DEBUG_ID_USR, HIADP_DEBUG_LEVEL);

	Ret = HIADP_Snd_Init();
	if(HI_SUCCESS != Ret)
	{
		hiAdpTrace(ERROR, "HIADP_Snd_Init is error\n");
		return Ret;
	}

	Ret = HIADP_Disp_Init(HI_UNF_ENC_FMT_720P_50);
	if(HI_SUCCESS != Ret)
  {
    hiAdpTrace(ERROR, "call HIADP_Disp_DeInit failed.\n");
		return Ret;
  }

  Ret = HIADP_VO_Init(HI_UNF_VO_DEV_MODE_NORMAL);
  if (HI_SUCCESS != Ret)
  {
    hiAdpTrace(ERROR, "call HIADP_VO_Init failed.\n");
		return Ret;
  }

  Ret = HI_UNF_DMX_Init();
  Ret |= HI_UNF_DMX_AttachTSPort(0, 0);
  if (HI_SUCCESS != Ret)
  {
		hiAdpTrace(ERROR, "call HIADP_Demux_Init failed.\n");
		return Ret;
  }

  Ret = HIADP_Tuner_Init();
  if (HI_SUCCESS != Ret)
  {
		hiAdpTrace(ERROR, "call HIADP_Tuner_Init failed.\n");
		//return Ret;

  }
	
	Ret = HIADP_AVPlay_RegADecLib();
	Ret |= HI_UNF_AVPLAY_Init();
	if (Ret != HI_SUCCESS)
	{
		hiAdpTrace(ERROR, "call HI_UNF_AVPLAY_Init failed.\n");
		return Ret;
	}
		

	if (HIADP_Uio_Init() != 0)
	{
		hiAdpTrace(ERROR, "hisi_ir_key_init is error!\n");
		return HI_FAILURE;
	}


#endif
#endif
	return HI_SUCCESS;
}


HI_U32 HIADP_Deinit(HI_VOID)
{
#if 0
	HI_UNF_AVPLAY_DeInit();

	HI_UNF_TUNER_DeInit();

	HI_UNF_DMX_DetachTSPort(0);
	HI_UNF_DMX_DeInit();
	
	HIADP_VO_DeInit();

	HIADP_Disp_DeInit();
	
	HIADP_Snd_DeInit();

	HIADP_Uio_UnInit();

	HI_SYS_DeInit();

	init_flag = HI_FALSE;
#endif
	return HI_SUCCESS;
}
