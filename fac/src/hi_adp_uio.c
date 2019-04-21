/******************************************************************************/

/*  Copyright (c) 2010        */
/*  All rights reserved.                                                      */
/*  You are not allowed to copy or distribute the code without permission.    */
/******************************************************************************/

/******************************************************************************
* @file:    dass_ui.c
* @brief:
* @author:  lee
* @created: 2010-05-06 09:10:04
******************************************************************************/

/*
  Rev   Date        Author        Comments
--------------------------------------------------------------------------------
  1     2010-06-12  lee 		  add volume +&- repeat
  2 	2010-06-12  lee   		  add volume +&- key to left & right.
--------------------------------------------------------------------------------
 */
#include <semaphore.h>
#include "hi_adp.h"

typedef struct
{
    unsigned long long hi_key;
    unsigned int ui_key;
}S_HISI_KEY_MAP;


/****************************   IR1 key cfg  ***********************************/

#define IR1HisiMap_USR_CODE 0xFF00     //0xFD01

#define IR1_KEY_POWER  0xeb14ff00
#define IR1_KEY_MUTE   0xe31cff00
#define IR1_KEY_DIGIT1 0x6d92ff00
#define IR1_KEY_DIGIT2 0x6c93ff00
#define IR1_KEY_DIGIT3 0x33ccff00
#define IR1_KEY_DIGIT4 0x718eff00
#define IR1_KEY_DIGIT5 0x708fff00
#define IR1_KEY_DIGIT6 0x37c8ff00
#define IR1_KEY_DIGIT7 0x758aff00
#define IR1_KEY_DIGIT8 0x748bff00
#define IR1_KEY_DIGIT9 0x3bc4ff00
#define IR1_KEY_DIGIT0 0x7887ff00
#define IR1_KEY_HOMEPAGE 0x629dff00      //Menu(epg key)
#define IR1_KEY_QUIT     0x7788ff00        //QUIT
#define IR1_KEY_BACK     0x6f90ff00        //BACK ??
#define IR1_KEY_FAVOR  0xe916ff00
#define IR1_KEY_SELECT 0x31ceff00          // ok
#define IR1_KEY_LEFT     0x6699ff00
#define IR1_KEY_UP        0x35caff00
#define IR1_KEY_DOWN  0x2dd2ff00
#define IR1_KEY_RIGHT 0x3ec1ff00
#define IR1_KEY_GUIDE 0xf906ff00
#define IR1_KEY_PAGE_UP 0xbf40ff00
#define IR1_KEY_PAGE_DOWN 0xbb44ff00
#define IR1_KEY_VOLUME_UP 0xf40bff00
#define IR1_KEY_VOLUME_DOWN 0xa758ff00    //
#define IR1_KEY_CHANNEL_UP 0xFFFFff00
#define IR1_KEY_CHANNEL_DOWN 0xFFFFff00
#define IR1_KEY_INFORMATION 0xef10ff00    //资讯
#define IR1_KEY_TAB 0xe718ff00            //显示
#define IR1_KEY_RED 0xff00ff00
#define IR1_KEY_BLUE 0xe11eff00
#define IR1_KEY_GREEN 0xf708ff00
#define IR1_KEY_YELLOW 0xf50aff00

#define IR1_KEY_TV 0xfa05ff00
#define IR1_KEY_RADIO 0xfb04ff00
#define IR1_KEY_VOD 0xf30cff00

#define IR1_KEY_RECALL 0xec13ff00
#define IR1_KEY_TRACK 0xab54ff00
#define IR1_KEY_MAIL 0xaf50ff00
#define IR1_KEY_STOCK 0xb34cff00
#define IR1_KEY_GAME 0xFFFFff00


static S_HISI_KEY_MAP IR1HisiMap[] = {
    {IR1_KEY_POWER,       MUI_REMOTE_POWER      },
    {IR1_KEY_MUTE,        MUI_REMOTE_MUTE       },
    {IR1_KEY_DIGIT1,      MUI_REMOTE_1          },
    {IR1_KEY_DIGIT2,      MUI_REMOTE_2          },
    {IR1_KEY_DIGIT3,      MUI_REMOTE_3          },
    {IR1_KEY_DIGIT4,      MUI_REMOTE_4          },
    {IR1_KEY_DIGIT5,      MUI_REMOTE_5          },
    {IR1_KEY_DIGIT6,      MUI_REMOTE_6          },
    {IR1_KEY_DIGIT7,      MUI_REMOTE_7          },
    {IR1_KEY_DIGIT8,      MUI_REMOTE_8          },
    {IR1_KEY_DIGIT9,      MUI_REMOTE_9          },
    {IR1_KEY_DIGIT0,      MUI_REMOTE_0          },
    {IR1_KEY_HOMEPAGE,    MUI_REMOTE_MENU       },
    {IR1_KEY_BACK,        MUI_REMOTE_BACK       },
    {IR1_KEY_QUIT,        MUI_REMOTE_QUIT       },
    {IR1_KEY_FAVOR,       MUI_REMOTE_FAVORITE   },
    {IR1_KEY_SELECT,      MUI_REMOTE_OK         },
    {IR1_KEY_LEFT,        MUI_REMOTE_LEFT       }, /*left & fb*/
    {IR1_KEY_UP,          MUI_REMOTE_UP         }, /*up & channel+ */
    {IR1_KEY_DOWN,        MUI_REMOTE_DOWN       }, /*down & channel- */
    {IR1_KEY_RIGHT,       MUI_REMOTE_RIGHT      }, /* right & ff */
    {IR1_KEY_GUIDE,       MUI_REMOTE_GUIDE      },
    {IR1_KEY_PAGE_UP,     MUI_REMOTE_PAGEUP     },
    {IR1_KEY_PAGE_DOWN,   MUI_REMOTE_PAGEDOWN   },
    {IR1_KEY_VOLUME_UP,   MUI_REMOTE_VOLUME_UP  }, /* vol+ & add */
    {IR1_KEY_VOLUME_DOWN, MUI_REMOTE_VOLUME_DOWN}, /* vol- & del */
    {IR1_KEY_TV,          MUI_REMOTE_TV         },
    {IR1_KEY_RADIO,       MUI_REMOTE_RADIO      },
    {IR1_KEY_VOD,         MUI_REMOTE_VOD        },
    {IR1_KEY_INFORMATION, MUI_REMOTE_INFORMATION}, //资讯
    {IR1_KEY_TAB,         MUI_REMOTE_TIP        }, //显示
    {IR1_KEY_RECALL,      MUI_REMOTE_BACK       }, //返回
    {IR1_KEY_RED,         MUI_REMOTE_RED        },
    {IR1_KEY_BLUE,        MUI_REMOTE_BLUE       },
    {IR1_KEY_GREEN,       MUI_REMOTE_GREEN      },
    {IR1_KEY_YELLOW,      MUI_REMOTE_YELLOW     },
    {IR1_KEY_TRACK,       MUI_REMOTE_TRACK      },
    {IR1_KEY_GAME,        MUI_REMOTE_DASSN      },
    {IR1_KEY_CHANNEL_UP,  MUI_REMOTE_CHANNEL_UP },
    {IR1_KEY_CHANNEL_DOWN,MUI_REMOTE_CHANNEL_DOWN},
};

#define IR1HisiMap_MAX_NUM (sizeof(IR1HisiMap) / sizeof(IR1HisiMap[0]))


/****************************   IR2 key cfg  ***********************************/

#define IR2OcnMap_USR_CODE 		0x434f    


static S_HISI_KEY_MAP IR2OcnMap[] =
{
    /*遥控器实际键值*/   /*OpenTV统一定义键值*/
    {	0xf10e4e434fULL, MUI_REMOTE_QUIT },
    { 0xf00f4e434fULL, MUI_REMOTE_POWER   }, /**< Power */
    { 0xf40b4e434fULL, MUI_REMOTE_BACK      }, /**< Back */
    //{ 0xf20d4e434fULL, MUI_REMOTE_VOL_UP    }, /**< VOL+ */
    //{ 0xd02f4e434fULL, MUI_REMOTE_PMINUS    },
    { 0xf30c4e434fULL, MUI_REMOTE_MUTE      }, /**< Mute */
    //{ 0xd22d4e434fULL, MUI_REMOTE_VOL_DOWN  }, /**< VOL- */
    //{ 0xcf304e434fULL, MUI_REMOTE_EPG       }, /**导视界面，非epg*/
    //{ 0xe41b4e434fULL, MUI_REMOTE_INFO      }, /**< INFO */

    //{ 0xf10e4e434fULL, MUI_REMOTE_EXIT},
    { 0x60284e434fULL, MUI_REMOTE_MENU}, /**< EPG ocn的服务按键，非传统意义上的menu*/
    { 0xd42b4e434fULL, MUI_REMOTE_UP        }, /**< UP */
    { 0xda254e434fULL, MUI_REMOTE_DOWN      }, /**< DOWN */
    { 0xd6294e434fULL, MUI_REMOTE_LEFT      }, /**< LEFT */
    { 0xd7284e434fULL, MUI_REMOTE_RIGHT     }, /**< RIGHT */
    { 0xd32c4e434fULL, MUI_REMOTE_OK        }, /**< OK */
    { 0x3e424e434fULL, MUI_REMOTE_RED       }, /**< F2 */
    { 0x585a4e434fULL, MUI_REMOTE_GREEN     }, /**< F1 */
    { 0x605c4e434fULL, MUI_REMOTE_YELLOW    }, /**< F3 */
    { 0x4f324e434fULL, MUI_REMOTE_BLUE      }, /**< F4 */
    { 0xec134e434fULL, MUI_REMOTE_0         },/*TODO:文档与实际按键值不对应，这里是实际按键值，文档中是eb14*/
    { 0xde214e434fULL, MUI_REMOTE_1         },
    { 0xdc234e434fULL, MUI_REMOTE_2         },
    { 0xdd224e434fULL, MUI_REMOTE_3         },
    { 0xe21d4e434fULL, MUI_REMOTE_4         },
    { 0xe11e4e434fULL, MUI_REMOTE_5         },
    { 0xe01f4e434fULL, MUI_REMOTE_6         },
    { 0xdf204e434fULL, MUI_REMOTE_7         },
    { 0xee114e434fULL, MUI_REMOTE_8         },
    { 0xed124e434fULL, MUI_REMOTE_9         },
   // { 0x78334e434fULL, MUI_REMOTE_SEARCH    },
   // { 0x1a354e434fULL, MUI_REMOTE_CONFIG    }, /**< SET Key */

    // { xxx,            MUI_REMOTE_LIST},
    // { xxx,            MUI_REMOTE_REMIND},
   // { 0xe31c4e434fULL, MUI_REMOTE_PAGE_UP   }, /**< PgUp */
   // { 0xd9264e434fULL, MUI_REMOTE_PAGE_DOWN }, /**< PgDown */

   // { 0x12654e434fULL,            MUI_REMOTE_HELP},
    // { xxx,            MUI_REMOTE_LANGUAGE},
    { 0x2a494e434fULL, MUI_REMOTE_AUDIO     }, /**< Audio */
   //{ 0x12864e434fULL, MUI_REMOTE_RECORD    }, /**< nPVR */

   // { 0xe9164e434fULL, MUI_REMOTE_DTV},
    //{ xxx, MUI_REMOTE_WEB},
    { 0xd52a4e434fULL, MUI_REMOTE_VOD},

    // { xxx,            MUI_REMOTE_DVR},
   // { 0xeb144e434fULL, MUI_REMOTE_XINHAO},
   // { 0xea154e434fULL, MUI_REMOTE_JINHAO},
    //{ xxx,             MUI_REMOTE_TIMESHIFT},
    //{ xxx, MUI_REMOTE_SELTIME   }, //seek
    //{ xxx, MUI_REMOTE_JUMP_START}, //REW
    //{ xxx, MUI_REMOTE_JUMP_END  },

    //{ xxx,             MUI_REMOTE_VODPLY},
 //   { 0xe8174e434fULL,             MUI_REMOTE_MUSIC},
    //{ xxx,             MUI_REMOTE_ITV},
  //  { 0xe7184e434fULL,             MUI_REMOTE_JUMP},
    //{ xxx, MUI_REMOTE_F1        }, /**< F1 */
    //{ xxx, MUI_REMOTE_F2        }, /**< F2 */

    //{ xxx,             MUI_REMOTE_MAIL},
 //   { 0xdb244e434fULL,             MUI_REMOTE_FAV},
    //{ xxx,             MUI_REMOTE_STOCK},
    //{ xxx, MUI_REMOTE_UNDEFINED },
};

#define IR2OcnMap_MAX_NUM (sizeof(IR2OcnMap) / sizeof(IR2OcnMap[0]))


//--------------------------------------------------------------------------

#define IRRC52OcnMap_USR_CODE 0x500     

static S_HISI_KEY_MAP IRRC52OcnMap[] =
{
    /*遥控器实际键值*/   /*OpenTV统一定义键值*/
    {	0x594, MUI_REMOTE_QUIT },

    { 0x590, MUI_REMOTE_POWER   }, /**< Power */
   // { 0x59a, MUI_REMOTE_PPLUS     },
    { 0x595, MUI_REMOTE_BACK      }, /**< Back */
  //  { 0x597, MUI_REMOTE_VOL_UP    }, /**< VOL+ */
   // { 0x599, MUI_REMOTE_PMINUS    },
    { 0x591, MUI_REMOTE_MUTE      }, /**< Mute */
   // { 0x596, MUI_REMOTE_VOL_DOWN  }, /**< VOL- */
    //{ 0x5a2, MUI_REMOTE_EPG       }, /**导视界面，非epg*/
    //{ 0x5a0, MUI_REMOTE_INFO      }, /**< INFO */

   // { 0x594, MUI_REMOTE_EXIT},
    { 0x5a1, MUI_REMOTE_MENU}, /**< EPG ocn的服务按键，非传统意义上的menu*/
    { 0x5a3, MUI_REMOTE_UP        }, /**< UP */
    { 0x5a4, MUI_REMOTE_DOWN      }, /**< DOWN */
    { 0x5a5, MUI_REMOTE_LEFT      }, /**< LEFT */
    { 0x5a6, MUI_REMOTE_RIGHT     }, /**< RIGHT */
    { 0x5a7, MUI_REMOTE_OK        }, /**< OK */
    { 0x5ac, MUI_REMOTE_RED       }, /**< F2 */
    { 0x5ad, MUI_REMOTE_GREEN     }, /**< F1 */
    { 0x5ae, MUI_REMOTE_YELLOW    }, /**< F3 */
    { 0x5af, MUI_REMOTE_BLUE      }, /**< F4 */
    { 0x5b0, MUI_REMOTE_0         },/*TODO:文档与实际按键值不对应，这里是实际按键值，文档中是eb14*/
    { 0x5b1, MUI_REMOTE_1         },
    { 0x5b2, MUI_REMOTE_2         },
    { 0x5b3, MUI_REMOTE_3         },
    { 0x5b4, MUI_REMOTE_4         },
    { 0x5b5, MUI_REMOTE_5         },
    { 0x5b6, MUI_REMOTE_6         },
    { 0x5b7, MUI_REMOTE_7         },
    { 0x5b8, MUI_REMOTE_8         },
    { 0x5b9, MUI_REMOTE_9         },
  //  { 0x592, MUI_REMOTE_SEARCH    },
   // { 0x598, MUI_REMOTE_CONFIG    }, /**< SET Key */

    // { xxx,            MUI_REMOTE_LIST},
    // { xxx,            MUI_REMOTE_REMIND},
   // { 0x5a8, MUI_REMOTE_PAGE_UP   }, /**< PgUp */
   // { 0x5a9, MUI_REMOTE_PAGE_DOWN }, /**< PgDown */

  //  { 0x5aa,            MUI_REMOTE_HELP},
    // { xxx,            MUI_REMOTE_LANGUAGE},
    { 0x59c, MUI_REMOTE_AUDIO     }, /**< Audio */
   // { 0x583, MUI_REMOTE_RECORD    }, /**< nPVR */

  //  { 0x585,            MUI_REMOTE_DTV},
    // { xxx,            MUI_REMOTE_WEB},
    { 0x584, MUI_REMOTE_VOD       },

    // { xxx,            MUI_REMOTE_DVR},
  //  { 0x589,            MUI_REMOTE_XINHAO},
  //  { 0x58a,            MUI_REMOTE_JINHAO},
    //{ xxx,             MUI_REMOTE_TIMESHIFT},
    //{ xxx, MUI_REMOTE_SELTIME   }, //seek
    //{ xxx, MUI_REMOTE_JUMP_START}, //REW
    //{ xxx, MUI_REMOTE_JUMP_END  },

    //{ xxx,             MUI_REMOTE_VODPLY},
  //  { 0x586,             MUI_REMOTE_MUSIC},
  // //{ xxx,             MUI_REMOTE_JUMP},
    //{ xxx, MUI_REMOTE_F2        }, /**< F2 */

    //{ xxx, MUI_REMOTE_F1        }, /**< F1 */
    //{ xxx,             MUI_REMOTE_MAIL},
   // { 0x582,             MUI_REMOTE_FAV},
    //{ xxx,             MUI_REMOTE_STOCK},
    //{ xxx, MUI_REMOTE_UNDEFINED },
};

#define IRRC52OcnMap_MAX_NUM (sizeof(IRRC52OcnMap) / sizeof(IRRC52OcnMap[0]))


//------------------------------------------------------------------------------------

#define IRNEC2OcnMap_USR_CODE 0x7f00   


static S_HISI_KEY_MAP IRNEC2OcnMap[] =
{
    /*遥控器实际键值*/   /*OpenTV统一定义键值*/

    { 0xe51a7f00, MUI_REMOTE_POWER   }, /**< Power */
    //{ 0xe9167f00, MUI_REMOTE_PPLUS     },
    { 0xf10e7f00, MUI_REMOTE_BACK      }, /**< Back */
  //  { 0xf9067f00, MUI_REMOTE_VOL_UP    }, /**< VOL+ */
 //   { 0xed127f00, MUI_REMOTE_PMINUS    },
    { 0xe11e7f00, MUI_REMOTE_MUTE      }, /**< Mute */
  //  { 0xfd027f00, MUI_REMOTE_VOL_DOWN  }, /**< VOL- */
  //  { 0xe41b7f00, MUI_REMOTE_EPG       }, /**导视界面，非epg*/
   // { 0xf40b7f00, MUI_REMOTE_INFO      }, /**< INFO */

  	{ 0xf50a7f00, MUI_REMOTE_QUIT },
    { 0xfc037f00, MUI_REMOTE_MENU}, /**< EPG ocn的服务按键，非传统意义上的menu*/
    { 0xab547f00, MUI_REMOTE_UP        }, /**< UP */
    { 0xaf507f00, MUI_REMOTE_DOWN      }, /**< DOWN */
    { 0xbb447f00, MUI_REMOTE_LEFT      }, /**< LEFT */
    { 0xa35c7f00, MUI_REMOTE_RIGHT     }, /**< RIGHT */
    { 0xb34c7f00, MUI_REMOTE_OK        }, /**< OK */
    { 0xba457f00, MUI_REMOTE_RED       }, /**< F2 */
    { 0xb24d7f00, MUI_REMOTE_GREEN     }, /**< F1 */
    { 0xaa557f00, MUI_REMOTE_YELLOW    }, /**< F3 */
    { 0xa25d7f00, MUI_REMOTE_BLUE      }, /**< F4 */
    { 0xeb147f00, MUI_REMOTE_0         },/*TODO:文档与实际按键值不对应，这里是实际按键值，文档中是eb14*/
    { 0xb6497f00, MUI_REMOTE_1         },
    { 0xae517f00, MUI_REMOTE_2         },
    { 0xa6597f00, MUI_REMOTE_3         },
    { 0xf20d7f00, MUI_REMOTE_4         },
    { 0xea157f00, MUI_REMOTE_5         },
    { 0xe21d7f00, MUI_REMOTE_6         },
    { 0xf6097f00, MUI_REMOTE_7         },
    { 0xee117f00, MUI_REMOTE_8         },
    { 0xe6197f00, MUI_REMOTE_9         },
 //   { 0xff007f00, MUI_REMOTE_SEARCH    },
  //  { 0xf8077f00, MUI_REMOTE_CONFIG    }, /**< SET Key */

    // { xxx,            MUI_REMOTE_LIST},
    // { xxx,            MUI_REMOTE_REMIND},
 //   { 0xbf407f00, MUI_REMOTE_PAGE_UP   }, /**< PgUp */
 //   { 0xb7487f00, MUI_REMOTE_PAGE_DOWN }, /**< PgDown */

 //   { 0xa7587f00,            MUI_REMOTE_HELP},
    // { xxx,            MUI_REMOTE_LANGUAGE},
    { 0xfa057f00, MUI_REMOTE_AUDIO     }, /**< Audio */
 //   { 0xf7087f00, MUI_REMOTE_RECORD    }, /**< nPVR */

  //  { 0xf00f7f00,            MUI_REMOTE_DTV},
    // { xxx,            MUI_REMOTE_WEB},
    { 0xe8177f00, MUI_REMOTE_VOD       },

    // { xxx,            MUI_REMOTE_DVR},
//    { 0xf30c7f00,            MUI_REMOTE_XINHAO},
 //   { 0xe31c7f00,            MUI_REMOTE_JINHAO},
    //{ xxx,             MUI_REMOTE_TIMESHIFT},
    //{ xxx, MUI_REMOTE_SELTIME   }, //seek
    //{ xxx, MUI_REMOTE_JUMP_START}, //REW
    //{ xxx, MUI_REMOTE_JUMP_END  },

    //{ xxx,             MUI_REMOTE_VODPLY},
 //   { 0xec137f00,             MUI_REMOTE_MUSIC},
    //{ xxx,             MUI_REMOTE_ITV},
  //  { 0xbe417f00,             MUI_REMOTE_JUMP},
    //{ xxx, MUI_REMOTE_F1        }, /**< F1 */
    //{ xxx, MUI_REMOTE_F2        }, /**< F2 */

    //{ xxx,             MUI_REMOTE_MAIL},
 //   { 0xe01f7f00,             MUI_REMOTE_FAV},
    //{ xxx,             MUI_REMOTE_STOCK},
    //{ xxx, MUI_REMOTE_UNDEFINED },
};

#define IRNEC2OcnMap_MAX_NUM (sizeof(IRNEC2OcnMap) / sizeof(IRNEC2OcnMap[0]))


static unsigned char DigDisCode[10] = 
                                    {0x3f, 0x06, 0x5b, 0x4f, 0x66,
                                     0x6d, 0x7d, 0x07, 0x7f, 0x67};

static unsigned char LCharDisCode[26] = {
    0x5f, 0x7c, 0x39, 0x5e, 0x7b, 0x71, 0x67, 0x76, 0x06, 0x0e,  /* A -> J */
    0x70, 0x3c, 0xbf, 0xc8, 0x3f, 0x8c, 0x98, 0xce, 0x92, 0x78,  /* K -> T */
    0xc1, 0xc1, 0xbf, 0xbf, 0x99, 0xa4                           /* U -> Z */
};

static unsigned char UCharDisCode[26] = {
    0x5f, 0x7c, 0x39, 0x5e, 0x7b, 0x71, 0x67, 0x76, 0x06, 0x0e,  /* a -> j */
    0x70, 0x3c, 0xbf, 0xc8, 0x3f, 0x8c, 0x98, 0xaf, 0x92, 0x78,  /* k -> t */
    0xe3, 0xe3, 0xbf, 0xbf, 0x91, 0xa4                           /* u -> z */
};

#define POWERLED_GPIO_GNUM	5
#define POWERLED_GPIO_PNUM	5

static Uio_CallbackProc_f hisi_mui_callback = NULL;

static pthread_t hisi_ir_thread_pid;
static pthread_t hisi_key_thread_pid;


static int hisi_ir_thread_flag  = 1;  /*红外线程标志*/
static int hisi_key_thread_flag = 1;   /*按键标志*/

static int hisi_ir_run_flag  = 1;
static int hisi_key_run_flag = 1;

static void hisi_submit_key(unsigned int ui_key, UIO_KeySrc_e key_source)
{
  UIO_RKey_t key = {0};
	
	key.keyData = ui_key;
	key.keySrc = key_source;

	printf("ui_key %x, key_source %x\n", ui_key, key_source);
  hisi_mui_callback(&key);
}

static void hisi_ir_thread()
{
  HI_S32 s32Ret = HI_FAILURE;
  HI_UNF_KEY_STATUS_E eKeyPressStatus = 0;
  HI_U64 u64KeyId = 0;
  S_HISI_KEY_MAP *p_keymap = NULL;
  int key_num = 0;
  int i = 0;

  //default is red 
  HI_UNF_GPIO_SetDirBit(POWERLED_GPIO_GNUM * 8 + POWERLED_GPIO_PNUM, HI_FALSE);
	
  HI_UNF_GPIO_WriteBit(POWERLED_GPIO_GNUM * 8 + POWERLED_GPIO_PNUM, HI_TRUE);
	
  while (hisi_ir_run_flag)
  {
    s32Ret = HI_UNF_IR_GetValue(&eKeyPressStatus, &u64KeyId, 100);
    if (s32Ret != 0)
    {
      usleep(10 * 1000);
      continue;
    }

	if(eKeyPressStatus == HI_UNF_KEY_STATUS_UP)//green
	{
		HI_UNF_GPIO_WriteBit(POWERLED_GPIO_GNUM * 8 + POWERLED_GPIO_PNUM, HI_TRUE);
  		continue;
	}
	else if(eKeyPressStatus == HI_UNF_KEY_STATUS_DOWN)//red
	{
		HI_UNF_GPIO_WriteBit(POWERLED_GPIO_GNUM * 8 + POWERLED_GPIO_PNUM, HI_FALSE);
	}

	if((u64KeyId & 0xffff) == IR1HisiMap_USR_CODE)
    {
		p_keymap = IR1HisiMap;
		key_num = IR1HisiMap_MAX_NUM;
    }
	else  if((u64KeyId & 0xffff) == IR2OcnMap_USR_CODE)
    {
    	p_keymap = IR2OcnMap;
		key_num = IR2OcnMap_MAX_NUM;
    } 
	else if((u64KeyId & 0xf00) == IRRC52OcnMap_USR_CODE)
	{
		p_keymap = IRRC52OcnMap;
		key_num = IRRC52OcnMap_MAX_NUM;
	}
	else	if((u64KeyId & 0xffff) == IRNEC2OcnMap_USR_CODE)
	{
		p_keymap = IRNEC2OcnMap;
		key_num = IRNEC2OcnMap_MAX_NUM;
	}

	for (i = 0; i < key_num; i++)
    {
      if (p_keymap[i].hi_key == u64KeyId)
      {
          break;
      }
    }

    if (i < key_num)
    {
		hisi_submit_key(p_keymap[i].ui_key, UIO_REMOTE);
    }
  }
}

/*************************************************
* FUNCTION:	hisi_key_thread
* PARAMETERS:
* DESCRIPTION:
* RETURNS:		None
*************************************************/
static void hisi_key_thread()
{
    HI_U32 press_status, key_id;
    HI_BOOL keyEnableFlag = HI_FALSE;
    
    hiAdpEnter();

    while (hisi_key_run_flag)
    {
        if (HI_UNF_KEY_GetValue(&press_status, &key_id) != 0)
        { 	
        		
           usleep(10 * 1000);
           continue;
        }

        keyEnableFlag = HI_TRUE;
                

        /* convert key value to IR value */
        switch (key_id)
        {
        case 0x4f:
          key_id = MUI_REMOTE_DOWN;
          break;
            
        case 0x47:
          key_id = MUI_REMOTE_UP;
          break;
						
        case 0xfe:
	        key_id = MUI_REMOTE_POWER;
	        break;

        default:
            keyEnableFlag = HI_FALSE;
            break;
        }

        if(keyEnableFlag && (press_status != HI_UNF_KEY_STATUS_UP))
        {
          hisi_submit_key(key_id, UIO_FRONT_PANEL);
        }
        
    }

    hiAdpLeave();
    
    return;
}



/*************************************************
* FUNCTION: 	mUI_RegisterKeyCallback
* PARAMETERS:
* DESCRIPTION:
* RETURNS:		None
*************************************************/
HI_VOID HIADP_Uio_Register_Callback(Uio_CallbackProc_f callback)
{
    hisi_mui_callback = callback;

    /* create ir pthread */
    hisi_ir_run_flag = 1;
    if (hisi_ir_thread_flag)
    {
        if (pthread_create(&hisi_ir_thread_pid, NULL, (void*)hisi_ir_thread, NULL) < 0)
        {
            perror("mUI_RegisterKeyCallback, create hisi_ir_thread");
        }
        else
        {
            hisi_ir_thread_flag = 0;
        }
    }

    /* create key pthread */
    hisi_key_run_flag = 1;
    if (hisi_key_thread_flag)
    {
        if (pthread_create(&hisi_key_thread_pid, NULL, (void*)hisi_key_thread, NULL) < 0)
        {
            perror("mUI_RegisterKeyCallback, create hisi_key_thread");
        }
        else
        {
            hisi_key_thread_flag = 0;
        }
    }

    return;
}


HI_S32 HIADP_Uio_Display(HI_CHAR *str)
{
  int i;
  HI_U32 display = 0;
  HI_CHAR *tmp = NULL;
  HI_CHAR aTmpDisp[4] = {0};      

  if(NULL == str)
  {
    hiAdpTrace(ERROR, "error: param is invalid!\n");
    return HI_FAILURE;
  }

  tmp = (HI_CHAR*)str;
  for (i = 0; (i < 4) && i < strlen((HI_CHAR*)tmp); i++)
  {
      if ((tmp[i] >= '0') && (tmp[i] <= '9'))
      {
          display = (display << 8) | DigDisCode[tmp[i] - '0'];
      }
      else if ((tmp[i] >= 'a') && (tmp[i] <= 'z'))
      {
          display = (display << 8) | LCharDisCode[tmp[i] - 'a'];
      }
      else if ((tmp[i] >= 'A') && (tmp[i] <= 'Z'))
      {
          display = (display << 8) | UCharDisCode[tmp[i] - 'A'];
      }
      else
      {
          display = (display << 8) | 0xff;
      }
  }

  /*将数值前后换一下位置*/
  memcpy(aTmpDisp, &display, 4);
  display = 0x0;
  for (i = 0; i < 4; i++)
  {
      display  = display << 8;
      display |= aTmpDisp[i];
  }

  hiAdpTrace(DEBUG, "display is 0x%x\n", display);
  
  if(HI_UNF_LED_Display(display) != 0)
  {
    hiAdpTrace(ERROR, "The Function process failed !\n");
    return HI_FAILURE;
  }

	return HI_SUCCESS;
}

HI_S32  HIADP_Uio_UnInit(HI_VOID)
{
	if (hisi_ir_run_flag)
  {
    hisi_ir_run_flag = 0;
    pthread_join(hisi_ir_thread_pid, NULL);
  }

  if (hisi_key_run_flag)
  {
    hisi_key_run_flag = 0;
    pthread_join(hisi_key_thread_flag, NULL);
  }
		
  if (HI_UNF_IR_Close() != 0)
  {
    hiAdpTrace(ERROR, "IR Close failed !\n");
		return HI_FAILURE;
  }

  if (HI_UNF_KEY_Close() != 0)
  {
    hiAdpTrace(ERROR, "KEY Close failed !\n");
		return HI_FAILURE;
  }
	
  if (HI_UNF_LED_Close() != 0)
  {
    hiAdpTrace(ERROR, "The Function process failed !\n");
    return HI_FAILURE;
  }
  
  if (HI_UNF_KEYLED_DeInit() != 0)
  {
    hiAdpTrace(ERROR, "The Function process failed !\n");
    return HI_FAILURE;
  }
  
  return HI_SUCCESS;
}

HI_S32 HIADP_Uio_Init(HI_VOID)
{
	//init key
	HI_UNF_KEYLED_Init();
	if (HI_SUCCESS != HI_UNF_KEYLED_SelectType(HIADP_KEYLED_TYPE))
	{
		hiAdpTrace(ERROR, "HI_UNF_KEYLED_SelectType fail\n");
		return HI_FAILURE;
	}

	//LED
	HI_UNF_GPIO_Open();
	if (HI_UNF_LED_Open() != 0)
	{
		hiAdpTrace(ERROR, "HI_UNF_LED_Open fail\n");
		return HI_FAILURE;
	}

	if (HI_UNF_LED_Display(0xffffffff) != 0)
	{
		hiAdpTrace(ERROR, "The Function process failed !\n");
		return HI_FAILURE;
	}

	//IR
	if (HI_UNF_IR_Open() != 0)
	{
		hiAdpTrace(ERROR, "IR Open failed !\n");
		HI_UNF_IR_Close();
		return -1;
	}

	if (HI_UNF_IR_Enable(1) != 0)
	{
		hiAdpTrace(ERROR, "IR Enable failed !\n");
		HI_UNF_IR_Close();
		return HI_FAILURE;
	}

	if (HI_UNF_IR_EnableKeyUp(1) != 0)
	{
		hiAdpTrace(ERROR, "IR EnableKeyUp failed !\n");
		HI_UNF_IR_Close();
		return HI_FAILURE;
	}

	if (HI_UNF_IR_EnableRepKey(1) != 0)
	{
		/* 0 is disable, 1 is enable */
		hiAdpTrace(ERROR, "IR EnableRepKey failed !\n");
		HI_UNF_IR_Close();
		return HI_FAILURE;
	}

	if (HI_UNF_IR_SetRepKeyTimeoutAttr(400) != 0)
	{
		/* 400ms*/
		hiAdpTrace(ERROR, "IR SetRepKeyTimeoutAttr failed !\n");
		HI_UNF_IR_Close();
		return HI_FAILURE;
	}

  if (HI_SUCCESS != HI_UNF_KEY_Open() )
  {
    hiAdpTrace(ERROR, "KEY Open failed !\n");
    HI_UNF_KEY_Close();
		return HI_FAILURE;
  }

  if (HI_UNF_KEY_SetBlockTime(0) != 0)
  {
    hiAdpTrace(ERROR, "KEY SetBlockTime failed !\n");		
    HI_UNF_KEY_Close();
		return HI_FAILURE;
  }

  if (HI_UNF_KEY_IsKeyUp(1) != 0)
  {
    hiAdpTrace(ERROR, "KEY IsKeyUp failed !\n");
    HI_UNF_KEY_Close();
		return HI_FAILURE;
  }

  if (HI_UNF_KEY_IsRepKey(0) != 0)
  {
    hiAdpTrace(ERROR, "KEY IsRepKey failed !\n");
    HI_UNF_KEY_Close();
		return HI_FAILURE;
  }

  if (HI_UNF_KEY_RepKeyTimeoutVal(500) != 0)
  {
    /* 400ms*/
    hiAdpTrace(ERROR, "KEY RepKeyTimeoutVal failed !\n");
    HI_UNF_KEY_Close();
		return HI_FAILURE;
  }

	return HI_SUCCESS;
}


