#pragma once
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 270  // ограничиваем строку шириной экрана

struct UTF8Replace {
    uint8_t firstByte;    // первый байт UTF-8
    uint8_t secondByte;   // второй байт UTF-8
    uint8_t replacement;  // код для шрифта
};

const UTF8Replace replacements[] = {
    {208, 129, 192},  // Ё
    {209, 145, 193},  // ё
    {208, 132, 194},  // Є
    {209, 148, 195},  // є
    {208, 134, 196},  // І
    {209, 150, 197},  // і
    {208, 135, 198},  // Ї
    {209, 151, 199},  // ї
    {210, 144, 200},  // Ґ
    {210, 145, 201}   // ґ
};
const int replacementsCount = sizeof(replacements) / sizeof(replacements[0]);

// Функция преобразования строки UTF-8 в коды шрифта
// buf — буфер для результата, должен быть размером не меньше MAX_STRING+1
inline char* utf8rus2(const char* source, char* buf) {
    int i = 0, j = 0;
    while (source[i] && j < MAX_STRING) {
        uint8_t first = source[i++];
        uint8_t n = first;

        if (first >= 127) {  // двухбайтовый UTF-8
            uint8_t second = source[i++];
            bool replaced = false;
            for (int k = 0; k < replacementsCount; k++) {
                if (replacements[k].firstByte == first && replacements[k].secondByte == second) {
                    n = replacements[k].replacement;
                    replaced = true;
                    break;
                }
            }
            if (!replaced) {
                n = second;  // используем второй байт как индекс шрифта
            }
        }

        buf[j++] = n;
    }
    buf[j] = '\0';
    return buf;
}
