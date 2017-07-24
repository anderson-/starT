#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef STAR_T_H
#define STAR_T_H

typedef struct func {
	uint8_t * prog;
	uint8_t * mem;
	uint8_t mem_used;
	uint8_t mem_p;
} func;

typedef struct {
  uint8_t * mem;
  func * stack;
  uint8_t stack_size;
} task;

extern task ** mtask;
extern uint8_t n_tasks;

uint8_t add_task(uint8_t * prog);
void push_func(uint8_t * prog, task * task);
void pop_func(task * task);
uint8_t * run(uint8_t task_id, uint8_t clear);
void step_task(task * task);

#endif
