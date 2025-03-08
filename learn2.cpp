#include "curses.h"

int main()
{
  int ch;
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  ch = getch();
  if (ch == KEY_F(10))
  {
    printw("F10 Key pressed");
  }
  else
  {
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%c\n", ch);
    attroff(A_BOLD);
  }

  refresh();
  getch();
  endwin();
}
