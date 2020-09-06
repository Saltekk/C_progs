/*
** EPITECH PROJECT, 2019
** first_try
** File description:
** c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my.h"
#include <stdlib.h>
#include <ncurses.h>

int start(values_t *idk)
{
    initscr();
    while (1) {
        noecho();
        curs_set(0);
        move_p_x(idk);
        move_p_y(idk);
        if (idk->command == ' ')
            reset(idk);
        lose(idk);
        display_map(idk);
        if (idk->box_stuck == idk->nbr_of_X || win(idk) == 1) {
            refresh();
            break;
        }
        idk->command = getch();
        noecho();
        refresh();
    }
    endwin();
    return (0);
}

void size_lines(values_t *idk)
{
    int n = 0;
    int num_ligne = 0;
    idk->lignes = malloc(sizeof(int)* idk->hauteur + 1);
    idk->pos_O = malloc(sizeof(int *)* idk->nbr_of_O);
    for (int n = 0; n < idk->nbr_of_O; n++) {
        idk->pos_O[n] = malloc(sizeof(int)* 3);
    }
    idk->pos_X = malloc(sizeof(int *)* idk->nbr_of_X);
    for (int z = 0; z < idk->nbr_of_X; z++) {
        idk->pos_X[z] = malloc(sizeof(int)* 3);
    }
    for (int l = 0; l < idk->len; l++) {
        if (idk->map[l] == '\n') {
            idk->lignes[num_ligne] = n;
            num_ligne++;
            n = 0;
        }
        else
            n++;
    }
}

void height(values_t *idk)
{
    idk->nbr_of_O = 0;
    idk->nbr_of_X = 0;
    idk->hauteur = 0;

    for (int i = 0; i < idk->len; i++) {
        if (idk->map[i] == 'X')
            idk->nbr_of_X++;
        if (idk->map[i] == 'O')
            idk->nbr_of_O++;
        if (idk->map[i] == '\n')
            idk->hauteur++;
    }
}

int map(char *filepath, values_t *idk)
{
    struct stat data;
    int test = stat(filepath, &data);
    if (test == -1)
        return (84);
    idk->len = data.st_size;
    idk->map = malloc(sizeof(char) * (idk->len + 1));
    if (idk->map == NULL)
        return (84);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    int error = read(fd, idk->map, idk->len);
    idk->map[idk->len] = '\0';
    if (error == -1)
        return (84);
    height(idk);
    size_lines(idk);
    fill_new_map(idk);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "WELCOME to my_sokoban, try to push "
        "all the boxes(X) on their place(O) and Win, if you block "
        "all the boxes you Lose. You play the Player (P), Good luck !\n", 154);
    }
    values_t idk;
    int valeur = map(av[1], &idk);
    if (valeur == 84)
        return (84);
    int retour = error_map(&idk);
    if (retour == 84)
        return (84);
    valeur = start(&idk);
    if (win(&idk) == 1)
        return (0);
    if (idk.box_stuck == idk.nbr_of_X)
        return (1);
    return (valeur);
}
