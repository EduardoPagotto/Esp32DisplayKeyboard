#include "../include/keyboard.hpp"
#include "Arduino.h"

#define LINHAS 4
#define COLUNAS 4

const int linhas[] = {16, 17, 18, 19};
const int colunas[] = {21, 22, 23, 25};
const char hexaKey[LINHAS][COLUNAS] = {{'1', '2', '3', 'A'},  // Linha 0
                                       {'4', '5', '6', 'B'},  // Linha 1
                                       {'7', '8', '9', 'C'},  // Linha 2
                                       {'*', '0', '#', 'D'}}; // Linha 3

void initKey() {

    int pin;
    for (uint8_t l = 0; l < LINHAS; l++) {
        pin = linhas[l];
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }

    for (uint8_t c = 0; c < COLUNAS; c++) {
        pin = colunas[c];
        pinMode(pin, INPUT_PULLUP);
    }
}

bool __getKey(uint8_t* linha, uint8_t* coluna) {
    uint8_t debuncingTime;
    for (uint8_t l = 0; l < LINHAS; l++) {
        digitalWrite(linhas[l], LOW);
        for (uint8_t c = 0; c < COLUNAS; c++) {

            debuncingTime = 0;
            while ((digitalRead(colunas[c]) == 0) && (debuncingTime < 10)) {
                debuncingTime++;
                vTaskDelay(pdMS_TO_TICKS(10));
            }

            if (debuncingTime == 10) {
                *linha = l;
                *coluna = c;
                digitalWrite(linhas[l], HIGH);
                return true;
            }
        }
        digitalWrite(linhas[l], HIGH);
    }
    return false;
}

char* getKey(char* pcLastKey) {
    uint8_t l, c;

    if ((pcLastKey == NULL) && (__getKey(&l, &c) == true))
        return (char*)&hexaKey[l][c];

    return NULL;
}
