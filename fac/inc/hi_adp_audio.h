/**
 \file
 \brief common head file or PVR
 \copyright Shenzhen Hisilicon Co., Ltd.
 */

#ifndef __HI_ADP_AUDIO_H_
#define __HI_ADP_AUDIO_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************************* API declaration *****************************/

HI_S32 AudioSIOPinSharedEnable();

HI_VOID AudioSlicTlv320RST();

HI_VOID AudioSPIPinSharedEnable();


#ifdef __cplusplus
}
#endif

#endif /* __HIADP_AUDIO_H_ */
