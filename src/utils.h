#pragma once
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 270  // ������������ ������ ������� ������

struct UTF8Replace {
    uint8_t firstByte;    // ������ ���� UTF-8
    uint8_t secondByte;   // ������ ���� UTF-8
    uint8_t replacement;  // ��� ��� ������
};

const UTF8Replace replacements[] = {
    {208, 129, 192},  // �
    {209, 145, 193},  // �
    {208, 132, 194},  // �
    {209, 148, 195},  // �
    {208, 134, 196},  // �
    {209, 150, 197},  // �
    {208, 135, 198},  // �
    {209, 151, 199},  // �
    {210, 144, 200},  // �
    {210, 145, 201}   // �
};
const int replacementsCount = sizeof(replacements) / sizeof(replacements[0]);

// ������� �������������� ������ UTF-8 � ���� ������
// buf � ����� ��� ����������, ������ ���� �������� �� ������ MAX_STRING+1
inline char* utf8rus2(const char* source, char* buf) {
    int i = 0, j = 0;
    while (source[i] && j < MAX_STRING) {
        uint8_t first = source[i++];
        uint8_t n = first;

        if (first >= 127) {  // ������������ UTF-8
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
                n = second;  // ���������� ������ ���� ��� ������ ������
            }
        }

        buf[j++] = n;
    }
    buf[j] = '\0';
    return buf;
}
