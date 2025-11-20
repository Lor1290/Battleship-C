#include <ncurses.h> 

int main(void) {
    initscr();              // initialize the screen
    raw();                  // get input without waiting for the "\n" char 
    keypad(stdscr, TRUE);   // accept special char 
    noecho();               // don't output the input of the user  
    
    int loop = 1;
    int chr;

    while(loop) {
        chr  = getch();

        switch(chr) {
            case KEY_F(1): { 
                printw("F1");
                loop = 0;
                break;
            }     
            
            case KEY_F(2): 
                printw("F2");
                break;

            case KEY_F(3): 
                printw("F3");
                break;

            case KEY_F(4):
                printw("F4");
                break;

            case KEY_F(5): 
                printw("F5"); 
                break;

            case KEY_F(6): 
                printw("F6"); 
                break;

            case KEY_F(7): 
                printw("F7");
                break;
      
            case KEY_F(8):
                printw("F8");
                break;

            case KEY_F(9): 
                printw("F9");
                break;

            default:
                printw("%c", chr); 
                break;
        }
       printw(" Key Pressed\n");
       refresh();
    }

    printw("Press a key to exit...");
    refresh();
    getch();

    endwin();

    return 0;
}
