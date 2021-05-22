#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "../include/keyboard.hpp"

// na mao
#include <Adafruit_I2CDevice.h>

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SPI.h>

#define LED 2

TaskHandle_t taskHandle1;
TaskHandle_t taskHandle2;

void task1(void* ppParamters);
void task2(void* ppParamters);

KeyBoardMatrix keyboard = KeyBoardMatrix();

Adafruit_PCD8544 display = Adafruit_PCD8544(18, 23, 4, 15, 2);
int contrastValue = 60; // Default Contrast Value
const int adcPin = 34;
int adcValue = 0;

void setup() {
    Serial.begin(9600);

    pinMode(LED, OUTPUT);

    // inicio

    /* Initialize the Display*/
    display.begin();

    /* Change the contrast using the following API*/
    display.setContrast(contrastValue);

    /* Clear the buffer */
    display.clearDisplay();
    display.display();
    delay(1000);

    /* Now let us display some text */
    display.setTextColor(WHITE, BLACK);
    display.setCursor(0, 1);
    display.setTextSize(2);
    display.println("|ESP32|");
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(22, 20);
    display.println("|Nokia|");
    display.setCursor(22, 32);
    display.println("|5110|");
    display.display();
    delay(2000);

    // fim

    xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &taskHandle1);
    xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &taskHandle2);
}

void loop() {
    digitalWrite(LED, !digitalRead(LED));
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void task2(void* ppParamters) {

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void task1(void* ppParamters) {
    char* key = NULL;
    while (1) {
        key = keyboard.getKey();
        if (key != NULL) {
            Serial.println("Teclado: " + String(*key));
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
