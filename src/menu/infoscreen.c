#include <ncurses.h>
#include "../cursesort.h"

void infoscreen(int Y, int X)
{

  WINDOW * infowin = newwin(36, 96, Y, X);
  wbkgd(infowin,COLOR_PAIR(1));
  wattron(infowin,COLOR_PAIR(1));
  box(infowin,0,0);

  wattron(infowin,A_BOLD);
  mvwprintw(infowin,1,1,"CurseSort by ACT");
  mvwprintw(infowin,2,1,"%s  -  %s",VERSION_ID,VERSION_DATE);
  wattroff(infowin,A_BOLD);

  mvwprintw(infowin,3,1,"CurseSort is a Curses-based tool used to display various Sorting Algorithms.");

  mvwprintw(infowin,5,1,"For help, please refer to README.md.");

  mvwprintw(infowin,7,1,"CurseSort is free software, covered by the GNU General Public License. There is NO warranty;");
  mvwprintw(infowin,8,1,"not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. You are welcome to");
  mvwprintw(infowin,9,1,"change and distribute copies under certain conditions. See the source for more");
  mvwprintw(infowin,10,1,"information.");

  mvwprintw(infowin,13,1,"Copyright 2023 ACT");
  mvwprintw(infowin,14,1,"https://github.com/act17/cursesort");

  wattron(infowin,A_REVERSE);
  mvwprintw(infowin,16,1,"STRIKE ANY KEY TO RETURN TO THE PREVIOUS SCREEN.");

  wrefresh(infowin);
  wrefresh(stdscr);
  getch();

  return;
}
