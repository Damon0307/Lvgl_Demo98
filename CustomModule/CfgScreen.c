#include <stdio.h>
#include <stdlib.h>
#include "../lvgl/lvgl.h"
#include "Util.h"

#include "DemoInfoDef.h"

// 下面变量定义在Showdemo.c 中，但是我没有包含他所以需要这样使用
extern uint32_t EVENT_CHANGE_SCREEN;

static EventScreenChangeReq CFG_EScrChangeReq;

extern lv_obj_t *g_scr;

#define CFG_SCR_NORMAL_SECLTOR 1

LV_IMG_DECLARE(wjc_left)
LV_IMG_DECLARE(wjc_right)
LV_IMG_DECLARE(ProcessStart)

typedef struct
{
    lv_obj_t *base;
    lv_obj_t *cfg_name;
    lv_obj_t *cfg_cur;
    int cfg_id;
} CfgItem;

typedef struct
{
    lv_obj_t *base;
    CfgItem *cfg_arr;
} CfgList;

typedef struct
{
    lv_obj_t *base;
    lv_obj_t *l_ctl;
    lv_obj_t *r_ctl;
    CfgList *cfg_list;
} CfgModule;

typedef struct
{
    lv_obj_t *base; // 程序控制
    lv_obj_t *process_start_img;
    lv_obj_t *process_start_ring;
    int ctrl_state;
} CfgCtrlMod;

typedef struct
{
    lv_obj_t *base;
    lv_obj_t *back;               // 返回程序
    lv_obj_t *process_name;       // 程序名称
    lv_obj_t *process_tte;        // 程序剩余时间
    CfgCtrlMod *process_ctrl_mod; // 程序启停控制模块
    CfgModule *cfg_module;        // 程序配置列表
    lv_obj_t *cfg_selector;
} CfgScreen;
// 配置界面初始化

static CfgScreen cfg_screen;

// 初始化一些样式表
LV_FONT_DECLARE(FontLCD50F)
LV_FONT_DECLARE(MachinePro80F)

static lv_style_t sty_tte;

// 处理模块所有对象的点击事件
static void CfgModuleHandleEvents(lv_event_t *event);

// 初始化配置菜单
static void InitCfgModule(lv_obj_t *parent);

// 显示数据选择器
static void CfgSelectorCB(lv_event_t *e);
static void mask_event_cb(lv_event_t *e);

static void ShowCFGSelector(int x, int min, int max, int cur);

static void InitStyles()
{
    // tte
    lv_style_init(&sty_tte);
    lv_style_set_align(&sty_tte, LV_ALIGN_LEFT_MID);
    lv_style_set_x(&sty_tte, 30);  // 这里的X是基于上面的布局以后进行的
    lv_style_set_y(&sty_tte, -20); // 这里的X是基于上面的布局以后进行的
    lv_style_set_text_font(&sty_tte, &FontLCD50F);
    lv_style_set_text_color(&sty_tte, lv_color_hex(0xffffff));
}

static void CfgTestTouchCB(lv_event_t *event)
{
    printf("Cfg got touched \n");
 
    int i= lv_obj_get_child_cnt(event->current_target);

    printf(" child %d\n",i);

}

static lv_obj_t* m_scr;
 
static lv_obj_t* cfg_acr_scr; 

void CfgInit(lv_obj_t *parent)
{
 
    m_scr = lv_scr_act();
    lv_obj_set_size(m_scr, 780, 220);
    lv_obj_set_style_bg_color(m_scr,lv_color_hex(0x000000),0);

    cfg_screen.base = lv_obj_create(m_scr);
 
    printf("PS w %d, h %d\n", (int)lv_obj_get_width(m_scr), (int)lv_obj_get_height(m_scr));
    lv_obj_set_size(cfg_screen.base, lv_obj_get_width(m_scr), lv_obj_get_height(m_scr));

    lv_obj_set_style_bg_color(cfg_screen.base, lv_color_hex(0x000000), 0);

    cfg_screen.process_name = lv_label_create(cfg_screen.base);
    cfg_screen.process_tte = lv_label_create(cfg_screen.base);
    cfg_screen.cfg_selector = lv_roller_create(cfg_screen.base);

 
#if (CFG_SCR_NORMAL_SECLTOR)

    printf("Going Here\n");

    lv_roller_set_options(cfg_screen.cfg_selector, "January\n"
                                                   "February\n"
                                                   "March\n"
                                                   "April\n"
                                                   "May\n"
                                                   "June\n"
                                                   "July\n"
                                                   "August\n"
                                                   "September\n"
                                                   "October\n"
                                                   "November\n"
                                                   "December",
                          LV_ROLLER_MODE_INFINITE);

    lv_roller_set_visible_row_count(cfg_screen.cfg_selector, 3);
    lv_obj_set_style_text_font(cfg_screen.cfg_selector, &lv_font_montserrat_14, LV_PART_SELECTED);
    lv_obj_set_style_border_color(cfg_screen.cfg_selector, lv_color_hex(0x000000), LV_PART_MAIN);

    lv_obj_set_style_border_color(cfg_screen.cfg_selector, lv_color_hex(0xFFFFFF), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(cfg_screen.cfg_selector, lv_color_hex(0x4F4F4F), LV_PART_SELECTED);
    // lv_obj_set_style_border_width(cfg_screen.cfg_selector,1,LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(cfg_screen.cfg_selector, lv_color_hex(0x4F4F4F), LV_PART_MAIN);
    lv_obj_set_style_border_width(cfg_screen.cfg_selector, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cfg_screen.cfg_selector, LV_OPA_40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(cfg_screen.cfg_selector, lv_color_hex(0xFF7F24), LV_PART_MAIN);
    lv_obj_set_style_shadow_width(cfg_screen.cfg_selector, 8, LV_PART_MAIN);
    lv_obj_set_style_shadow_spread(cfg_screen.cfg_selector, 4, LV_PART_MAIN);
    lv_obj_set_size(cfg_screen.cfg_selector, 85, 120);  
    lv_obj_add_flag(cfg_screen.cfg_selector,LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_event_cb(cfg_screen.cfg_selector,CfgSelectorCB,LV_EVENT_DEFOCUSED,NULL);
    lv_obj_add_event_cb(cfg_screen.cfg_selector,CfgSelectorCB,LV_EVENT_CLICKED,NULL);
#else

    lv_obj_set_size(cfg_screen.cfg_selector, 85, lv_obj_get_height(cfg_screen.base));

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_black());
    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_border_width(&style, 0);
    lv_style_set_pad_all(&style, 0);
    lv_obj_add_style(lv_scr_act(), &style, 0);

    lv_obj_add_style(cfg_screen.cfg_selector, &style, 0);
    lv_obj_set_style_bg_opa(cfg_screen.cfg_selector, LV_OPA_TRANSP, LV_PART_SELECTED);
    lv_obj_set_style_text_font(cfg_screen.cfg_selector, &lv_font_montserrat_14, LV_PART_SELECTED);

    lv_roller_set_options(cfg_screen.cfg_selector,
                          "January\n"
                          "February\n"
                          "March\n"
                          "April\n"
                          "May\n"
                          "June\n"
                          "July\n"
                          "August\n"
                          "September\n"
                          "October\n"
                          "November\n"
                          "December",
                          LV_ROLLER_MODE_INFINITE);

    lv_roller_set_visible_row_count(cfg_screen.cfg_selector, 3);
    // selector sty

    lv_obj_add_event_cb(cfg_screen.cfg_selector, mask_event_cb, LV_EVENT_ALL, NULL);
#endif

    // ctrl mod
    cfg_screen.process_ctrl_mod = (CfgCtrlMod *)malloc(sizeof(CfgCtrlMod));

    cfg_screen.process_ctrl_mod->base = lv_obj_create(cfg_screen.base);
    cfg_screen.process_ctrl_mod->process_start_img = lv_img_create(cfg_screen.process_ctrl_mod->base);
    lv_obj_clear_flag(cfg_screen.process_ctrl_mod->base, LV_OBJ_FLAG_SCROLLABLE);
    lv_img_set_src(cfg_screen.process_ctrl_mod->process_start_img, &ProcessStart);
    lv_obj_set_size(cfg_screen.process_ctrl_mod->base, 105, 105);
    lv_obj_set_align(cfg_screen.process_ctrl_mod->base, LV_ALIGN_RIGHT_MID);
    lv_obj_set_x(cfg_screen.process_ctrl_mod->base, -10);
    lv_obj_set_size(cfg_screen.process_ctrl_mod->process_start_img, 64, 64);
    lv_obj_set_style_bg_color(cfg_screen.process_ctrl_mod->base, lv_color_hex(0x000000), 0);
    lv_obj_set_style_border_color(cfg_screen.process_ctrl_mod->base, lv_color_hex(0x000000), 0);

    lv_obj_center(cfg_screen.process_ctrl_mod->process_start_img);
    lv_obj_set_x(cfg_screen.process_ctrl_mod->process_start_img, 5);

    cfg_screen.process_ctrl_mod->process_start_ring = lv_arc_create(cfg_screen.process_ctrl_mod->base);
    lv_obj_set_size(cfg_screen.process_ctrl_mod->process_start_ring, 90, 90);
    lv_obj_center(cfg_screen.process_ctrl_mod->process_start_ring);
    lv_arc_set_bg_end_angle(cfg_screen.process_ctrl_mod->process_start_ring, 360);
    lv_arc_set_bg_angles(cfg_screen.process_ctrl_mod->process_start_ring, 0, 360); // 设置圆环的开始角度和结束角度
    lv_arc_set_rotation(cfg_screen.process_ctrl_mod->process_start_ring, 0);       // 设置圆环的旋转角度
    lv_arc_set_value(cfg_screen.process_ctrl_mod->process_start_ring, 0);
    lv_obj_set_style_bg_color(cfg_screen.process_ctrl_mod->process_start_ring, lv_color_hex(0xffffff), 0);

    lv_obj_set_style_arc_width(cfg_screen.process_ctrl_mod->process_start_ring, 4, LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(cfg_screen.process_ctrl_mod->process_start_ring, 2, LV_PART_MAIN);
    lv_obj_set_style_arc_color(cfg_screen.process_ctrl_mod->process_start_ring, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(cfg_screen.process_ctrl_mod->process_start_ring, lv_color_hex(0xFF7F24), LV_PART_INDICATOR);
    lv_obj_remove_style(cfg_screen.process_ctrl_mod->process_start_ring, NULL, LV_PART_KNOB);

    lv_label_set_text(cfg_screen.process_tte, "666");
    lv_label_set_text(cfg_screen.process_name, "Cotton");
    lv_obj_set_style_text_color(cfg_screen.process_name, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(cfg_screen.process_name, &MachinePro80F, 0);

    InitStyles();
    lv_obj_add_style(cfg_screen.process_tte, &sty_tte, LV_STATE_DEFAULT);
    lv_obj_align_to(cfg_screen.process_name, cfg_screen.process_tte, LV_ALIGN_BOTTOM_MID, 0, 50);

    // 程序配置列表初始化
    InitCfgModule(cfg_screen.base);

    // 谁最后被Creare 谁就在最上层，也就容易接收信号
    lv_obj_add_event_cb(cfg_screen.process_ctrl_mod->process_start_ring, CfgModuleHandleEvents, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(cfg_screen.process_ctrl_mod->process_start_ring, CfgModuleHandleEvents, LV_EVENT_RELEASED, NULL);

    //  lv_obj_add_event_cb(cfg_screen.process_ctrl_mod->process_start_ring,CfgModuleHandleEvents,LV_EVENT_PRESSING,NULL);

//!这里要load的是屏幕，也就是传过来的g_scr 否则虽然能显示但是触摸会有问题
   //  lv_scr_load_anim(cfg_screen.base, LV_SCR_LOAD_ANIM_OVER_BOTTOM,1000,0,0);
 
  //  lv_scr_load_anim(parent, LV_SCR_LOAD_ANIM_OVER_BOTTOM,700,0,0);
  
     lv_scr_load_anim(m_scr, LV_SCR_LOAD_ANIM_OVER_BOTTOM,700,0,0);
  
    //! lv_obj_del 只是删除一个  lv_obj_clean() 是全部
    CFG_EScrChangeReq.cur_scr_id = Screen_ID_CFG;

      

}
// 释放一些资源
void CfgDelete()
{
    lv_obj_clean(m_scr);
    printf("Cfg scrren delete...\n");
}
// 初始化配置菜单
static void InitCfgModule(lv_obj_t *parent)
{
    const int base_w = 360;
    const int base_h = 140;
    //! 这里还需要为子结构体申请内存
    cfg_screen.cfg_module = (CfgModule *)malloc(sizeof(CfgModule));
    cfg_screen.cfg_module->base = lv_obj_create(parent);
    cfg_screen.cfg_module->l_ctl = lv_obj_create(cfg_screen.cfg_module->base);
    cfg_screen.cfg_module->r_ctl = lv_obj_create(cfg_screen.cfg_module->base);

    // BASE STY
    lv_obj_set_style_size(cfg_screen.cfg_module->base, base_w, base_h, 0);
    lv_obj_set_style_align(cfg_screen.cfg_module->base, LV_ALIGN_CENTER, 0);
    lv_obj_set_style_x(cfg_screen.cfg_module->base, 25, 0);
    lv_obj_set_style_y(cfg_screen.cfg_module->base, 0, 0);
    lv_obj_set_style_bg_color(cfg_screen.cfg_module->base, lv_color_hex(0x000000), 0);
    lv_obj_set_style_border_width(cfg_screen.cfg_module->base, 0, 0);
    lv_obj_set_style_pad_all(cfg_screen.cfg_module->base, 0, 0);

    // LEFT STY

    lv_obj_set_style_align(cfg_screen.cfg_module->l_ctl, LV_ALIGN_LEFT_MID, 0);
    lv_obj_set_style_size(cfg_screen.cfg_module->l_ctl, base_w / 9, base_h - 40, 0);
    lv_obj_set_style_border_width(cfg_screen.cfg_module->l_ctl, 1, 0);
    lv_obj_set_style_bg_color(cfg_screen.cfg_module->l_ctl, lv_color_hex(0x202020), 0);
    lv_obj_set_style_border_color(cfg_screen.cfg_module->l_ctl, lv_color_hex(0x808080), 0);
    lv_obj_clear_flag(cfg_screen.cfg_module->l_ctl, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_color(cfg_screen.cfg_module->l_ctl, lv_color_hex(0xFFFFFF), LV_STATE_PRESSED);

    lv_obj_t *left_symbol = lv_img_create(cfg_screen.cfg_module->l_ctl);
    lv_img_set_src(left_symbol, &wjc_left);
    lv_obj_center(left_symbol);

    // RIGHT STY
    lv_obj_set_style_align(cfg_screen.cfg_module->r_ctl, LV_ALIGN_RIGHT_MID, 0);
    lv_obj_set_style_size(cfg_screen.cfg_module->r_ctl, base_w / 9, base_h - 40, 0);
    lv_obj_set_style_border_width(cfg_screen.cfg_module->r_ctl, 1, 0);
    lv_obj_set_style_bg_color(cfg_screen.cfg_module->r_ctl, lv_color_hex(0x202020), 0);
    lv_obj_set_style_border_color(cfg_screen.cfg_module->r_ctl, lv_color_hex(0x808080), 0);
    lv_obj_clear_flag(cfg_screen.cfg_module->r_ctl, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_color(cfg_screen.cfg_module->r_ctl, lv_color_hex(0xFFFFFF), LV_STATE_PRESSED);

    lv_obj_t *right_symbol = lv_img_create(cfg_screen.cfg_module->r_ctl);
    lv_img_set_src(right_symbol, &wjc_right);
    lv_obj_center(right_symbol);

    // config list sty
    cfg_screen.cfg_module->cfg_list = (CfgList *)malloc(sizeof(CfgList));
    cfg_screen.cfg_module->cfg_list->base = lv_obj_create(cfg_screen.cfg_module->base);
    lv_obj_set_style_size(cfg_screen.cfg_module->cfg_list->base, (base_w - (base_w / 9) * 2 - 10), base_h - 10, 0);
    lv_obj_set_style_x(cfg_screen.cfg_module->cfg_list->base, 45, 0);
    lv_obj_set_style_y(cfg_screen.cfg_module->cfg_list->base, 5, 0);
    lv_obj_set_style_pad_all(cfg_screen.cfg_module->cfg_list->base, 0, 0);
    lv_obj_set_style_border_width(cfg_screen.cfg_module->cfg_list->base, 0, 0);
    lv_obj_set_style_bg_color(cfg_screen.cfg_module->cfg_list->base, lv_color_hex(0x000000), 0);
    lv_obj_clear_flag(cfg_screen.cfg_module->cfg_list->base, LV_OBJ_FLAG_SCROLLABLE);
    // lv_obj_set_style_bg_color(cfg_screen.cfg_module->cfg_list->base,lv_color_hex(0x202020), 0);

    cfg_screen.cfg_module->cfg_list->cfg_arr = (CfgItem *)malloc(sizeof(CfgItem) * cfg_data_list_len);
    int x_offset = 0;
    int space = 2;

    for (int i = 0; i < cfg_data_list_len; i++)
    {
        CfgItem *cfg_item = (CfgItem *)malloc(sizeof(CfgItem));
        cfg_item->base = lv_obj_create(cfg_screen.cfg_module->cfg_list->base);
        cfg_item->cfg_name = lv_label_create(cfg_item->base);
        cfg_item->cfg_cur = lv_label_create(cfg_item->base);

        lv_obj_clear_flag(cfg_item->base, LV_OBJ_FLAG_SCROLLABLE);

        lv_obj_set_style_align(cfg_item->base, LV_ALIGN_LEFT_MID, 0);
        lv_obj_set_style_pad_all(cfg_item->base, 0, 0);
        lv_obj_set_style_size(cfg_item->base, 85, 90, 0);
        lv_obj_set_x(cfg_item->base, (i * space) + (i * 90));

        lv_obj_set_style_bg_color(cfg_item->base, lv_color_hex(0x202020), 0);
        lv_obj_set_style_border_width(cfg_item->base, 1, 0);
        lv_obj_set_style_outline_width(cfg_item->base, 1, 0);
        lv_obj_set_style_outline_color(cfg_item->base, lv_color_hex(0xA9A9A9), 0);

        cfg_item->cfg_id = CfgDataList[i].id;
        lv_label_set_text(cfg_item->cfg_name, CfgDataList[i].name);
        lv_label_set_text(cfg_item->cfg_cur, CfgDataList[i].cur_value);

        lv_obj_set_style_text_font(cfg_item->cfg_name, &lv_font_montserrat_12, 0);
        lv_obj_set_style_text_font(cfg_item->cfg_cur, &lv_font_montserrat_18, 0);

        // NAME
        lv_obj_set_style_align(cfg_item->cfg_name, LV_ALIGN_CENTER, 0);
        lv_obj_set_style_text_color(cfg_item->cfg_name, lv_color_hex(0xE8E8E8), 0);
        lv_obj_set_style_y(cfg_item->cfg_name, 20, 0);
        // CUR
        lv_obj_set_style_align(cfg_item->cfg_cur, LV_ALIGN_CENTER, 0);
        lv_obj_set_style_y(cfg_item->cfg_cur, -15, 0);
        lv_obj_set_style_text_color(cfg_item->cfg_cur, lv_color_hex(0xE8E8E8), 0);

        cfg_screen.cfg_module->cfg_list->cfg_arr[i] = *cfg_item;

        lv_obj_add_event_cb(cfg_screen.cfg_module->cfg_list->cfg_arr[i].base, CfgModuleHandleEvents, LV_EVENT_CLICKED,
                            (void *)&cfg_screen.cfg_module->cfg_list->cfg_arr[i].cfg_id);
    }

    lv_obj_add_event_cb(cfg_screen.cfg_module->l_ctl, CfgModuleHandleEvents, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(cfg_screen.cfg_module->r_ctl, CfgModuleHandleEvents, LV_EVENT_CLICKED, NULL);
}

static void CfgModuleHandleEvents(lv_event_t *event)
{

    lv_obj_t *p_obj = event->current_target;

    // 启动停止
    if (p_obj == cfg_screen.process_ctrl_mod->process_start_ring)
    {
        static int rotation = 0;
        if (event->code == LV_EVENT_RELEASED)
        {
            if (rotation >= 100)
            {
                printf("Lets go start either\n");
            //todo 发送信号

              CFG_EScrChangeReq.go_scr_id=SCREEN_ID_RUN;
              lv_event_send(g_scr,EVENT_CHANGE_SCREEN,(void*)&CFG_EScrChangeReq);

            }
            else
                rotation = 0;
            lv_arc_set_value(p_obj, rotation);
        }
        else if (event->code == LV_EVENT_PRESSING)
        {
            if (rotation < 100)
            {
                lv_arc_set_value(p_obj, rotation);
                rotation += 5;
            }
            else
            {
                printf("Lets go start\n");
                lv_arc_set_value(p_obj, 0);
                rotation = 0;

              CFG_EScrChangeReq.go_scr_id=SCREEN_ID_RUN;
              lv_event_send(g_scr,EVENT_CHANGE_SCREEN,(void*)&CFG_EScrChangeReq);

            }
        }
    }

    // 左右翅膀 clicked
    if (event->current_target == cfg_screen.cfg_module->l_ctl || event->current_target == cfg_screen.cfg_module->r_ctl)
    {
        int step_width = (int)lv_obj_get_width(cfg_screen.cfg_module->cfg_list->cfg_arr[0].base) + 7;

        int x_offset = (int)lv_obj_get_scroll_x(cfg_screen.cfg_module->cfg_list->base);
        // printf("x_offset -> %d step_width %d \n", x_offset, step_width);
        // printf("-------------\n");
        if (event->current_target == cfg_screen.cfg_module->l_ctl)
        {
            lv_obj_scroll_by_bounded(cfg_screen.cfg_module->cfg_list->base, +step_width, 0, LV_ANIM_ON);
        }
        else
        {
            lv_obj_scroll_by_bounded(cfg_screen.cfg_module->cfg_list->base, -step_width, 0, LV_ANIM_ON);
        }
        // lv_obj_scroll_to_view(cfg_screen.cfg_module->cfg_list->base,LV_ANIM_ON);
        // lv_point_t pp; //!获取当前的偏移量
        // lv_obj_get_scroll_end(cfg_screen.cfg_module->cfg_list->base,&pp);
        //*scroll_by 是根据步长来进行滑动
        // lv_obj_scroll_by(cfg_screen.cfg_module->cfg_list->base,-step_width,0,LV_ANIM_ON);
        //*scroll_to 是直接滑动到指定位置
    }

    // todo 单元配置

    for (int i = 0; i < cfg_data_list_len; i++)
    {
        if (p_obj == cfg_screen.cfg_module->cfg_list->cfg_arr[i].base)
        {
            int *p_cfg_id = (int *)event->user_data;
            printf("Got Cfgid -> %d\n", *p_cfg_id);

            int index = lv_obj_get_child_cnt(cfg_screen.base);

            lv_obj_move_to_index(cfg_screen.cfg_selector, index - 1);

            int base_x = (int)lv_obj_get_x(cfg_screen.cfg_module->cfg_list->base) + (int)lv_obj_get_x(cfg_screen.cfg_module->base);

            lv_point_t pp = Util_GetTouchPoint();
            printf("Touched x %d y %d  base_x %d \n", (int)pp.x, (int)pp.y, (int)base_x);

            if (((int)pp.x - base_x) > 90 && ((int)pp.x - base_x) < 180)
            {
                ShowCFGSelector(base_x + 90, 0, 0, 0);
            }
            else if (((int)pp.x - base_x) > 180)
            {
                ShowCFGSelector(base_x + 180, 0, 0, 0);
            }
            else
            {
                ShowCFGSelector(base_x + 0, 0, 0, 0);
            }
        }
    }
}

// 一次性的展示
static void ShowCFGSelector(int x, int min, int max, int cur)
{
    lv_obj_set_pos(cfg_screen.cfg_selector, x + 2, 75);
    lv_obj_clear_flag(cfg_screen.cfg_selector, LV_OBJ_FLAG_HIDDEN);
}

static void mask_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if (code == LV_EVENT_COVER_CHECK)
    {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);
    }
    else if (code == LV_EVENT_DRAW_MAIN_BEGIN)
    {
        /* add mask */
        const lv_font_t *font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t *fade_mask_top = lv_malloc(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t *fade_mask_bottom = lv_malloc(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);
    }
    else if (code == LV_EVENT_DRAW_POST_END)
    {
        lv_draw_mask_fade_param_t *fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t *fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_free(fade_mask_top);
        lv_free(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
   
}

static void CfgSelectorCB(lv_event_t *e)
{
    if (e->code == LV_EVENT_DEFOCUSED)
    {
        lv_obj_add_flag(cfg_screen.cfg_selector, LV_OBJ_FLAG_HIDDEN);
        printf("  LV_EVENT_DEFOCUSED  cur selector id %d\n", lv_roller_get_selected(cfg_screen.cfg_selector));
    }
    else if (e->code == LV_EVENT_CLICKED)
    {
        //  lv_obj_add_flag(cfg_screen.cfg_selector,LV_OBJ_FLAG_HIDDEN);
        printf("  LV_EVENT_CLICKED  cur selector id %d\n", lv_roller_get_selected(cfg_screen.cfg_selector));
    }
}

