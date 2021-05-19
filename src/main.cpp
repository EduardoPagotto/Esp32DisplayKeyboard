#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED 2

#define C0 16
#define C1 17
#define C2 18
#define C3 19

#define L0 21
#define L1 22
#define L2 23
#define L3 25

TaskHandle_t taskHandle1, taskHandle2;

void task1(void* ppParamters);
void task2(void* ppParamters);

void setup() {
    Serial.begin(9600);

    pinMode(LED, OUTPUT);

    pinMode(C0, INPUT_PULLUP);
    pinMode(L0, OUTPUT);

    digitalWrite(L0, HIGH);

    xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &taskHandle1);
    xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &taskHandle2);
}

void loop() {

    digitalWrite(LED, !digitalRead(LED));
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void task1(void* ppParamters) {

    while (1) {
        Serial.println("Ligado");
        digitalWrite(L0, LOW);
        vTaskDelay(pdMS_TO_TICKS(5000));
        Serial.println("Desligado");
        digitalWrite(L0, HIGH);
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void task2(void* ppParamters) {

    while (1) {

        int val = digitalRead(C0);
        Serial.println("Leitura: " + String(val));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}