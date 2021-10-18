/*
  Exercise 2-6
  Write a function setbits(x,p,n,y)
  that returns x with the n bits that begin at position p
  set to the rightmost n bits of y,
  leaving the other bits unchanged.
*/

#include <stdio.h>

int bitlen(unsigned d)
{
  int len = 0;
  for (; d; d >>= 1)
    len++;
  return len;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
  unsigned x_len = bitlen(x);
  unsigned y_len = bitlen(y);

  if (x_len < p + n || y_len < n)
  {
    printf("Error: illegal p or n.\n");
    return 0;
  }
  else
  {
    unsigned x_tail_len = x_len - p - n;
    unsigned x_right = x & ~(~0 << x_tail_len);
    /*
      ~0 => all 32 bits are 1
      in this case, x_tail_len == 3, so we got ...1000
      we got 0111 in right part
      x & 0111 is done to got the x.rightmost 3 bits
    */
    unsigned replace = y & ~(~0 << n); // done to get the y.rightmost n bits
    
    x >>= x_len - p;
    x <<= n;
    x |= replace;
    x <<= x_tail_len;
    x |= x_right;

    printf("setbits(11, 1, 2, 6) -> %u\n", x);
    return 0;
  }
}

int main()
{
  setbits(11, 1, 2, 6);
  setbits(11, 3, 2, 6);
}

/*
  Thoughts: 
    It's quite difficult for me at the first time since I am a beginer.
    But when you understood what those meaning, it became easily. 
    Try to thinking in binary when you are looking at a digit.
*/