/*
** EPITECH PROJECT, 2020
** nfors.h
** File description:
** nfors.h
*/

#ifndef NFORS_H
#define NFORS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct nfors_s
{
    char **pos;
} nfors_t;

char **str_to_word_tab(char *board, char a);
int my_strcmp(char const *s1, char const *s2);

#endif /* !NFORS_H */
