#ifndef __HI_ADP_MPI_H_
#define __HI_ADP_MPI_H_

#ifdef __cplusplus
extern "C"	{
#endif

HI_S32 HIADP_Snd_Init(HI_VOID);

HI_S32 HIADP_Snd_DeInit(HI_VOID);

HI_S32 HIADP_Disp_Init(HI_UNF_ENC_FMT_E enFormat);

HI_S32 HIADP_Disp_DeInit(HI_VOID);

HI_S32 HIADP_VO_CreatWin(HI_RECT_S *pstWinRect,HI_HANDLE *phWin);

HI_S32 HIADP_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode);

HI_S32 HIADP_VO_DeInit();

HI_S32 HIADP_AVPlay_RegADecLib(HI_VOID);

HI_S32 HIADP_AVPlay_PlayProg(HI_HANDLE hAvplay, PMT_COMPACT_TBL *pProgTbl,HI_U32 ProgNum,HI_BOOL bAudPlay);


#ifdef __cplusplus
}
#endif

#endif
