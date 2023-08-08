#include "../lvgl/lvgl.h"

lv_point_t Util_GetTouchPoint(void)
{
    lv_point_t point;
    int px;
    int py;
 
    lv_indev_t *indev = lv_indev_get_act(); // 获取当前正在活动的输入设备
    if (indev != NULL)
    {
     
        lv_indev_get_point(indev, &point); // 获取输入设备的坐标
                                           // 这里的 point.x 和 point.y 就是点击的坐标
        px = (int)point.x;
        py = (int)point.y;
        // 这里的坐标是基于固定的触摸设备的，和具体的对象的坐标不相关
       //   printf("Touched x %d y %d\n", px, py);
    }

    return point;
}


int GetObjTestWidth(lv_obj_t *p_obj)
{
    // 获取文本，获取所使用字体，获取行间距，获取文本标志

    const char *text = lv_label_get_text(p_obj);

    lv_font_t *font;
    font = lv_obj_get_style_text_font(p_obj, NULL);

    lv_coord_t line_space = lv_obj_get_style_text_line_space(p_obj, NULL);

    lv_text_flag_t text_flag = lv_label_get_long_mode(p_obj);

    lv_coord_t res = lv_txt_get_width(text, strlen(text), font, line_space, text_flag);

    printf("Len of label %s is %d\n", text, res);

    return (int)res;
}