#include "star_t.h"
#include "tokens.h"

task ** mtask = NULL;
uint8_t n_tasks = 0;

uint8_t add_task(uint8_t * prog){
	int8_t index = -1;
	if (mtask != NULL){
		for (uint8_t i = 0; i < n_tasks; i++){
			if (mtask[i] == NULL){
				index = i;
				break;
			}
		}
	} else {
		mtask = (task **) realloc(mtask, (n_tasks+1)*sizeof(task *));
		index = n_tasks++;
	}
	mtask[index] = (task *) malloc(sizeof(task));
	mtask[index]->mem = NULL;
	mtask[index]->stack = NULL;
	mtask[index]->stack_size = 0;
	push_func(prog, mtask[index]);
	return index;
}

void push_func(uint8_t * prog, task * task){
	task->stack = (func *) realloc(task->stack, (task->stack_size+1)*sizeof(func));
	task->stack[task->stack_size].prog = prog;
	task->stack[task->stack_size].mem = NULL;
	task->stack[task->stack_size].mem_used = 0;
	task->stack[task->stack_size].mem_p = 0;
	task->stack_size++;
}

void pop_func(task * task){
	task->stack = (func *) realloc(task->stack, (task->stack_size-1)*sizeof(func));
	task->stack_size--;
}

uint8_t * run(uint8_t task_id, uint8_t clear){
	task * task = mtask[task_id];
	while(task->stack_size){
		step_task(task);
	}
	uint8_t * mem = task->mem;
	if (clear){
		free(task->mem);
	}
	free(task);
	mtask[task_id] = NULL;
	return mem;
}

void step_task(task * task){
	func f = task->stack[task->stack_size-1];
	while(1){
		switch (*(f.prog++)) {
			case SET_MEM_SIZE:
				{
					int msize = (uint8_t) atoi(f.prog);
					if (msize > 0){
						task->mem = (uint8_t*)malloc(msize*sizeof(uint8_t));
						for (uint8_t i = 0; i < msize; i++){
							task->mem[i] = 0;
						}
					}
					f.mem = task->mem;
					break;
				}
			case '=':
				{
					f.mem[f.mem_p] = (uint8_t) atoi(f.prog);
					break;
				}
			case 0:
				{
					pop_func(task);
					return;
				}
		}
	}
}

/*
void init(uint8_t msize, uint8_t * prog){
	stack = (task *) malloc(sizeof(task));



	mem = (uint8_t *) malloc(msize * sizeof(uint8_t));
	for (int i = 0; i < msize; i++){
		mem[i] = 0;
	}

}*/
