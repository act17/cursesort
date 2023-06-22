#include "../cursesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *sorted, int size, int delay, unsigned long *comp)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = delay;

  int offset = 0;
  int current, next;

  // This loop repeats until the array is garunteed to be sorted.
  for(int a = 0; a < size; a++) {

    // Done to appease GCC.
    current = sorted[offset];

    /* This loop runs through each array entry, and swaps them.
       This repeats until the highest digit (so far) reachest the end
       of the array. */
    for(int b = 1; b < size - a; b++) {

      current = sorted[offset];
      next = sorted[offset + 1];

      nanosleep(&ts, &ts);
      *comp = *comp + 1;

      // This is the comparison. In the case that our current number is
      // higher...
      if(current > next) {
        // We define the array entries as their opposite.
        sorted[offset] = next;
        sorted[offset + 1] = current;
      }

      /* If the opposite is true, then no swap needs to be performed.
         For some reason, this is the determining factor if the sort is
         completed. Why I need to add this else statement or else the sort
         duplicates numbers is unknown - but it's been bugging me for months
         now. */
      else
        current = sorted[offset + 1];

      // Regardless, the offset must be then increased by one for the next pass.
      offset++;
    }

    // Then we need to do a check to ensure that we don't have the special case
    // of the final value. If so, then we do this guard:
    if(a != (size - 1))
      sorted[offset] = current;

    offset = 0;
  }

  return;
}
