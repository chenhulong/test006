/***********************************************************************************
*              Copyright 2008 - 2050, Hisilicon Tech. Co., Ltd.
*                           ALL RIGHTS RESERVED
* FileName: hi_adp_debug.h
* Description: Hi3110EV100 adapter layer (Yinhe) debug config file.
*
* History:
* Version      Date                Author    DefectNum    Description
* V1.00    May 19th,09    y45343      NA              1 st release
***********************************************************************************/

#ifndef __HI_ADP_DEBUG_H__
#define __HI_ADP_DEBUG_H__

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#include <stdio.h>

typedef enum hiADP_ERRLEVEL_E
{
    DEBUG = 1,  /* debug-level                       */
    WARNING,    /* warning information            */
    ERROR,      /* error conditions                  */
    INFO        /* always print */
} HIADP_ERRLEVEL_E;

#define HIADP_DEBUG
#define HIADP_TRACE_LEVEL ERROR

#define HIADP_DEBUG
#ifdef HIADP_DEBUG
 #define hiAdpTrace( level, fmt, args... ) \
    do { \
        if (level >= HIADP_TRACE_LEVEL)\
        {\
            printf("%s():%04d:  ", __FUNCTION__, __LINE__); \
            switch (level) \
            {\
            case ERROR: \
                printf("error: "); \
                break; \
            case WARNING: \
                printf("warning: "); \
                break; \
            default: \
                break; \
                } \
                printf( fmt, ## args ); \
                } \
                } while (0)
#else
 #define hiAdpTrace( level, fmt, args... )
#endif

#define HIADP_USE_ASSERT
#ifdef HIADP_USE_ASSERT
 #define hiAdpAssert(expr) do {      \
        if (!(expr)) { \
            printf( "Assertion [%s] failed! %s:%s(line=%d)\n", \
                    # expr, __FILE__, __FUNCTION__, __LINE__); \
            _exit(0);     \
        } } while (0)

#else
 #define hiAdpAssert(expr)
#endif

#define hiAdpEnter() \
    do \
    {\
        hiAdpTrace(DEBUG, "enter >> \n"); \
    } while (0)

#define hiAdpLeave() \
    do \
    {\
        hiAdpTrace(DEBUG, "leave << .. \n"); \
    } while (0)


#define HIAPI_RUN(api, ret) \
				do {\
						HI_S32 errCode; \
						errCode = api; \
						if (errCode != 0)\
						{\
								ret |= errCode; \
								printf("\033[0;31m" "[Function: %s line: %d] %s failed ret = 0x%x \n" "\033[0m", __FUNCTION__, __LINE__ , # api, errCode); \
						} \
				} while (0)
		
#define HIAPI_RUN_RETURN(api) \
				do {\
						HI_S32 errCode; \
						errCode = api; \
						if (errCode != 0)\
						{\
								printf("\033[0;31m" "[Function: %s line: %d] %s failed ret = 0x%x \n" "\033[0m",	__FUNCTION__, __LINE__ , #api, errCode); \
								return HI_FAILURE; \
						} \
				} while (0)
		
		
#define HIAPI_ERR_PRINTF(ret) \
			do {\
					printf("\033[0;31m" " [Function: %s line: %d]  ret = 0x%x \n" "\033[0m", __FUNCTION__, __LINE__ , ret); \
			}while(0)\
		
		
								
#define SAMPLE_RUN(api, ret) \
				do{ \
						HI_S32 l_ret = api; \
						if (l_ret != HI_SUCCESS) \
						{ \
							printf("run %s failed, ERRNO:%#x.\n", #api, l_ret); \
						} \
						else\
						{\
						/*printf("sample %s: run %s ok.\n", __FUNCTION__, #api);}*/ 	\
						}\
						ret = l_ret;\
				}while(0)
		
		
#define SAMPLE_CheckNullPTR(pointer)                    \
				do																									\
				{ 																									\
						if (NULL == pointer)														\
						{ 																							\
							printf("%s failed:NULL Pointer in Line:%d!\n", __FUNCTION__, __LINE__);\
							return HI_FAILURE; \
						} 										 \
				}while(0) 	 
				


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* __HI_ADP_DEBUG_H__ */
