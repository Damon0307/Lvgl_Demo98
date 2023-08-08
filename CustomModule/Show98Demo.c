#include "../lvgl/lvgl.h"
#include <stdio.h>
#include <stdlib.h>
#include "Show98Demo.h"
#include "DemoInfoDef.h"
#include "ProcessList.h"
#include "CfgScreen.h"
#include "RunningScr.h"

typedef struct
{
    void (*ConstructScr)(lv_obj_t *);
    void (*DeconstructScr)();
} CSCR;

typedef struct
{
    CSCR *screen_main;
    CSCR *screen_cfg;
    CSCR *screen_run;
} ScreenList;

static ScreenList s_sl;

static CSCR scr_main;
static CSCR scr_cfg;
static CSCR scr_run;

//! 引用外部定义的一些全局信息 extern 只有在不包含 *——pub.h 时候才需要写，既然你已经包含了，就不用写了
// extern int Screen_ID_MAIN;
// extern int Screen_ID_CFG;
// extern int Screen_ID_RUN;

// 声明这个变量，给外部文件引用
uint32_t EVENT_CHANGE_SCREEN;

EventScreenChangeReq event_screen_change_req;

// 从子界面得到信号
static void GetEventFromSubScreen(lv_event_t *event);

static void InitMainScreen();
static void InitCfgScreen();
static void InitRunningScreen();



// 全局唯一的屏幕 如果使用会导致 使用 lv_scr_load 的时候只有一个scr, 
lv_obj_t *g_scr = NULL;

void Show98DEMO()
{

    EVENT_CHANGE_SCREEN = lv_event_register_id();

    printf("FUCK IN Show98DEMO %d\n", EVENT_CHANGE_SCREEN);

   g_scr = lv_scr_act();
   lv_obj_set_size(g_scr, 780, 220);
   lv_obj_set_style_bg_color(g_scr,lv_color_hex(0x000000),0);

    InitMainScreen();
    InitCfgScreen();
    InitRunningScreen();

    s_sl.screen_main->ConstructScr(g_scr);
  // s_sl.screen_cfg->ConstructScr(g_scr);
   //  s_sl.screen_run->ConstructScr(g_scr);


   lv_obj_add_event_cb(g_scr,GetEventFromSubScreen,EVENT_CHANGE_SCREEN,NULL);

//!param user_data 吐了
//! 吐了 lv_obj_add_event_cb(g_scr,GetEventFromSubScreen,EVENT_CHANGE_SCREEN,(void*)ppt);

}

static void InitMainScreen()
{
    s_sl.screen_main = &scr_main;
    s_sl.screen_main->ConstructScr = PLInit;
    s_sl.screen_main->DeconstructScr = PLDelete;
}

static void InitCfgScreen()
{
    s_sl.screen_cfg = &scr_cfg;
    s_sl.screen_cfg->ConstructScr = CfgInit;
    s_sl.screen_cfg->DeconstructScr = CfgDelete;
}

static void InitRunningScreen()
{
    s_sl.screen_run = &scr_run;
    s_sl.screen_run->ConstructScr = RunningInit;
    s_sl.screen_run->DeconstructScr = RunningDelete;
}

static void GetEventFromSubScreen(lv_event_t *event)
{
    // 先释放

    printf("****************************************\n");
    if(event->user_data ==NULL)
    {
        printf("NULL event->user_data \n");
    }

 //! EventScreenChangeReq *p_req = (EventScreenChangeReq*)(event->user_data);

     EventScreenChangeReq *p_req = (EventScreenChangeReq*)(event->param);
   
     printf("Router Got Event %d  from screen id %d want to go scr_id %d\n", 
     event->code,(*p_req).cur_scr_id,(*p_req).go_scr_id);

    if (p_req->cur_scr_id == SCREEN_ID_MAIN)
    {
        s_sl.screen_main->DeconstructScr();
    }
    else if (p_req->cur_scr_id == SCREEN_ID_CFG)
    {
        s_sl.screen_cfg->DeconstructScr();
    }
    else if (p_req->cur_scr_id == SCREEN_ID_RUN)
    {
        s_sl.screen_run->DeconstructScr();
    }
    // 加载屏幕
 
    switch (p_req->go_scr_id)
    {
    case SCREEN_ID_MAIN:
    {
        s_sl.screen_main->ConstructScr(g_scr);
    }
    break;
    case SCREEN_ID_CFG:
    {
        s_sl.screen_cfg->ConstructScr(g_scr);
    }
    break;
    case SCREEN_ID_RUN:
    {
        s_sl.screen_run->ConstructScr(g_scr);
    }
    break;
    default:
    printf("unexpect branch\n");
        break;
    }
 
}
