#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bogosort(int* array, int size, int delay, unsigned long* comp)
{

  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = delay;

  int sortedcheck = 0;
  int offset,ud,buffer;

  while(sortedcheck < size - 1) {
    // Shuffling, based on randomizer.c
    for(int i = 0; i < size; i++) {
      buffer = array[i];
      ud = rand() % 2;
      offset = rand() % size + 1;
      if(ud == 0) {
        if(offset + i > size - 1) {
          array[i] = array[(i + offset) - size];
          array[(i + offset) - size] = buffer;
        } else {
          array[i] = array[i + offset];
          array[i + offset] = buffer;
        }
      }
      if(ud == 1) {
        if(i - offset < 0) {
          array[i] = array[size - (offset - i)];
          array[size - (offset - i)] = buffer;
        } else {
          array[i] = array[i - offset];
          array[i - offset] = buffer;
        }
      }
    }
    // Checking to see if it's sorted
    for(int i = 0; i < size - 1; i++) {
      nanosleep(&ts, &ts);
      *comp = *comp + 1;
      if(array[i] < array[i + 1])
        sortedcheck++;
      else {
        sortedcheck = 0;
        break;
      }
    }
  }

}
