/*
** EPITECH PROJECT, 2019
** position_element
** File description:
** c
*/

#include "structure.h"

void state_elements(values_t *idk, int l, int x, int y)
{
    if (idk->map[l] == 'P') {
        idk->pos_p_x = x;
        idk->pos_p_y = y;
    }
    if (idk->map[l] == 'X') {
        idk->pos_X[idk->num_X][0] = y;
        idk->pos_X[idk->num_X][1] = x;
        idk->num_X++;
    }
    if (idk->map[l] == 'O') {
        idk->pos_O[idk->num_O][0] = y;
        idk->pos_O[idk->num_O][1] = x;
        idk->num_O++;
    }
}
