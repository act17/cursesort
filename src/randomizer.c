#include <stdlib.h>

// This function takes int* array and randomizes it.
void randomizer(int* array, int seed, int size)
{
  srand(seed);
  for(int i = 0; i < size; i++)
    array[i] = i + 1;
  int offset,ud,buffer;

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

  return;
}
