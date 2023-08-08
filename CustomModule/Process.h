#ifndef __PROCESS_H__
#define __PROCESS_H__

#include "lvgl/lvgl.h"


//程序主要有4大部分组成，每个部分可以独立的拥有自己的Sty
typedef struct 
{
    lv_style_t base_sty;
    lv_style_t tte_sty;
    lv_style_t name_sty;
    lv_style_t img_src_sty;
    lv_style_t img_qs_sty;
}ProcessSty;

//自定义消息
typedef struct 
{
    int focus_num;
}ProcessTouchEvent;

  //注册一个事件ID
//uint32_t LV_EVENT_CUSTOM_PROCESS_TOUCHED = lv_event_register_id();
 
typedef struct 
{
    lv_obj_t* base;
    lv_obj_t* tte;
    lv_obj_t* name;
    lv_obj_t* img_src;
    lv_obj_t* img_qs; //快速启动
    
    bool expand_flag;
    int  node_num; //节点号码
    ProcessSty* process_sty;

   //void (*func)(int *,int*); //!这里可以放函数指针也可以像是Processfunc实现， 我的理解是如果放在这里说明是变量，
   //!就是说func 可以是func1 ,也可以是func2 一样进行多态，但是如果在外面使用就是类似c++ 的类的static func
 
}Process;

  
void Process_SetStyle(Process* this,ProcessSty* p_process_sty);

void Process_Init(Process* this,lv_obj_t* parent,int p_tte,char* p_name,void* p_img_src,int node_num);

int Process_GetNodeNum(Process* this);
 
//void Process_Expand(Process* this);
//void Process_Recude(Process* this);

#endif // __PROCESS_H__