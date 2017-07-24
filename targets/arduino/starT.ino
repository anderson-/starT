#include "star_t.h"
#include "star_t.c" //FIX

void setup(){
  Serial.begin(9600);
  const char * str = "I46s>I0s>I1s?![2<I1@l-s?!2> l@<l@s+>s]";
  uint8_t* asd = (uint8_t*) str;

  run(asd);
}

void loop(){

}
