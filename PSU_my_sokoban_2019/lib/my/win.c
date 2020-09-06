/*
** EPITECH PROJECT, 2019
** win
** File description:
** c
*/

#include "my.h"

int win(values_t *idk)
{
    int nbr = 0;

    for (int i = 0; i < idk->nbr_of_O; i++) {
        if (idk->new_map[idk->pos_O[i][0]][idk->pos_O[i][1]] == 'X') {
            nbr++;
        }
    }
    if (nbr == idk->nbr_of_O) {
        return (1);
    } else
        return (0);
}