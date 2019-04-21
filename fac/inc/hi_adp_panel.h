#ifndef __HIADP_PANEL_H_
#define __HIADP_PANEL_H_

#ifdef __cplusplus
extern "C"
{
#endif


HI_S32 HIADP_Panel_Init(HI_VOID);

HI_S32  HIADP_Panel_UnInit(HI_VOID);

HI_S32 HIADP_Panel_Display(HI_U8 *str);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif     /* __HIADP_PANEL_H_ */
