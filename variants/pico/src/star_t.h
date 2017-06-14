#include <stdint.h>

#ifndef STAR_T_H
#define STAR_T_H

#	  ifdef _UNIT_TEST
extern uint8_t* mem_begin;
uint8_t ** M = &mem_begin;
# 	endif

#define PICO

#include "tokens.h"

#define MEM_SIZE 64

void begin();
int8_t run(uint8_t* code);

#endif
