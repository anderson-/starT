#include <stdio.h>
#include "assert.h"
#define _UNIT_TEST
#include "../src/star_t.h"

int main(void){

  begin_section("");
  assert_eq((run("s{1}"), *M[0]), 1);
  assert_eq((run("s{255}"), *M[0]), 255);
  assert_eq((run("s{252}"), *M[0]), 252);
  assert_eq((run("s{l1}"), ((int16_t*) *M)[0]), 1);
  assert_eq((run("s{l+2}"), ((int16_t*) *M)[0]), 2);
  assert_eq((run("s{l-1}"), ((int16_t*) *M)[0]), -1);
  assert_eq((run("s{-1}"), ((int8_t*) *M)[0]), -1);
  assert_eq((run("s{-10}"), ((int8_t*) *M)[0]), -10);
  assert_eq((run("s{f-3.22e-32}"), ((int8_t*) *M)[0]), 3.22e-32f);
  assert_eq((run("s{b\x01\xFF}"), (*M)[0]), 0xFF);
  assert_eq((run("s{b\x04\xFF\xFF\x23\xFF}"), (*M)[2]), 0x23);
  assert_eq((run("s{b\x04\xFF\x01\x23\x02}"), (*M)[1]), 0x1);
  assert_eq((run("s{b\x04\xFF\x01\x23\x02}"), (*M)[3]), 0x2);
  assert_eq((run("s{b\x01\x01}s{b\x01\x02}"), (*M)[0]), 0x2);
  assert_eq((run("s{b\x01\x01}s{b\x01\x02}s{b\x01\x03}"), (*M)[0]), 0x3);
  end_section();

  end_tests();

  return 0;
}
