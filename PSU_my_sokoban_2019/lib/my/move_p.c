/*
** EPITECH PROJECT, 2019
** move_p
** File description:
** c
*/

#include "my.h"

void respawn_O(values_t *idk)
{
    for (int i = 0; i < idk->nbr_of_O; i++) {
        if (idk->pos_p_y == idk->pos_O[i][0]
        && idk->pos_p_x == idk->pos_O[i][1])
            idk->new_map[idk->pos_p_y][idk->pos_p_x] = 'O';
    }
}

int manage_barriers_y(values_t *idk, int pos)
{
    if (idk->new_map[pos][idk->pos_p_x] == '#')
        return (1);
    return (0);
}

int manage_barriers_x(values_t *idk, int pos)
{
    if (idk->new_map[idk->pos_p_y][pos] == '#')
        return (1);
    return (0);
}

void move_p_y(values_t *idk)
{
    if (idk->command == 65) {
        if (manage_barriers_y(idk, idk->pos_p_y - 1) != 1
        && manage_box_y_less(idk, idk->pos_p_y - 1) == 1) {
            idk->new_map[idk->pos_p_y][idk->pos_p_x] = ' ';
            idk->new_map[idk->pos_p_y - 1][idk->pos_p_x] = 'P';
            respawn_O(idk);
            idk->pos_p_y--;
        }
    }
    if (idk->command == 66) {
        if (manage_barriers_y(idk, idk->pos_p_y + 1) != 1
        && manage_box_y_more(idk, idk->pos_p_y + 1) == 1) {
            idk->new_map[idk->pos_p_y][idk->pos_p_x] = ' ';
            idk->new_map[idk->pos_p_y + 1][idk->pos_p_x] = 'P';
            respawn_O(idk);
            idk->pos_p_y++;
        }
    }
}

void move_p_x(values_t *idk)
{
    if (idk->command == 67) {
        if (manage_barriers_x(idk, idk->pos_p_x + 1) != 1
        && manage_box_x_more(idk, idk->pos_p_x + 1) == 1) {
            idk->new_map[idk->pos_p_y][idk->pos_p_x] = ' ';
            idk->new_map[idk->pos_p_y][idk->pos_p_x + 1] = 'P';
            respawn_O(idk);
            idk->pos_p_x++;
        }
    }
    if (idk->command == 68) {
        if (manage_barriers_x(idk, idk->pos_p_x - 1) != 1
        && manage_box_x_less(idk, idk->pos_p_x - 1) == 1) {
            idk->new_map[idk->pos_p_y][idk->pos_p_x] = ' ';
            idk->new_map[idk->pos_p_y][idk->pos_p_x - 1] = 'P';
            respawn_O(idk);
            idk->pos_p_x--;
        }
    }
}
