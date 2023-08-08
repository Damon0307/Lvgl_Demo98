#ifndef __UTIL_H__
#define __UTIL_H__
// 工具类
#include <stdio.h>
#include "../lvgl/lvgl.h"

/// @brief 获取对象默认状态下的文本长度
/// @param obj
/// @return

int GetObjTestWidth(lv_obj_t *p_obj);

lv_point_t Util_GetTouchPoint(void);


#endif // __UTIL_H__