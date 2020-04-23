/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "include/nfors.h"

int my_str_size(char *len)
{
    int u = 0;

    for (u = 0; len[u] != '.' && len[u] != '\0'; u++);
    return (u);
}

int check_pos(char *buffer, nfors_t *nfors, char *fonction)
{
    nfors->pos = str_to_word_tab(buffer, ':');
    char *tmp = malloc(sizeof(char) * 4);
    int size = 0;
    int pos = 0;

    for (int i = 0; nfors->pos[i]; i++) {
        if (my_strcmp(nfors->pos[i], "0.0") == 0)
            return (2);
        // write(1, nfors->pos[i], strlen(nfors->pos[i]));
        // write(1, "\n\n\n", 3);
        if (i > 3 && i != 20) {
            size = my_str_size(nfors->pos[i]);
            tmp = strncpy(tmp, nfors->pos[i], size);
            write(1, tmp, strlen(tmp));
            write(1, "\n\n\n", 3);
            pos = atoi(tmp);
            if (pos < 200 && i < 19)
                return (3);
            if (pos < 200 && i > 19)
                return (4);
        }
    }
    return (0);
}

int command(char *fonction, char *buffer, size_t size, nfors_t *nfors)
{
    int check = 0;

    write(1, fonction, strlen(fonction));
    if (getline(&buffer, &size, stdin) <= 1)
        return (1);
    write(2, buffer, strlen(buffer));
    check = check_pos(buffer, nfors, fonction);
    return(check);
}

int main(int ac, char **av)
{
    char *buffer = NULL;
    nfors_t *nfors = malloc(sizeof(nfors_t));
    size_t size;
    int value = 0;

    command("START_SIMULATION\n", buffer, size, nfors);
    while (value != 2) {
        value = command("GET_INFO_LIDAR\n", buffer, size, nfors);
        command("CAR_FORWARD:1\n", buffer, size, nfors);
        if (value == 3)
            command("WHEELS_DIR:0.5\n", buffer, size, nfors);
        else if (value == 4)
            command("WHEELS_DIR:-0.5\n", buffer, size, nfors);
    }
    command("CAR_FORWARD:0\n", buffer, size, nfors);
    puts("STOP_SIMULATION");
    return (0);
}