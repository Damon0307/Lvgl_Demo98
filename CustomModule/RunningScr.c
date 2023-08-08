#include <stdio.h>

#include "RunningScr.h"

typedef struct
{
    lv_obj_t *base;
    lv_obj_t *process_name;
    lv_obj_t *remain_time;
    lv_obj_t *run_stage;
    lv_obj_t *run_progress;
    lv_obj_t *run_ctl;

} RunningScreen;

static int running_flag; // 作为USER_DATA 传递到事件中
//? 没想到还有这一出呢 像是 label , img 这些对象是不能直接捕捉到 clicked 这种信号的，只能纯显示，如果想捕捉需要搞一个透明的
//?按钮附着在上面，或者是通过父对象的容器判断 点击的位置来判断该对象是不是被点击了

static RunningScreen s_run_scr;

// 初始化一些样式表
static lv_style_t sty_tte;

LV_IMG_DECLARE(wjc_pause)
LV_IMG_DECLARE(wjc_finish)

LV_FONT_DECLARE(FontLCD50F)
LV_FONT_DECLARE(MachinePro80F)

static void RunEventCB_Ctrl(lv_event_t *event);

// static lv_anim_t run_ctrl_ani;

// 启动按钮透明度变化的cb
static void RunAniCB_Ctrl(void *, int32_t v);

// 动画完成时的回调函数
static void anim_ready_cb(lv_anim_t *anim)
{
      lv_img_set_src(anim->var,&wjc_finish);

        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, s_run_scr.run_ctl);
        lv_anim_set_exec_cb(&a, RunAniCB_Ctrl);
        lv_anim_set_time(&a, 700);
        lv_anim_set_values(&a, 0, 255);
        lv_anim_set_path_cb(&a, lv_anim_path_linear);
       // lv_anim_set_ready_cb(&a,anim_ready_cb);
         lv_anim_start(&a);
       

}

static lv_obj_t *m_scr;

void RunningInit(lv_obj_t *parent)
{

    m_scr = lv_scr_act();
    lv_obj_set_size(m_scr, 780, 220);

    s_run_scr.base = lv_obj_create(m_scr);
    lv_obj_set_size(s_run_scr.base, lv_obj_get_width(m_scr), lv_obj_get_height(m_scr));

    lv_obj_set_style_bg_color(s_run_scr.base, lv_color_hex(0x000000), 0);

    s_run_scr.process_name = lv_label_create(s_run_scr.base);
    s_run_scr.remain_time = lv_label_create(s_run_scr.base);
    s_run_scr.run_stage = lv_label_create(s_run_scr.base);
    s_run_scr.run_progress = lv_slider_create(s_run_scr.base);
    s_run_scr.run_ctl = lv_img_create(s_run_scr.base);

    running_flag = 0;
    // tte

    lv_style_init(&sty_tte);
    lv_style_set_align(&sty_tte, LV_ALIGN_LEFT_MID);
    lv_style_set_x(&sty_tte, 30);  // 这里的X是基于上面的布局以后进行的
    lv_style_set_y(&sty_tte, -20); // 这里的X是基于上面的布局以后进行的
    lv_style_set_text_font(&sty_tte, &FontLCD50F);
    lv_style_set_text_color(&sty_tte, lv_color_hex(0xffffff));

    lv_label_set_text(s_run_scr.remain_time, "120");
    lv_obj_add_style(s_run_scr.remain_time, &sty_tte, LV_STATE_DEFAULT);

    lv_label_set_text(s_run_scr.process_name, "Skirt");
    lv_obj_set_style_text_color(s_run_scr.process_name, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(s_run_scr.process_name, &MachinePro80F, 0);
    lv_obj_align_to(s_run_scr.process_name, s_run_scr.remain_time, LV_ALIGN_BOTTOM_MID, 0, 50);

    // slider
    /*Create a transition*/
    static const lv_style_prop_t props[] = {LV_STYLE_BG_COLOR, 0};
    static lv_style_transition_dsc_t transition_dsc;
    lv_style_transition_dsc_init(&transition_dsc, props, lv_anim_path_linear, 300, 0, NULL);

    static lv_style_t style_main;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;
    static lv_style_t style_pressed_color;
    lv_style_init(&style_main);
    lv_style_set_bg_opa(&style_main, LV_OPA_COVER);
    lv_style_set_bg_color(&style_main, lv_color_hex3(0xbbb));
    lv_style_set_radius(&style_main, LV_RADIUS_CIRCLE);
    lv_style_set_pad_ver(&style_main, -2); /*Makes the indicator larger*/

    lv_style_init(&style_indicator);
    lv_style_set_bg_opa(&style_indicator, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indicator, lv_palette_main(LV_PALETTE_ORANGE));
    lv_style_set_radius(&style_indicator, LV_RADIUS_CIRCLE);
    lv_style_set_transition(&style_indicator, &transition_dsc);

    lv_style_init(&style_knob);
    lv_style_set_bg_opa(&style_knob, LV_OPA_COVER);
    lv_style_set_bg_color(&style_knob, lv_palette_main(LV_PALETTE_ORANGE));
    lv_style_set_border_color(&style_knob, lv_palette_darken(LV_PALETTE_ORANGE, 3));
    lv_style_set_border_width(&style_knob, 2);
    lv_style_set_radius(&style_knob, LV_RADIUS_CIRCLE);
    lv_style_set_pad_all(&style_knob, 6); /*Makes the knob larger*/
    lv_style_set_transition(&style_knob, &transition_dsc);

    lv_style_init(&style_pressed_color);
    lv_style_set_bg_color(&style_pressed_color, lv_palette_darken(LV_PALETTE_ORANGE, 2));
    lv_obj_remove_style_all(s_run_scr.run_progress); /*Remove the styles coming from the theme*/
    lv_obj_add_style(s_run_scr.run_progress, &style_main, LV_PART_MAIN);
    lv_obj_add_style(s_run_scr.run_progress, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(s_run_scr.run_progress, &style_pressed_color, LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_obj_add_style(s_run_scr.run_progress, &style_knob, LV_PART_KNOB);
    lv_obj_add_style(s_run_scr.run_progress, &style_pressed_color, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_center(s_run_scr.run_progress);

    lv_obj_align_to(s_run_scr.run_stage, s_run_scr.run_progress, LV_ALIGN_OUT_TOP_LEFT, 5, -10);
    lv_label_set_text(s_run_scr.run_stage, "washing...");
    lv_obj_set_style_text_font(s_run_scr.run_stage, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(s_run_scr.run_stage, lv_color_hex(0xffffff), 0);

    lv_img_set_src(s_run_scr.run_ctl, &wjc_pause);
    lv_obj_align_to(s_run_scr.run_ctl, s_run_scr.run_progress, LV_ALIGN_OUT_RIGHT_MID, 80, -10);

    // 透明按钮
    lv_obj_t *run_ctl_btn = lv_btn_create(s_run_scr.run_ctl);
    lv_obj_set_size(run_ctl_btn, lv_obj_get_width(s_run_scr.run_ctl), lv_obj_get_height(s_run_scr.run_ctl));
    lv_obj_center(run_ctl_btn);
    // lv_obj_remove_style_all(run_ctl_btn);
    lv_obj_set_style_opa(run_ctl_btn, LV_OPA_0, 0);

    // 添加按钮的事件，注意这里绑定的是user_data 而不是 param
    lv_obj_add_event_cb(s_run_scr.run_ctl, RunEventCB_Ctrl, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(run_ctl_btn, RunEventCB_Ctrl, LV_EVENT_CLICKED, (void *)&running_flag);

    // lv_obj_add_event_cb(s_run_scr.remain_time,RunEventCB_Ctrl,LV_EVENT_CLICKED,(void*)&running_flag);

    // lv_obj_add_event_cb(s_run_scr.base,RunEventCB_Ctrl,LV_EVENT_CLICKED,(void*)&running_flag);

    lv_scr_load_anim(m_scr, LV_SCR_LOAD_ANIM_FADE_ON, 600, 0, 0);
}
void RunningDelete()
{
    lv_obj_clean(m_scr);
    printf("RunningDelete...\n");
}

static void RunAniCB_Ctrl(void *obj, int32_t v)
{
    lv_obj_set_style_opa(obj, v, 0);
}

// 做一个
static void RunEventCB_Ctrl(lv_event_t *event)
{
    // 比判断图片资源更便捷的方式是，通过传递过来的 user_data 处理逻辑
    //  if(event->code = LV_EVENT_CLICKED)
    //  {
    //      lv_img_get_src
    //  }

    printf("hhhhh event code %d\n", event->code);

    int *user_data = (int *)event->user_data;
    if (*user_data == 1)
    {

    //     lv_anim_t a;
    //     lv_anim_init(&a);
    //     lv_anim_set_var(&a, s_run_scr.run_ctl);
    //     lv_anim_set_exec_cb(&a, RunAniCB_Ctrl);
    //     lv_anim_set_time(&a, 1000);
    //     lv_anim_set_values(&a, 0, 255);
    //     lv_anim_set_path_cb(&a, lv_anim_path_linear);
    //    // lv_anim_set_ready_cb(&a,anim_ready_cb);
    //      lv_anim_start(&a);
    //     *(int *)(event->user_data) = 0;
    }
    else
    {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, s_run_scr.run_ctl);
        lv_anim_set_exec_cb(&a, RunAniCB_Ctrl);
        lv_anim_set_time(&a, 850);
        lv_anim_set_values(&a, 255, 0);
        lv_anim_set_path_cb(&a, lv_anim_path_linear);
        lv_anim_set_ready_cb(&a,anim_ready_cb);
         lv_anim_start(&a);
        *(int *)(event->user_data) = 1;
    }
}

#if 0
 
 

#endif