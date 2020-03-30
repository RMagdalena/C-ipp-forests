#ifndef _INPUT_COMMANDS_H_
#define _INPUT_COMMANDS_H_

#include "bst.h"

// Wywołuje komendę command z parametrami forest, tree i animal.
// Parametr command nie moze byc nullem.
// Parametry forest, tree i animal mogą byc nullem, gwiazdka albo konkretna wartoscia.
// Dla niektorych kombinacji parametrow funkcja wypisze ERROR zgodnie z trescia zadania.
void run_command(Tree *world_pointer, char *command, char *forest, char *tree, char *animal);

#endif
