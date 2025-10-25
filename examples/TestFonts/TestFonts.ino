#include <Arduino_GFX_Library.h>
#include <utils.h>
#include <tahomaUkr12.h>

#define GFX_BL 21  // пин подсветки

// ===== ILI9341 CYD дисплей =====
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS 15
#define TFT_DC 2
#define TFT_RST -1

Arduino_ESP32SPI *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCLK, TFT_MOSI, TFT_MISO);
Arduino_ILI9341 *gfx = new Arduino_ILI9341(bus, GFX_NOT_DEFINED /* RST */, 1 /* rotation */);

String msg = "На ґанку фортеці вранці,\nЗачаївшись й зажадавши,\nГріючись в проміннях сонця,\nКиця щастя в'є в клубочок.\n\nThe quick brown fox jumps over the lazy dog";

void setup() {
  Serial.begin(115200);

  gfx->begin();
  gfx->invertDisplay(true);
  gfx->fillScreen(0x0000);

  // Подсветка через LEDC
  pinMode(GFX_BL, OUTPUT);
  analogWriteFrequency(GFX_BL, 1000);  // Set PWM frequency to 1kHz
  analogWriteResolution(GFX_BL, 8);    // Set PWM resolution to 10 bits (0-1023)
  analogWrite(GFX_BL, 255);
  gfx->setTextColor(0xFFFF, 0x0000);
  gfx->setFont(&tahomaUkr12);
  gfx->setCursor(0, 20);
  gfx->print(String(utf8rus2(msg.c_str())));

}

void loop() {
  // put your main code here, to run repeatedly:
}
