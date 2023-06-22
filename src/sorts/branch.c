#include "../cursesort.h"
#include <stdlib.h>

void* sortbranch(void* args)
{
  struct argumentstruct *sortargs = args;
  switch(sortargs->algol) {
  case 0:
    bubble(sortargs->array, 32, sortargs->delay, sortargs->comp);
    break;
  case 1:
    qksrt(sortargs->array, sortargs->comp, 0, 31, sortargs->delay);
    break;
  case 2:
    insertion(sortargs->array, 32, sortargs->delay, sortargs->comp);
    break;
  default:
    bubble(sortargs->array, 32, sortargs->delay, sortargs->comp);
    break;
  }
  return NULL;
}
