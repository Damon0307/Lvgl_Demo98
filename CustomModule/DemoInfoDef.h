#ifndef __DEMOINFODEF_H__
#define __DEMOINFODEF_H__

 
//todo C语言的extern 好可恶阿我原来一直理解的是错误的
//! https://www.cnblogs.com/yyxt/p/3891712.html   
//全局变量信息的传递
#include <stdio.h>
#include "../lvgl/lvgl.h"

#define SCREEN_ID_MAIN       1
#define SCREEN_ID_CFG        2
#define SCREEN_ID_RUN        3


#if 0  //下面的写法属于既是声明也是定义 但是在这里我们只能声明，不然头文件就不能被重复包含
//屏幕ID 枚举？
uint8_t Screen_ID_MAIN = 1;
uint8_t Screen_ID_CFG =  2;
uint8_t Screen_ID_RUN =  3;
 
CfgItemData CfgDataList[6]={
    {"Wash Time",1,"40"},
     {"Speed",2,"800"},
      {"Wash Temp",3,"60℃"},
      {"UV",4,"ON"},
      {"Dry Mode",5,"Quick"},
      {"AF",6,"Test"},
 };
#endif

//请求改变屏幕的消息，包含当前在那个界面，希望到哪个界面
typedef struct 
{
  int cur_scr_id;
  int go_scr_id;
}EventScreenChangeReq;



extern int Screen_ID_MAIN;
extern int Screen_ID_CFG;
extern int Screen_ID_RUN;
// //自定义事件
// extern uint32_t Event_Go_CFG ;
// extern uint32_t Event_Go_RUN ;
// extern uint32_t Event_Go_MAIN ;

 typedef struct 
 {
   int id;
   char* name;
   char* cur_value;
 }CfgItemData;
 
//!  extern CfgItemData CfgDataList[6];
extern CfgItemData CfgDataList[];
extern int cfg_data_list_len;

 #endif // __DEMOINFODEF_H__
  