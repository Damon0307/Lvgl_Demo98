#include "DemoInfoDef.h"

Screen_ID_MAIN = 1;
Screen_ID_CFG = 2;
Screen_ID_RUN = 3;
 
CfgItemData CfgDataList[]={{1,"Wash Time","40"},{2,"Speed","800"},{3,"Wash Temp","60"},{4,"UV","ON"},{5,"Dry Mode","Quick"},{6,"AF","Test"}};


cfg_data_list_len = sizeof(CfgDataList) / sizeof(CfgDataList[0]);