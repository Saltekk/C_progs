/*
** EPITECH PROJECT, 2019
** reset
** File description:
** c
*/

#include "my.h"

void reset_state_elements(values_t *idk, int l, int x, int y)
{
    if (idk->map[l] == 'P') {
        idk->pos_p_x = x;
        idk->pos_p_y = y;
    }
}

void reset(values_t *idk)
{
    int l = 0;

    for (int i = 0; i <= (idk->hauteur - 1); i++) {
        for (int z = 0; z <= idk->lignes[i]; z++) {
            idk->new_map[i][z] = idk->map[l];
            reset_state_elements(idk, l, z, i);
            l++;
        }
    }
}