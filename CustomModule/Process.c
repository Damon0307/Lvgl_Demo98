
#include "Process.h"
#include "Util.h"
#include <stdlib.h>

static const int def_width = 160;
static const int def_height = 120;
static const int def_y = 20;
static const int def_border_width = 1;


static const int name_y = 5;
static const int tte_y = def_height - 25;

static const int expand_width = 200;
static const int expand_height = 140;
static const int expand_y = 10;
static const int expand_border_width = 10;

static const int ani_time = 200;

static ProcessSty process_expand_sty;
static ProcessSty process_def_sty;

LV_IMG_DECLARE(pstart1);

static void EventCB4Child(lv_event_t *e)
{
 // printf("Got event code %d\n", e->code);

  if (e->code == LV_EVENT_CLICKED || e->code == LV_EVENT_PRESSED)
  {
     lv_obj_add_state(e->target, LV_EVENT_CLICKED);
  }
  else if (e->code == LV_EVENT_DEFOCUSED)
  {
   lv_obj_add_state(e->target, LV_STATE_DEFAULT); 
  }

}

// 对process 进行默认的style 配置
static void InitProcessSty()
{

  lv_style_init(&process_def_sty.base_sty);
  lv_style_init(&process_def_sty.img_src_sty);
  lv_style_init(&process_def_sty.name_sty);
  lv_style_init(&process_def_sty.tte_sty);
  lv_style_init(&process_def_sty.img_qs_sty);


  lv_style_init(&process_expand_sty.base_sty);
  lv_style_init(&process_expand_sty.img_src_sty);
  lv_style_init(&process_expand_sty.name_sty);
  lv_style_init(&process_expand_sty.tte_sty);
  lv_style_init(&process_expand_sty.img_qs_sty);

  // 集合， 扩大和缩小状态都会用到的属性集合 但是这个是单一style ,需不需要搞多个？
  static const lv_style_prop_t trans_props[] = {
      LV_STYLE_BORDER_COLOR,
      LV_STYLE_WIDTH,
      LV_STYLE_Y,
      LV_STYLE_X,
      LV_STYLE_BG_COLOR,
      LV_STYLE_HEIGHT,
      LV_STYLE_BORDER_WIDTH,
      LV_STYLE_OPA,
      0,
  };

  static lv_style_transition_dsc_t trans_expand;
  static lv_style_transition_dsc_t trans_def;

  //*默认状态
  // base
  //  lv_style_set_bg_color(&process_def_sty.base_sty, lv_color_hex(0xc0c0c0));
  //  lv_style_set_opa(&process_def_sty.base_sty,LV_OPA_80);

  lv_style_set_border_color(&process_def_sty.base_sty, lv_color_hex(0xe0e0e0));
  lv_style_set_border_width(&process_def_sty.base_sty, def_border_width);
  lv_style_set_y(&process_def_sty.base_sty, def_y);
  lv_style_set_width(&process_def_sty.base_sty, def_width);
  lv_style_set_height(&process_def_sty.base_sty, def_height);
  lv_style_set_border_side(&process_def_sty.base_sty, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);

  // name
  lv_style_set_align(&process_def_sty.name_sty, LV_ALIGN_TOP_MID);
  lv_style_set_y(&process_def_sty.name_sty, name_y);

  // tte
  lv_style_set_align(&process_def_sty.tte_sty, LV_ALIGN_TOP_MID);
  lv_style_set_y(&process_def_sty.tte_sty, tte_y);

  //img_src
  lv_style_set_align(&process_def_sty.img_src_sty, LV_ALIGN_CENTER);
  lv_style_set_x(&process_def_sty.img_src_sty,0);

  //img_qs
  lv_style_set_opa(&process_def_sty.img_qs_sty,LV_OPA_0);

 
  lv_style_transition_dsc_init(&trans_def, trans_props, lv_anim_path_linear, ani_time, 0, 0);
  lv_style_set_transition(&process_def_sty.base_sty, &trans_def);
  lv_style_set_transition(&process_def_sty.tte_sty, &trans_def);
  lv_style_set_transition(&process_def_sty.name_sty, &trans_def);
  lv_style_set_transition(&process_def_sty.img_src_sty, &trans_def);
  lv_style_set_transition(&process_def_sty.img_qs_sty, &trans_def);

  //*放大状态
  // lv_style_set_bg_color(&process_def_sty.base_sty, lv_color_hex(0xffffff));
  // lv_style_set_opa(&process_def_sty.base_sty,LV_OPA_100);

  lv_style_set_border_color(&process_expand_sty.base_sty, lv_color_hex(0x757575));
  lv_style_set_border_width(&process_expand_sty.base_sty, expand_border_width);
  lv_style_set_width(&process_expand_sty.base_sty, expand_width);
  lv_style_set_height(&process_expand_sty.base_sty, expand_height);
  lv_style_set_y(&process_expand_sty.base_sty, expand_y);

  //*name  先设置对齐再设置偏移，也是奇了怪了
  lv_style_set_align(&process_expand_sty.name_sty, LV_ALIGN_TOP_MID);
  lv_style_set_x(&process_expand_sty.name_sty, -40);
  lv_style_set_y(&process_expand_sty.name_sty, name_y);
  // tte
  lv_style_set_align(&process_expand_sty.tte_sty, LV_ALIGN_TOP_MID);
  lv_style_set_x(&process_expand_sty.tte_sty, -40);
  lv_style_set_y(&process_expand_sty.tte_sty, tte_y);

  //img_src
  lv_style_set_align(&process_expand_sty.img_src_sty, LV_ALIGN_CENTER);
  lv_style_set_x(&process_expand_sty.img_src_sty,-40);

  //img_qs
  lv_style_set_opa(&process_expand_sty.img_qs_sty,LV_OPA_100);


  lv_style_set_border_side(&process_expand_sty.base_sty, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT);
  lv_style_transition_dsc_init(&trans_expand, trans_props, lv_anim_path_linear, ani_time, 0, 0);
  // 把style 绑定到这条船上
  lv_style_set_transition(&process_expand_sty.base_sty, &trans_expand);
  lv_style_set_transition(&process_expand_sty.name_sty, &trans_expand);
  lv_style_set_transition(&process_expand_sty.tte_sty, &trans_expand);
  lv_style_set_transition(&process_expand_sty.img_src_sty, &trans_expand);
  lv_style_set_transition(&process_expand_sty.img_qs_sty, &trans_expand); 

}

void Process_SetStyle(Process *this, ProcessSty *p_process_sty)
{
  // todo
  // this->process_sty = p_process_sty;
}

void Process_Init(Process *this, lv_obj_t *parent, int p_tte, char *p_name, void *p_img_src, int node_num)
{
  if (parent != NULL)
  {
    this->base = lv_obj_create(parent);
//*加了这个事件才能冒泡传递
 // lv_obj_add_flag(this->base,LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_set_y(this->base, 20);

    lv_obj_set_size(this->base, def_width, def_height);
  }
  else
  {
    printf("parent NULL\n");
  }
  this->name = lv_label_create(this->base);
  this->tte = lv_label_create(this->base);
  this->img_src = lv_img_create(this->base);
  this->node_num = node_num;

  this->img_qs = lv_img_create(this->base);

  
  //样式中并不能控制对象的显示与隐藏（OPA)
  // lv_obj_add_flag(this->img_qs, LV_OBJ_FLAG_HIDDEN);
 
  //*更灵活的状态是可以接受外界设置内部的style属性
  // this->process_sty=&process_def_sty;

  InitProcessSty();

  lv_label_set_text_fmt(this->name, "%s", p_name);
  lv_label_set_text_fmt(this->tte, "%d", p_tte);
  lv_img_set_src(this->img_src, p_img_src);
  lv_img_set_src(this->img_qs, &pstart1);
  lv_obj_set_style_pad_all(this->base, 0, 0);

  lv_obj_center(this->img_src);
  lv_obj_center(this->img_qs);

 
   lv_obj_set_x(this->img_qs,45);
  //  lv_obj_set_style_opa(this->img_qs,LV_OPA_10,LV_PART_MAIN);

  lv_obj_add_event_cb(this->name, EventCB4Child, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(this->tte, EventCB4Child, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(this->img_src, EventCB4Child, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(this->img_qs, EventCB4Child, LV_EVENT_CLICKED, NULL);

  
  lv_obj_add_style(this->base, &process_def_sty.base_sty, LV_STATE_DEFAULT);
  lv_obj_add_style(this->name, &process_def_sty.name_sty, LV_STATE_DEFAULT); 
  lv_obj_add_style(this->tte, &process_def_sty.tte_sty, LV_STATE_DEFAULT);
  lv_obj_add_style(this->img_src, &process_def_sty.img_src_sty, LV_STATE_DEFAULT);
  lv_obj_add_style(this->img_qs, &process_def_sty.img_qs_sty, LV_STATE_DEFAULT);
 
  lv_obj_add_style(this->base, &process_expand_sty.base_sty, LV_EVENT_CLICKED);
  lv_obj_add_style(this->name, &process_expand_sty.name_sty, LV_EVENT_CLICKED);
  lv_obj_add_style(this->tte, &process_expand_sty.tte_sty, LV_EVENT_CLICKED);
  lv_obj_add_style(this->img_src, &process_expand_sty.img_src_sty, LV_EVENT_CLICKED);
  lv_obj_add_style(this->img_qs, &process_expand_sty.img_qs_sty, LV_EVENT_CLICKED);

  this->expand_flag=false;
 
}

int Process_GetNodeNum(Process *this)
{
  return this->node_num;
}
 