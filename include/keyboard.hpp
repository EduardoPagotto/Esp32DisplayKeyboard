#ifndef __KEY_BOARD__HPP__
#define __KEY_BOARD__HPP__

#include "freertos/FreeRTOS.h"

class KeyBoardMatrix {
  public:
    KeyBoardMatrix();
    virtual ~KeyBoardMatrix();
    char* getKey();

  private:
    bool __getKey();
    uint8_t linha;
    uint8_t coluna;
    bool last;
};

#endif