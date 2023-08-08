#ifndef HELLOWIDGET_H_INCLUDED
#define HELLOWIDGET_H_INCLUDED

#define LABEL_LEARN 0
#define SLIDER_LEARN 0
#define BTN_LEARN 0
#define SWITCH_LEARN 0
#define LOAD_LEARN 0
#define LED_LEARN 0
#define LIST_LEARN 0
#define DD_LEARN 0
#define ROLLER_LEARN 0
#define SLIDER_LEARN 0
 
// #define LED_LEARN                  1
// #define LED_LEARN                  1

// #define SLIDER_LEARN  0

#include <stdio.h>
#include "lvgl/lvgl.h"

typedef struct
{
    int id;
    char *str;
} CustomData;

static lv_timer_t *t1_handler;
static lv_timer_t *t2_handler;

static lv_obj_t *label_s;
static lv_obj_t *list1;
static lv_obj_t *bar_text;
static lv_obj_t *bar;

static int seq=0;
lv_obj_t* img_seq;
//刷图
// LV_IMG_DECLARE(I0002);
// LV_IMG_DECLARE(I0003);
// LV_IMG_DECLARE(I0004);
// LV_IMG_DECLARE(I0005);
// LV_IMG_DECLARE(I0006);
// LV_IMG_DECLARE(I0007);
// LV_IMG_DECLARE(I0008);
// LV_IMG_DECLARE(I0009);
// LV_IMG_DECLARE(I0010);
// LV_IMG_DECLARE(I0011);
// LV_IMG_DECLARE(I0012);
// LV_IMG_DECLARE(I0013);
// LV_IMG_DECLARE(I0014);
// LV_IMG_DECLARE(I0015);
// LV_IMG_DECLARE(I0016);
// LV_IMG_DECLARE(I0017);

//需要定义一个数组
//void* img_array[16]={&I0002,&I0003,&I0004,&I0005,&I0006,&I0007,&I0008,&I0009,&I0010,&I0011,&I0012,&I0013,&I0014,&I0015,&I0016,&I0017};
void* img_array[16]={};


lv_obj_t *container_row; // 横向的layout

static void my_event_cb1(lv_event_t *e)
{

    // printf("Event by ")

    if (e->code == LV_EVENT_PRESSED)
    {
        printf("Got  LV_EVENT_PRESSED   event\n");
    }
    else if (e->code == LV_EVENT_LONG_PRESSED)
    {
        printf("Got  LV_EVENT_LONG_PRESSED  event\n");
    }
    else if (e->code == LV_EVENT_CLICKED)
    {
        char *text = lv_label_get_text(lv_obj_get_child(e->current_target, 0));
        printf("Got   LV_EVENT_CLICKED  event text-> %s\n", text);

        if (strcmp(text, "Hello") == 0)
        {
            lv_label_set_text(lv_obj_get_child(e->current_target, 0), "World");
        }
        else
        {
            lv_label_set_text(lv_obj_get_child(e->current_target, 0), "Hello");
        }
    }
}


static void anim_x_cb(void * var, int32_t v)
{
    printf("y u call me? %d\n",v);

    lv_obj_set_x(var, v);

    lv_obj_set_y(var,lv_obj_get_y(var)+10);
}

static void TCB_UpdateImgSeq(struct _lv_timer_t *timer)
{
    printf("this is the call back\n");
    if(seq<=16)
    {
     lv_img_set_src(img_seq,img_array[seq]);
    }
    seq++;
}

static void sw_event_cb(lv_event_t *e)
{
    lv_obj_t * sw = lv_event_get_target(e);
    lv_obj_t * label = lv_event_get_user_data(e);

    if(lv_obj_has_state(sw,LV_STATE_CHECKED)==true)
    {
        lv_anim_t ani;
        lv_anim_init(&ani);
        lv_anim_set_var(&ani,label);
        lv_anim_set_values(&ani,lv_obj_get_x(label),500);
        lv_anim_set_time(&ani,500);
        lv_anim_set_exec_cb(&ani, anim_x_cb);
        lv_anim_set_path_cb(&ani, lv_anim_path_bounce);
        lv_anim_start(&ani);

    }else
    {
         lv_anim_t ani;
        lv_anim_init(&ani);
        lv_anim_set_var(&ani,label);
        lv_anim_set_values(&ani,lv_obj_get_x(label),0);
        lv_anim_set_time(&ani,500);
        lv_anim_set_exec_cb(&ani, anim_x_cb);
        lv_anim_set_path_cb(&ani, lv_anim_path_ease_in);
        lv_anim_start(&ani);
    }


}

// 通过点击按钮的文本确定是那个对象
static void my_list_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        LV_LOG_USER("Clicked: %s", lv_list_get_btn_text(list1, obj));
    }
}

static void my_event_cb2(lv_event_t *e)
{
    CustomData *pdata = (CustomData *)e->user_data;
    lv_label_set_text_fmt(label_s, "%s:%d", pdata->str, pdata->id);
}

static void my_timer_cb(struct _lv_timer_t *timer)
{
    // 定时器回调函数
    lv_obj_t *obj_1 = timer->user_data;
    lv_obj_update_layout(obj_1);
    lv_coord_t x = lv_obj_get_x(obj_1);
    int x_int = (int)x;
    printf("timer cb  the x pos is %d\n", x_int);
    lv_obj_set_pos(obj_1, 0, 0);
    lv_timer_del(t1_handler);
}

static void my_t2_cb(struct _lv_timer_t *timer)
{

    static int percent = 0;

    // 定时器回调函数

    if (percent <= 100)
    {
        lv_label_set_text_fmt(bar_text, "Percent %d", percent);
        lv_bar_set_value(bar, percent, LV_ANIM_ON);
    }
    else
    {
        lv_label_set_text(bar_text, "Complete !!!");
        lv_timer_del(t2_handler);
    }
    percent++;
}
 
static Timer1CB(struct _lv_timer_t *timer)
{
    int* i = (int*)timer->user_data;
    printf("Timer1CB %d\n",*i);
    (*i)++;
}

static ImgBtnHandler(lv_event_t *e)
{
 
    lv_obj_t* obj = e->target;

   // printf("e code %d\n",e->code);
    if(e->code==LV_EVENT_PRESSED)
    {
       printf("Go LV_EVENT_PRESSED\n");
       lv_obj_set_style_img_recolor(obj,lv_color_hex(0xFF00FF),LV_PART_MAIN);
       lv_obj_set_style_img_recolor_opa(obj,150,LV_STATE_DEFAULT); //必须有这一行才能上色？
    }else if (e->code==LV_EVENT_RELEASED)
    {
       printf("Go LV_EVENT_RELEASED\n");
       lv_obj_set_style_img_recolor(obj,lv_color_hex(0x000000),LV_PART_MAIN);
    }
    
   // 
}

// 处理下拉框选择的event
void DD_Handler(lv_event_t *e)
// 处理滚轮的事件
{

    char *buf = lv_malloc(10);
    lv_obj_t *target = e->target;
    lv_dropdown_get_selected_str(target, buf, 10);
    printf("Current you select %s\n", buf);
}

void RollerHandler(lv_event_t *e)
{
    char *buf = lv_malloc(10);

    if (e->code == LV_EVENT_VALUE_CHANGED)
    {
        lv_roller_get_selected_str(e->target, buf, 10);
        printf("currently u select %s\n", buf);
    }
    lv_free(buf);
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

static void ManuallyScrollCB(lv_event_t *e)
{
    int *id = (int *)(e->user_data);

    printf("id %d\n", *id);

    if (*id == 1)
    {
        printf("LEFT BTN \n");
        lv_obj_scroll_by(container_row, 100, 0, LV_ANIM_ON);
    }
    else
    {
        printf("RIGHT BTN\n");
        lv_obj_scroll_by(container_row, -100, 0, LV_ANIM_ON);
    }
}




void BasicLearn()
{
#if 0
    lv_obj_t* main_screen =lv_scr_act();
    lv_obj_t* obj_1 =  lv_obj_create(main_screen);
    lv_obj_set_size(obj_1,200,200);
    lv_obj_set_pos(obj_1,100,100);

//样式分为两种，普通样式和本地样式，普通样式需要static 不能是局部变量，不然离开了函数，样式就失效了。好处就是可以公用
//本地样式 不能公用但是对样式生命周期没有要求


    static lv_style_t style_shadow;//阴影效果
    lv_style_init(&style_shadow);
    lv_style_set_shadow_width(&style_shadow,100);
    lv_style_set_shadow_spread(&style_shadow,10);
    lv_style_set_shadow_color(&style_shadow, lv_palette_main(LV_PALETTE_BLUE));

    //把这个阴影效果运用到 对象上
    lv_obj_add_style(obj_1,&style_shadow,0);
    //如果立刻获取到的是0，则可能是没有执行这个，LVGL底层没来得及刷新

    lv_obj_update_layout(obj_1);
    lv_coord_t x = lv_obj_get_x(obj_1);
    int x_int =(int)x;

//deprecated! 现在改用Timer 执行回调了
//lv_delay_ms(1000);//阻塞1000ms


    /* 创建定时器，延迟 1000 毫秒后执行 */
    // lv_obj_remove_style_all(obj_1);
    // t1_handler  = lv_timer_create(my_timer_cb, 10000, obj_1);
    printf("ok the x pos is %d\n",x_int);



//已知的类型组件

    lv_obj_t* switch_1 = lv_switch_create(obj_1);

    lv_obj_set_size(switch_1,100,30);

    lv_obj_set_align(switch_1,LV_ALIGN_CENTER);

    // lv_obj_set_align(obj_1,LV_ALIGN_OUT_TOP_RIGHT);

    lv_obj_t* switch_2 =lv_switch_create(main_screen);

    lv_obj_align_to(switch_2,obj_1,LV_ALIGN_BOTTOM_LEFT,10,-10);

    t1_handler  = lv_timer_create(my_timer_cb, 3000, obj_1);

    lv_obj_t* obj2=lv_obj_create(main_screen);
    lv_obj_set_size(obj2,50,50);
    lv_obj_align(obj2,LV_ALIGN_BOTTOM_LEFT,10,-10);
    lv_obj_set_style_bg_color(obj2,lv_color_hex(0x446699),LV_STATE_PRESSED);
#endif
}
// 学习一些LVGL 自带的组件
void CoreWidgetLearn()
{
    lv_obj_t *main_screen = lv_scr_act();

//!tabview
#if 0
    lv_obj_t*  tabview1 = lv_tabview_create(main_screen,LV_DIR_TOP,100);
    
    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t * tab1 = lv_tabview_add_tab(tabview1, "Tab 1");
    lv_obj_t * tab2 = lv_tabview_add_tab(tabview1, "Tab 2");
    lv_obj_t * tab3 = lv_tabview_add_tab(tabview1, "Tab 3");

  
    /*Add content to the tabs*/
    lv_obj_t * label = lv_label_create(tab1);
    lv_label_set_text(label, "If the content in TAB is too long, it will have the effect of scroll bar.");

    label = lv_label_create(tab2);
    lv_label_set_text(label, "Second tab");

    label = lv_label_create(tab3);
    lv_label_set_text(label, "Third tab");

    lv_obj_scroll_to_view_recursive(label, LV_ANIM_ON);
#endif

    LV_FONT_DECLARE(simhei);
    lv_obj_t* chinese_font = lv_label_create(main_screen);

    lv_obj_center(chinese_font);
    lv_obj_set_style_text_font(chinese_font,&simhei,0);
    lv_label_set_text(chinese_font,"你好魏嘉成,谢谢");
    

#if 0
   // 图片的显示有三种，内部符号，图片转化成数组，带文件系统的 资源路径
    LV_IMG_DECLARE(Box7);
    // lv_obj_t *first_img = lv_img_create(main_screen);
    // lv_img_set_src(first_img, &Box7);
 
//imgbtn的方式也很常用
    LV_IMG_DECLARE(hellotree)
    lv_obj_t* img_btn = lv_imgbtn_create(main_screen);
    lv_obj_set_size(img_btn,128,128);
    
    lv_imgbtn_set_src(img_btn,LV_STATE_DEFAULT,NULL,&hellotree,NULL);
    
    lv_obj_add_event_cb(img_btn,ImgBtnHandler,LV_EVENT_ALL,NULL);
 #endif
   
#if SLIDER_LEARN == 1
    lv_obj_t *slider_1 = lv_slider_create(main_screen);
    lv_obj_set_size(slider_1, 100, 20);
    lv_obj_align(slider_1, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_bg_color(slider_1, lv_color_hex(0xFF00FF), LV_STATE_DEFAULT);

#endif // HELLOWIDGET_H_INCLUDED

#if LABEL_LEARN == 1
    lv_obj_t *label_1 = lv_label_create(main_screen);
    //  lv_obj_set_size(label_1,100,20);
    lv_obj_align(label_1, LV_ALIGN_CENTER, 0, -100);
    lv_label_set_text(label_1, "hello the text is very long...");

    lv_obj_set_style_text_font(label_1, &lv_font_montserrat_30, LV_STATE_DEFAULT);

    lv_obj_update_layout(label_1);

    // 设置颜色 与单独设置个别文本颜色
    lv_label_set_recolor(label_1, true); // 开启重新着色功能
    lv_label_set_text(label_1, "hello #ff00ff lvgl#  #00ff00 fuck #");

    lv_obj_set_style_bg_color(label_1, lv_color_hex(0xFF00FF), LV_STATE_DEFAULT);

    lv_obj_set_style_bg_opa(label_1, 200, LV_STATE_DEFAULT); // 不使能还看不到颜色，只是背景的颜色变了

    // 如果要设置文本颜色用
    // lv_obj_set_style_text_color()

    char *my_text = lv_malloc(30);

    strcpy(my_text, "my text is very long");

    lv_coord_t w = lv_obj_get_width(label_1);

    printf("width is %d\n", (int)w);

    lv_obj_t *label_2 = lv_label_create(main_screen);
    lv_obj_align(label_2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(label_2, 100, 50);
    lv_obj_set_style_text_font(label_2, &lv_font_montserrat_20, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_2, lv_color_hex(0x0000ff), LV_STATE_DEFAULT);
    lv_label_set_text(label_2, my_text);
    // lv_label_set_long_mode(label_2,LV_LABEL_LONG_SCROLL);
    // lv_label_set_long_mode(label_2,LV_LABEL_LONG_DOT);
    lv_label_set_long_mode(label_2, LV_LABEL_LONG_SCROLL_CIRCULAR);

    // 阴影效果
    lv_obj_t *hello = lv_label_create(main_screen);

    lv_obj_align(hello, LV_ALIGN_CENTER, 0, 100);
    lv_obj_set_style_text_font(hello, &lv_font_montserrat_30, LV_STATE_DEFAULT);
    lv_label_set_text(hello, "Hello Shadow");

    lv_obj_t *hello_shadow = lv_label_create(main_screen);
    lv_label_set_text(hello_shadow, lv_label_get_text(hello));
    lv_obj_set_style_text_font(hello_shadow, &lv_font_montserrat_30, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(hello_shadow, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_text_opa(hello_shadow, LV_OPA_30, LV_PART_MAIN);

    /*Shift the second label down and to the right by 2 pixel*/
    lv_obj_align_to(hello_shadow, hello, LV_ALIGN_TOP_LEFT, 2, 2);

    // 上面是原理，下面是实际用法

    /*Create a style for the shadow*/
    static lv_style_t style_shadow;
    lv_style_init(&style_shadow);
    lv_style_set_text_opa(&style_shadow, LV_OPA_30);
    lv_style_set_text_color(&style_shadow, lv_color_black());

    /*Create a label for the shadow first (it's in the background)*/
    lv_obj_t *shadow_label = lv_label_create(lv_scr_act());
    lv_obj_add_style(shadow_label, &style_shadow, 0);

    /*Create the main label*/
    lv_obj_t *main_label = lv_label_create(lv_scr_act());
    lv_label_set_text(main_label, "A simple method to create\n"
                                  "shadows on a text.\n"
                                  "It even works with\n\n"
                                  "newlines     and spaces.");

    /*Set the same text for the shadow label*/
    lv_label_set_text(shadow_label, lv_label_get_text(main_label));

    /*Position the main label*/
    lv_obj_align(main_label, LV_ALIGN_CENTER, 0, 0);

    /*Shift the second label down and to the right by 2 pixel*/
    lv_obj_align_to(shadow_label, main_label, LV_ALIGN_TOP_LEFT, 2, 2);

#endif // HELLOWIDGET_H_INCLUDED

#if BTN_LEARN == 1

    lv_obj_t *btn_1 = lv_btn_create(main_screen);
    lv_obj_t *label = lv_label_create(btn_1);

    lv_obj_center(label);

    lv_label_set_text(label, "Hello");

    lv_obj_set_align(btn_1, LV_ALIGN_CENTER);
    lv_obj_set_size(btn_1, 100, 40);

    lv_obj_add_event_cb(btn_1, my_event_cb1, LV_EVENT_ALL, NULL);

    static CustomData custom_data;
    custom_data.id = 666;
    custom_data.str = "hi";

    lv_obj_t *btn_2 = lv_btn_create(main_screen);
    lv_obj_align_to(btn_2, btn_1, LV_ALIGN_OUT_BOTTOM_RIGHT, 100, 0);

    label_s = lv_label_create(lv_scr_act());

    lv_label_set_text(label_s, "change me");

    lv_obj_center(label_s);

    lv_obj_add_event_cb(btn_2, my_event_cb2, LV_EVENT_CLICKED, (void *)&custom_data);

    // 卧槽，还有对象树的概念
// lv_obj_get_child
// lv_obj_tree_walk
#endif // BTN_LEARN

#if SWITCH_LEARN == 1
    lv_obj_t *switch_1 = lv_switch_create(main_screen);
    lv_obj_center(switch_1);

    // LV_STATE_CHECKED 开关被打开了
    // lv_obj_has_state  判断有没有这个状态
    // lv_obj_clear_state  清除这个状态

#endif // SWITCH_LEARN

#if LOAD_LEARN == 1
    // 分为进度条和加载器
    bar_text = lv_label_create(main_screen);
    bar = lv_bar_create(main_screen);

    lv_obj_align(bar_text, LV_ALIGN_CENTER, 0, -50);
    lv_obj_set_size(bar, 400, 20);
    lv_obj_align(bar, LV_ALIGN_CENTER, 0, 0);
    lv_bar_set_range(bar, 0, 100);
    lv_bar_set_value(bar, 1, LV_ANIM_ON);
    lv_bar_set_mode(bar, LV_BAR_MODE_NORMAL);
    lv_obj_set_style_anim_time(bar, 300, LV_STATE_DEFAULT);
    t2_handler = lv_timer_create(my_t2_cb, 300, NULL);

    // 加载器
    lv_obj_t *spinner = lv_spinner_create(main_screen, 3000, 100);

#endif // LOAD_LEARN

#if LED_LEARN == 1
    lv_obj_t *led = lv_led_create(main_screen);
    lv_led_on(led);
#endif // LED_LEARN

#if LIST_LEARN == 1
    // 列表部件
    list1 = lv_list_create(main_screen);
    lv_obj_align(list1, LV_ALIGN_CENTER, 0, 0);

    /*Add buttons to the list*/
    lv_obj_t *btn;
    lv_list_add_text(list1, "File");
    btn = lv_list_add_btn(list1, LV_SYMBOL_FILE, "New");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_DIRECTORY, "Open");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_SAVE, "Save");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(list1, "Connectivity");
    btn = lv_list_add_btn(list1, LV_SYMBOL_BLUETOOTH, "Bluetooth");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_GPS, "Navigation");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(list1, "Exit");
    btn = lv_list_add_btn(list1, LV_SYMBOL_OK, "");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "");
    lv_obj_add_event_cb(btn, my_list_cb, LV_EVENT_CLICKED, NULL);
#endif // LIST_LEARN

#if DD_LEARN == 1
    // 下拉菜单
    lv_obj_t *dd = lv_dropdown_create(main_screen);
    lv_dropdown_set_options(dd, "Lebrn\nAD\nLifus\nOvin\nKD\n");
    lv_obj_add_event_cb(dd, DD_Handler, LV_EVENT_VALUE_CHANGED, NULL);

#endif // DD_LEARN

#if 0
 //滚轮。数字选择器
    lv_obj_t* roller =lv_roller_create(main_screen);
//中间高亮部分，LVGL 叫selected
    static lv_style_t selected_styel; //!fuck 如果出现样式丢失需要考虑一下这个是不是static的
    lv_style_init(&selected_styel);
    lv_style_set_text_font(&selected_styel,&lv_font_montserrat_24);
//如果需要中间有放大效果则需要有特殊的style
    lv_obj_add_style(roller,&selected_styel,LV_PART_SELECTED);

    lv_roller_set_options(roller,"1\n 2\n 3\n 4\n 5\n 6",LV_ROLLER_MODE_INFINITE); //设置为无限循环
    lv_roller_set_visible_row_count(roller,3);//设置可见行数
    lv_roller_set_selected(roller,2,LV_ANIM_ON);
    lv_obj_center(roller);
    lv_obj_add_event_cb(roller,RollerHandler,LV_EVENT_VALUE_CHANGED,NULL);
#endif
 
}

void EventLearn()
{
}
 
void func_async()
{
    lv_log("async call\n");

  //lv_obj_add_flag(guider_ui.screen_1_img_0, LV_OBJ_FLAG_HIDDEN);    
}
 

//定时器与异步执行
void TimerLearn()
{   
    // static int a =10;
    // lv_timer_t* timer_1 = lv_timer_create(Timer1CB,1000,&a);
    // //设置运行次数
    // lv_timer_set_repeat_count(timer_1,10);
    // lv_async_call(func_async,NULL);



lv_timer_t * img_timer;

img_seq = lv_img_create(lv_scr_act());

img_timer =lv_timer_create(TCB_UpdateImgSeq,1000,NULL);


 
}

void AniLearn()
{


    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello animations!");
    lv_obj_set_pos(label, 500, 10);


    lv_obj_t * sw = lv_switch_create(lv_scr_act());
    lv_obj_center(sw);
    lv_obj_add_state(sw, LV_STATE_CHECKED);
    lv_obj_add_event_cb(sw, sw_event_cb, LV_EVENT_VALUE_CHANGED, label);   


}

//文件区域和键盘的学习
void TextAndKeyboardLeran()
{
    lv_obj_t* text_area =lv_textarea_create(lv_scr_act());
    lv_obj_set_size(text_area,400,250);

    lv_textarea_set_placeholder_text(text_area,"please hold ");
//设置为密码模式
    lv_textarea_set_password_mode(text_area, true);

    lv_obj_t* kb =lv_keyboard_create(lv_scr_act());

    //将键盘和文本框关联起来
    //如果多个文本区域连接，可以判断哪个focus然后在进行绑定
    lv_keyboard_set_textarea(kb,text_area);

}


void LayoutLearn()
{
    lv_log("Layout is importent!\n");
    lv_obj_t *main_screen = lv_scr_act();

    container_row = lv_obj_create(main_screen);
    lv_obj_set_size(container_row, 500, 100);
    lv_obj_align(container_row, LV_ALIGN_TOP_MID, 0, 10);

    // 下面这句话给这个lv_obj_t 对象带来了布局的属性
    lv_obj_set_flex_flow(container_row, LV_FLEX_FLOW_ROW);
    //    lv_stylt_t container_row_style;
    //    container_row_style =lv_
    for (int i = 0; i < 10; i++)
    {
        lv_obj_t *item;
        item = lv_btn_create(container_row);
        lv_obj_set_size(item, 50, LV_PCT(100));
        lv_obj_t *label = lv_label_create(item);
        lv_label_set_text_fmt(label, "Btn %d", i);
        lv_obj_center(label);
        // lv_style_set_pad_row
    }

    //     lv_obj_t* container_row_wrap=lv_obj_create(main_screen);
    //     lv_obj_align_to(container_row_wrap,container_row,LV_ALIGN_OUT_RIGHT_MID,10,10);
    //     lv_obj_set_size(container_row_wrap,300,100);
    // //设置为包装属性
    //     lv_obj_set_flex_flow(container_row_wrap,LV_FLEX_FLOW_ROW_WRAP);

    //     for (int i = 0; i < 10; i++)
    //     {
    //         lv_obj_t *item;
    //         item = lv_btn_create(container_row_wrap);
    //         lv_obj_set_size(item,50,50);
    //         lv_obj_t *label = lv_label_create(item);
    //         lv_label_set_text_fmt(label,"Btn %d",i);
    //         lv_obj_center(label);
    //         //lv_style_set_pad_row
    //     }

    lv_obj_t *container_col_grow = lv_obj_create(main_screen);
    lv_obj_align_to(container_col_grow, container_row, LV_ALIGN_OUT_BOTTOM_MID, 10, 10);
    lv_obj_set_size(container_col_grow, 300, 100);
    lv_obj_set_style_pad_all(container_col_grow, 0, LV_PART_MAIN);
    // 设置为列布局
    lv_obj_set_flex_flow(container_col_grow, LV_FLEX_FLOW_COLUMN);
    // 设置对象间隔
    lv_obj_set_style_pad_gap(container_col_grow, 0, LV_PART_MAIN);

    for (int i = 0; i < 10; i++)
    {
        lv_obj_t *item;
        item = lv_btn_create(container_col_grow);
        lv_obj_set_size(item, lv_pct(50), lv_pct(50));
        lv_obj_t *label = lv_label_create(item);
        lv_label_set_text_fmt(label, "Btn %d", i);
        lv_obj_center(label);
        // lv_style_set_pad_row
    }
    // 搞两个按钮来手动设置偏移
    lv_obj_t *btn_left = lv_btn_create(main_screen);
    lv_obj_t *btn_right = lv_btn_create(main_screen);

    lv_obj_set_size(btn_left, 100, 100);
    lv_obj_set_size(btn_right, 100, 100);

    lv_obj_t *btn_left_text = lv_label_create(btn_left);
    lv_obj_t *btn_right_text = lv_label_create(btn_right);

    lv_obj_center(btn_left_text);
    lv_obj_center(btn_right_text);

    lv_label_set_text(btn_left_text, "-");
    lv_label_set_text(btn_right_text, "+");
    lv_obj_set_style_text_font(btn_right_text, &lv_font_montserrat_22, LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_left_text, &lv_font_montserrat_22, LV_PART_MAIN);

    lv_obj_align_to(btn_left, container_row, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    lv_obj_align_to(btn_right, container_row, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

    lv_obj_update_layout(btn_left);
    lv_obj_update_layout(btn_right);

    //! 事件里面东西都得是静态的，所以这个参数也得是静态的生命周期或者是通过 malloc 而来的
    static int l_id = 1;
    static int r_id = 2;
    lv_obj_add_event_cb(btn_left, ManuallyScrollCB, LV_EVENT_CLICKED, &l_id);
    lv_obj_add_event_cb(btn_right, ManuallyScrollCB, LV_EVENT_CLICKED, &r_id);
}

#endif // HELLOWIDGET_H_INCLUDED
 



 
 