#include "cursesort.h"
#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void comp(int Y, int X)
{

  // Name-related char*s
  char* anames[5] = {
    "Bubble Sort",
    "Quick Sort",
    "Insertion Sort",
    "Cocktail Sort",
    "Bogo Sort"
  };

  // Nessicary variables:
  int algol = 0;
  int array[32];
  int delay = 12500000;
  int userinput = 0;
  unsigned long comparisons = 0;
  unsigned long elapsedtime = 0;
  double elapsedtimebuffer = 0;
  double elapsedtimeseconds = 0;
  randomizer(array, 0, 32);

  // User Input-Output Loop
  while(userinput != 'q') {

    // Calling Windows:
    WINDOW * mainwin = newwin(36,96,Y,X);
    WINDOW * sortbackground = newwin(34,34,Y + 1,X + 1);
    WINDOW * infowin = newwin(34,56,Y + 1,X + 36);
    WINDOW * arraywin[32];

    for(int i = 0; i < 32; i++)
      arraywin[i] = newwin(array[i],1,(Y + 34) - array[i],X + 2 + i);

    box(mainwin,0,0);
    box(sortbackground,0,0);
    box(infowin,0,0);

    wattron(stdscr,COLOR_PAIR(4));
    wattron(mainwin,COLOR_PAIR(1));
    wattron(sortbackground,COLOR_PAIR(2));
    wattron(infowin,COLOR_PAIR(1));
    wbkgd(stdscr,COLOR_PAIR(4));
    wbkgd(mainwin,COLOR_PAIR(1));
    wbkgd(sortbackground,COLOR_PAIR(2));
    wbkgd(infowin,COLOR_PAIR(1));

    // Printing static info:
    wattron(infowin,A_BOLD);
    mvwprintw(infowin,1,1,"Algorithm:");
    mvwprintw(infowin,3,1,"Delay:");
    mvwprintw(infowin,7,1,"Comparisons:");
    mvwprintw(infowin,9,1,"Elapsed Time:");
    mvwprintw(infowin,11,1,"Array:");
    mvwprintw(infowin,29,1,"Controls:");
    mvwprintw(infowin,30,1,"A - Select Algorithm       | D - Select Delay");
    mvwprintw(infowin,31,1,"S/R - Scramble/Reset Array | RETURN - Begin Sorting");
    mvwprintw(infowin,32,1,"I - Show Info Screen       | Q - Quit CurseSort");
    wattroff(infowin,A_BOLD);


    // Resizing windows in case S/R is used:
    for(int i = 0; i < 32; i++) {
      wbkgd(arraywin[i],COLOR_PAIR(2));
      wrefresh(arraywin[i]);
      wresize(arraywin[i], array[i], 1);
      mvwin(arraywin[i],(Y + 34) - array[i],X + 2 + i);
      wbkgd(arraywin[i],COLOR_PAIR(1));
    }

    // Printing variables:
    mvwprintw(infowin,2,1,"%s        ",anames[algol]);
    mvwprintw(infowin,4,1,"%d ns",delay);
    mvwprintw(infowin,8,1,"%u",comparisons);
    mvwprintw(infowin,10,1,"%lf ms",elapsedtimeseconds);
    for(int i = 0; i < 16; i++)
      mvwprintw(infowin,12,1 + (i * 3),"%d",array[i]);
    for(int i = 0; i < 16; i++)
      mvwprintw(infowin,13,1 + (i * 3),"%d",array[i + 16]);


    // Refreshing:
    wrefresh(stdscr);
    wrefresh(mainwin);
    wrefresh(infowin);
    wrefresh(sortbackground);
    for(int i = 0; i < 32; i++)
      wrefresh(arraywin[i]);
    refresh();

    userinput = getch();
    switch(userinput) {
    case 'a':
      algol = algolsel(Y,X,algol,anames);
      break;
    case 'd':
      delay = delaysel(Y,X);
      break;
    case 's':
      randomizer(array, time(0), 32);
      break;
    case 'r':
      randomizer(array, 0, 32);
      break;
    case 'i':
      infoscreen(Y, X);
      break;
    default:
      break;
    }

    // This is where the sorting stuff begins.
    if(userinput == 10) {
      // Preparing args:
      struct argumentstruct args;
      void *arrayvoid = array;
      int *arraypoint = (int *)arrayvoid;
      args.array = arraypoint;
      args.algol = algol;
      args.delay = delay;
      args.comp = &comparisons;

      struct timespec ts;
      ts.tv_sec = 0;
      ts.tv_nsec = delay;

      // Thread creation:
      pthread_t thread;
      pthread_create(&thread, NULL, sortbranch, &args);

      // Restructuring the array windows:
      int sortedcheck = 1;
      while(1) {
        for(int i = 0; i < 32; i++) {
          wbkgd(arraywin[i],COLOR_PAIR(2));
          wrefresh(arraywin[i]);
          wresize(arraywin[i], array[i], 1);
          mvwin(arraywin[i],(Y + 34) - array[i],X + 2 + i);
          if(array[i] == i + 1) {
            wbkgd(arraywin[i],COLOR_PAIR(3));
            sortedcheck++;
          } else {
            wbkgd(arraywin[i],COLOR_PAIR(1));
            sortedcheck = 1;
          }
          wrefresh(arraywin[i]);
          wrefresh(stdscr);
        }


        if(sortedcheck >= 32)
          break;
        else
          sortedcheck = 1;

        nanosleep(&ts,&ts);
        elapsedtime = elapsedtime + delay;
        elapsedtimebuffer = elapsedtime;
        elapsedtimeseconds = elapsedtimebuffer / 1000000;
        mvwprintw(infowin,8,1,"%u",comparisons);
        mvwprintw(infowin,10,1,"%f ms",elapsedtimeseconds);
        for(int i = 0; i < 16; i++)
          mvwprintw(infowin,12,1 + (i * 3),"%d  ",array[i]);
        for(int i = 0; i < 16; i++)
          mvwprintw(infowin,13,1 + (i * 3),"%d  ",array[i + 16]);
        wrefresh(infowin);
      }

      pthread_cancel(thread);
      wattron(infowin,A_REVERSE);
      wattron(infowin,A_BOLD);
      mvwprintw(infowin,27,1,"Sorting is complete. Press any key to reset.");
      wrefresh(infowin);
      wattroff(infowin,A_REVERSE);
      wattroff(infowin,A_BOLD);
      getch();

      randomizer(array, 0, 32);
      comparisons = 0;
      elapsedtime = 0;
    }
  }

  return;
}
