# Ukr_GFX_fonts

---

## 🇬🇧 English

**Ukr_GFX_fonts** is a collection of fonts with Ukrainian character support for GFX libraries (Adafruit GFX, Arduino GFX) and a helper function to convert UTF-8 strings with Ukrainian letters into font codes.

### Library Contents

- **Fonts** (`.h` files are in `src/fonts/`):  
  - Tahoma, Cambria, FreeSans, and other fonts with Ukrainian letters support.  
- **Conversion function**:  
  - `utf8rus2(const char* source)` — converts a UTF-8 string into font codes using a replacement table.  
  - Used to display Ukrainian letters via GFX.

### Usage

Example of including the library and font:

```cpp
#include <Arduino_GFX_Library.h>
#include <utils.h>
#include <tahomaUkr12.h> // desired font
```

Example of printing Ukrainian text:

```cpp
String msg = "Привіт Ґ!";
gfx->setFont(&tahomaUkr12);
gfx->setCursor(0, 20);
gfx->print(String(utf8rus2(msg.c_str())));
```

### Demo Sketch

The example sketch `examples/TestFonts/TestFonts.ino` demonstrates displaying Ukrainian text on the screen.

### Support

If you find this project useful and want to support its development, you can donate via:

- **PayPal**: [gia@gia.org.ua] [Donate via PayPal](https://www.paypal.me)  
- **Ko-fi**: [Donate on Ko-fi](https://ko-fi.com/igorgimelfarb)  

**Your support is greatly appreciated!**

### License

MIT License — free to use, modify, and distribute. See `LICENSE` for details.  

---

## 🇺🇦 Українська

**Ukr_GFX_fonts** — це колекція шрифтів з підтримкою українських букв для бібліотек GFX (Adafruit GFX, Arduino GFX) та допоміжна функція для перетворення UTF-8 рядків з українськими символами у коди шрифтів.

### Вміст бібліотеки

- **Шрифти** (файли `.h` знаходяться в `src/fonts/`):  
  - Tahoma, Cambria, FreeSans та інші шрифти з підтримкою українських букв.  
- **Функція перетворення**:  
  - `utf8rus2(const char* source)` — перетворює UTF-8 рядок у коди шрифта, використовуючи таблицю замін.  
  - Використовується для відображення українських символів через GFX.

### Підключення

Приклад підключення бібліотеки та шрифту:

```cpp
#include <Arduino_GFX_Library.h>
#include <utils.h>
#include <tahomaUkr12.h> // потрібний шрифт
```

### Використання

Приклад виклику функції `utf8rus2` для виводу тексту на дисплей:

```cpp
String msg = "Привіт Ґ!";
gfx->setFont(&tahomaUkr12);
gfx->setCursor(0, 20);
gfx->print(String(utf8rus2(msg.c_str())));
```

### Приклад

Скетч `examples/TestFonts/TestFonts.ino` демонструє вивід українського тексту на дисплей.

### Підтримка

Якщо ви вважаєте цей проект корисним і хочете підтримати його розробку, ви можете зробити пожертву будь-яким із наступних способів:

- **PayPal**: [gia@gia.org.ua] [Donate via PayPal](https://www.paypal.me)  
- **Ko-fi**: [Donate on Ko-fi](https://ko-fi.com/igorgimelfarb)  

**Ваша підтримка буде дуже цінною!**

### Ліцензія

MIT License — вільне використання, модифікація та розповсюдження. Детальніше у файлі `LICENSE`.

## Keywords

Ukrainian, GFX, Adafruit, Arduino, fonts, UTF-8, display, text, Тahoma, Cambria, FreeSans
