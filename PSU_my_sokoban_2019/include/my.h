/*
** EPITECH PROJECT, 2019
** my h
** File description:
** my h
*/

#ifndef MY_H_
#define MY_H_

#include "ncurses.h"
#include "structure.h"

int my_strlen(char const *str);
void move_p_x(values_t *idk);
void move_p_y(values_t *idk);
int win(values_t *idk);
void lose(values_t *idk);
void reset(values_t *idk);
void fill_new_map(values_t *idk);
void display_map(values_t *idk);
int error_map(values_t *idk);

#endif
