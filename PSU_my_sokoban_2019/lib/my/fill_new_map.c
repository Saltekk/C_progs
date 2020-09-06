/*
** EPITECH PROJECT, 2019
** fill_new_map
** File description:
** c
*/

#include "my.h"
#include <stdlib.h>

void fill_new_map(values_t *idk)
{
    int l = 0;
    idk->pos_p_x = 0;
    idk->pos_p_y = 0;
    idk->num_O = 0, idk->num_X = 0;

    idk->new_map = malloc(sizeof(char *) *idk->hauteur + 1);
    for (int l = 0; l <= idk->hauteur; l++) {
        idk->new_map[l] = malloc(sizeof(char)* idk->lignes[l] + 1);
    }
    for (int y = 0; y <= (idk->hauteur - 1); y++) {
        for (int x = 0; x <= idk->lignes[y]; x++) {
            idk->new_map[y][x] = idk->map[l];
            state_elements(idk, l, x, y);
            l++;
        }
    }
}