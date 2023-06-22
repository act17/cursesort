#include "../cursesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// This function partitions and sorts the array into two halves.
int qpart(int *array, unsigned long *comp, int min, int max, int delay)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = delay;

  int pivot = array[max];
  // This is the numeric value of the index which the two
  // partitions split.
  int index = min - 1;
  double temp;
  for(int i = min; i < max; i++) {
    nanosleep(&ts, &ts);
    *comp = *comp + 1;

    // This routine places numbers on their correct position.
    if(array[i] <= pivot) {
      index++;
      temp = array[i];
      array[i] = array[index];
      array[index] = temp;
    }
  }
  index++;
  // This swap is made to correct the index position.
  temp = array[max];
  array[max] = array[index];
  array[index] = temp;
  return index;
}

// This function serves as a wrapper to qpart();.
void qksrt(int *array, unsigned long *comp, int min, int max, int delay)
{
  if(min >= max || min < 0)
    return;
  int partition = qpart(array, comp, min, max, delay);
  qksrt(array, comp, min, partition - 1, delay);
  qksrt(array, comp, partition + 1, max, delay);
}
