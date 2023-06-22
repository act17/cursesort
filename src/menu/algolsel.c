#include "../cursesort.h"
#include <ncurses.h>
#include <stdlib.h>

int algolsel(int Y, int X, int prvalgol, char** anames)
{
  int userinput = 0;
  int highlight = 0;

  WINDOW * mainwin = newwin(36, 96, Y, X);
  WINDOW * selectwin = newwin(12,94,Y+2,X+1);
  wattron(mainwin,COLOR_PAIR(1));
  wattron(selectwin,COLOR_PAIR(2));
  wbkgd(mainwin,COLOR_PAIR(1));
  wbkgd(selectwin,COLOR_PAIR(2));
  box(mainwin,0,0);
  box(selectwin,0,0);
  keypad(stdscr,true);

  wattron(mainwin,A_BOLD);
  wattron(selectwin,A_BOLD);
  mvwprintw(mainwin,1,1,"Algorithm Selection:");
  mvwprintw(mainwin,33,1,"Controls:");
  mvwprintw(mainwin,34,1,"Up/Down/RETURN - Select Algorithm | Q - Leave Without Changing Algorithm");
  wrefresh(mainwin);

  while(1) {
    for(int i = 0; i < NUMBER_OF_ALGORITHMS; i++) {
      if(i == highlight)
        wattron(selectwin,A_REVERSE);
      mvwprintw(selectwin,i + 1, 1, "%s",anames[i]);
      wattroff(selectwin,A_REVERSE);
    }
    wrefresh(selectwin);
    refresh();

    userinput = getch();
    switch(userinput) {
    case KEY_UP:
      if(highlight == 0)
        break;
      highlight--;
      break;
    case KEY_DOWN:
      if(highlight == NUMBER_OF_ALGORITHMS - 1)
        break;
      highlight++;
      break;
    default:
      break;
    }
    if(userinput == 'q' || userinput == 10)
      break;
  }

  if(userinput == 'q')
    return prvalgol;
  else
    return highlight;
}
