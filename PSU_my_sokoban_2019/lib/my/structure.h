/*
** EPITECH PROJECT, 2019
** structure
** File description:
** h
*/

typedef struct values {
    int *lignes;
    char *map;
    char **new_map;
    int **pos_X;
    int **pos_O;
    int nbr_of_X;
    int nbr_of_O;
    int pos_p_x;
    int pos_p_y;
    int hauteur;
    int len;
    int num_O;
    int num_X;
    int command;
    int box_stuck;
} values_t;
