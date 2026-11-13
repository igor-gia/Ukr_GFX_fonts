#include <Arduino.h>
#include <LovyanGFX.hpp>
#include <utils.h>            // Твой конвертер
#include <fonts/tahomaUkr8.h> // Берем шрифт поменьше для 128x160

// Класс инициализации твоего дисплея (S2 mini + ST7735S)
class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7735S _panel_instance;
  lgfx::Bus_SPI       _bus_instance;

public:
  LGFX() {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host    = SPI2_HOST;
      cfg.spi_mode    = 0;
      cfg.freq_write  = 20000000;
      cfg.pin_sclk    = 12;
      cfg.pin_mosi    = 11;
      cfg.pin_miso    = -1;
      cfg.pin_dc      = 14;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }
    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs         = 10;
      cfg.pin_rst        = 15;
      cfg.panel_width    = 128;
      cfg.panel_height   = 160;
      _panel_instance.config(cfg);
    }
    setPanel(&_panel_instance);
  }
};

LGFX lcd;

void setup() {
  Serial.begin(115200);

  // Инициализация дисплея напрямую
  lcd.init();
  lcd.setRotation(1);

  // Отключаем встроенный UTF-8 в LovyanGFX для работы нашей перекодировки
  lcd.setAttribute(lgfx::attribute::utf8_switch, false);

  lcd.fillScreen(TFT_BLACK);

  // Настройка шрифта и вывода
  lcd.setFont(&tahomaUkr8);
  lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  lcd.setCursor(0, 5);

  // Простой вывод украинского текста
  lcd.println(Utf8win1251("Привіт, світ!"));
  lcd.println(Utf8win1251("На ґанку ґава..."));
  lcd.println(Utf8win1251("Українські букви:"));
  lcd.println(Utf8win1251("Є, Ї, І, Ґ, є, ї, і, ґ"));
}

void loop() {
}