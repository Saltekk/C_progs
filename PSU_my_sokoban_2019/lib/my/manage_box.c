/*
** EPITECH PROJECT, 2019
** manage_box
** File description:
** c
*/

#include "structure.h"

int manage_box_x_more(values_t *idk, int pos)
{
    if (idk->new_map[idk->pos_p_y][pos] == 'X') {
        if (idk->new_map[idk->pos_p_y][pos + 1] == '#'
        || idk->new_map[idk->pos_p_y][pos + 1] == 'X')
            return (0);
        else
            idk->new_map[idk->pos_p_y][pos + 1] = 'X';
    }
    return (1);
}

int manage_box_x_less(values_t *idk, int pos)
{
    if (idk->new_map[idk->pos_p_y][pos] == 'X') {
        if (idk->new_map[idk->pos_p_y][pos - 1] == '#'
        || idk->new_map[idk->pos_p_y][pos - 1] == 'X')
            return (0);
        else
            idk->new_map[idk->pos_p_y][pos - 1] = 'X';
    }
    return (1);
}

int manage_box_y_more(values_t *idk, int pos)
{
    if (idk->new_map[pos][idk->pos_p_x] == 'X') {
        if (idk->new_map[pos + 1][idk->pos_p_x] == '#'
        || idk->new_map[pos - 1][idk->pos_p_x] == 'X')
            return (0);
        else
            idk->new_map[pos + 1][idk->pos_p_x] = 'X';
    }
    return (1);
}

int manage_box_y_less(values_t *idk, int pos)
{
    if (idk->new_map[pos][idk->pos_p_x] == 'X') {
        if (idk->new_map[pos - 1][idk->pos_p_x] == '#'
        || idk->new_map[pos - 1][idk->pos_p_x] == 'X')
            return (0);
        else
            idk->new_map[pos - 1][idk->pos_p_x] = 'X';
    }
    return (1);
}