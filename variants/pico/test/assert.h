#ifndef ASSERT_H
#define ASSERT_H

#ifndef NDEBUG
#   define assert(A) __assert(#A, A, __FILE__, __LINE__)
#   define assert_eq(A, B) __assert_eq(#A, A, B, __FILE__, __LINE__)
#   define assert_str_eq(A, B) __assert_str_eq(#A, A, B, __FILE__, __LINE__)
#else
#   define assert(A) ;
#   define assert_eq(A, B) ;
#   define assert_str_eq(A, B) ;
#endif

void start_tests();
void end_tests();
void begin_section(const char* name);
void end_section();
void __assert(const char* expr_str, int a, const char* file, int line);
void __assert_eq(const char* expr_str, int a, int b, const char* file, int line);
void __assert_str_eq(const char* expr_str, const char* a, const char* b, const char* file, int line);

#endif
