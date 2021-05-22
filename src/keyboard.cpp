#include "../include/keyboard.hpp"
#include "Arduino.h"

#define LINHAS 4
#define COLUNAS 4

const int linhas[] = {16, 17, 13, 19};
const int colunas[] = {21, 22, 12, 25};
const char hexaKey[LINHAS][COLUNAS] = {{'1', '2', '3', 'A'},  // Linha 0
                                       {'4', '5', '6', 'B'},  // Linha 1
                                       {'7', '8', '9', 'C'},  // Linha 2
                                       {'*', '0', '#', 'D'}}; // Linha 3

KeyBoardMatrix::KeyBoardMatrix() {
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

    this->coluna = 0;
    this->linha = 0;
    this->last = false;
}

KeyBoardMatrix::~KeyBoardMatrix() {}

bool KeyBoardMatrix::__getKey() {

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
                this->linha = l;
                this->coluna = c;
                digitalWrite(linhas[l], HIGH);
                return true;
            }
        }
        digitalWrite(linhas[l], HIGH);
    }
    return false;
}

char* KeyBoardMatrix::getKey() {

    if (this->__getKey() == true) {
        if (last == true)
            return NULL;

        last = true;
        return (char*)&hexaKey[linha][coluna];
    }

    last = false;
    return NULL;
}