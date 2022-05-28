#ifndef _SHARED_H_
#define _SHARED_H_

#include <stdio.h>
#include <semphr.h>

extern uint32_t *lcd_gram0;
extern uint32_t *lcd_gram1;
extern SemaphoreHandle_t semEmpty;
extern SemaphoreHandle_t semAvailable;

#define GRAM_SIZE 320 * 240 * 2


#endif