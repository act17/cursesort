#include "cursesort.h"
#include <ncurses.h>
#include <stdlib.h>

int main()
{

  // NCurses init routine.
  initscr();
  start_color();
  cbreak();
  noecho();

  int MaxY, MaxX;
  getmaxyx(stdscr, MaxY, MaxX);
  if(MaxY < 36 || MaxX < 94) {
    echo();
    endwin();
    printf("\n\nError!\nScreen too small!");
    printf("\nYour Y:	%d\nYour X:	%d", MaxY, MaxX);
    printf("\nMinimum:	36\n		94");
    return 1;
  }

  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_WHITE,COLOR_BLACK);
  init_pair(3,COLOR_GREEN,COLOR_GREEN);
  init_pair(4,COLOR_CYAN,COLOR_CYAN);

  comp((MaxY - 36) / 2, (MaxX - 94) / 2);

  echo();
  clear();
  endwin();
  return 0;
}
