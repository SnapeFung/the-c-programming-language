/*
  Exercise 2-6
  Write a function setbits(x,p,n,y)
  that returns x with the n bits that begin at position p
  set to the rightmost n bits of y,
  leaving the other bits unchanged.

  ! This is a modified version
  ! In this version, we chose leftmost as the position 0
*/

#include <stdio.h>

void bin(unsigned n)
{
  for (unsigned i = 1 << 31; i > 0; i /= 2)
    (n & i) ? printf("1") : printf("0");
  printf("\n");
}

int bit_len(unsigned d)
{
  int len = 0;
  for (; d; d >>= 1)
    len++;
  return len;
}

unsigned get_bits(unsigned int x, int p, int n, unsigned int y)
{
  y = ((~((unsigned)(~0) << n) & y) << bit_len(x) - p - n);                                     // 0_nr << len-p-n
  x = (~((unsigned)(~0) >> (32 - bit_len(x) + p)) & x) | (~((~0) << (bit_len(x) - p - n)) & x); // r0 | 0r => r0r
  return x | y;
}

int main()
{
  unsigned x, y;
  int p, n;
  x = 99;
  y = 123;
  p = 3;
  n = 3;
  printf("x: ");
  bin(x);

  printf("y: ");
  bin(y);

  bin(get_bits(x, p, n, y));

  return 0;
}
