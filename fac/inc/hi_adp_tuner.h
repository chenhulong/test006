#ifndef __HI_ADP_TUNER_H_
#define __HI_ADP_TUNER_H_

HI_S32 HIADP_Tuner_Init(HI_VOID);

HI_S32 HIADP_Tuner_Init_Freq(HI_U32 Freq,HI_U32 SymbolRate,HI_U32 QamType);

HI_S32 HIADP_Tuner_Connect(HI_U32 Freq, HI_U32 SymbolRate, HI_U32 QamType);

HI_VOID HIADP_Tuner_DeInit(HI_VOID);

int HIADP_Tuner_getTuner_Name(char *name_buf, int len);


#endif
