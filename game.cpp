#include <ncurses.h>


int main() {
    const char *items[] = {"2 Pemain", "Lawan Komputer", "Cara Main", "Keluar"};
    const int N = 4;
    int sel = 0;

    initscr();              
    cbreak();               
    noecho();               
    keypad(stdscr, TRUE);   
    curs_set(0);            

    while (true) {
        erase();
        mvprintw(1, 4, "=== TIC TAC TOE ===");

        for (int i = 0; i < N; i++) {
            if (i == sel) attron(A_REVERSE);   
            mvprintw(3 + i, 4, " %s ", items[i]);
            attroff(A_REVERSE);
        }

        mvprintw(9, 4, "Panah: pilih | Enter: OK");
        refresh();

        int ch = getch();
        if (ch == KEY_UP && sel > 0) sel--;
        else if (ch == KEY_DOWN && sel < N - 1) sel++;
        else if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) break;
    }

    endwin();               
    printf("Kamu memilih: %s\n", items[sel]);
    return 0;
}