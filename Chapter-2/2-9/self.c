/*
  Exercise 2-9
  In a two's complement number system,
  x &= (x-1) deletes the rightmost 1-bit in x.
  Explain why. Use this observation to write a faster version of bitcount.
*/
#include <stdio.h>


int bit_count(unsigned x)
{
  int b;
  for (b = 0; x != 0; x &= (x - 1))
    b++;
  return b;
}

int main()
{
  bit_count(12312);
  return 0;
}


/* 
  1011100 & 1011011 => 1011000
  1011000 & 1010111 => 1010000
  1010000 & 1001111 => 1000000
  1000000 & 0111111 => 0000000
*/
