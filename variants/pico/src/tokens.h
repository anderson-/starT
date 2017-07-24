
#ifndef TOKENS_H
#define TOKENS_H

#ifdef NANO
#   define FUNCTION        'F'
#   define ENDFUNCTION     ';'
#   define RETURN          'r'
#   define SET_MEM_SIZE    'm'
#endif

#define IF              '('
#define ELSE            ':'
#define ENDIF           ')'
#define WHILE           '['
#define BREAK           'x'
#define CONTINUE        'c'
#define ENDWHILE        ']'
#define ARRAY           '{'
#define ENDARRAY        '}'

#define NOP             ' '
#define COND_MODIFIER   '?'
#define TYPE_SET        't' //eh necessario?
#define LEFT            '<'
#define RIGHT           '>'
#define CLEAR           'C'
#define SWITCH          '@'
#define STORE           's'
#define LOAD            'l'

#define OUT             '.'
#define IN              ','
#define MEM_JUMP        'm' //signed int
#define COPY_FROM       'v'
#define RUN             '^'
#define CODE_JMP        'J'

#define SUM             '+'
#define SUB             '-'
#define MULTI           '*'
#define DIV             '/'
#define MOD             '%'

#define C_EQ            '='
#define C_NEQ           '!'
#define C_LT            '<'
#define C_GT            '>'
#define C_LE            'l'
#define C_GE            'g'
#define C_NOT_NULL      '?'
#define C_ZERO          'O'

#define AND             '&'
#define OR              '|'
#define XOR             '^'
#define SHIFT_LEFT      '<'
#define SHIFT_RIGHT     '>'
#define INV             '~'

#define T_INT8          'b'
#define T_INT16         'i'
#define T_INT32         'I'
#define T_FLOAT         'f'
#define STRING          '\"'
#define CHAR            '\''


#define INT8    0
#define INT16   1
#define INT32   2
#define FLOAT   3


#define SYS_REALLOC
#define SYS_SW_DELAY

#endif
