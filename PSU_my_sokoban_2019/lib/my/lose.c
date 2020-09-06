/*
** EPITECH PROJECT, 2019
** verif_lose
** File description:
** c
*/

#include "my.h"

int walls(int y, int x, values_t *idk)
{
    if (idk->new_map[y][x] == 'X') {
        if ((idk->new_map[y][x + 1] == '#' || idk->new_map[y][x + 1] == 'X')
        && (idk->new_map[y + 1][x] == '#' || idk->new_map[y + 1][x] == 'X'
        || idk->new_map[y - 1][x] == '#' || idk->new_map[y - 1][x] == 'X')) {
                return (1);
        }
        if (idk->new_map[y][x - 1] == '#' || idk->new_map[y][x - 1] == 'X') {
            if (idk->new_map[y + 1][x] == '#' || idk->new_map[y + 1][x] == 'X'
            || idk->new_map[y - 1][x] == '#' || idk->new_map[y - 1][x] == 'X')
                return (1);
        }
    }
    return (0);
}

void lose(values_t *idk)
{
    idk->box_stuck = 0;
    for (int y = 0; y <= (idk->hauteur - 1); y++) {
        for (int x = 0; x <= idk->lignes[y]; x++) {
            idk->box_stuck += walls(y, x, idk);
            move(0, 0);
        }
    }
}