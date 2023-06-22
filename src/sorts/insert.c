#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../cursesort.h"

void insertion(int *sorted, int size, int delay, unsigned long *comp)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = delay;

  int Temp;

  // These two loops compare each element to eachother,
  // and swaps in the case one is greater than the other.
  for(int a = 0; a < size; a++) {
    for(int b = 0; b < size; b++) {
      // We do the comparison stuff...
      nanosleep(&ts,&ts);
      *comp = *comp + 1;
      // In the case we need to swap;
      if(sorted[a] < sorted[b]) {
        Temp = sorted[a];
        sorted[a] = sorted[b];
        sorted[b] = Temp;
      }
    }
  }

  return;
}
