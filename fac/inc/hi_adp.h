/********************************************************************************
 *              Copyright 2006 - 2050, Hisilicon Tech. Co., Ltd.
 *                           ALL RIGHTS RESERVED
 * FileName:    hi_adp.h
 * Description: hisilicon adapter layer module config.
 *
 * History:
 * Version   Date           Author       Description
 * V1.00    2013-11-28  borden       1 st release
 ********************************************************************************/
 
#ifndef __HI_ADP_H__  
#define __HI_ADP_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <stdarg.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/reboot.h>
#include <sys/sysinfo.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <poll.h>
#include <sys/mount.h>
#include <sys/un.h>

//hisi unf header
#include "hi_type.h"
#include "hi_common.h"
#include "hi_unf_common.h"
#include "hi_unf_disp.h"
#include "hi_unf_avplay.h"
#include "hi_unf_demux.h"
#include "hi_unf_ecs.h"
#include "hi_unf_sound.h"
#include "hi_unf_hdmi.h"
//#include "hi_unf_sio.h"
#include "hi_unf_so.h"
#include "hi_unf_venc.h"
#include "hi_unf_vi.h"
#include "hi_unf_vo.h"
#include "hi_unf_advca.h"
#include "hi_go.h"
#include "hi_tde_type.h"
#include "hi_tde_api.h"


#include "HA.AUDIO.MP3.decode.h"
#include "HA.AUDIO.MP2.decode.h"
#include "HA.AUDIO.AAC.decode.h"
#include "HA.AUDIO.DRA.decode.h"
#include "HA.AUDIO.PCM.decode.h"
#include "HA.AUDIO.WMA9STD.decode.h"
#include "HA.AUDIO.AMRNB.codec.h"
#include "HA.AUDIO.DOLBYPLUS.decode.h"

//hisi adapter headers
//#include "sys_types.h"
#include "hi_adp_debug.h"
#include "hi_adp_cfg.h"
#include "hi_adp_tuner.h"
#include "hi_adp_uio.h"
#include "hi_adp_search.h"
#include "hi_adp_mpi.h"
#include "hi_adp_hdmi.h"
#include "hi_adp_audio.h"
#include "hi_adp_data.h"
#include "hi_adp_osd.h"
#include "hi_adp_demux.h"
#include "hi_adp_eth.h"
#include "hi_unf_advca.h"
#include "ipanel_stbinfo.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */


#define HIADP_TUNER_MAX         1    /* single tuner */
#define HIADP_TUNER_PORT_1      0

/* AV */
#define HIADP_PAL_WIDTH         720
#define HIADP_PAL_HEIGHT        576

#define HIADP_NTSC_WIDTH        720
#define HIADP_NTSC_HEIGHT       480

#define HIADP_480P_WIDTH   	    HIADP_NTSC_WIDTH
#define HIADP_480P_HEIGHT   	HIADP_NTSC_HEIGHT

#define HIADP_576P_WIDTH   	    HIADP_PAL_WIDTH
#define HIADP_576P_HEIGHT   	HIADP_PAL_HEIGHT

#define HIADP_720P_WIDTH   	    1280
#define HIADP_720P_HEIGHT   	720

//#define HIADP_720P_WIDTH   	  HIADP_PAL_WIDTH
//#define HIADP_720P_HEIGHT   	HIADP_PAL_WIDTH


#define CANVAS_WIDTH					HIADP_720P_WIDTH
#define CANVAS_HEIGHT					HIADP_720P_HEIGHT

#define HIADP_1080P_WIDTH   	1920
#define HIADP_1080P_HEIGHT   	1080

#define HIADP_AV_STANDBY_IR     0x23DCFF00 //0xf40b9b44 //0xEB14FF00  /* standby ir key code: |~POWER|POWER|USR_CODE| */
#define HIADP_AV_STANDBY_KEY    0                 /* standby panel key code */


#define HIADP_VDAC_0            HI_UNF_DISP_DAC_MODE_HD_Y          // center up
#define HIADP_VDAC_1            HI_UNF_DISP_DAC_MODE_HD_PR         // right up
#define HIADP_VDAC_2            HI_UNF_DISP_DAC_MODE_HD_PB         // left up
#define HIADP_VDAC_3            HI_UNF_DISP_DAC_MODE_SVIDEO_C
#define HIADP_VDAC_4            HI_UNF_DISP_DAC_MODE_SVIDEO_Y
#define HIADP_VDAC_5            HI_UNF_DISP_DAC_MODE_CVBS       // left down

#define HISI_WIN_1080_SCREEN_W    (1920)
#define HISI_WIN_1080_SCREEN_H    (1080)
#define HISI_WIN_720_SCREEN_W     (1280)
#define HISI_WIN_720_SCREEN_H     (720)
#define HISI_WIN_576_SCREEN_W     (720)
#define HISI_WIN_576_SCREEN_H     (576)
#define HISI_WIN_480_SCREEN_W     (720)
#define HISI_WIN_480_SCREEN_H     (480)


/* DEMUX */
#define HIADP_INVALID_PID           0x1FFF
#define HIADP_INVALID_HANDLE        0xFFFFFFFF
#define HIADP_SUB_DMX_0             0
#define HIADP_SUB_DMX_1             1
#define HIADP_SUB_DMX_2             2     
#define HIADP_SUB_DMX_3             3
#define HIADP_SUB_DMX_4             4     
#define HIADP_SUB_DMX_MAX           5     
#define HIADP_ONE_DMX_FILTER_MAX 32

#define HIADP_PORT_PLAYBACK         5

#define HIADP_DMX_HANDLE_MAX        32
#define HIADP_DMX_FILTER_DEPTH      16
#define HIADP_DMX_CHAN_MAX          30
#define HIADP_DSC_HANDLE_MAX        24


/* OSD */
#define HIADP_OSD_KEYCOLOR_565      0x0000  /* transparent color */
#define HIADP_OSD_BLACK_565         0x0821




/************ struct definition *************/
typedef struct hiADP_AVStat_t
{
    HI_U32 u32PlayerCreate;
    HI_HANDLE u32PlayerHandle;
    HI_HANDLE u32AudChan;
    HI_HANDLE u32VidChan;
    HI_U16 u16aPid;             /*当前音频PID*/
    HI_U16 u16vPid;             /*当前视频PID*/
    HI_U16 u16pcrPid;           /*当前PCR PID*/
    HI_BOOL bAudPlayFile;     /*音频是否处在文件播放模式*/
    HI_BOOL bAudMute;         /*音频是否处在静音状态*/
    HI_BOOL bAudioStop;          /*是否处在节目停止播放状态*/
    HI_BOOL bVideoStop;
    HI_BOOL bShowIFrame;      /*是否处在I帧解码状态*/
    HI_BOOL bVidBlank;        /*是否处在黑屏状态*/
}ADP_AVStat_t;

typedef struct hiADP_DSCInfo_t
{
    HI_HANDLE u32Handle;       /* 标识物理密钥索引 */
    HI_HANDLE u32Chan;        /* 对应的通道索引 */
    HI_U16 u16PID;
} ADP_DSCInfo_t;

typedef enum hiADP_WAKEUP_MODE  /*fixme :: add in header file*/
{
    WAKEUP_BY_IR = 0,
    WAKEUP_BY_KEY = 1,
    WAKEUP_BY_RTC = 2
}ADP_WAKEUP_MODE_E;


HI_U32 HIADP_Init(HI_VOID);

HI_U32 HIADP_Deinit(HI_VOID);


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* __HI_ADP_H__ */

