/*****************************************************************************
 * Multiple Inclusion Guard
 *****************************************************************************/

#ifndef _MUI_DVN_H_
#define _MUI_DVN_H_

#ifdef __cplusplus
extern "C"
{
#endif

		/*通用遥控器*/

		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of power key of remote controller
		 */
#define MUI_REMOTE_POWER				(0xff000001)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of mute key of remote controller
		 */
#define MUI_REMOTE_MUTE				 	(MUI_REMOTE_POWER + 1)//(0xff000002)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 1 key of remote controller
		 */
#define MUI_REMOTE_1					(MUI_REMOTE_MUTE + 1)//(0xff000003)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 2 key of remote controller
		 */
#define MUI_REMOTE_2					(MUI_REMOTE_1 + 1)//(0xff000004)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 3 key of remote controller
		 */
#define MUI_REMOTE_3					(MUI_REMOTE_2 + 1)//(0xff000005)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 4 key of remote controller
		 */
#define MUI_REMOTE_4					(MUI_REMOTE_3 + 1)//(0xff000006)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 5 key of remote controller
		 */
#define MUI_REMOTE_5					(MUI_REMOTE_4 + 1)//(0xff000007)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 6 key of remote controller
		 */
#define MUI_REMOTE_6					(MUI_REMOTE_5 + 1)//(0xff000008)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 7 key of remote controller
		 */
#define MUI_REMOTE_7					(MUI_REMOTE_6 + 1)//(0xff000009)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 8 key of remote controller
		 */
#define MUI_REMOTE_8					(MUI_REMOTE_7 + 1)//(0xff00000a)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 9 key of remote controller
		 */
#define MUI_REMOTE_9					(MUI_REMOTE_8 + 1)//(0xff00000b)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of 0 key of remote controller
		 */
#define MUI_REMOTE_0					(MUI_REMOTE_9 + 1)//(0xff00000c)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of menu key of remote controller
		 */
#define MUI_REMOTE_MENU				    (MUI_REMOTE_0 + 1)//(0xff00000d)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of quit key of remote controller
		 */
#define MUI_REMOTE_QUIT					(MUI_REMOTE_MENU + 1)//(0xff00000e)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of back key of remote controller
		 */
#define MUI_REMOTE_BACK					(MUI_REMOTE_QUIT + 1)//(0xff00000f)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of favorite key of remote controller
		 */
#define MUI_REMOTE_FAVORITE				(MUI_REMOTE_BACK + 1)//(0xff000010)	
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of ok key of remote controller
		 */
#define MUI_REMOTE_OK				    (MUI_REMOTE_FAVORITE + 1)//(0xff000011)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of left key of remote controller
		 */
#define MUI_REMOTE_LEFT				    (MUI_REMOTE_OK + 1)//(0xff000012)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of up key of remote controller
		 */
#define MUI_REMOTE_UP				    (MUI_REMOTE_LEFT + 1)//(0xff000013)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of down key of remote controller
		 */
#define MUI_REMOTE_DOWN				    (MUI_REMOTE_UP + 1)//(0xff000014)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of right key of remote controller
		 */
#define MUI_REMOTE_RIGHT				(MUI_REMOTE_DOWN + 1)//(0xff000015)
		   /*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the play function of remote controller
		 */
#define MUI_REMOTE_PLAY					(MUI_REMOTE_RIGHT + 1)//(0xff000016)
		   /*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the stop function of remote controller
		 */
#define MUI_REMOTE_STOP					(MUI_REMOTE_PLAY + 1)//(0xff000017)		
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of guide key of remote controller
		 */
#define MUI_REMOTE_GUIDE	            (MUI_REMOTE_STOP + 1)//(0xff000018)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of pageup key of remote controller
		 */
#define MUI_REMOTE_PAGEUP				(MUI_REMOTE_GUIDE + 1)//(0xff000019)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of pagedown key of remote controller
		 */
#define MUI_REMOTE_PAGEDOWN				(MUI_REMOTE_PAGEUP + 1)//(0xff00001a)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of volume_up key of remote controller
		 */
#define MUI_REMOTE_VOLUME_UP			(MUI_REMOTE_PAGEDOWN + 1)//(0xff00001b)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of volume_down key of remote controller
		 */
#define MUI_REMOTE_VOLUME_DOWN			(MUI_REMOTE_VOLUME_UP + 1)//(0xff00001c)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of channel_up key of remote controller
		 */
#define MUI_REMOTE_CHANNEL_UP			(MUI_REMOTE_VOLUME_DOWN + 1)//(0xff00001d)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of channel_down key of remote controller
		 */
#define MUI_REMOTE_CHANNEL_DOWN			(MUI_REMOTE_CHANNEL_UP + 1)//(0xff00001e)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of TV key of remote controller
		 */
#define MUI_REMOTE_TV					(MUI_REMOTE_CHANNEL_DOWN + 1)//(0xff00001f)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of RADIO key of remote controller,音频广播
		 */
#define MUI_REMOTE_RADIO				(MUI_REMOTE_TV + 1)//(0xff000020)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of VOD key of remote controller
		 */
#define	MUI_REMOTE_VOD					(MUI_REMOTE_RADIO + 1)//(0xff000021)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of information key of remote controller
		 */
#define MUI_REMOTE_INFORMATION			(MUI_REMOTE_VOD + 1)//(0xff000022)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of TIP key of remote controller,屏幕显示
		 */
#define	MUI_REMOTE_TIP					(MUI_REMOTE_INFORMATION + 1)//(0xff000023)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of Tab key of remote controller
		 */
#define MUI_REMOTE_TAB				    (MUI_REMOTE_TIP + 1)//(0xff000024)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of red button key of remote controller
		 */
#define MUI_REMOTE_RED			 		(MUI_REMOTE_TAB + 1)//(0xff000025)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of blue button key of remote controller
		 */
#define MUI_REMOTE_BLUE		 			(MUI_REMOTE_RED + 1)//(0xff000026)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of green button key of remote controller
		 */
#define MUI_REMOTE_GREEN		 		(MUI_REMOTE_BLUE + 1)//(0xff000027)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of yellow key of remote controller
		 */
#define MUI_REMOTE_YELLOW		 		(MUI_REMOTE_GREEN + 1)//(0xff000028)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of RECALL key of remote controller
		 */
#define MUI_REMOTE_RECALL				(MUI_REMOTE_YELLOW + 1)//(0xff000029)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of DASSD key of remote controller,精灵显示
		 */
#define MUI_REMOTE_DASSD				(MUI_REMOTE_RECALL + 1)//(0xff00002a)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of DASSV key of remote controller,精灵收藏
		 */
#define MUI_REMOTE_DASSV				(MUI_REMOTE_DASSD + 1)//(0xff00002b)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of DASSN key of remote controller,保留
		 */
#define MUI_REMOTE_DASSN				(MUI_REMOTE_DASSV + 1)//(0xff00002c)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of FORWARD key of remote controller
		 */
#define MUI_REMOTE_FORWARD				(MUI_REMOTE_DASSN + 1)//(0xff00002d)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of BACKWARD key of remote controller
		 */
#define MUI_REMOTE_BACKWARD				(MUI_REMOTE_FORWARD + 1)//(0xff00002e)
		/*!
		 *	\ingroup	DVN_M_UI
		 *	\brief	the constant of TRACK key of remote controller,声道
		 */
#define MUI_REMOTE_TRACK				(MUI_REMOTE_BACKWARD + 1)//(0xff00002f)

#define MUI_REMOTE_PREVIEW 0x48

#define MUI_REMOTE_LANGUAGE				(MUI_REMOTE_TRACK + 1)
#define MUI_REMOTE_SWITCH				  (MUI_REMOTE_TRACK + 2)
#define MUI_REMOTE_AUDIO				  (MUI_REMOTE_TRACK + 3)
#define MUI_REMOTE_MESSAGE				(MUI_REMOTE_TRACK + 4)
#define MUI_REMOTE_F1				      (MUI_REMOTE_TRACK + 5)
#define MUI_REMOTE_F2				      (MUI_REMOTE_TRACK + 6)
#define MUI_REMOTE_F3				      (MUI_REMOTE_TRACK + 7)
#define MUI_REMOTE_F4				      (MUI_REMOTE_TRACK + 8)
#define MUI_REMOTE_BROADCAST		  (MUI_REMOTE_TRACK + 9)
#define MUI_REMOTE_STOCK				  (MUI_REMOTE_TRACK + 10)
#define MUI_REMOTE_DISPLAY				(MUI_REMOTE_TRACK + 11)

typedef enum UIO_KeySrc
{
	UIO_FRONT_PANEL,
	UIO_REMOTE,
	UIO_KEYBORAD,
	UIO_MOUSE,
	UIO_JOYSTICK,
	UIO_SERIAL,
	UIO_NUMOFSOURCE
}UIO_KeySrc_e;


typedef struct UIO_RKey
{
	UIO_KeySrc_e keySrc;  /*!<the source of user input ,the highest bit show the status is keydown or keyup.*/
	HI_U32 keyData;       /*!<keycode of key being pressed or the Y axis component of mouse movement */
}UIO_RKey_t ;

typedef HI_VOID(*Uio_CallbackProc_f)(UIO_RKey_t *key);

HI_VOID HIADP_Uio_Register_Callback(Uio_CallbackProc_f callback);

HI_S32 HIADP_Uio_Display(HI_CHAR *str);

HI_S32  HIADP_Uio_UnInit(HI_VOID);

HI_S32 HIADP_Uio_Init(HI_VOID);




#ifdef __cplusplus
}

#endif


#endif   /* _MUI_DVN_H_ */

