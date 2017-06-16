#include <stdlib.h>
#include "star_t.h"
#include "assert.h"

#ifndef NDEBUG
#   include <stdio.h>
#   define pe() __parsing_error(__FILE__, __LINE__, code_begin, code); return -1;
    void __parsing_error(const char* file, int line, const char* code_begin, const char* pos){
      int at = (int)(pos - code_begin + 1);
      char token = *(pos + 1);
      printf("Parsing error: Unexpected token '%c' at position %d on file '%s', line %d.\n", token, at, file, line);
      printf("\t%s\n\t", code_begin);
      while(at){
        at--;
        printf(" ");
      }
      printf("^\n");

    }
    #   define printf(...) printf("[%s,%d]", __FILE__, __LINE__); printf(__VA_ARGS__)
#else
#   define pe() ;
#endif

#define next(x) *(code + x)
#define prev(x) *(code - x)
#define consume() (code++)

#define _atoi(_type, str) ({ \
    _type val = 0; \
    int8_t sign = 1; \
    if (*str == '+'){ \
      str++; \
    } else if (*str == '-'){ \
      sign = -1; \
      str++; \
    } \
    while(*str >= '0' && *str <= '9'){ \
      val = val*10 + (*str++ - '0'); \
    } \
    val*sign; \
})


uint8_t* mem = NULL;
uint8_t* mem_begin = NULL;
uint8_t* code_begin = NULL;

void begin(){
  if (mem_begin){
    free(mem_begin);
  }
  mem = mem_begin = (uint8_t*) malloc (sizeof(uint8_t) * MEM_SIZE);
  code_begin = NULL;
}

int8_t run(uint8_t* code){
  begin();
  code_begin = code;
  uint8_t prev_op;
  while (*code){
    switch (*code) {
      case IF:{
        break;
      }
      case ENDIF:{
        break;
      }
      case ELSE:{
        break;
      }
      case WHILE:{
        break;
      }
      case ENDWHILE:{
        break;
      }
      case LOAD:{
        consume();
        switch (*code) {
          case BINARY: {
              consume();
              uint8_t l, len = *code++;
              l = len;
              while (l--) *mem++ = *code++;
              mem-=len;
              break;
            }
          case INT16:
            consume();
            *((int16_t*) mem) = _atoi(int16_t, code);
            break;
          case INT32:
            consume();
            *((int32_t*) mem) = _atoi(int32_t, code);
            break;
          case FLOAT:
            consume();
            *((float*) mem) = atof(code);
            break;
          case STRING: {
              consume();
              uint8_t l, len = *code++;
              l = len;
              while (l--) *mem++ = *code++;
              *mem++ = 0;
              mem-=len+1;
              if (*code != STRING){
                pe();
              }
              break;
            }
          default:
            switch (prev_op) {
              // case :
            }

            *mem = _atoi(int8_t, code);
            break;
        }
        while(*code != ENDLOAD){
          code++;
        }
        break;
      }
      case NOP:{
        // done
        break;
      }
      case NOT_NULL:{
        *mem = *mem == 0 ? 0 : 1;
        break;
      }
      case ZERO:{
        *mem = 0;
        break;
      }
      case LEFT:{
        break;
      }
      case RIGHT:{
        break;
      }
      case OUT:{
        break;
      }
      case IN:{
        break;
      }
      case STORE:{
        prev_op = STORE;
        if (next(1) != LOAD){
          pe();
        }
        break;
      }
      case MEM_JUMP:{
        break;
      }
      case COPY_FROM:{
        break;
      }
      case RUN:{
        break;
      }
      case CODE_JMP:{
        break;
      }
      case BREAK:{
        break;
      }
      case CONTINUE:{
        break;
      }
      case RETURN:{
        break;
      }

      case SUM:{
        if (next(1) == SCA_MODIFIER){
          prev_op = *code;
          consume();
          if (next(1) != LOAD){
            pe();
          }
        } else if (next(1) == MCA_MODIFIER){
          consume();
          *mem += *(mem + 1);
        } else {
          pe();
        }
        break;
      }
      case SUB:{
        break;
      }
      case MULTI:{
        break;
      }
      case DIV:{
        break;
      }
      case MOD:{
        break;
      }
      case EQ:{
        break;
      }
      case NEQ:{
        break;
      }
      case LE:{
        break;
      }
      case GE:{
        break;
      }
      case AND:{
        break;
      }
      case OR:{
        break;
      }
      case XOR:{
        break;
      }
      case SHIFT_LEFT:{
        break;
      }
      case SHIFT_RIGHT:{
        break;
      }
      default:
        pe();
        break;
    }
    code++;
  }
}
