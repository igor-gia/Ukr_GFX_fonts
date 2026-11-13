#pragma once
#include <Arduino.h>

// Функция перекодировки UTF-8 в коды шрифта
inline String Utf8win1251(const char* source) {
    String result = "";
    if (!source) return result;

    // Резервируем память, чтобы избежать фрагментации кучи
    result.reserve(strlen(source)); 

    int i = 0;
    while (source[i]) {
        uint8_t first = source[i++];
        
        // 1-байтовый символ (ASCII: 0xxxxxxx)
        if ((first & 0x80) == 0) {  
            result += (char)first;
            continue;
        }
        
        // 2-байтовый символ (Кириллица: 110xxxxx)
        if ((first & 0xE0) == 0xC0) {
            if (!source[i]) break; // Защита от внезапного конца строки
            uint8_t second = source[i++];
            uint8_t n = second; // По умолчанию используем второй байт

            // Быстрая замена украинских и спец. букв
            if (first == 208) {
                switch (second) {
                    case 129: n = 192; break; // Ё
                    case 132: n = 194; break; // Є
                    case 134: n = 196; break; // І
                    case 135: n = 198; break; // Ї
                }
            } else if (first == 209) {
                switch (second) {
                    case 145: n = 193; break; // ё
                    case 148: n = 195; break; // є
                    case 150: n = 197; break; // і
                    case 151: n = 199; break; // ї
                }
            } else if (first == 210) {
                switch (second) {
                    case 144: n = 200; break; // Ґ
                    case 145: n = 201; break; // ґ
                }
            }
            
            result += (char)n;
            continue;
        }
        
        // 3-байтовый символ (1110xxxx) - например, знак евро или градуса
        if ((first & 0xF0) == 0xE0) {
            if (source[i]) i++; // пропускаем 2-й байт
            if (source[i]) i++; // пропускаем 3-й байт
            // В шрифт не пишем, просто идем дальше
            continue; 
        }
        
        // 4-байтовый символ (11110xxx) - например, эмодзи
        if ((first & 0xF8) == 0xF0) {
            if (source[i]) i++; // пропускаем 2-й байт
            if (source[i]) i++; // пропускаем 3-й байт
            if (source[i]) i++; // пропускаем 4-й байт
            // В шрифт не пишем, просто идем дальше
            continue; 
        }
    }
    return result;
}