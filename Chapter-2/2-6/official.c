#include <stdio.h>

/*
  Exercise 2-6
  Write a function setbits(x,p,n,y)
  that returns x with the n bits that begin at position p
  set to the rightmost n bits of y,
  leaving the other bits unchanged.
  
  Note that p is the position of the leftmost bit of the n ones to set. This
  is somewhat unusual but we follow the convention used in the book for the
  getbits() example.
*/


/*
  In official answer, position 0 is at the right end. So p
  was started at rightmost, but I didn't know that n 
  was chosen form left to right. So I got stuck in why
  (p + 1 - n) for awhile. 
  Position started at rightmost is easier than the leftmost,
  started at leftmost need to know what the number's width.
*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  y = (y & ~(~0 << n)) << (p + 1 - n);
  x = x & ~(~(~0 << n) << (p + 1 - n));
  return x | y;
}

int main()
{
  unsigned x, y;
  int p, n;

  x = 0x0b;
  y = 0x06;
  p = 1;
  n = 2;
  printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n",
         x, p, n, y,
         setbits(x, p, n, y));

  return 0;
}