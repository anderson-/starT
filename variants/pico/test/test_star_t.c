#include <stdio.h>
#include <stdlib.h>
#define _UNIT_TEST
#include "assert.h"
#include "../src/star_t.h"


int v(int a, float b){
  int i = (int)(b*a);
  printf("asd %d %f = %d\n", a, b, i);
  return i;
}

int main(void){

  // void * (* p) (void *);
  // p = (void * (* ) (void *)) v;
  //
  // int i = 123;
  // float f = 0.12432f;
  //
  // uint8_t * data = (uint8_t *) malloc (sizeof(int) + sizeof(float));
  // *((int*)data) = i;
  // *((float*)(data + sizeof(int))) = f;
  // // ((int*)data)[0] = i;
  // // ((float*)(data + sizeof(int)))[1] = f;
  //
  // p(&i);
  //
  // return 0;


  begin_section("NOP");
  assert_eq(run(" "), 0);
  assert_eq(run("   "), 0);
  // assert_eq(run(" ` "), -1);
  end_section();

  begin_section("DATA TYPES");
  assert_eq((run("3"), s->info.type), INT8);
  assert_eq((run("3"), s->A.i8[0]), 3);
  assert_eq((run("1"), s->A.i8[0]), 1);
  assert_eq((run("10"), s->A.i8[0]), 10);
  assert_eq((run("20"), s->A.i8[0]), 20);
  assert_eq((run("33"), s->A.i8[0]), 33);
  assert_eq((run("128"), s->A.i8[0]), 128);
  assert_eq((run("255"), s->A.i8[0]), 255);
  assert_eq((run("256"), s->A.i8[0]), 0);
  assert_eq((run("257"), s->A.i8[0]), 1);
  assert_eq((run("257"), s->A.i8[1]), 0);
  assert_eq((run("b"), s->info.type), INT8);
  assert_eq((run("b"), s->A.i8[0]), 0);
  assert_eq((run("b3"), s->info.type), INT8);
  assert_eq((run("b3"), s->A.i8[0]), 3);
  assert_eq((run("b33"), s->A.i8[0]), 33);
  assert_eq((run("b128"), s->A.i8[0]), 128);
  assert_eq((run("b255"), s->A.i8[0]), 255);
  assert_eq((run("b256"), s->A.i8[0]), 0);
  assert_eq((run("b257"), s->A.i8[0]), 1);
  assert_eq((run("b257"), s->A.i8[1]), 0);

  assert_eq((run("i3"), s->info.type), INT16);
  assert_eq((run("I3"), s->info.type), INT32);
  assert_eq((run("f3"), s->info.type), FLOAT);
  end_section();

  begin_section("STORE");
  assert_eq((run("3s"), (*M)[0]), 3);
  end_section();

  begin_section("Move/Load");
  assert_eq((run("3s>4s"), (*M)[0]), 3);
  assert_eq((run("3s>4s"), (*M)[1]), 4);
  assert_eq((run(">4s<3s"), (*M)[0]), 3);
  assert_eq((run(">4s<3s"), (*M)[1]), 4);
  assert_eq((run(">4s<3s1"), s->A.i8[0]), 1);
  assert_eq((run(">4s<3s1l"), s->A.i8[0]), 3);
  assert_eq((run(">4s<3s1>l"), s->A.i8[0]), 4);
  end_section();

  begin_section("SWITCH");
  assert_eq((run("2"), s->A.i8[0]), 2);
  assert_eq((run("2@"), s->B.i8[0]), 2);
  assert_eq((run("2@3"), s->A.i8[0]), 3);
  assert_eq((run("2@3"), s->B.i8[0]), 2);
  end_section();

  begin_section("COMP");
  assert_eq((run("0@1?<"), s->info.comp), 0);
  assert_eq((run("1@1?<"), s->info.comp), 0);
  assert_eq((run("2@1?<"), s->info.comp), 1);
  assert_eq((run("0@1@?>"), s->info.comp), 0);
  assert_eq((run("1@1@?>"), s->info.comp), 0);
  assert_eq((run("2@1@?>"), s->A.i8[0]), 2);
  assert_eq((run("2@1@?>"), s->B.i8[0]), 1);
  assert_eq((run("2@1@?>"), s->info.comp), 1);
  end_section();

  begin_section("OP");
  assert_eq((run("12@1+"), s->A.i8[0]), 13);
  assert_eq((run("1@12-"), s->A.i8[0]), 11);
  assert_eq((run("1@12--"), s->A.i8[0]), 10);
  assert_eq((run("2@3*"), s->A.i8[0]), 6);
  end_section();

  begin_section("IF");
  assert_eq(run("()"), 0);
  assert_eq(run("(:)"), 0);
  assert_eq(run("1(2)"), 0);
  assert_eq((run("1(2)"), s->A.i8[0]), 1);
  assert_eq((run("1(2:)"), s->A.i8[0]), 1);
  assert_eq((run("1(:2)"), s->A.i8[0]), 2);
  assert_eq((run("?!(1:2)"), s->A.i8[0]), 2);
  assert_eq(run("?=(1:2)"), 0);
  assert_eq(run("?!(1:2)"), 0);
  assert_eq((run("(2:3)"), s->A.i8[0]), 3);
  assert_eq(run("?=(1:2)"), 0);
  assert_eq((run("?=(1:2)"), s->info.comp), 1);
  assert_eq((run("?=(1:2)"), s->A.i8[0]), 1);
  assert_eq((run("0@1@?>(2:3)s"), s->mem[0]), 3);
  assert_eq((run("1@1@?>(2:3)s"), s->mem[0]), 3);
  assert_eq((run("2@1@?>(2:3)s"), s->mem[0]), 2);
  end_section();

  begin_section("WHILE");
  assert_eq(run("[]"), 0);
  assert_eq(run("1[2]"), 0);
  assert_eq((run("1[2]"), s->A.i8[0]), 1);
  assert_eq(run("?=[x]"), 0);
  assert_eq(run("1[2x3]"), 0);
  assert_eq((run("1[2x3]"), s->A.i8[0]), 1);
  assert_eq(run("?=1[2x3]"), 0);
  assert_eq((run("?=1[2x3]"), s->A.i8[0]), 2);
  assert_eq(run("1?![x]"), 0);
  assert_eq((run("1?![x]"), s->A.i8[0]), 1);
  assert_eq(run("1@1?![-?!]"), 0);
  assert_eq((run("12@?![+?!]"), s->A.i8[0]), 12);
  assert_eq((run("12@?![+?!]"), s->B.i8[0]), 12);
  assert_eq((run("8s?![1@l-s?! c x ]"), s->A.i8[0]), 1);
  end_section();

  begin_section("Fibonacci");
  assert_eq((run("8s>0s>1s?![2<1@l-s?!2> l@<l@s+>s]"), s->A.i8[0]), 21);
  assert_eq((run("9s>0s>1s?![2<1@l-s?!2> l@<l@s+>s]"), s->A.i8[0]), 34);
  assert_eq((run("10s>0s>1s?![2<1@l-s?!2> l@<l@s+>s]"), s->A.i8[0]), 55);
  assert_eq((run("I46s>I0s>I1s?![2<I1@l-s?!2> l@<l@s+>s]"), s->A.i32), 1836311903);
  assert_eq((run("tI46s>0s>1s?![2<1@l-s?!2> l@<l@s+>s]"), s->A.i32), 1836311903);
  end_section();

  end_tests();

  return 0;
}
