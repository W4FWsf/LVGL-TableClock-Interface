
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/win32drv/win32drv.h"
#include "lvgl/examples/lv_examples.h"
#include <windows.h>


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow)
{
    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL for LittlevGL*/
    lv_win32_init(hInstance, SW_SHOWNORMAL, 320, 240, NULL);

    /*Output prompt information to the console, you can also use printf() to print directly*/
    LV_LOG_USER("LVGL initialization completed!");

/*************************************************************************************

 我们的代码

 *************************************************************************************/





/**************************************************************************************

屏幕和一些小组件，不用管

***************************************************************************************/


lv_obj_t * Screen2 = lv_obj_create(NULL);


static lv_style_t BottonToScreen2Style; // 按钮样式
    lv_style_reset(&BottonToScreen2Style); // 重置样式
    lv_style_init(&BottonToScreen2Style); // 初始化样式
    lv_style_set_radius(&BottonToScreen2Style, 0);
    lv_style_set_bg_color(&BottonToScreen2Style,lv_color_hsv_to_rgb(24,3.1,62.4));
    lv_style_set_bg_grad_dir(&BottonToScreen2Style, LV_GRAD_DIR_HOR);


static lv_style_t TextBoard; // 左栏样式
    lv_style_reset(&TextBoard); // 重置样式
    lv_style_init(&TextBoard); // 初始化样式
    lv_style_set_radius(&TextBoard, 0);
    lv_style_set_bg_color(&TextBoard,lv_color_hsv_to_rgb(32,28.8,91.4));

lv_obj_t * Screen1 = lv_obj_create(NULL);
lv_scr_load(Screen1);

lv_obj_t * BottonToScreen2 = lv_btn_create(Screen1);
lv_obj_align(BottonToScreen2, LV_ALIGN_TOP_RIGHT,0,0);
lv_obj_add_style(BottonToScreen2, &BottonToScreen2Style, LV_STATE_DEFAULT);
lv_obj_t * BottonToScreen2Lable = lv_label_create(BottonToScreen2);
lv_label_set_text(BottonToScreen2Lable, LV_SYMBOL_RIGHT);


lv_obj_t * NewsSquare = lv_obj_create(Screen2);
lv_obj_align(NewsSquare,LV_ALIGN_LEFT_MID,0,0);
lv_obj_set_size(NewsSquare,165,240);
lv_obj_add_style(NewsSquare, &TextBoard, LV_STATE_DEFAULT);


//按钮样式2
static lv_style_t BottonToScreen1Style; // 按钮样式
    lv_style_reset(&BottonToScreen1Style); // 重置样式
    lv_style_init(&BottonToScreen1Style); // 初始化样式
    lv_style_set_radius(&BottonToScreen1Style, 0);
    lv_style_set_bg_color(&BottonToScreen1Style,lv_color_hsv_to_rgb(24,3.1,62.4));
    lv_style_set_bg_grad_dir(&BottonToScreen1Style, LV_GRAD_DIR_NONE);

lv_obj_t * Battery = lv_btn_create(Screen1);
lv_obj_t * BatteryLable = lv_label_create(Battery);
lv_label_set_text(BatteryLable, LV_SYMBOL_BATTERY_FULL);
lv_obj_align(Battery,LV_ALIGN_TOP_RIGHT,-35,0);
lv_obj_add_style(Battery, &BottonToScreen1Style, LV_STATE_DEFAULT);

lv_obj_t * Volume = lv_btn_create(Screen1);
lv_obj_t * VolumeLable = lv_label_create(Volume);
lv_label_set_text(VolumeLable, LV_SYMBOL_VOLUME_MAX);
lv_obj_align(Volume,LV_ALIGN_TOP_RIGHT,-75,0);
lv_obj_add_style(Volume, &BottonToScreen1Style, LV_STATE_DEFAULT);

lv_obj_t * WIFI = lv_btn_create(Screen1);
lv_obj_t * WIFILable = lv_label_create(WIFI);
lv_label_set_text(WIFILable, LV_SYMBOL_WIFI);
lv_obj_align(WIFI,LV_ALIGN_TOP_RIGHT,-113,0);
lv_obj_add_style(WIFI, &BottonToScreen1Style, LV_STATE_DEFAULT);


//到第二块屏幕

 void ToScreen2(lv_event_t * event)
{

    printf("Clicked\n");
    lv_scr_load_anim(Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, 0);//change Screen

}

lv_obj_add_event_cb(BottonToScreen2, ToScreen2, LV_EVENT_CLICKED, NULL);

//返回第一块屏幕


lv_obj_t * BottonToScreen1 = lv_btn_create(Screen2);
lv_obj_add_style(BottonToScreen1, &BottonToScreen1Style, LV_STATE_DEFAULT);
lv_obj_t * BottonToScreen1Lable = lv_label_create(BottonToScreen1);
lv_label_set_text(BottonToScreen1Lable, LV_SYMBOL_LEFT);

 void ToScreen1(lv_event_t * event)
{

    printf("Clicked\n");
    lv_scr_load_anim(Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, 0);//change Screen
}
lv_obj_add_event_cb(BottonToScreen1, ToScreen1, LV_EVENT_CLICKED, NULL);

//第三块屏幕

lv_obj_t * Screen3 = lv_obj_create(NULL);
lv_obj_t * BottonToScreen3 = lv_btn_create(Screen2);
lv_obj_add_style(BottonToScreen3, &BottonToScreen2Style, LV_STATE_DEFAULT);
lv_obj_t * BottonToScreen3Lable = lv_label_create(BottonToScreen3);
lv_label_set_text(BottonToScreen3Lable, LV_SYMBOL_DOWN);
lv_obj_set_size(BottonToScreen3,30,15);
lv_obj_align(BottonToScreen3,LV_ALIGN_BOTTOM_MID,0,0);
lv_obj_align(BottonToScreen3Lable,LV_ALIGN_BOTTOM_MID,0,10);

 void ToScreen3(lv_event_t * event)
{

    printf("Clicked\n");
    lv_scr_load_anim(Screen3, LV_SCR_LOAD_ANIM_OUT_TOP, 200, 0, 0);//change Screen

}

lv_obj_add_event_cb(BottonToScreen3, ToScreen3, LV_EVENT_CLICKED, NULL);



/*******************************************************************************************

弹出文本，把按钮触发改为语音触发

*******************************************************************************************/

lv_obj_t * LableOnBotton = lv_btn_create(Screen2);
lv_obj_align(LableOnBotton,LV_ALIGN_CENTER,0,0);

lv_obj_t * LableBackground;
lv_obj_t * LableOffBotton;

 void my_event_OffLable(lv_event_t * event)
    {
       lv_obj_t *obj = lv_event_get_user_data(event);

        lv_obj_del(obj);
    }

static lv_style_t LableBackgroundStyle;
    lv_style_reset(&LableBackgroundStyle);
    lv_style_init(&LableBackgroundStyle);
    lv_style_set_radius(&LableBackgroundStyle, 0);
    lv_style_set_bg_opa(&LableBackgroundStyle, LV_OPA_20);
    lv_style_set_border_width(&LableBackgroundStyle, 0);
    lv_style_set_border_color(&LableBackgroundStyle, lv_color_black());
    lv_style_set_border_opa(&LableBackgroundStyle,LV_OPA_30);
    lv_style_set_bg_color(&LableBackgroundStyle, lv_color_black());
    lv_style_set_pad_left(&LableBackgroundStyle, 0);
    lv_style_set_pad_right(&LableBackgroundStyle, 0);
    lv_style_set_pad_top(&LableBackgroundStyle, 0);
    lv_style_set_pad_bottom(&LableBackgroundStyle, 0);



void my_event_OnLable(lv_event_t * event)
{

    lv_obj_t * LableBackground = lv_obj_create(Screen2);
    lv_obj_align(LableBackground,LV_ALIGN_CENTER,0,0);
    lv_obj_set_size(LableBackground,320,240);
    lv_obj_add_style(LableBackground, &LableBackgroundStyle, LV_STATE_DEFAULT);

    lv_obj_t * LableSquare = lv_obj_create(LableBackground);
    lv_obj_align(LableSquare,LV_ALIGN_CENTER,0,0);
    lv_obj_set_size(LableSquare,300,220);

    lv_obj_t * LableOut1 = lv_label_create(LableSquare);
    lv_obj_align(LableOut1, LV_ALIGN_TOP_LEFT, 0, 40);
    lv_label_set_text(LableOut1, "Day1   Weather1  temper1");//接受数据得改

    lv_obj_t * LableOut2 = lv_label_create(LableSquare);
    lv_obj_align(LableOut2, LV_ALIGN_TOP_LEFT, 0, 80);
    lv_label_set_text(LableOut2, "Day1   Weather1  temper1");//接受数据得改

    lv_obj_t * LableOut3 = lv_label_create(LableSquare);
    lv_obj_align(LableOut3, LV_ALIGN_TOP_LEFT, 0, 120);
    lv_label_set_text(LableOut3, "NEWsreport   Weather1  temper1");//接受数据得改



    lv_obj_t * LableOffBotton = lv_btn_create(LableSquare);
    lv_obj_align(LableOffBotton, LV_ALIGN_TOP_LEFT,-10,-10);

    lv_obj_t * OffLable = lv_label_create(LableOffBotton);
    lv_label_set_text(OffLable, LV_SYMBOL_CLOSE);



    lv_obj_add_event_cb(LableOffBotton, my_event_OffLable, LV_EVENT_CLICKED, LableBackground);

}


lv_obj_add_event_cb(LableOnBotton, my_event_OnLable, LV_EVENT_CLICKED, NULL);//弹窗的开关，控制开


/*******************************************************************************************

天上掉下来的时钟，不用管

********************************************************************************************/


typedef struct _lv_clock
{
    lv_obj_t *time_label; // 时间标签
    lv_obj_t *date_label; // 日期标签
    lv_obj_t *weekday_label; // 星期标签
}lv_clock_t;


void clock_date_task_callback(lv_timer_t *timer)
{

    static const char *week_day[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    static time_t unix_time;
    static struct tm *time_info;

    unix_time = time(NULL);
    time_info = localtime(&unix_time);

    int year = time_info->tm_year+1900;
    int month = time_info->tm_mon + 1;
    int day = time_info->tm_mday;
    int weekday = time_info->tm_wday;
    int hour = time_info->tm_hour;
    int minutes = time_info->tm_min;
    int second = time_info->tm_sec;

    if (timer != NULL && timer->user_data != NULL)
    {
        lv_clock_t * clock = (lv_clock_t *)(timer->user_data);
        if (clock->time_label != NULL)
        {
            lv_label_set_text_fmt(clock->time_label, "%02d:%02d:%02d", hour, minutes, second);
            lv_obj_align_to(clock->time_label, lv_obj_get_parent(clock->time_label), LV_ALIGN_CENTER, 0, 0);
        }

        if (clock->date_label != NULL)
        {
            lv_label_set_text_fmt(clock->date_label, "%d-%02d-%02d", year, month, day);
            lv_obj_align_to(clock->date_label, lv_obj_get_parent(clock->date_label), LV_ALIGN_TOP_MID, 2, 0);
        }

         if (clock->weekday_label != NULL)
         {
            lv_label_set_text_fmt(clock->weekday_label, "%s", week_day[weekday]);
            lv_obj_align_to(clock->weekday_label, lv_obj_get_parent(clock->weekday_label), LV_ALIGN_BOTTOM_MID, -2, 0);
         }
    }
}



    static lv_style_t date_time_clock_style; // 最外层对象的样式
    lv_style_reset(&date_time_clock_style); // 重置样式
    lv_style_init(&date_time_clock_style); // 初始化样式
    lv_style_set_radius(&date_time_clock_style, 0); // 设置样式圆角
    lv_style_set_bg_opa(&date_time_clock_style, LV_OPA_0); // 设置样式背景透明度
    lv_style_set_border_width(&date_time_clock_style, 0); // 设置样式边框宽度
    lv_style_set_bg_color(&date_time_clock_style, lv_color_white()); // 设置样式背景颜色，白色
    lv_style_set_pad_left(&date_time_clock_style, 1); // 设置样式左边padding填充宽度
    lv_style_set_pad_right(&date_time_clock_style, 1); // 设置样式右边padding填充宽度
    lv_style_set_pad_top(&date_time_clock_style, 0); // 设置样式顶部padding填充宽度
    lv_style_set_pad_bottom(&date_time_clock_style, 0); // 设置样式底部padding填充宽度

    static lv_style_t time_style; // 时间对象样式
    lv_style_reset(&time_style);
    lv_style_init(&time_style);
    lv_style_set_bg_opa(&time_style, LV_OPA_COVER);
    lv_style_set_border_width(&time_style, 1);
    lv_style_set_radius(&time_style, 0);
    lv_style_set_bg_color(&time_style, lv_color_hsv_to_rgb(24,3.1,62.4));
    lv_style_set_pad_left(&time_style, 0);
    lv_style_set_pad_right(&time_style, 0);
    lv_style_set_pad_top(&time_style, 0);
    lv_style_set_pad_bottom(&time_style, 0);

    static lv_style_t date_style; // 日期对象样式
    lv_style_reset(&date_style);
    lv_style_init(&date_style);
    lv_style_set_bg_opa(&date_style, LV_OPA_COVER);
    lv_style_set_border_width(&date_style, 2);
    lv_style_set_radius(&date_style, 0);
    lv_style_set_bg_color(&date_style, lv_color_hsv_to_rgb(207,67.3,44.3));
    lv_style_set_pad_left(&date_style, 0);
    lv_style_set_pad_right(&date_style, 0);

	/* Time font */
    static lv_style_t time_label_style; // 时间标签样式
    lv_style_reset(&time_label_style); // 重置样式
    lv_style_init(&time_label_style); // 初始化样式
    lv_style_set_text_color(&time_label_style ,lv_color_hsv_to_rgb(0,0,100)); // 设置标签样式文本颜色
  //  lv_style_set_text_font(&time_label_style, LV_FONT_MONTSERRAT_36); // 设置字体大小
    lv_style_set_text_opa(&time_label_style, LV_OPA_COVER); // 设置字体透明度
    lv_style_set_bg_opa(&time_label_style, LV_OPA_0); // 设置样式背景透明度

	/* Date font */
    static lv_style_t date_label_style; // 日期标签样式
    lv_style_reset(&date_label_style);
    lv_style_init(&date_label_style);
    lv_style_set_text_opa(&date_label_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&date_label_style, LV_OPA_0);
    lv_style_set_text_color(&date_label_style , lv_color_white());
    //lv_style_set_text_font(&date_label_style, LV_FONT_MONTSERRAT_16);

	/* Week font */
    static lv_style_t week_lable_style; // 日期标签样式
    lv_style_reset(&week_lable_style);
    lv_style_init(&week_lable_style);
    lv_style_set_text_opa(&week_lable_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&week_lable_style, LV_OPA_0);
    lv_style_set_text_color(&week_lable_style, lv_color_white());
   // lv_style_set_text_font(&week_lable_style, LV_FONT_MONTSERRAT_16);

	/* Time & Date */
    lv_obj_t *time_date_obj = lv_obj_create(lv_scr_act()); // 基于屏幕创建时间日期对象
    if (time_date_obj == NULL)
    {
        printf("[%s:%d] time_date_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }

	lv_obj_set_size(time_date_obj, 250, 150); // 设置对象大小
    lv_obj_align(time_date_obj,LV_ALIGN_TOP_LEFT,-75,-10);
	lv_obj_add_style(time_date_obj, &date_time_clock_style, LV_STATE_DEFAULT); //给time_date_obj对象添加样式

    /*Time display*/
    lv_obj_t *time_obj = lv_obj_create(Screen1); // 基于time_date_obj对象创建时间对象
    if (time_obj == NULL)
    {
        printf("[%s:%d] time_obj create failed\n", __FUNCTION__, __LINE__);
        return;
    }

    lv_obj_set_size(time_obj, 164, 25); // 设置对象大小
    lv_obj_align_to(time_obj, Screen1, LV_ALIGN_TOP_LEFT, -2, 0);
    lv_obj_add_style(time_obj, &time_style, LV_STATE_DEFAULT);  // 给time_obj对象添加样式

    static lv_clock_t lv_clock = { 0 };

    lv_clock.time_label = lv_label_create(time_obj); // 基于time_obj对象创建时间显示标签对象 lv_clock.time_label
    if (lv_clock.time_label == NULL)
    {
        printf("[%s:%d] time_label create failed\n", __FUNCTION__, __LINE__);
        return ;
    }

    lv_obj_add_style(lv_clock.time_label, &time_label_style, LV_STATE_DEFAULT); // 给对象 lv_clock.time_label添加样式

    /*Date display*/
    lv_obj_t *date_obj = lv_obj_create(time_date_obj); // 基于time_date_obj对象创建date_obj对象
    if (date_obj == NULL)
    {
        printf("[%s:%d] date_obj create failed\n", __FUNCTION__, __LINE__);
        return ;
    }
    lv_obj_set_size(date_obj, 165, 60); // 设置对象大小
    lv_obj_align_to(date_obj, time_date_obj, LV_ALIGN_RIGHT_MID, -11, -15); //设置date_obj对象基于time_date_obj对象右边中部对齐
    lv_obj_add_style(date_obj, &date_style, LV_STATE_DEFAULT); // 给date_obj对象添加样式

    lv_clock.date_label = lv_label_create(date_obj); // 基于date_obj对象创建lv_clock.date_label日期显示对象
    if (lv_clock.date_label == NULL)
    {
        printf("[%s:%d] date_label create failed\n", __FUNCTION__, __LINE__);
        return ;
    }
    lv_obj_add_style(lv_clock.date_label, &date_label_style, LV_STATE_DEFAULT); // 给lv_clock.date_label对象添加样式

    /*Week display*/
    lv_clock.weekday_label = lv_label_create(date_obj); // 基于date_obj对象创建星期显示lv_clock.weekday_label对象
    if (lv_clock.weekday_label == NULL)
    {
        printf("[%s:%d] weekday_label create failed\n", __FUNCTION__, __LINE__);
        return;
    }
    lv_obj_add_style(lv_clock.weekday_label, &week_lable_style, LV_STATE_DEFAULT); // 给对象lv_clock.weekday_label添加样式

    // 设置时间标签lv_clock.time_label对象基于父对象居中对齐
    lv_obj_align_to(lv_clock.time_label, lv_obj_get_parent(lv_clock.time_label), LV_ALIGN_CENTER, 0, 0);
     // 设置时间标签lv_clock.date_label对象基于父对象顶部中间对齐
    lv_obj_align_to(lv_clock.date_label, lv_obj_get_parent(lv_clock.date_label), LV_ALIGN_TOP_MID, 2, 0);
    // 设置时间标签lv_clock.weekday_label对象基于父对象底部中间对齐
    lv_obj_align_to(lv_clock.weekday_label, lv_obj_get_parent(lv_clock.weekday_label), LV_ALIGN_BOTTOM_MID, -2, 0);

    lv_timer_t* task_timer = lv_timer_create(clock_date_task_callback, 200, (void *)&lv_clock); // 创建定时任务，200ms刷新一次
    if (task_timer == NULL)
    {
        printf("[%s:%d] lv_timer_create failed\n", __FUNCTION__, __LINE__);
    }


/*******************************************************************************************

第二个界面不能修改的日程表，和一个没有用的可以输入的文本框，不用管

********************************************************************************************/

void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);
    if(code == LV_EVENT_FOCUSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
/*
    if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
    */
}

    /*Create a keyboard to use it with an of the text areas*/
    lv_obj_t *kb = lv_keyboard_create(Screen2);

    /*Create a text area. The keyboard will write here*/
    lv_obj_t * ta;

    ta = lv_textarea_create(Screen2);
    lv_obj_align(ta, LV_ALIGN_TOP_RIGHT, -10, 10);
    lv_obj_add_event_cb(ta, ta_event_cb, LV_EVENT_ALL, kb);
    lv_obj_set_size(ta, 140, 90);
    lv_textarea_set_placeholder_text(ta, "Just For Wonderful.\nIt is useless");
    lv_obj_set_size(kb,140, 130);
    lv_obj_align(kb, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);





    lv_obj_t * NewsTable = lv_table_create(NewsSquare);
    lv_obj_align(NewsTable, LV_ALIGN_LEFT_MID,0,0);
    lv_table_set_col_width(NewsTable, 1,1);

    lv_table_set_cell_value(NewsTable, 0, 0,"To DO He Suan");
    lv_table_set_cell_value(NewsTable, 1, 0, "CovID-19");
    lv_table_set_cell_value(NewsTable, 2, 0, "Do Homewo");
    lv_table_set_cell_value(NewsTable, 3, 0, "Sleep Well");
    lv_table_set_cell_value(NewsTable, 4, 0, "Play Fun");
    lv_table_set_cell_value(NewsTable, 5, 0, "Goal");



/*******************************************************************************************

第一个页面的三个天气列表，最底下的接收数据要改

********************************************************************************************/

 static lv_style_t WeatherSquare_style;
    lv_style_reset(&WeatherSquare_style);
    lv_style_init(&WeatherSquare_style);
    lv_style_set_text_opa(&WeatherSquare_style, LV_OPA_COVER);
    lv_style_set_bg_opa(&WeatherSquare_style, LV_OPA_COVER);
    lv_style_set_bg_color(&WeatherSquare_style, lv_color_hsv_to_rgb(198,91.6,69.8));
    lv_style_set_text_color(&WeatherSquare_style,  lv_color_white());
    lv_style_set_bg_grad_dir(&WeatherSquare_style, LV_GRAD_DIR_VER);
    lv_style_set_radius(&WeatherSquare_style, 0);
    lv_style_set_border_width(&WeatherSquare_style, 0); //
    lv_style_set_border_color(&WeatherSquare_style, lv_color_hsv_to_rgb(198,91,69.8));
    lv_style_set_pad_left(&WeatherSquare_style, 0);
    lv_style_set_pad_right(&WeatherSquare_style, 0);
    lv_style_set_pad_top(&WeatherSquare_style, 0);
    lv_style_set_pad_bottom(&WeatherSquare_style, 0);

lv_obj_t * WeatherSquare1 = lv_obj_create(Screen1);
lv_obj_t * WeatherSquare2 = lv_obj_create(Screen1);
lv_obj_t * WeatherSquare3 = lv_obj_create(Screen1);

lv_obj_set_size(WeatherSquare1,157,210);
lv_obj_set_size(WeatherSquare2,80,160);
lv_obj_set_size(WeatherSquare3,80,160);

lv_obj_align(WeatherSquare1, LV_ALIGN_BOTTOM_RIGHT,0,0);
lv_obj_align(WeatherSquare2, LV_ALIGN_BOTTOM_MID,-39,0);
lv_obj_align(WeatherSquare3, LV_ALIGN_BOTTOM_LEFT,0,0);

lv_obj_add_style(WeatherSquare1, &WeatherSquare_style, LV_STATE_DEFAULT);
lv_obj_add_style(WeatherSquare2, &WeatherSquare_style, LV_STATE_DEFAULT);
lv_obj_add_style(WeatherSquare3, &WeatherSquare_style, LV_STATE_DEFAULT);

lv_obj_t * WeatherLable1Day = lv_label_create(WeatherSquare1);
lv_obj_t * WeatherLable1Wea = lv_label_create(WeatherSquare1);
lv_obj_t * WeatherLable1Tem = lv_label_create(WeatherSquare1);
lv_obj_t * WeatherLable1Win = lv_label_create(WeatherSquare1);
lv_obj_align(WeatherLable1Day, LV_ALIGN_BOTTOM_MID, 0, -80);
lv_obj_align(WeatherLable1Wea, LV_ALIGN_BOTTOM_MID, 0, -60);
lv_obj_align(WeatherLable1Tem, LV_ALIGN_BOTTOM_MID, 0, -40);
lv_obj_align(WeatherLable1Win, LV_ALIGN_BOTTOM_MID, 0, -20);

lv_obj_t * WeatherLable2Day = lv_label_create(WeatherSquare2);
lv_obj_t * WeatherLable2Wea = lv_label_create(WeatherSquare2);
lv_obj_t * WeatherLable2Tem = lv_label_create(WeatherSquare2);
lv_obj_t * WeatherLable2Win = lv_label_create(WeatherSquare2);
lv_obj_align(WeatherLable2Day, LV_ALIGN_BOTTOM_MID, 0, -60);
lv_obj_align(WeatherLable2Wea, LV_ALIGN_BOTTOM_MID, 0, -45);
lv_obj_align(WeatherLable2Tem, LV_ALIGN_BOTTOM_MID, 0, -30);
lv_obj_align(WeatherLable2Win, LV_ALIGN_BOTTOM_MID, 0, -15);

lv_obj_t * WeatherLable3Day = lv_label_create(WeatherSquare3);
lv_obj_t * WeatherLable3Wea = lv_label_create(WeatherSquare3);
lv_obj_t * WeatherLable3Tem = lv_label_create(WeatherSquare3);
lv_obj_t * WeatherLable3Win = lv_label_create(WeatherSquare3);
lv_obj_align(WeatherLable3Day, LV_ALIGN_BOTTOM_MID, 0, -60);
lv_obj_align(WeatherLable3Wea, LV_ALIGN_BOTTOM_MID, 0, -45);
lv_obj_align(WeatherLable3Tem, LV_ALIGN_BOTTOM_MID, 0, -30);
lv_obj_align(WeatherLable3Win, LV_ALIGN_BOTTOM_MID, 0, -15);

lv_label_set_text(WeatherLable1Day, "Day1");
lv_label_set_text(WeatherLable1Wea, "Weather1");
lv_label_set_text(WeatherLable1Tem, "Temper1");
lv_label_set_text(WeatherLable1Win, "Windy1");

lv_label_set_text(WeatherLable2Day, "Day2");
lv_label_set_text(WeatherLable2Wea, "Weather2");
lv_label_set_text(WeatherLable2Tem, "Temper2");
lv_label_set_text(WeatherLable2Win, "Windy2");

lv_label_set_text(WeatherLable3Day, "Day3");
lv_label_set_text(WeatherLable3Wea, "Weather3");
lv_label_set_text(WeatherLable3Tem, "Temper3");
lv_label_set_text(WeatherLable3Win, "Windy3");

/**********************************************************************************************

下面是插入图标的，用小记号对齐了，透明背景板，直接在上面加图标

***********************************************************************************************/

lv_obj_t * Symbg1 = lv_obj_create(WeatherSquare1);
lv_obj_t * Symbg2 = lv_obj_create(WeatherSquare2);
lv_obj_t * Symbg3 = lv_obj_create(WeatherSquare3);
lv_obj_set_size(Symbg1,80,80);//参考图标大小
lv_obj_align(Symbg1, LV_ALIGN_TOP_MID,0,20);
lv_obj_set_size(Symbg2,40,40);//参考图标大小
lv_obj_align(Symbg2, LV_ALIGN_TOP_MID,0,15);
lv_obj_set_size(Symbg3,40,40);//参考图标大小
lv_obj_align(Symbg3, LV_ALIGN_TOP_MID,0,15);

static lv_style_t Symbg_style;
        lv_style_set_bg_opa(&Symbg_style, 0);
        lv_style_set_border_width(&Symbg_style, 0);


//lv_obj_add_style(Symbg1, &Symbg_style, LV_STATE_DEFAULT);
//lv_obj_add_style(Symbg2, &Symbg_style, LV_STATE_DEFAULT);//去掉注释获得透明背景板
//lv_obj_add_style(Symbg3, &Symbg_style, LV_STATE_DEFAULT);


/*******************************************************************************************

第三个界面的新闻表，看着改

********************************************************************************************/
void scroll_begin_event(lv_event_t * e)
{

    if(lv_event_get_code(e) == LV_EVENT_SCROLL_BEGIN) {
        lv_anim_t * a = lv_event_get_param(e);
        if(a)  a->time = 0;
    }
}

    lv_obj_t *tabview;
    tabview = lv_tabview_create(Screen3, LV_DIR_LEFT, 80);
    lv_obj_add_event_cb(lv_tabview_get_content(tabview), scroll_begin_event, LV_EVENT_SCROLL_BEGIN, NULL);

    lv_obj_set_style_bg_color(tabview, lv_palette_lighten(LV_PALETTE_RED, 2), 0);

    lv_obj_t * tab_btns = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(tab_btns, lv_palette_darken(LV_PALETTE_GREY, 3), 0);
    lv_obj_set_style_text_color(tab_btns, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_border_side(tab_btns, LV_BORDER_SIDE_RIGHT, LV_PART_ITEMS | LV_STATE_CHECKED);



    lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Title1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Title2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Title3");
    lv_obj_t *tab4 = lv_tabview_add_tab(tabview, "Title4");
    lv_obj_t *tab5 = lv_tabview_add_tab(tabview, "Title5");

    lv_obj_set_style_bg_color(tab2, lv_palette_lighten(LV_PALETTE_AMBER, 3), 0);
    lv_obj_set_style_bg_opa(tab2, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(tab3, lv_color_hsv_to_rgb(198,91.6,69.8),0);
    lv_obj_set_style_bg_opa(tab3, LV_OPA_COVER, 0);


    lv_obj_t * label = lv_label_create(tab1);
    lv_label_set_text(label, "News1");

    label = lv_label_create(tab2);
    lv_label_set_text(label, "News2");

    label = lv_label_create(tab3);
    lv_label_set_text(label, "News3");//新闻信息往里填

    label = lv_label_create(tab4);
    lv_label_set_text(label, "News4");

    label = lv_label_create(tab5);
    lv_label_set_text(label, "News5");

    lv_obj_clear_flag(lv_tabview_get_content(tabview), LV_OBJ_FLAG_SCROLLABLE);

/***********************************************************************************************

下面不用管了

************************************************************************************************/



//黑色幽默，从三到一屏幕

lv_obj_t * BottonBackToScreen1 = lv_btn_create(Screen3);
lv_obj_add_style(BottonBackToScreen1, &BottonToScreen2Style, LV_STATE_DEFAULT);
lv_obj_t * BottonBackToScreen1Lable = lv_label_create(BottonBackToScreen1);
lv_label_set_text(BottonBackToScreen1Lable, LV_SYMBOL_UP);
lv_obj_set_size(BottonBackToScreen1,40,15);
lv_obj_align(BottonBackToScreen1,LV_ALIGN_TOP_MID,0,0);
lv_obj_align(BottonBackToScreen1Lable,LV_ALIGN_TOP_MID,0,-10);

 void BackToScreen1(lv_event_t * event)
{

    printf("Clicked\n");
    lv_scr_load_anim(Screen1, LV_SCR_LOAD_ANIM_OUT_TOP, 200, 0, 0);//change Screen

}

lv_obj_add_event_cb(BottonBackToScreen1, BackToScreen1, LV_EVENT_CLICKED, NULL);

/****************************************************************************************

下面的是mainc自带的

*****************************************************************************************/


    while(!lv_win32_quit_signal)
        {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(10000);       /*Just to let the system breath*/
    }
    return 0;

 }
