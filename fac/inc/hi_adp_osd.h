/*****************************************************************************
 * Multiple Inclusion Guard
 *****************************************************************************/

#ifndef __HIADP_OSD_H_
#define __HIADP_OSD_H_

#ifdef __cplusplus
extern "C"
{
#endif



typedef struct OSD_Rect
{
 int x1;
 int y1;
 int x2;
 int y2;
}OSD_Rect_t;

typedef enum OSD_Layer
{
	OSD_BAKGRD,                /*!< back ground layer */
	OSD_VIDEO,                 /*!< video layer */
	OSD_STILLP,                /*!< still picture layer */
	OSD_OSD,                   /*!< OSD layer */
	OSD_OSD2,										/*!< second OSD layer */
	OSD_CURSOR                 /*!< cursor layer */
}OSD_Layer_e;

typedef enum OSD_ColorMode
{
  OSD_GALPF_UNKNOWN,     /*!< no specific format,unusual and unsupported */
  OSD_GALPF_ARGB1555,    /*!< 16bit ARGB (2 bytes, alpha 1@15,red 5@10, green 5@5, blue 5@0) */
  OSD_GALPF_ARGB4444,    /*!< 16bit ARGB (2 bytes, alpha 4@12,red 4@8, green 4@4, blue 4@0) */
  OSD_GALPF_RGB16,       /*!< 16bit  RGB (2 bytes, red 5@11,green 6@5, blue 5@0) */
  OSD_GALPF_RGB24,       /*!< 24bit  RGB (3 bytes, red 8@16,green 8@8, blue 8@0) */
  OSD_GALPF_RGB32,       /*!< 24bit  RGB (4 bytes, nothing@24,red 8@16, green 8@8, blue 8@0)*/
  OSD_GALPF_ARGB,        /*!< 32bit ARGB (4 bytes, alpha 8@24,red 8@16, green 8@8, blue 8@0)*/
  OSD_GALPF_A8,          /*!< 8bit alpha (1 byte, alpha 8@0 ),e.g. anti-aliased text glyphs */
  OSD_GALPF_YUY2,        /*!< A macropixel (32bit / 2 pixel) contains YUYV (starting with the LOWEST byte on the LEFT) */
  OSD_GALPF_RGB332,      /*!< 8bit true color (1 byte, red 3@5, green 3@2, blue 2@0 */
  OSD_GALPF_UYVY,        /*!< A macropixel (32bit / 2 pixel) contains UYVY (starting with the LOWEST byte on the LEFT) */
  OSD_GALPF_I420,        /*!< 8 bit Y plane followed by 8 bit 2x2 subsampled U and V planes */
  OSD_GALPF_YV12,        /*!< 8 bit Y plane followed by 8 bit 2x2 subsampled V and U planes */
  OSD_GALPF_YCBCR888_422,/*!< Y, Cb, Cr unsigned components with 8 bit precision in a 4:2:2 sampling model */
  OSD_GALPF_LUT8,        /*!< 8 bit lookup table (palette) */
  OSD_GALPF_ALUT44       /*!< 4 bit alpha + 4 bit lookup table */
}OSD_ColorMode_e;

typedef struct OSD_Parameter
{
  HI_U16 x;           /*!< the x-coordinate of the upper-left corner of the gc */
  HI_U16 y;           /*!< the y-coordinate of the upper-left corner of the gc */
  HI_U16 bpp;         /*!< the count of the bits per pixel */
  HI_U16 width;       /*!< the width of the gc,return fail if width is too larger */
  HI_U16 height;      /*!< the height of the gc,return fail if height is too larger */
	OSD_Layer_e typef; /*!<图层创建时所指定的层*/
}OSD_Parameter_t;

typedef struct OSD_Rectangle
{
  HI_S16      left;       /*!< left */
  HI_S16      top;        /*!< top */
  HI_S16      right;  /*!< right */
  HI_S16      bottom; /*!< bottom */
}OSD_Rectangle_t;

typedef struct OSD_GContext
{
	HI_U32  gcId;           /*!< the handle of gc */
	HI_U8   mixWeight;      /*!< Mix Weight */
	OSD_Parameter_t param;
	OSD_ColorMode_e colorFormat;   /*!< color Format */
	HI_VOID *buffer;            /*!< datas */
}OSD_GContext_t;

void HIADP_OSD_Enable_GC(int bEnable);

HI_S32 HIADP_OSD_Create_GC(OSD_Parameter_t param, OSD_GContext_t **gc);

HI_S32 HIADP_OSD_Destroy_GC(OSD_GContext_t *gc);

HI_S32 HIADP_OSD_Update_GC(HI_VOID);

HI_S32 HIADP_OSD_SetAlpha(HI_U8 mixWeight);

void HIADP_OSD_SetText(char *p_str, unsigned int cl_value, HI_RECT tx_rect,  HIGO_LAYOUT_E Style);

#ifdef __cplusplus
}
#endif


#endif
