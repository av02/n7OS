#include <n7OS/console.h>

uint16_t *scr_tab;
int curseur_index;

void init_console() {
    scr_tab= (uint16_t *) SCREEN_ADDR;
    curseur_index = 0;
}

void console_putchar(const char c) {
    if (c >= '!' && c<='~') {
        scr_tab[curseur_index]= CHAR_COLOR<<8|c;
        curseur_index++;
    }//TODO: gestion des caractères echapés
}

void console_putbytes(const char *s, int len) {
    for (int i= 0; i<len; i++) {
        console_putchar(s[i]);
    }
}