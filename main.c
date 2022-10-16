#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void print_tab(char **tab)
{
    for (int line = 0; tab[line]; line += 1)
        printf("%s\n", tab[line]);
}

char **create_tab(int x, int y, char chara)
{
    char **tab = malloc(sizeof(char *) * (y + 1));
    int cmpt;
    int i;
    
    for (cmpt = 0; cmpt < y; cmpt += 1) {
        tab[cmpt] = malloc(sizeof(char) * (x + 1));
        for (i = 0; i < x; i += 1)
            tab[cmpt][i] = chara;
        tab[cmpt][x] = '\0';
    }
    tab[y] = NULL;
    return (tab);
}

int get_x(char **tab)
{
    int len = 0;
    int col;

    for (int line = 1; tab[line]; line += 1) {
        for (col = 0; tab[line][col] != '\0'; col += 1);
        if (col > len)
            len = col;
    }
    return ((len - 1) / 2);
}

int get_y(char **tab)
{
    int line;

    for (line = 0; tab[line]; line += 1);
    return ((line - 1) / 2);
}

void set_center(char **tab, int x, int y)
{
    tab[y][x] = 'X';
    print_tab(tab);
}

void get_center(char **tab)
{
    int px = get_x(tab);
    int py = get_y(tab);

    printf("\nCenter of my pix :\nx: %d\ny: %d\n", px, py);
    set_center(tab, px, py);
}

void free_tab(char **tab)
{
    for (int cmpt = 0; tab[cmpt]; cmpt += 1)
        free(tab[cmpt]);
    free(tab);
}

void print_help(void)
{
    printf("  _______________________________________________________________\n");
    printf(" |                                                               |\n");
    printf(" | This binary create an array with a defined size and character.|\n");
    printf(" | It also display the center of this array.                     |\n");
    printf(" | Usage : ./a.out [x] [y] [character]                           |\n");
    printf(" |                                                               |\n");
    printf(" |                                                       Donat.  |\n");
    printf(" |_______________________________________________________________|\n\n");
}

int main(int argc, char **argv)
{
    char **tab;

    if (argc == 2 && strcmp(argv[1], "--help") == 0)
        print_help();
    else if (argc != 4) {
        write(2, "invalid number of params\n", 25);
        return (84);
    } else {
        tab = create_tab(atoi(argv[1]), atoi(argv[2]), argv[3][0]);
        get_center(tab);
        free_tab(tab);
    }
    return (0);
}