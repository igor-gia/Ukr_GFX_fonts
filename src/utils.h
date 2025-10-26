#pragma once
#include <Arduino.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 270  // ограничиваем строку шириной экрана

// Глобальный буфер для преобразованных строк
char target[MAX_STRING + 1] = "";

// Таблица замены UTF-8 -> код шрифта
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

// Функция преобразования UTF-8 строки в коды шрифта
inline char* Utf8win1251(const char* source) {
    strcpy(target, "");  // очищаем буфер
    int i = 0, j = 0;
    while (source[i] && j < MAX_STRING) {
        unsigned char first = source[i++];
        unsigned char n = first;

        if (first >= 127) {  // двухбайтовый UTF-8
            unsigned char second = source[i++];
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

        target[j++] = n;
    }
    target[j] = '\0';
    return target;
}

