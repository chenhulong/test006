/*********************************************************************
* Copyright (c) 2010
* All rights reserved. You are not allowed to copy or distribute
* the code without permission.
*
*********************************************************************/

/*************************************************
* @file:    dass_tuner.c
* @brief:   frequency-locking and query the status
* @author:  lee
* @created: 2010-02-04 20:20:50
*************************************************/
#include "hi_adp.h"

#define TUNER_TYPE_MAX_NUM 3
#define TUNER_DEV_ADDR_ALPS_TDAE 0xc2 
#define TUNER_DEV_ADDR_TDA18250B 0xc0 
#define TUNER_DEV_ADDR_SI2147 0xc6 
#define DEMOD_DEV_ADDR        0xa0


static char *g_HI_ADP_tuner_name[] = {"TDA18250B", "ALPS_TDAE", "SI2147"};
static int g_HI_ADP_Tuner_index = -1;

int HIADP_Tuner_getTuner_Name(char *str, int len)
{
#if 0
    if (g_HI_ADP_Tuner_index>TUNER_TYPE_MAX_NUM || g_HI_ADP_Tuner_index<0)
    {
        snprintf(str, len, "-");
        return 1;
    }
    
    snprintf(str, len, g_HI_ADP_tuner_name[g_HI_ADP_Tuner_index]);
    return strlen(str);
#endif
}


HI_S32 HIADP_Tuner_Init(HI_VOID)
{
#if 0
    HI_S32   Ret;
    HI_UNF_TUNER_ATTR_S TunerAttr;
	int i;
    HI_UNF_TUNER_CONNECT_PARA_S  ConnectPara;
	int tuner_type[] = {HI_UNF_TUNER_DEV_TYPE_TDA18250B, 
						HI_UNF_TUNER_DEV_TYPE_ALPS_TDAE, 
						HI_UNF_TUNER_DEV_TYPE_SI2147}; 
	int tuner_addr[] = {TUNER_DEV_ADDR_TDA18250B, 
						TUNER_DEV_ADDR_ALPS_TDAE, 
						TUNER_DEV_ADDR_SI2147}; 

    ConnectPara.enSigType = HI_UNF_TUNER_SIG_TYPE_CAB;
    ConnectPara.unConnectPara.stCab.bReverse = 0;
    ConnectPara.unConnectPara.stCab.u32Freq = 115 * 1000;
    ConnectPara.unConnectPara.stCab.u32SymbolRate = 6875 * 1000;
	ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_64;

    /*Initialize Tuner*/
    Ret = HI_UNF_TUNER_Init();
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_TUNER_Init failed.\n");
        return Ret;
    }

    /* open Tuner*/
    Ret = HI_UNF_TUNER_Open(HIADP_TUNER_USE);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_TUNER_Open failed.\n");
        HI_UNF_TUNER_DeInit();
        return Ret;
    }

    /*get default attribute in order to set attribute next*/
    Ret = HI_UNF_TUNER_GetDeftAttr(HIADP_TUNER_USE, &TunerAttr);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_TUNER_GetDeftAttr failed.\n");
        HI_UNF_TUNER_Close(HIADP_TUNER_USE);
        HI_UNF_TUNER_DeInit();
        return Ret;
    }
	
	for(i = 0; i < TUNER_TYPE_MAX_NUM; i++)
	{
		printf("\n\033[32mTrying Tuner Type : %s \033[0m\n", g_HI_ADP_tuner_name[i]);
		TunerAttr.enTunerDevType = tuner_type[i];
		TunerAttr.enDemodDevType = HIADP_DEMOD_TYPE;
		TunerAttr.enI2cChannel = HIADP_I2C_CHANNEL;
		TunerAttr.u32TunerAddr = tuner_addr[i];
		TunerAttr.u32DemodAddr = DEMOD_DEV_ADDR;
		Ret = HI_UNF_TUNER_SetAttr(HIADP_TUNER_USE, &TunerAttr);
		if (HI_SUCCESS == Ret)
		{
			Ret = HI_UNF_TUNER_Connect(HIADP_TUNER_USE, &ConnectPara, 500);
			if (Ret == HI_SUCCESS)
			{
				g_HI_ADP_Tuner_index = i;
				break;
			}
		}
		printf("HI_UNF_TUNER_Connect %s failed.\n", g_HI_ADP_tuner_name[i]);
	}
	
	if(Ret != HI_SUCCESS)
	{
		HI_UNF_TUNER_Close(HIADP_TUNER_USE);
		HI_UNF_TUNER_DeInit();
	}
	
	return Ret;
#endif
}


HI_S32 HIADP_Tuner_Init_Freq(HI_U32 Freq,HI_U32 SymbolRate,HI_U32 QamType)
{
#if 0
    HI_S32   Ret;
    HI_UNF_TUNER_ATTR_S TunerAttr;
	int i;
    HI_UNF_TUNER_CONNECT_PARA_S  ConnectPara;
	int tuner_type[] = {HI_UNF_TUNER_DEV_TYPE_TDA18250B, 
						HI_UNF_TUNER_DEV_TYPE_ALPS_TDAE, 
						HI_UNF_TUNER_DEV_TYPE_SI2147}; 
	int tuner_addr[] = {TUNER_DEV_ADDR_TDA18250B, 
						TUNER_DEV_ADDR_ALPS_TDAE, 
						TUNER_DEV_ADDR_SI2147}; 

    ConnectPara.enSigType = HI_UNF_TUNER_SIG_TYPE_CAB;
    ConnectPara.unConnectPara.stCab.bReverse = 0;
    ConnectPara.unConnectPara.stCab.u32Freq = Freq * 1000;
    ConnectPara.unConnectPara.stCab.u32SymbolRate = SymbolRate * 1000;
    switch (QamType)
    {
        case 16 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_16;
            break;
        case 32 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_32;
            break;
        case 64 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_64;
            break;
        case 128 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_128;
            break;
        case 256 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_256;
            break;
        case 512 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_512;
            break;            
        default:
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_64; 
    }


    /*Initialize Tuner*/
    Ret = HI_UNF_TUNER_Init();
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_TUNER_Init failed.\n");
        return Ret;
    }

    /* open Tuner*/
    Ret = HI_UNF_TUNER_Open(HIADP_TUNER_USE);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_TUNER_Open failed.\n");
        HI_UNF_TUNER_DeInit();
        return Ret;
    }

    /*get default attribute in order to set attribute next*/
    Ret = HI_UNF_TUNER_GetDeftAttr(HIADP_TUNER_USE, &TunerAttr);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_TUNER_GetDeftAttr failed.\n");
        HI_UNF_TUNER_Close(HIADP_TUNER_USE);
        HI_UNF_TUNER_DeInit();
        return Ret;
    }
	
	for(i = 0; i < TUNER_TYPE_MAX_NUM; i++)
	{
		printf("\n\033[32mTrying Tuner Type : %s \033[0m\n", g_HI_ADP_tuner_name[i]);
		TunerAttr.enTunerDevType = tuner_type[i];
		TunerAttr.enDemodDevType = HIADP_DEMOD_TYPE;
		TunerAttr.enI2cChannel = HIADP_I2C_CHANNEL;
		TunerAttr.u32TunerAddr = tuner_addr[i];
		TunerAttr.u32DemodAddr = DEMOD_DEV_ADDR;
		Ret = HI_UNF_TUNER_SetAttr(HIADP_TUNER_USE, &TunerAttr);
		if (HI_SUCCESS == Ret)
		{
			Ret = HI_UNF_TUNER_Connect(HIADP_TUNER_USE, &ConnectPara, 500);
			if (Ret == HI_SUCCESS)
			{
				g_HI_ADP_Tuner_index = i;
				break;
			}
		}
		printf("HI_UNF_TUNER_Connect %s failed.\n", g_HI_ADP_tuner_name[i]);
	}
	
	if(Ret != HI_SUCCESS)
	{
		HI_UNF_TUNER_Close(HIADP_TUNER_USE);
		HI_UNF_TUNER_DeInit();
	}
	
	return Ret;
#endif
}


/* Freq:MHZ  SymbolRate:KHZ  */
HI_S32 HIADP_Tuner_Connect(HI_U32 Freq,HI_U32 SymbolRate,HI_U32 QamType)
{
#if 0
    HI_UNF_TUNER_CONNECT_PARA_S  ConnectPara;

    ConnectPara.enSigType = HI_UNF_TUNER_SIG_TYPE_CAB;
    ConnectPara.unConnectPara.stCab.bReverse = 0;
    ConnectPara.unConnectPara.stCab.u32Freq = Freq * 1000;
    ConnectPara.unConnectPara.stCab.u32SymbolRate = SymbolRate * 1000;
    switch (QamType)
    {
        case 16 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_16;
            break;
        case 32 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_32;
            break;
        case 64 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_64;
            break;
        case 128 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_128;
            break;
        case 256 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_256;
            break;
        case 512 :
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_512;
            break;            
        default:
            ConnectPara.unConnectPara.stCab.enModType = HI_UNF_MOD_TYPE_QAM_64; 
    }

    /* connect Tuner*/
    return HI_UNF_TUNER_Connect(HIADP_TUNER_USE, &ConnectPara, 500);
#endif
}

HI_VOID HIADP_Tuner_DeInit(HI_VOID)
{
#if 0
    HI_UNF_TUNER_Close(HIADP_TUNER_USE);
    HI_UNF_TUNER_DeInit();
#endif
}

