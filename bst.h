#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;

typedef struct Node *Tree;

struct Node
{
    char *name;
    Tree content;
    Tree left, right;
};

// Zwraca wezel o nazwie name z drzewa do ktorego nalezy tree
Tree find(Tree tree, char *name);

// Zwraca węzeł o nazwie name_in_content ze srodka węzłow
// np. find_in_content(<bst_lasow>, "Sosna") zwraza wezel drzewa "Sosna"

Tree find_in_content(Tree tree, char *name_in_content);

// Jeśli w drzewie wskazywanym przez tree_pointer
// znajduje się byt o nazwie name - usuwa go i jego zawartość
void remove_value(Tree *tree_pointer, char *name);

//usuwa całe drzewo wskazane przez tree_pointer
void remove_all(Tree *tree_pointer);

// Jeśli w drzewie wskazywanym przez tree_pointer nie występuje wartość x, to zostaje wstawiona.
Tree insert(Tree *tree_pointer, char *name);

// Wypisuje drzewo (infiksowo) w porządku leksykograficznym
void print_all(Tree tree);

#endif
