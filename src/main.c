#include <ncurses.h>

int main(void) {
    initsrc();
    cbreak();
    noecho();

    noqiflush();
    keypad(stdsrc, TRUE);

    return 0;
}
