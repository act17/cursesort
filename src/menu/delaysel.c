#include <ncurses.h>
#include <stdlib.h>

int delaysel(int Y, int X)
{
  int userinput = 0;
  int highlight = 3;

  char* delaynames[7] = {
    "Snail (100ms/Comparison)",
    "Painful (50ms/Comparison)",
    "Slow (25ms/Comparison)",
    "Medium (12.5ms/Comparison)",
    "Fast (6.25ms/Comparison)",
    "Speedy (3.125ms/Comparison)",
    "Egregious (1.56ms/Comparison)"
  };

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
  mvwprintw(mainwin,1,1,"Delay Selection:");
  mvwprintw(mainwin,33,1,"Controls:");
  mvwprintw(mainwin,34,1,"Up/Down/RETURN - Select Delay | Q - Leave Without Changing Delay");
  wrefresh(mainwin);

  while(1) {
    for(int i = 0; i < 7; i++) {
      if(i == highlight)
        wattron(selectwin,A_REVERSE);
      mvwprintw(selectwin,i + 1, 1, "%s",delaynames[i]);
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
      if(highlight == 6)
        break;
      highlight++;
      break;
    default:
      break;
    }
    if(userinput == 'q' || userinput == 10)
      break;
  }

  int delay = 0;
  switch(highlight) {
  case 0:
    delay = 100000000;
    break;
  case 1:
    delay = 50000000;
    break;
  case 2:
    delay = 25000000;
    break;
  case 3:
    delay = 12500000;
    break;
  case 4:
    delay = 6250000;
    break;
  case 5:
    delay = 3125000;
    break;
  case 6:
    delay = 1562500;
    break;
  default:
    break;
  }

  return delay;
}
