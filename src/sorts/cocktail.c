#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Homemade Cocktail-Shaker Sort, made without the use of pseudocode.
// There's probably a more effecient way to do this.
void cocktailsort(int* array, int size, int delay, unsigned long *comp)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = delay;

  int current,next;
  int offset = 0;


  for(int a = 0; a < size; a++) {

    for(int b = 1; b < size - a; b++) {
      current = array[offset];
      next = array[offset + 1];
      nanosleep(&ts, &ts);
      *comp = *comp + 1;
      if(current > next) {
        array[offset] = next;
        array[offset + 1] = current;
      } else
        current = array[offset + 1];
      offset++;
    }

    if(a != size - 1)
      array[offset] = current;
    offset = size - 1;

    for(int b = 1; b < size - a; b++) {
      current = array[offset];
      next = array[offset - 1];
      nanosleep(&ts, &ts);
      *comp = *comp + 1;
      if(current < next) {
        array[offset] = next;
        array[offset - 1] = current;
      } else
        current = array[offset - 1];
      offset--;
    }

    if(a != size - 1)
      array[offset] = current;
    offset = 0;
  }


  return;
}
