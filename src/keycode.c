#include <ncurses.h>
#include <signal.h>  // For signal handling
#include <stdlib.h>  // For exit()

// Signal handler function
void handle_sigint(int sig) {
    endwin();  // End ncurses mode before exiting
    exit(0);   // Exit the program
}

int main() {
    int key;

    // Initialize ncurses screen
    initscr();
    raw();      // Line buffering disabled, pass key presses directly to program
    keypad(stdscr, TRUE);  // Enable keypad mode for arrow keys
    noecho();   // Don't echo key presses to screen

    // Register signal handler for Ctrl+C
    signal(SIGINT, handle_sigint);

    printw("Press Arrow keys (Up, Down, Left, Right) to see their keycodes.\n");
    printw("Press Ctrl+C to exit.\n");
    refresh();

    while (1) {
        key = getch();  // Get key code

        // Check for arrow keys
        switch (key) {
            case KEY_UP:
                printw("Up Arrow key pressed! Key code: %d\n", key);
                break;
            case KEY_DOWN:
                printw("Down Arrow key pressed! Key code: %d\n", key);
                break;
            case KEY_LEFT:
                printw("Left Arrow key pressed! Key code: %d\n", key);
                break;
            case KEY_RIGHT:
                printw("Right Arrow key pressed! Key code: %d\n", key);
                break;
            case 'q':  // Exit on 'q'
            case 'Q':
                endwin();  // End ncurses mode
                return 0;
            default:
                printw("Key pressed: %c (%d)\n", key, key);
                break;
        }
        refresh();
    }

    // This part is unreachable due to the signal handler
    endwin();  // End ncurses mode
    return 0;
}