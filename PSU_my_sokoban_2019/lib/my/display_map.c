/*
** EPITECH PROJECT, 2019
** display_map
** File description:
** c
*/

#include "my.h"

void display_map(values_t *idk)
{
    for (int i = 0; i < idk->hauteur; i++) {
        move(LINES/2 + i - idk->hauteur/2, COLS/2-idk->lignes[idk->hauteur/2]);
        printw("%s", idk->new_map[i]);
    }
}