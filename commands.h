#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <stdio.h>
#include "bst.h"

// Dodaje las jeśli go nie ma
Tree add_forest(Tree *world_pointer, char *forest_name);

// Dodaje las i drzewo w lesie jeśli ich nie ma
Tree add_tree(Tree *world_pointer, char *forest_name, char *tree_name);

// Dodaje las, drzewo w lesie i zwierzę żyjące na tym drzewie jeśli ich nie ma
Tree add_animal(Tree *world_pointer, char *forest_name, char *tree_name, char *animal_name);

// Sprawdza, czy istnieje las o danej nazwie.
int check_forest(Tree world, char *forest_name);

// Sprawdza, czy istnieje drzewo o danej nazwie w podanym lesie.
int check_tree(Tree world, char *forest_name, char *tree_name);

// Sprawdza, czy na podanym drzewie w podanym lesie
// żyje zwierzę o danej nazwie.
int check_animal(Tree world, char *forest_name, char *tree_name, char *animal_name);

// CHECK * * zwierzę
int check_animal_anywhere(Tree world, char *animal_name);

// CHECK * drzewo zwierzę
int check_animal_any_forest(Tree world, char *tree_name, char *animal_name);

// CHECK las * zwierzę
int check_animal_any_tree(Tree world, char *forest_name, char *animal_name);

// CHECK * drzewo
int check_tree_anywhere(Tree world, char *tree_name);

// Usuwa wszystkie lasy, wszystkie w nich drzewa i wszystkie zwierzęta żyjące na tych drzewach.
void del_all(Tree *world_pointer);

// Usuwa las, wszystkie w nim drzewa i wszystkie zwierzęta żyjące na tych drzewach.
void del_forest(Tree *world_pointer, char *forest_name);

// Usuwa drzewo w podanym lesie i wszystkie zwierzęta żyjące na tym drzewie.
void del_tree(Tree *world_pointer, char *forest_name, char *tree_name);

// Usuwa zwierzę żyjące na danym drzewie w podanym lesie.
void del_animal(Tree *world_pointer, char *forest_name, char *tree_name, char *animal_name);

// Wypisuje wszystkie lasy istniejące w świecie.
void print_world(Tree world);

// Wypisuje wszystkie drzewa w podanym lesie.
void print_forest(Tree world, char *forest_name);

// Wypisuje wszystkie zwierzęta żyjące na danym drzewie w podanym lesie.
void print_tree(Tree world, char *forest_name, char *tree_name);

#endif
