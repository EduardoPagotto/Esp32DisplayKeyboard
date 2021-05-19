#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../include/keyboard.hpp"

#define LED 2

TaskHandle_t taskHandle1;
// TaskHandle_t taskHandle2;

void task1(void* ppParamters);
// void task2(void* ppParamters);

void setup() {
    Serial.begin(9600);

    pinMode(LED, OUTPUT);

    initKey();

    xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &taskHandle1);
    // xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &taskHandle2);
}

void loop() {
    digitalWrite(LED, !digitalRead(LED));
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void task1(void* ppParamters) {
    while (1) {
        char* key = getKey();
        if (key != NULL) {
            Serial.println("Teclado: " + String(*key));
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
