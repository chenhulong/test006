/********************************************************************************
*              Copyright 2006 - 2050, Hisilicon Tech. Co., Ltd.
*                           ALL RIGHTS RESERVED
* FileName: hi_adp_config.h
* Description: hisilicon adapter layer module config.
*
* History:
* Version   Date           Author    DefectNum    Description
* V1.00    2011-08-05    Jiang Lei     NA              1 st release
********************************************************************************/

#ifndef __HI_ADP_CONFIG_H__
#define __HI_ADP_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define HIADP_VERSION "HD1.00"
#define HIADP_DEBUG_LEVEL HI_LOG_LEVEL_ERROR


/* TUNER */
#define HIADP_TUNER_USE    0
#define HIADP_TUNER_TYPE   HI_UNF_TUNER_DEV_TYPE_ALPS_TDAE
#define HIADP_DEMOD_TYPE   HI_UNF_DEMOD_DEV_TYPE_3130I
#define HIADP_I2C_CHANNEL  HI_UNF_I2C_CHANNEL_QAM
/* DAC */
#define DACMODE0 HI_UNF_DISP_DAC_MODE_CVBS
#define DACMODE1 HI_UNF_DISP_DAC_MODE_SVIDEO_Y
#define DACMODE2 HI_UNF_DISP_DAC_MODE_SVIDEO_C
#define DACMODE3 HI_UNF_DISP_DAC_MODE_HD_PB 
#define DACMODE4 HI_UNF_DISP_DAC_MODE_HD_Y
#define DACMODE5 HI_UNF_DISP_DAC_MODE_HD_PR
/* SIO */
#define SLAC_RESET_GPIO_GNUM	8
#define SLAC_RESET_GPIO_PNUM	5
/* E2PROM */
#define E2PROM_I2C_NUM          2


/**************************** keyled type config ******************************/

#define HIADP_KEYLED_TYPE HI_UNF_KEYLED_TYPE_FD650

/**************************** SmartCard  config *******************************/
#define HIADP_SCI_PROTOCOL 0  /* 0 for T0 */
#define HIADP_SCI_DEV_PORT 0
#define HIADP_SCI_INIT_TRY_CNT 10      /* 10*200ms */
#define HIADP_SCI_VCCEN HI_UNF_SCI_LEVEL_HIGH
#define HIADP_SCI_DETECTEN HI_UNF_SCI_LEVEL_HIGH

/**************************** eth port select  ********************************/
#define HIADP_ETH_DEV_NAME "eth0"
#define HIADP_ETH_DEV_IDX 0

/****************************   FLASH cfg  ************************************/
#ifdef DEMO_TEST
 #define NAND_FLASH_BLK_SIZE 0x100000             /* block size:1M */
 #define DASS_FLASH "/dev/mtd15"                  /* get reference from bootargs */
 #define DASS_EEPROM "/dev/mtd13"
 #define DASS_STB_INFO "/dev/mtd8"               /* mtd for stbid info, get reference from bootargs */
 #define DASS_LOADER_INFO "/dev/mtd9"            /* mtd for stbid info */
 #define DASS_CA_EEPROM "/dev/mtd14"
#else
 #define NAND_FLASH_BLK_SIZE 0x200000             /* block size:2M */
 #define DASS_FLASH "/dev/mtd15"                  /* get reference from bootargs */
 #define DASS_EEPROM "/dev/mtd13"
 #define DASS_STB_INFO "/dev/mtd8"               /* mtd for stbid info, get reference from bootargs */
 #define DASS_LOADER_INFO "/dev/mtd9"            /* mtd for stbid info */
 #define DASS_CA_EEPROM "/dev/mtd14"
#endif

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* __HI_ADP_CONFIG_H__ */
