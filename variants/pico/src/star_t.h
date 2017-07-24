#include <stdint.h>
#include "tokens.h"

#ifndef STAR_T_H
#define STAR_T_H

#define PICO
#define MEM_SIZE 64

#define JM_NONE 0
#define JM_EIFE 1
#define JM_ENIF 2
#define JM_EWHI 3
#define JM_WHI0 4
#define JM_WHI1 5

typedef union {
  uint8_t i8 [4];
  uint16_t i16 [2];
  uint32_t i32;
  float f32;
} Register;

typedef struct {
  Register A;
  Register B;
  struct {
    uint8_t comp:1;
    uint8_t type:2;
    uint8_t i:2;
    uint8_t o:2;
  } info;
  uint8_t* mem;
} State;

void begin();
int8_t run(uint8_t* code);

#	  ifdef _UNIT_TEST
extern State * s;
extern uint8_t* mem_begin;
uint8_t ** M = &mem_begin;
# 	endif

#endif
