#include "Display_SPD2010.h"
#include "LVGL_Driver.h"

unsigned long loopStartTime = 0;
lv_obj_t *label;

void Driver_Loop(void *parameter) {
  while (1) {
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void Driver_Init() {
  I2C_Init();
  TCA9554PWR_Init(0x00);
  Backlight_Init();
  Set_Backlight(50);
}

void setup() {
  delay(3000);  // Time to press play
  loopStartTime = millis();

  Driver_Init();
  LCD_Init();
  Lvgl_Init();

  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_PART_MAIN);
  lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, LV_PART_MAIN);

  label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "");
  lv_obj_set_style_text_color(label, lv_color_white(), LV_PART_MAIN);
  lv_obj_set_style_text_font(label, &lv_font_montserrat_40, LV_PART_MAIN);
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  xTaskCreatePinnedToCore(
    Driver_Loop,
    "Other Driver task",
    2048,
    NULL,
    3,
    NULL,
    0
  );
}

void loop() {
  Lvgl_Loop();
  vTaskDelay(pdMS_TO_TICKS(5));

  unsigned long elapsed = millis() - loopStartTime;

  if (elapsed < 4000) {
    lv_label_set_text(label, ""); // Opening
  } else if (elapsed < 8000) {
    lv_label_set_text(label, "Scrolling...");
  } else if (elapsed < 9000) {
    lv_label_set_text(label, "Tapping...");
  } else if (elapsed < 10000) {
    lv_label_set_text(label, "Liking...");
  } else if (elapsed < 13000) {
    lv_label_set_text(label, "Scrolling...");
  } else if (elapsed < 14000) {
    lv_label_set_text(label, "Tapping...");
  } else if (elapsed < 15000) {
    lv_label_set_text(label, "Liking...");
  } else if (elapsed < 18000) {
    lv_label_set_text(label, "Scrolling...");
  } else if (elapsed < 19000) {
    lv_label_set_text(label, "Tapping...");
  } else if (elapsed < 20000) {
    lv_label_set_text(label, "Liking...");
  } else if (elapsed < 22000) {
    lv_label_set_text(label, "Scrolling...");
  } else if (elapsed < 23000) {
    lv_label_set_text(label, "Tapping...");
  } else if (elapsed < 25000) {
    lv_label_set_text(label, "Liking...");
  } else if (elapsed < 27000) {
    lv_label_set_text(label, "Scrolling...");
  } else if (elapsed < 28000) {
    lv_label_set_text(label, "Tapping...");
  } else if (elapsed < 29000) {
    lv_label_set_text(label, "Liking...");
  } else if (elapsed < 31000) {
    lv_label_set_text(label, ""); // Black screen
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_PART_MAIN);
  } else {
    loopStartTime = millis(); // Loop again (optional)
  }
}
