/*
** EPITECH PROJECT, 2019
** verif_map
** File description:
** c
*/

#include "my.h"

int error_map(values_t *idk)
{
    for (int i = 0; idk->map[i] != '\0'; i++) {
        if (idk->map[i] != '\n' && idk->map[i] != 'P' && idk->map[i] != 'O'
        && idk->map[i] != ' ' && idk->map[i] != 'X' && idk->map[i] != '#') {
            return (84);
        }
    }
    return (0);
}