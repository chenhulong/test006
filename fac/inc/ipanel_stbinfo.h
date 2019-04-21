/******************************************************************************/
/*    Copyright (c) 2005 iPanel Technologies, Ltd.                     */
/*    All rights reserved. You are not allowed to copy or distribute          */
/*    the code without permission.                                            */
/*    This is the demo implenment of the stbifno APIs needed by other        */
/*    application.                                                             */
/*    Maybe you should modify it accorrding to Platform.                      */
/*                                                                            */
/*    $author duxy 2013/12/27                                           */
/******************************************************************************/

#ifndef _IPANEL_MIDDLEWARE_STBINFO_API_FUNCTOTYPE_H_
#define _IPANEL_MIDDLEWARE_STBINFO_API_FUNCTOTYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

/* general return values */
#define IPANEL_OK	0
#define IPANEL_ERR	(-1)

typedef enum
{
	IPANEL_STB_CHIPID                     = 0, /*盒子的chipid,只读,4字节,类型unsigned int*/   
	IPANEL_STB_SOFTVER                    = 1, /*盒子的软件版本号,只读，6字节字串 ,1.2.34，至少给6字节buf*/
	IPANEL_STB_HARDVER                    = 2, /*盒子的硬件版本号,只读,     6字节字串 , a.2.f1 ,    至少给6字节buf*/  
	IPANEL_STB_LOADVER                    = 3, /*盒子的LOAD版本号,只读,3字节，字符串,样例:3.0.2,请至少给8个字节的buf*/
	IPANEL_STB_SN                         = 4, /*盒子的SN,读写,16字节,字符串, 读写时保证长度大于0*/
	IPANEL_STB_CAKEY                      = 5, /*盒子的CAKEY,读写，11字节，字符串，读写时保证长度大于0*/ 
	IPANEL_STB_PRIVATE_DATA       		  = 6, /*盒子的PRIVATE DATA,读写,16字节,类型buf*/
	IPANEL_STB_PERSONAL_DATA     		  = 7, /*盒子的PERSONAL DATA,读写,22字节,类型buf*/
	IPANEL_STB_MAC                        = 8, /*盒子的MAC,字符串,样例: 1078d2c9a1bf(没有冒号),请写至少给12字节的buf*/
	IPANEL_STB_FACTORY_STATUS    		  = 9, /*盒子的生产状态,读写,3字节*/
	IPANEL_STB_FACTORY_FLAG         	  = 10,/*盒子的生产标志,读写,1字节,含义0:不启动;非0:启动*/
	IPANEL_STB_CA_FLAG                    = 11,/*盒子的高安使能,读写,1字节,含义0:不启动/非使能;非0:启动/使能*/
	IPANEL_STB_UNKNOWN
} FACTORY_STB_INFO_e;

/********************************************************************************************************
功能：获取系统的相关信息
原型：int ipanel_get_stb_info(IPANEL_STB_INFO_e name, unsigned char *buf,int len)
参数说明：
输入参数：
name：希望获取的信息类型,具体参考IPANEL_STB_INFO_e；
buf：用来保存获取信息的buffer的地址
len：用来保存获取信息的buffer的长度
name, len取值范围见下表
输出参数：buf 
返    回：
> 0:获取信息的实际长度;
IPANEL_ERR:没有获取到指定信息
********************************************************************************************************/
int ipanel_get_stb_info(FACTORY_STB_INFO_e name, unsigned char *buf, int len);

/********************************************************************************************************
功能：设置系统的相关信息
原型：int ipanel_set_stb_info(IPANEL_STB_INFO_e name, unsigned char *buf,int len)
参数说明：
输入参数：
name：希望设置的信息类型,具体参考IPANEL_STB_INFO_e；
buf：用来保存设置信息的buffer的地址
len：用来保存设置信息的buffer的长度
name, len取值范围见下表
输出参数：
返    回：
IPANEL_OK:获取信息成功;
IPANEL_ERR:失败
********************************************************************************************************/
int ipanel_set_stb_info(FACTORY_STB_INFO_e name, unsigned char *buf, int len);


#ifdef __cplusplus
}
#endif

#endif//_IPANEL_MIDDLEWARE_STBINFO_API_FUNCTOTYPE_H_