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

#define _case_math_data_op(pre, suf) \
  case STORE:{ \
    pre = suf; \
    break; \
  } \
  case SUM:{ \
    pre += suf; \
    break; \
  } \
  case SUB:{ \
    pre -= suf; \
    break; \
  } \
  case MULTI:{ \
    pre *= suf; \
    break; \
  } \
  case DIV:{ \
    pre /= suf; \
    break; \
  } \
  case EQ:{ \
    pre = (pre == suf); \
    break; \
  } \
  case NEQ:{ \
    pre = (pre != suf); \
    break; \
  } \
  case LT:{ \
    pre = (pre < suf); \
    break; \
  } \
  case GT:{ \
    pre = (pre > suf); \
    break; \
  } \
  case LE:{ \
    pre = (pre <= suf); \
    break; \
  } \
  case GE:{ \
    pre = (pre >= suf); \
    break; \
  } \

#define _case_int_data_op(pre, suf) \
  case MOD:{ \
    pre %= suf; \
    break; \
  } \
  case AND:{ \
    pre &= suf; \
    break; \
  } \
  case OR:{ \
    pre |= suf; \
    break; \
  } \
  case XOR:{ \
    pre ^= suf; \
    break; \
  } \
  case SHIFT_LEFT:{ \
    pre <<= suf; \
    break; \
  } \
  case SHIFT_RIGHT:{ \
    pre >>= suf; \
    break; \
  } \

#define _int_data_operation(OP) { \
  if (next(1) == SCA_MODIFIER){ \
    prev_op = *code; \
    consume(); \
    if (next(1) != LOAD){ \
      pe(); \
    } \
  } else if (next(1) == MCA_MODIFIER){ \
    consume(); \
    switch (next(1)){ \
      case INT32: \
          *((int32_t*) mem) OP *((int32_t*) (mem + 1)); \
        break; \
      case INT16: \
          *((int16_t*) mem) OP *((int16_t*) (mem + 1)); \
        break; \
      case INT8: \
        *((int8_t*) mem) OP *((int8_t*) (mem + 1)); \
        break; \
      default: \
        pe(); \
    } \
    consume(); \
  } else { \
    pe(); \
  } \
} \

#define _num_data_operation(OP) { \
  if (next(1) == SCA_MODIFIER){ \
    prev_op = *code; \
    consume(); \
    if (next(1) != LOAD){ \
      pe(); \
    } \
  } else if (next(1) == MCA_MODIFIER){ \
    consume(); \
    switch (next(1)){ \
      case FLOAT: \
          *((float*) mem) OP *((float*) (mem + 1)); \
        break; \
      case INT32: \
          *((int32_t*) mem) OP *((int32_t*) (mem + 1)); \
        break; \
      case INT16: \
          *((int16_t*) mem) OP *((int16_t*) (mem + 1)); \
        break; \
      case INT8: \
        *((int8_t*) mem) OP *((int8_t*) (mem + 1)); \
        break; \
      default: \
        pe(); \
    } \
    consume(); \
  } else { \
    pe(); \
  } \
} \

#define _num_cmp_operation(OP) { \
  if (next(1) == SCA_MODIFIER){ \
    prev_op = *code; \
    consume(); \
    if (next(1) != LOAD){ \
      pe(); \
    } \
  } else if (next(1) == MCA_MODIFIER){ \
    consume(); \
    switch (next(1)){ \
      case FLOAT: \
          *((float*) mem) = *((float*) mem) OP *((float*) (mem + 1)); \
        break; \
      case INT32: \
          *((int32_t*) mem) = *((int32_t*) mem) OP *((int32_t*) (mem + 1)); \
        break; \
      case INT16: \
          *((int16_t*) mem) = *((int16_t*) mem) OP *((int16_t*) (mem + 1)); \
        break; \
      case INT8: \
        *((int8_t*) mem) = *((int8_t*) mem) OP *((int8_t*) (mem + 1)); \
        break; \
      default: \
        pe(); \
    } \
    consume(); \
  } else { \
    pe(); \
  } \
} \

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
              if (prev_op != STORE){
                pe();
              }
              consume();
              uint8_t l, len = *code++;
              l = len;
              while (l--) *mem++ = *code++;
              mem-=len;
              break;
            }
          case STRING: {
              if (prev_op != STORE){
                pe();
              }
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
          case FLOAT:
            consume();
            switch (prev_op) {
              _case_math_data_op(*((float*) mem), atof(code))
              default:
                pe();
                break;
            }
            break;
          case INT32:
            consume();
              switch (prev_op) {
                _case_math_data_op(*((int32_t*) mem), _atoi(int32_t, code))
                _case_int_data_op(*((int32_t*) mem), _atoi(int32_t, code))
                default:
                  pe();
                  break;
              }
            break;
          case INT16:
            consume();
            switch (prev_op) {
              _case_math_data_op(*((int16_t*) mem), _atoi(int16_t, code))
              _case_int_data_op(*((int16_t*) mem), _atoi(int16_t, code))
              default:
                pe();
                break;
            }
            break;
          case INT8:
            consume();
          default:
            switch (prev_op) {
              _case_math_data_op(*mem, _atoi(int8_t, code))
              _case_int_data_op(*mem, _atoi(int8_t, code))
              default:
                pe();
                break;
            }
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
        if (next(1) == LOAD){

        } else {
          _num_cmp_operation(<);
        }
        break;
      }
      case RIGHT:{
        if (next(1) == LOAD){

        } else {
          _num_cmp_operation(>);
        }
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

      case SUM:{
        _num_data_operation(+=);
        break;
      }
      case SUB:{
        _num_data_operation(-=);
        break;
      }
      case MULTI:{
        _num_data_operation(*=);
        break;
      }
      case DIV:{
        _num_data_operation(/=);
        break;
      }

      case MOD:{
        _int_data_operation(/=);
        break;
      }
      case AND:{
        _int_data_operation(&=);
        break;
      }
      case OR:{
        _int_data_operation(|=);
        break;
      }
      case XOR:{
        _int_data_operation(^=);
        break;
      }
      case SHIFT_LEFT:{
        _int_data_operation(<<=);
        break;
      }
      case SHIFT_RIGHT:{
        _int_data_operation(>>=);
        break;
      }
      case EQ:{
        _num_cmp_operation(==);
        break;
      }
      case NEQ:{
        _num_cmp_operation(!=);
        break;
      }
      case LE:{
        _num_cmp_operation(<=);
        break;
      }
      case GE:{
        _num_cmp_operation(>=);
        break;
      }
      default:
        pe();
        break;
    }
    code++;
  }
  return 0;
}
