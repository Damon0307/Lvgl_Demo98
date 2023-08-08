#include "ProcessList.h"
#include "DemoInfoDef.h"


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

LV_IMG_DECLARE(cy);
LV_IMG_DECLARE(ds);
LV_IMG_DECLARE(etdx);
LV_IMG_DECLARE(jf);
LV_IMG_DECLARE(mj);
LV_IMG_DECLARE(ssf);
LV_IMG_DECLARE(yj);
LV_IMG_DECLARE(yms);
LV_IMG_DECLARE(yrf);
LV_IMG_DECLARE(zbww);

 
extern uint32_t EVENT_CHANGE_SCREEN;
extern lv_obj_t* g_scr;
static EventScreenChangeReq PL_EScrChangeReq;
 
#define PROCESS_NUM   10

typedef struct
{
    const char *name;
    int tte;
    void *img_src;
} ProcessInfo;

typedef struct
{
   lv_obj_t* base;
   Process* process_list[PROCESS_NUM];
}ProcessList;

static void ProcessList_AddProcess(ProcessList* this,Process* p_item);

static ProcessList s_processlist;

static int pl_scroll_x_offset = 0;
static int space = 5; // 节点之间的间距

static  lv_obj_t* m_scr;

static ProcessInfo arr_process_info[PROCESS_NUM] = {
    {"Shirt", 30, (void *)&cy},
    {"Timing", 60, (void *)&ds},
    {"Kid's Shirt", 80, (void *)&etdx},
    {"Home Textiles", 120, (void *)&jf},
    {"Towel", 36, (void *)&mj},
    {"Sailor Suit", 60, (void *)&ssf},
    {"Night", 60, (void *)&yj},
    {"Woolen", 45, (void *)&yms},
    {"Down", 120, (void *)&yrf},
    {"Toy", 60, (void *)&zbww},
};

static bool ProcessTouchArea(lv_obj_t *obj, int node_num); // 判断节点点击的区域
static void Process_FocusedCB(lv_event_t *e);
static void Process_DefocusCB(lv_event_t *e);

static int ani_time = 200;

static void PLReorderNodeCB(void *var, int32_t v)
{
    lv_obj_set_pos((lv_obj_t *)var, v, lv_obj_get_y((lv_obj_t *)var));
}

static lv_timer_t *debug_timer;
static int debug_param = 0;
static void TimerCB4Debug(lv_timer_t *timer)
{

    int *p = (int *)timer->user_data;
    printf("Defocus num %d y %d  state %d\n", *p, lv_obj_get_y(s_processlist.process_list[*p - 1]->base),
           lv_obj_get_state(s_processlist.process_list[*p - 1]->base));
}
static void anim_y_cb(void *var, int32_t v)
{
    lv_obj_set_y(var, v);
}

// 处理点击后的列表排列问题
static void PLDealTouch(int expand_num)
{
    // X 轴变化的大小是40+10（border width）
    static int ani_var_x = 40 + 0;
    static int cur_expand_num = 0;

    static lv_anim_t *ani_arr;
    int ani_num = 0;
    // 计算该次点击影响到的节点数量
    if (cur_expand_num == 0)
    { // 当前无节点扩大
        ani_num = PROCESS_NUM - expand_num;
        if (ani_num != 0)
        {
            ani_arr = lv_malloc(ani_num * sizeof(lv_anim_t));
        }
        else
        {
            printf("No ani trigger will return \n");
            return;
        }

        for (int i = 0; i < ani_num; i++)
        {
            lv_anim_init(&ani_arr[i]);
            lv_anim_set_time(&ani_arr[i], ani_time);
            lv_anim_set_path_cb(&ani_arr[i], lv_anim_path_linear);
            lv_anim_set_exec_cb(&ani_arr[i], PLReorderNodeCB);
        }
        int ani_arr_pos = 0;
        for (int i = expand_num; i < PROCESS_NUM; i++)
        {

            lv_obj_t *t = s_processlist.process_list[i]->base;
            int x_start = (int)lv_obj_get_x(t);
            int x_stop = (int)lv_obj_get_x(t) + ani_var_x;
            lv_anim_set_var(&ani_arr[ani_arr_pos], t);
            lv_anim_set_values(&ani_arr[ani_arr_pos], x_start, x_stop);
            ani_arr_pos++;
        }
    }
    else
    {
        // 当前有节点扩大
        ani_num = abs(ani_num = expand_num - cur_expand_num);
        if (ani_num != 0)
        {
            ani_arr = lv_malloc(ani_num * sizeof(lv_anim_t));
        }
        else
        { // 没有任何一个节点聚焦，且点击到了最后一个则没有动画
          //  printf("No ani trigger will return? \n");
            return;
        }
        for (int i = 0; i < ani_num; i++)
        {
            lv_anim_init(&ani_arr[i]);
            lv_anim_set_time(&ani_arr[i], ani_time);
            lv_anim_set_path_cb(&ani_arr[i], lv_anim_path_linear);
            lv_anim_set_exec_cb(&ani_arr[i], PLReorderNodeCB);
        }

        if (expand_num > cur_expand_num) // 新点击的节点在当前扩大节点的右边
        {
            int ani_arr_pos = 0;
            for (int i = cur_expand_num; i < expand_num; i++)
            {
                lv_obj_t *t = s_processlist.process_list[i]->base;
                lv_anim_set_var(&ani_arr[ani_arr_pos], t);
                lv_anim_set_values(&ani_arr[ani_arr_pos], lv_obj_get_x(t), lv_obj_get_x(t) - ani_var_x);
                ani_arr_pos++;
            }
        }
        else
        { // 新点击的节点在当前扩大节点的左边
            int ani_arr_pos = 0;
            for (int i = expand_num; i < cur_expand_num; i++)
            {
                lv_obj_t *t = s_processlist.process_list[i]->base;
                lv_anim_set_var(&ani_arr[ani_arr_pos], t);
                lv_anim_set_values(&ani_arr[ani_arr_pos], lv_obj_get_x(t), lv_obj_get_x(t) + ani_var_x);
                ani_arr_pos++;
            }
        }
    }
    // 更新当前扩大节点的值
    cur_expand_num = expand_num;

    for (int i = 0; i < ani_num; i++)
    {
        lv_anim_start(&ani_arr[i]);
    }
    if (NULL != ani_arr || ani_num != 0)
    {
        lv_free(ani_arr);
    }
}

static void PLScrollCB(lv_event_t *event)
{
    // printf("PLScrollCB.....event->code %d\n",event->code);
    pl_scroll_x_offset = (int)lv_obj_get_scroll_x(event->current_target);
}

  
void ProcessList_AddProcess(ProcessList *this, Process *p_item)
{
    static int seq = 0;

    if (seq < PROCESS_NUM)
    {
        // 排列一下UI顺序
        lv_obj_update_layout(p_item->base); //! 需要手动刷新一下这个对象，不然获取到的是0
        lv_coord_t width = lv_obj_get_width(p_item->base);
        int px = (int)width;
        int cur_x = (seq) * (int)width + (seq)*space;
        // printf("cur_x %d\n",px);
        //! 之前是set pos
        lv_obj_set_x(p_item->base, cur_x);
        this->process_list[seq] = p_item;
        seq++;
    }
}


void PLInit(lv_obj_t* parent)
{

    m_scr = lv_scr_act();
    lv_obj_set_size(m_scr, 780, 220);
    lv_obj_set_style_bg_color(m_scr,lv_color_hex(0x000000),0);


    s_processlist.base = lv_obj_create(m_scr);
    lv_obj_center(s_processlist.base);
    lv_obj_set_size(s_processlist.base,lv_obj_get_width(m_scr),lv_obj_get_height(m_scr));
    lv_obj_set_style_bg_color(s_processlist.base, lv_color_hex(0x000000), LV_PART_MAIN);
    //! 更新X的滑动坐标方便处理点击
    lv_obj_add_event_cb(s_processlist.base, PLScrollCB, LV_EVENT_SCROLL, NULL);

    for (int i = 0; i < PROCESS_NUM; i++)
    {
        Process *p_item = (Process *)malloc(sizeof(Process));
        // Process *p_item; //!被内存教训了
        // printf("Process size %d\n",sizeof(Process));

        Process_Init(p_item, s_processlist.base, arr_process_info[i].tte, arr_process_info[i].name, arr_process_info[i].img_src, i + 1);

        ProcessList_AddProcess(&s_processlist, p_item);
        //! 注意添加的是base 而不是 p_item,而且父对象要对一些信号进行传递给子对象
        // 并且需要分开两个CB，因为是不同对象不同信号，而不是 同一对象多个信号
        lv_obj_add_event_cb(p_item->base, Process_DefocusCB, LV_EVENT_DEFOCUSED, NULL);
        lv_obj_add_event_cb(p_item->base, Process_FocusedCB, LV_EVENT_CLICKED, NULL);
        lv_obj_add_event_cb(p_item->base, Process_FocusedCB, LV_EVENT_PRESSING, NULL);
    }

    PL_EScrChangeReq.cur_scr_id=SCREEN_ID_MAIN;

    printf("--------------------------\n");
 
}
//释放资源
void PLDelete()
{
        lv_obj_clean(s_processlist.base);
        printf("PLDelete...\n ");
}

void Process_FocusedCB(lv_event_t *event)
{
    lv_obj_t *parent_obj = lv_event_get_target(event);
    lv_obj_t *child_obj;
    uint32_t i;
    int node_num = 0;
    // printf(" Focus obj event code %d\n",event->code);

    /* 获取父对象的子对象数量 */
    uint32_t child_count = lv_obj_get_child_cnt(parent_obj);

    /* 遍历子对象并将焦点事件传递给它们 */
    for (i = 0; i < child_count; i++)
    {
        child_obj = lv_obj_get_child(parent_obj, i);
        lv_event_send(child_obj, event->code, NULL);
    }
    for (int i = 0; i < PROCESS_NUM; i++)
    {
        if (event->target == s_processlist.process_list[i]->base)
        {
            // printf("obj %d  state %d \n",i,(int)lv_obj_get_state(s_processlist.process_list[i]->base));
            node_num = s_processlist.process_list[i]->node_num;
            lv_obj_add_state(s_processlist.process_list[i]->base, LV_EVENT_CLICKED);
            PLDealTouch(s_processlist.process_list[i]->node_num);
        }
    }
    if (event->code == LV_EVENT_CLICKED)
    {
        int width = (int)lv_obj_get_width(event->current_target);
       // printf("Clicked and width is -> %d\n",width);
        if (width == 200) //不能用>160 动画已经在执行
        {
            if (ProcessTouchArea(event->current_target, node_num) == true)
            {
                printf("Quick Start\n");
                PL_EScrChangeReq.go_scr_id=SCREEN_ID_RUN;
                lv_event_send(g_scr,EVENT_CHANGE_SCREEN,(void*)&PL_EScrChangeReq);
            }
            else
            {
              printf("Normal Config\n");
               PL_EScrChangeReq.go_scr_id=SCREEN_ID_CFG;
              lv_event_send(g_scr,EVENT_CHANGE_SCREEN,(void*)&PL_EScrChangeReq);
            }
        }
    }
}

//* defocus 状态
void Process_DefocusCB(lv_event_t *event)
{
    // 发生失去焦点时候，如果同时在移动则不处理
    lv_obj_t *parent_obj = lv_event_get_target(event);
    lv_obj_t *child_obj;
    uint32_t i;

    /* 获取父对象的子对象数量 */
    uint32_t child_count = lv_obj_get_child_cnt(parent_obj);

    /* 遍历子对象并将焦点事件传递给它们 */
    for (i = 0; i < child_count; i++)
    {
        child_obj = lv_obj_get_child(parent_obj, i);
        lv_event_send(child_obj, event->code, NULL);
    }
    // 当前谁失去了焦点？
    for (int i = 0; i < PROCESS_NUM; i++)
    {
        if (s_processlist.process_list[i]->base == event->target)
        {
            int y = (int)lv_obj_get_y(event->target);
            if (y == 10)
            {
                lv_obj_add_state(event->target, LV_STATE_DEFAULT);
                // printf("Node %d  Defocus The fucking y %d\n", s_processlist.process_list[i]->node_num,
                //        (int)lv_obj_get_y(event->target));
                lv_obj_set_y(event->target, 20);
                lv_anim_t a;
                lv_anim_init(&a);
                lv_anim_set_var(&a, event->target);
                lv_anim_set_values(&a, 10, 20);
                lv_anim_set_time(&a, ani_time);
                lv_anim_set_exec_cb(&a, anim_y_cb);
                lv_anim_set_path_cb(&a, lv_anim_path_linear);
                lv_anim_start(&a);
            }
        }
    }
}

// 判断当前的点击区域
static bool ProcessTouchArea(lv_obj_t *obj, int node_num)
{
    // align_x = obj_x - scroll_x - space*num
    // align_x can be compare with touch px

    int align_x = 0;
    int px;
    int py;
    int obj_x;
    int obj_y;

    lv_indev_t *indev = lv_indev_get_act(); // 获取当前正在活动的输入设备
    if (indev != NULL)
    {
        lv_point_t point;
        lv_indev_get_point(indev, &point); // 获取输入设备的坐标
                                           // 这里的 point.x 和 point.y 就是点击的坐标
        px = (int)point.x;
        py = (int)point.y;
        // 这里的坐标是基于固定的触摸设备的，和具体的对象的坐标不相关
        // printf("Touched x %d y %d\n", px, py);
    }

    obj_x = (int)lv_obj_get_x(obj); // 获取到的值是固定的
    obj_y = (int)lv_obj_get_y(obj);

    align_x = obj_x - (space * (node_num - 1)) - pl_scroll_x_offset;

    int percent = 100 * (px - align_x) / lv_obj_get_width(obj);

   // printf(" x percent %d  align x %d  px %d\n", percent, align_x, px);

    if (percent <= 50)
    {
        return false;
    }
    else
    {
        return true;
    }

    return false;
}