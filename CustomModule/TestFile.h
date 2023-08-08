#ifndef __TESTFILE_H__
#define __TESTFILE_H__

#include "../lvgl/lvgl.h"

#include <stdlib.h>
#include <stdio.h>
#if 0
static void anim_x_cb(void * var, int32_t v)
{
   printf(" anim_x_cb v->  %d\n",v);
    lv_obj_set_x(var, v);

}

static void anim_size_cb(void * var, int32_t v)
{
     printf(" anim_size_cb v->  %d\n",v);
    lv_obj_set_size(var, v, v);
}
 
/**
 * Create a playback animation
 */
void lv_example_anim_2(void)
{

    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);

    lv_obj_align(obj, LV_ALIGN_LEFT_MID, 10, 0);
 
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 10, 50);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_playback_time(&a, 300);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);

    lv_anim_set_exec_cb(&a, anim_size_cb);
    lv_anim_start(&a);
    lv_anim_set_exec_cb(&a, anim_x_cb);
    lv_anim_set_values(&a, 10, 240);



    lv_anim_start(&a);
    
}
#endif

#if 0  
//expand 效果的测试
static lv_obj_t *t1, *t2, *t3, *t4;
static int cur_expand_node = 0;

static void set_pos_cb(void * var, int32_t v)
{
    //lv_coord_t cur_x = lv_obj_get_x((lv_obj_t *)var);
      
     lv_obj_set_pos((lv_obj_t *)var,v,lv_obj_get_y((lv_obj_t *)var));
 
}

static void Draft_CB(lv_event_t *e)
{
    // printf("Draft_CB  e->code %d\n", e->code);
    int *cur_focus_num = (int *)(e->user_data);
    printf("Hello focus %d\n", *cur_focus_num);

    if (cur_expand_node == 0 && *cur_focus_num != 4)
    {
        int ani_num = 4 - (*cur_focus_num);
        lv_anim_t ani_arr[ani_num];
        for (int i = 0; i < ani_num; i++)
        {
        lv_anim_init(&ani_arr[i]);
        lv_anim_set_time(&ani_arr[i], 250);
        
        lv_anim_set_path_cb(&ani_arr[i], lv_anim_path_linear);
        lv_anim_set_exec_cb(&ani_arr[i], set_pos_cb);
       
        }
        if (*cur_focus_num == 1)
        {
            lv_anim_set_var(&ani_arr[0], t2);
             lv_anim_set_values(&ani_arr[0], lv_obj_get_x(t2),lv_obj_get_x(t2) + 250-180);

            lv_anim_set_var(&ani_arr[1], t3);
             lv_anim_set_values(&ani_arr[1], lv_obj_get_x(t3),lv_obj_get_x(t3)+250-180);

            lv_anim_set_var(&ani_arr[2], t4);
             lv_anim_set_values(&ani_arr[2], lv_obj_get_x(t4),lv_obj_get_x(t4)+250-180);
        }
        else if (*cur_focus_num == 2)
        {
            lv_anim_set_var(&ani_arr[0], t3);
             lv_anim_set_values(&ani_arr[0], lv_obj_get_x(t3),lv_obj_get_x(t3)+250-180);

            lv_anim_set_var(&ani_arr[1], t4);
             lv_anim_set_values(&ani_arr[1], lv_obj_get_x(t4),lv_obj_get_x(t4)+250-180);
        }
        else if (*cur_focus_num == 3)
        {
            lv_anim_set_var(&ani_arr[0], t4);
             lv_anim_set_values(&ani_arr[0], lv_obj_get_x(t4),lv_obj_get_x(t4)+250-180);
        }

        for (int i = 0; i < ani_num; i++)
        {
        lv_anim_start(&ani_arr[i]);
     
        }
    }
    else
    {

    }
}

void Draft()
{

    // lvgl_example();

#if 1
    t1 = lv_obj_create(lv_scr_act());
    lv_obj_set_pos(t1, 100, 100);
    lv_obj_set_size(t1, 180, 100);

    // todo style  transition
    t2 = lv_obj_create(lv_scr_act());
    t3 = lv_obj_create(lv_scr_act());
    t4 = lv_obj_create(lv_scr_act());

    lv_obj_set_size(t2, 180, 100);
    lv_obj_set_size(t3, 180, 100);
    lv_obj_set_size(t4, 180, 100);

    lv_obj_align_to(t2, t1, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_align_to(t3, t2, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_align_to(t4, t3, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

    lv_obj_t *text_1 = lv_label_create(t1);
    lv_obj_t *text_2 = lv_label_create(t2);
    lv_obj_t *text_3 = lv_label_create(t3);
    lv_obj_t *text_4 = lv_label_create(t4);

    lv_obj_center(text_1);
    lv_obj_center(text_2);
    lv_obj_center(text_3);
    lv_obj_center(text_4);

    lv_label_set_text(text_1, "T1");
    lv_label_set_text(text_2, "T2");
    lv_label_set_text(text_3, "T3");
    lv_label_set_text(text_4, "T4");

    lv_obj_update_layout(t1);
    lv_obj_update_layout(t2);
    lv_obj_update_layout(t3);
    lv_obj_update_layout(t4);

    const lv_coord_t base_y = lv_obj_get_y(t1);

    // style是类似的只不过它可以被应用于不同的对象，所以这里只需要有两个Sty 一个扩大状态，一个缩小状态
    static lv_style_t sty_pr;
    static lv_style_t sty_def;

    lv_style_init(&sty_pr);
    lv_style_init(&sty_def);

    // 默认状态
    lv_style_set_border_color(&sty_def, lv_color_hex(0x808080));
    lv_style_set_border_width(&sty_def, 1);
    lv_style_set_width(&sty_def, 180);
    lv_style_set_height(&sty_def, 100);
    lv_style_set_y(&sty_def, base_y);
    lv_style_set_border_side(&sty_def, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);

    // 扩大状态
    lv_style_set_border_color(&sty_pr, lv_color_hex(0x808080));
    lv_style_set_border_width(&sty_pr, 5);
    lv_style_set_width(&sty_pr, 250);
    lv_style_set_height(&sty_pr, 110);
    lv_style_set_y(&sty_pr, base_y - 5);
    lv_style_set_border_side(&sty_pr, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);

    // 这里面变化的对象是默认状态和按下状态的 集合
    static const lv_style_prop_t style_props[] = {LV_STYLE_BORDER_COLOR, LV_STYLE_HEIGHT, LV_STYLE_Y,
                                                  LV_STYLE_BORDER_WIDTH, LV_STYLE_WIDTH, 0};

    static lv_style_transition_dsc_t transition_pr;
    static lv_style_transition_dsc_t transition_def;
    // lv_anim_path_bounce
    lv_style_transition_dsc_init(&transition_pr, style_props, lv_anim_path_linear, 250, 0, NULL);
    lv_style_set_transition(&sty_pr, &transition_pr);

    // lv_anim_path_bounce
    lv_style_transition_dsc_init(&transition_def, style_props, lv_anim_path_linear, 250, 0, NULL);
    lv_style_set_transition(&sty_def, &transition_def);

    lv_obj_add_style(t1, &sty_pr, LV_STATE_FOCUSED);
    lv_obj_add_style(t2, &sty_pr, LV_STATE_FOCUSED);
    lv_obj_add_style(t3, &sty_pr, LV_STATE_FOCUSED);
    lv_obj_add_style(t4, &sty_pr, LV_STATE_FOCUSED);

    lv_obj_add_style(t1, &sty_def, LV_STATE_DEFAULT);
    lv_obj_add_style(t2, &sty_def, LV_STATE_DEFAULT);
    lv_obj_add_style(t3, &sty_def, LV_STATE_DEFAULT);
    lv_obj_add_style(t4, &sty_def, LV_STATE_DEFAULT);

#endif
    // 节点要对应序号，这样才能方便管理
    static int t1_node_num = 1;
    static int t2_node_num = 2;
    static int t3_node_num = 3;
    static int t4_node_num = 4;
    lv_obj_add_event_cb(t1, Draft_CB, LV_EVENT_CLICKED, (void *)&t1_node_num);
    lv_obj_add_event_cb(t2, Draft_CB, LV_EVENT_CLICKED, (void *)&t2_node_num);
    lv_obj_add_event_cb(t3, Draft_CB, LV_EVENT_CLICKED, (void *)&t3_node_num);
    lv_obj_add_event_cb(t4, Draft_CB, LV_EVENT_CLICKED, (void *)&t4_node_num);

#if 0 // 光晕的效果并没有那么好做，还是直接贴图比较实际
    lv_obj_center(t1);
    lv_obj_set_size(t1, 480, 320);

    lv_obj_t *circle = lv_obj_create(t1);                                    // 创建一个新的对象
    lv_obj_set_size(circle, 100, 100);                                       // 设置对象的大小
    lv_obj_center(circle);                  // 将圆形居中显示
    // lv_obj_set_style_bg_color(circle,lv_color_hex(0xffffff),0);         // 设置圆形的背景色
    // lv_obj_set_style_border_width(circle,0, 0);              // 将边框宽度设置为0，使其变为圆形
    // lv_obj_set_style_radius(circle,LV_RADIUS_CIRCLE,0);     // 将圆形的半径设置为半宽度

    static lv_style_t sty1;

    lv_style_init(&sty1);

    lv_style_set_border_color(&sty1, lv_color_hex(0x0000ff));
    lv_style_set_shadow_color(&sty1, lv_color_hex(0xff0000));
    lv_style_set_shadow_spread(&sty1, 30);
    lv_style_set_shadow_width(&sty1, 30);
    lv_style_set_shadow_ofs_x(&sty1, 15);
    lv_style_set_shadow_opa(&sty1, LV_OPA_50);

    lv_style_set_bg_color(&sty1, lv_color_hex(0x000000));

    lv_obj_add_style(t1, &sty1, 0);

    static lv_style_t sty2;

    lv_style_init(&sty2);
    lv_style_set_border_color(&sty2, lv_color_hex(0xffffff));
    lv_style_set_shadow_color(&sty2, lv_color_hex(0xe0e0e0));
    lv_style_set_shadow_spread(&sty2,5);
    lv_style_set_shadow_width(&sty2,10);
    lv_style_set_border_width(&sty2,1);
    lv_style_set_shadow_opa(&sty1, LV_OPA_50);
    lv_obj_add_style(circle, &sty2, 0);
#endif
}
#endif

#if 0 
//!事件的冒泡传递 第一获得事件处理权的是 子对象，而不是父对象
#include "lvgl/lvgl.h"

// 子对象的点击事件处理函数
static lv_res_t child_obj_event_cb(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED) {
        printf("Child object clicked, pass event to parent!\n");
        return LV_RES_INV;  // 返回LV_RES_INV，将事件传递给父对象处理
    }

    return LV_RES_OK;
}

// 父对象的点击事件处理函数
static lv_res_t parent_obj_event_cb(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED) {
        printf("Parent object clicked!\n");
    }

    return LV_RES_OK;
}

int TestFile_T1(void)
{
    // 进行LVGL和其他初始化操作

    lv_obj_t *parent_obj = lv_obj_create(lv_scr_act());  // 创建父对象
    lv_obj_add_event_cb(parent_obj,parent_obj_event_cb,LV_EVENT_ALL,NULL);
    

    lv_obj_t *child_obj = lv_obj_create(parent_obj);  // 创建子对象，并将其设置为父对象的子对象
     lv_obj_add_event_cb(child_obj,child_obj_event_cb,LV_EVENT_ALL,NULL);
     lv_obj_add_flag(child_obj,LV_OBJ_FLAG_EVENT_BUBBLE);
  
    return 0;
}
#endif
#if 0
//!探索一下 event state 之间的关系
static lv_obj_t* t1;
static lv_obj_t* t2;

static int trigger_num=0;


static void T1CB(lv_event_t* event)
{
trigger_num++;
printf("trigger_num %d , event code %d\n",trigger_num,event->code);
}

void TestEventAndState()
{
    t1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(t1,200,200);
    lv_obj_t *text1 = lv_label_create(t1);
    lv_obj_center(text1);
    lv_label_set_text(text1,"t1");

//* 这种写法会触发两次
    // lv_obj_add_event_cb( t1,T1CB,LV_EVENT_CLICKED ,NULL);
    // lv_obj_add_event_cb( t1,T1CB,LV_EVENT_RELEASED,NULL);
 
 //! lv_obj_add_event_cb( t1,T1CB,LV_EVENT_PRESSING | LV_EVENT_LONG_PRESSED,NULL);

 //! LV_EVENT_PRESSING | LV_EVENT_LONG_PRESSED = 7; 
 //这里是他们的按位或的关系 所以这种写法是   LV_EVENT_PRESSING | LV_EVENT_LONG_PRESSED == LV_EVENT_CLICKED
 //并不是我们想的那种 LV_EVENT_PRESSING 和 LV_EVENT_LONG_PRESSED 都可以进入函数的
//*下面这种写法才是
   lv_obj_add_event_cb( t1,T1CB,LV_EVENT_LONG_PRESSED ,NULL);
   lv_obj_add_event_cb( t1,T1CB,LV_EVENT_PRESSING,NULL);

}
#endif

#if 0 // TMD user_data  和 param 是两回事

static lv_obj_t*   g_obj;

uint32_t CustomEventCode ;

static void Test_GotCustomEventCB(lv_event_t* event);
static void T1CB(lv_event_t* event);

static int container;

int var = 1;

void  TestCustomEvent()
{

    g_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(g_obj,400,400);

 
    lv_obj_t *text1 = lv_obj_create(g_obj);
    lv_obj_set_align(text1,LV_ALIGN_BOTTOM_RIGHT);
 
    CustomEventCode = lv_event_register_id();

    printf("CustomEventCode -> %d\n",CustomEventCode);

    container =10;

   //lv_obj_add_event_cb( g_obj,Test_GotCustomEventCB, CustomEventCode ,(void*)&container);
   lv_obj_add_event_cb( text1,T1CB,LV_EVENT_CLICKED,NULL);

}
static void Test_GotCustomEventCB(lv_event_t* event)
{
    int *p = (int*)event->user_data;

    printf("Got event code %d  user_data %d \n",event->code,*p);

}
static void T1CB(lv_event_t* event)
{
    
  lv_obj_add_event_cb(g_obj,Test_GotCustomEventCB, CustomEventCode ,(void*)&var);

   lv_event_send(g_obj,CustomEventCode,(void*)&var);    
}

// 是的，如果您需要将多个不同的值传递给 g_obj 对象，您需要多次调用 lv_obj_add_event_cb() 来绑定不同的用户数据。

// 每次调用 lv_obj_add_event_cb()，您可以传递不同的用户数据作为第四个参数。这样，在触发自定义事件时，您可以在相应的事件处理函数中访问不同的用户数据。

// 以下是示例代码，展示了如何将多个值传递给 g_obj 对象：

// lv_obj_add_event_cb(g_obj, Test_GotCustomEventCB1, CustomEventCode1, (void *)&var1);
// lv_obj_add_event_cb(g_obj, Test_GotCustomEventCB2, CustomEventCode2, (void *)&var2);
// lv_obj_add_event_cb(g_obj, Test_GotCustomEventCB3, CustomEventCode3, (void *)&var3);
// // 添加更多的事件处理函数和对应的用户数据
// 在上面的示例中，您调用了 lv_obj_add_event_cb() 三次，并为每个事件处理函数提供了不同的用户数据。这样，当这些自定义事件被触发时，相应的事件处理函数会收到不同的用户数据，并能够访问它们。

// 请注意，在使用这些用户数据时，您需要相应地在事件处理函数中进行强制类型转换，以便正确地访问和使用这些值。

// 因此，您可以多次调用 lv_obj_add_event_cb() 来将不同的值传递给 g_obj 对象，并确保在相应的事件处理函数中使用正确的用户数据。

#endif

static lv_obj_t *scr_a;
static lv_obj_t *scr_b;

static TestFile_ChangeScrCB(lv_event_t *event);

// 屏幕切换
#if 0
 
void TestFile_ScrB()
{

    scr_b = lv_obj_create(lv_scr_act());
    lv_obj_set_size(scr_b, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(scr_b,lv_color_hex(0xff0000), 0);
  
     lv_scr_load_anim(scr_b, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 700, 0, 0);
}

void TestFile_TestScr()
{
    scr_a = lv_obj_create(lv_scr_act());
    lv_obj_set_size(scr_a, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(scr_a,lv_color_hex(0x00ff00), 0);

    lv_obj_add_event_cb(scr_a, TestFile_ChangeScrCB, LV_EVENT_CLICKED, NULL);

}
static TestFile_ChangeScrCB(lv_event_t *event)
{
    TestFile_ScrB();
}

#endif

// 创建图像并设置调色板
void create_image_with_palette(void)
{
    // // 创建图像对象
    // lv_obj_t *img = lv_img_create(lv_scr_act());
    // lv_obj_set_pos(img, 50, 50);
    // // 分配图像缓冲区
    // lv_img_dsc_t img_dsc;
    // lv_img_buf_t img_buf;
    // lv_img_buf_init(&img_buf, buf, NULL, 100 * 100, LV_IMG_CF_INDEXED_1BIT);
    // // 设置调色板
    // lv_img_buf_set_palette(&img_buf, palette, LV_ARRAY_SIZE(palette));
    // // 设置图像对象的图像缓冲区和大小
    // lv_img_set_src(img, &img_dsc);
    // lv_img_set_size(img, 100, 100);
    // lv_palette_main()  // 0 - 19 的值
    // lv_palette_darken()  // 1-4 4个级别
    // lv_img_buf_set_palette
}

// Define palette colors
// const lv_color_t  palette[] = {
//     LV_COLOR_MAKE(0x00, 0x00, 0x00), // Black
//     LV_COLOR_MAKE(0xFF, 0x00, 0x00), // Red
//     LV_COLOR_MAKE(0x00, 0xFF, 0x00), // Green
//     LV_COLOR_MAKE(0x00, 0x00, 0xFF), // Blue
//     LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)  // White
// };

//! 了解 lv_img 的格式
LV_IMG_DECLARE(TCLUT);
LV_IMG_DECLARE(wjc_pause)

//! 第一步是要准备好你的调色板，调色板就是你准备画的图的所有颜色来源
lv_color_t* palette;

uint8_t my_img_data[7200] = {0};

static lv_img_dsc_t my_img_dsc = {
    .header.always_zero = 0,
    .header.w = 60,
    .header.h = 60,
    .data_size = 60 * 60 * LV_COLOR_DEPTH / 8,
    .header.cf = LV_IMG_CF_INDEXED_8BIT, /*Set the color format 意味着有256色*/ 
    .data = my_img_data,
};

  
// Create an image manually with palette
void create_image_with_palette_1(void)
{
    //初始化颜色表
    palette = lv_malloc(3 * sizeof(lv_color_t));//调色板最多可以有256颜色，我这里只用三个
    
    palette[0] = lv_palette_main(LV_PALETTE_RED);
    palette[1] = lv_palette_main(LV_PALETTE_YELLOW);
    palette[2] = lv_palette_main(LV_PALETTE_RED);


    static int img_data_index=0;
 
    lv_obj_t *img = lv_img_create(lv_scr_act());
    for (int y = 0; y < 60; y++)
    {
        for (int x = 0; x < 60; x++)
        {
        //     // Set index color (0 to 4) based on pixel coordinates
        //     uint8_t color_index = (x + y) % 5;
        //     // Set the pixel color using the palette
        //     //my_img_data[img_data_index++] = palette[color_index];
            
        //     // my_img_data[img_data_index++] =0x00;
 
        //    // my_img_data[img_data_index++] =(x*y)%50;

       // lv_img_buf_set_palette(my_img_data,0,palette[2]);

        // //! what fuck 竟然有这个 9.0不支持了
           // lv_img_buf_set_px_color(&my_img_dsc,x,y,lv_color_black() );
        //  img_data_index++;
 
        }
    }
    // lv_img_set_src(img,&TCLUT);
    // lv_color_t c = lv_palette_main(x%18) ;

    // lv_color_t c;
    // c.ch.blue=0x99;
    // c.ch.green=0x66;
    // c.ch.red=0x88;
    //  lv_color32_t c32;
    // c32.full      = lv_color_to32(c);
 
     lv_img_buf_set_palette(my_img_data,0,palette[2]);
     lv_img_set_src(img,&my_img_dsc);
 



}

#endif // __TESTFILE_H__

/**
 * @brief  
 
 * 
 */