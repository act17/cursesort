#ifndef _CURSESORT_H
#define _CURSESORT_H

void comp(int Y, int X);
void infoscreen(int Y, int X);
void randomizer(int* array, int seed, int size);

int algolsel(int Y, int X, int prvalgol, char** anames);
int delaysel(int Y, int X);

void* sortbranch(void* args);
void bubble(int* sorted, int size, int delay, unsigned long* comp);
void qksrt(int* array, unsigned long* comp, int min, int max, int delay);
void insertion(int* sorted, int size, int delay, unsigned long* comp);
struct argumentstruct {
  int algol;
  int delay;
  int *array;
  unsigned long *comp;
};

#define NUMBER_OF_ALGORITHMS 3
#define VERSION_ID "Relase 1.0.0"
#define VERSION_DATE "2023-06-22"

#endif
