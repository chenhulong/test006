#ifndef __HI_ADP_ETH_H_
#define __HI_ADP_ETH_H_

/* eth */
typedef enum hiEth_LinkStatus_E
{
    ETH_LINK_STATUS_OFF = 0,
    ETH_LINK_STATUS_ON,
    ETH_LINK_STATUS_MAX
} Eth_LinkStatus_E, *PTR_Eth_LinkStatus_E;


typedef enum hiEth_Port_E
{
    ETH_PORT_UP = 0,
    ETH_PORT_DOWN,
    ETH_PORT_MAX
} Eth_Port_E;

HI_S32 HI_ETH_GetLinkStatus(Eth_Port_E ePort, PTR_Eth_LinkStatus_E ptrLinkStatus);

HI_S32 HI_ETH_Open(Eth_Port_E ePort);

HI_S32 HI_ETH_IPAddressGet (Eth_Port_E ePort, HI_CHAR *ipAdd);

HI_S32 HI_ETH_IPAddressSet (Eth_Port_E ePort, HI_CHAR* ipAdd);

HI_S32 HI_ETH_SubNetmaskGet (Eth_Port_E ePort, HI_CHAR* subNetmask);

HI_S32 HI_ETH_SubNetmaskSet (Eth_Port_E ePort, HI_CHAR* subNetmask);

HI_S32 HI_ETH_GatewayGet (Eth_Port_E ePort, HI_CHAR* gateway);

HI_S32 HI_ETH_GatewaySet (Eth_Port_E ePort, HI_CHAR* gateway);

HI_S32 HI_ETH_GetMac(Eth_Port_E ePort, HI_CHAR *mac);

HI_S32 HI_ETH_SetMac(Eth_Port_E ePort, HI_CHAR *mac);


#endif // End for __HI_ADP_ETH_H_
