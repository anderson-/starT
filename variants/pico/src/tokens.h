
#ifndef TOKENS_H
#define TOKENS_H

#ifdef NANO
#   define FUNCTION        'F'
#   define ENDFUNCTION     ';'
#   define SET_MEM_SIZE    'm'
#endif

#define IF              '('
#define ENDIF           ')'
#define WHILE           '['
#define ENDWHILE        ']'
#define LOAD            '{'
#define ENDLOAD         '}'

#define NOP             '\\'

#define LEFT            '<'
#define RIGHT           '>'
#define OUT             '.'
#define IN              ','
#define STORE           's'
#define MEM_JUMP        'p'
#define COPY_FROM       'v'

#define SUM             '+'
#define SUB             '-'
#define MULTI           '*'
#define DIV             '/'
#define MOD             '%'

#define EQ              '='
#define NEQ             '!'
#define LT              '<'
#define GT              '>'
#define LE              'l'
#define GE              'g'
#define NOT_NULL        '?'
#define ZERO            'O'

#define AND             '&'
#define OR              '|'
#define XOR             '^'
#define SHIFT_LEFT      'L'
#define SHIFT_RIGHT     'R'

#define RUN             '~'
#define CODE_JMP        '@'
#define BREAK           'x'
#define CONTINUE        'c'
#define RETURN          'r'
#define ELSE            ':'

#define BINARY          'b'
#define INT16           'l'
#define INT32           'L'
#define FLOAT           'f'
#define STRING          '\"'

#define SCA_MODIFIER   '\''
#define MCA_MODIFIER   '\"'

#define SYS_REALLOC
#define SYS_SW_DELAY

/*
 * int v0;				m1v0
 * scanf("%d", &v0);	,
 * while(v0){			[v0|
 * 	v0 = v0 - 1;		v0-1
 * 	printf("%d");		.
 * 	printf("\n");		{10}.
 * }					]
 * v0 = !v0;			!
 * if (v0){				(v0|
 * 	printf("FIM");		{FIM}.
 * }					)
 *
 *
 * m1v0,[v0|v0-1.{10}.]!(v0|{FIM}.)       size:33 bytes
 * m1#,[-1.>1{10}.<1]
 */
 #endif
