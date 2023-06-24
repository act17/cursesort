# cursesort
A Curses-Based Sorting Algorithm Display

Current Version:

Release 1.1.0 | 2023/06/24


# Description

  CurseSort is a tool used to display various sorting algorithms using the Curses library.


# Compiling

  To compile CurseSort, simply navigate to the directory in which the source has been cloned to, and run the command ``make`` to compile. Simply run the binary ``cursesort`` to begin the program.


# Usage

  To use CurseSort, simply follow the onscreen instructions to select your sorting algorithm, your delay, and scramble or reset the array. Press the RETURN key to begin sorting, and Q to exit.


# Changelog

  Release 1.1.0 (2023/06/24)
  - Added two new files, ``./src/sorts/cocktail.c`` and ``./src/sorts/bogo.c``. These two files contain functions for Cocktail-Sort (``void cocktailsort(int* array, int size, int delay, unsigned long* comp``) and Bogo-Sort (``void bogosort(int* array, int size, int delay, unsigned long* comp)``.
  - The number of speeds the user can choose for the process of sorting has increased from 3 to 7, randing from 100ms/Comparison to 1.56ms/Comparison speeds. This change is reflected in ``delaysel.c``.
  - A new feature has been introduced to ``void comp()`` - the display of the current array in the center of the information window.
  - Headers in ``cursesort.c`` have been updated to reflect the increase in sorting algorithms. ``branch.c`` has also been updated to reflect this change.
  - The two new files added have been added to ``Makefile``.

  Release 1.0.0 (2023/06/22)
  - Added ``Makefile``.
  - Added the directory ``./src/``.
    - Added file ``main.c``, which includes ``int main()``, which handles Curses initialization.
    - Added file ``comp.c``, which includes ``void comp(int Y, int X)``, which acts as a function that gathers parameters for sorting, and handles the visual sorting process.
    - Added file ``randomizer.c``, which includes ``void randomizer(int* array, int seed, int size)``, which randomly shuffles the array.
    - Added file ``cursesort.h``, the header file for the program.
  - Added directory ``./src/menu/``.
    - Added file ``algolsel.c``, which includes ``int algolsel(int Y, int X, int prvalgol, char** anames)``, which allows the user to select a sorting algorithm of their choice.
    - Added file ``delaysel.c``, which includes ``int delaysel(int Y, int X)``, which permits the user to select a delay of either "Slow", "Medium", or "Fast" speeds.
    - Added file ``infoscreen.c``, which includes ``void infoscreen(int Y, int X)``. It simply displays information about the program.
  - Added directory ``./src/sorts/``.
    - Added file ``branch.c``, which includes ``void* sortbranch(void* args)``. It functions as a wrapper to the (currently) three sorts in the program.
    - Added file ``bubble.c``, which includes ``void bubble(int* sorted, int size, int delay, unsigned long* comp)``, which performs bubble-sort.
    - Added file ``quick.c``, which includes ``void qksrt(int* array, unsigned long* comp, int min, int max, int delay)``, which performs quick-sort.
    - Added file ``insertion.c``, which includes ``void insertion(int* sorted, int size, int delay, unsigned long* comp)``. It performs insertion sort.