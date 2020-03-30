#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "bst.h"
#include "commands.h"
#include "input_commands.h"

// biale znaki zgodnie z trescia zadania
#define DELIMITERS " \t\v\f\r\n"

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // zmienna na ktorej trzymamy stan swiata (czyli zbior lasow)
    Tree world = NULL;

    // wczytujemy wejscie linia po linii
    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        // omija komentarz oznaczony znakiem #
        if (line[0] == '#')
        {
            continue;
        }

        char *command = strtok(line, DELIMITERS); // PROCEDURA

        // omijam pusta linie i same białe znaki
        if (command == NULL)
        {
            continue;
        }
        char *forest = strtok(NULL, DELIMITERS); // las
        char *tree = strtok(NULL, DELIMITERS);   // drzewo
        char *animal = strtok(NULL, DELIMITERS); // zwierzę

        char *rest = strtok(NULL, DELIMITERS);
        if (rest != NULL)
        {
            fprintf(stderr, "ERROR\n");
            continue;
        }

        run_command(&world, command, forest, tree, animal);
    }

    // zwalnia pamiec przed wyjsciem z programu
    free(line);
    remove_all(&world);
}
