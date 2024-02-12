#include <Arduino.h>
#include <Audio.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>

void OnButtonClicked(lv_event_t *e)
{
    static uint8_t cnt = 0;
    cnt++;
    // lv_label_set_text_fmt(ui_lblCountValue, "%d", cnt);
}

void setup()
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1.0);

    smartdisplay_led_set_rgb(false, false, false);

    auto disp = lv_disp_get_default();
    lv_disp_set_rotation(disp, LV_DISP_ROT_90);

    ui_init();
}

ulong next_millis;

void loop()
{

    lv_timer_handler();
}