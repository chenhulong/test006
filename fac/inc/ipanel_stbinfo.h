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
	IPANEL_STB_CHIPID                     = 0, /*���ӵ�chipid,ֻ��,4�ֽ�,����unsigned int*/   
	IPANEL_STB_SOFTVER                    = 1, /*���ӵ�����汾��,ֻ����6�ֽ��ִ� ,1.2.34�����ٸ�6�ֽ�buf*/
	IPANEL_STB_HARDVER                    = 2, /*���ӵ�Ӳ���汾��,ֻ��,     6�ֽ��ִ� , a.2.f1 ,    ���ٸ�6�ֽ�buf*/  
	IPANEL_STB_LOADVER                    = 3, /*���ӵ�LOAD�汾��,ֻ��,3�ֽڣ��ַ���,����:3.0.2,�����ٸ�8���ֽڵ�buf*/
	IPANEL_STB_SN                         = 4, /*���ӵ�SN,��д,16�ֽ�,�ַ���, ��дʱ��֤���ȴ���0*/
	IPANEL_STB_CAKEY                      = 5, /*���ӵ�CAKEY,��д��11�ֽڣ��ַ�������дʱ��֤���ȴ���0*/ 
	IPANEL_STB_PRIVATE_DATA       		  = 6, /*���ӵ�PRIVATE DATA,��д,16�ֽ�,����buf*/
	IPANEL_STB_PERSONAL_DATA     		  = 7, /*���ӵ�PERSONAL DATA,��д,22�ֽ�,����buf*/
	IPANEL_STB_MAC                        = 8, /*���ӵ�MAC,�ַ���,����: 1078d2c9a1bf(û��ð��),��д���ٸ�12�ֽڵ�buf*/
	IPANEL_STB_FACTORY_STATUS    		  = 9, /*���ӵ�����״̬,��д,3�ֽ�*/
	IPANEL_STB_FACTORY_FLAG         	  = 10,/*���ӵ�������־,��д,1�ֽ�,����0:������;��0:����*/
	IPANEL_STB_CA_FLAG                    = 11,/*���ӵĸ߰�ʹ��,��д,1�ֽ�,����0:������/��ʹ��;��0:����/ʹ��*/
	IPANEL_STB_UNKNOWN
} FACTORY_STB_INFO_e;

/********************************************************************************************************
���ܣ���ȡϵͳ�������Ϣ
ԭ�ͣ�int ipanel_get_stb_info(IPANEL_STB_INFO_e name, unsigned char *buf,int len)
����˵����
���������
name��ϣ����ȡ����Ϣ����,����ο�IPANEL_STB_INFO_e��
buf�����������ȡ��Ϣ��buffer�ĵ�ַ
len�����������ȡ��Ϣ��buffer�ĳ���
name, lenȡֵ��Χ���±�
���������buf 
��    �أ�
> 0:��ȡ��Ϣ��ʵ�ʳ���;
IPANEL_ERR:û�л�ȡ��ָ����Ϣ
********************************************************************************************************/
int ipanel_get_stb_info(FACTORY_STB_INFO_e name, unsigned char *buf, int len);

/********************************************************************************************************
���ܣ�����ϵͳ�������Ϣ
ԭ�ͣ�int ipanel_set_stb_info(IPANEL_STB_INFO_e name, unsigned char *buf,int len)
����˵����
���������
name��ϣ�����õ���Ϣ����,����ο�IPANEL_STB_INFO_e��
buf����������������Ϣ��buffer�ĵ�ַ
len����������������Ϣ��buffer�ĳ���
name, lenȡֵ��Χ���±�
���������
��    �أ�
IPANEL_OK:��ȡ��Ϣ�ɹ�;
IPANEL_ERR:ʧ��
********************************************************************************************************/
int ipanel_set_stb_info(FACTORY_STB_INFO_e name, unsigned char *buf, int len);


#ifdef __cplusplus
}
#endif

#endif//_IPANEL_MIDDLEWARE_STBINFO_API_FUNCTOTYPE_H_