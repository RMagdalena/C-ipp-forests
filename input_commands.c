#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "commands.h"

void ok()
{
    printf("OK\n");
}

void yes_no(int i)
{
    if (i)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

void error()
{
    fprintf(stderr, "ERROR\n");
}

// ADD
void add_command(Tree *world_pointer, char *forest, char *tree, char *animal)
{
    if (forest && !tree && !animal) // ADD las
    {
        add_forest(world_pointer, forest);
        ok();
    }
    else if (forest && tree && !animal) // ADD las drzewo
    {
        add_tree(world_pointer, forest, tree);
        ok();
    }
    else if (forest && tree && animal) // ADD las drzewo zwierzę
    {
        add_animal(world_pointer, forest, tree, animal);
        ok();
    }
    else // BŁĄD
    {
        error();
    }
}

// DEL
void del_command(Tree *world_pointer, char *forest, char *tree, char *animal)
{
    if (!forest && !tree && !animal) // DEL
    {
        del_all(world_pointer);
        ok();
    }
    else if (forest && !tree && !animal) // DEL las
    {
        del_forest(world_pointer, forest);
        ok();
    }
    else if (forest && tree && !animal) // DEL las drzewo
    {
        del_tree(world_pointer, forest, tree);
        ok();
    }
    else if (forest && tree && animal) // DEL las drzewo zwierzę
    {
        del_animal(world_pointer, forest, tree, animal);
        ok();
    }
    else // BŁĄD
    {
        error();
    }
}

// PRINT
void print_command(Tree world, char *forest, char *tree, char *animal)
{
    if (!forest && !tree && !animal) // PRINT
    {
        print_world(world);
    }
    else if (forest && !tree && !animal) // PRINT las
    {
        print_forest(world, forest);
    }
    else if (forest && tree && !animal) // PRINT las drzewo
    {
        print_tree(world, forest, tree);
    }
    else // BŁĄD
    {
        error();
    }
}

// CHECK
void check_command(Tree world, char *forest, char *tree, char *animal)
{
    if (!forest && !tree && !animal) // CHECK
    {
        error();
    }
    else if (forest && !tree && !animal) // CHECK las
    {
        if (strcmp(forest, "*") == 0) // CHECK *
        {
            error();
        }
        else
        {
            int check = check_forest(world, forest);
            yes_no(check);
        }
    }
    else if (forest && tree && !animal) // CHECK las drzewo
    {
        if (strcmp(tree, "*") == 0) // CHECK _ *
        {
            error();
        }
        else
        {
            int check = 0;
            if (strcmp(forest, "*") == 0) // CHECK * drzewo
            {
                check = check_tree_anywhere(world, tree);
            }
            else
            {
                check = check_tree(world, forest, tree);
            }
            yes_no(check);
        }
    }
    else if (forest && tree && animal) // CHECK las drzewo zwierzę
    {
        if (strcmp(animal, "*") == 0) // CHECK _ _ *
        {
            error();
        }
        else
        {
            int check = 0;
            if ((strcmp(forest, "*") == 0) && (strcmp(tree, "*") == 0)) // CHECK * * zwierzę
            {
                check = check_animal_anywhere(world, animal);
            }
            else if (strcmp(forest, "*") == 0) // CHECK * drzewo zwierzę
            {
                check = check_animal_any_forest(world, tree, animal);
            }
            else if (strcmp(tree, "*") == 0) // CHECK las * zwierzę
            {
                check = check_animal_any_tree(world, forest, animal);
            }
            else
            {
                check = check_animal(world, forest, tree, animal);
            }
            yes_no(check);
        }
    }
    else // BŁĄD
    {
        error();
    }
}

void run_command(Tree *world_pointer, char *command, char *forest, char *tree, char *animal)
{
    if (strcmp(command, "ADD") == 0)
    {
        add_command(world_pointer, forest, tree, animal);
    }
    else if (strcmp(command, "PRINT") == 0)
    {
        print_command(*world_pointer, forest, tree, animal);
    }
    else if (strcmp(command, "DEL") == 0)
    {
        del_command(world_pointer, forest, tree, animal);
    }
    else if (strcmp(command, "CHECK") == 0)
    {
        check_command(*world_pointer, forest, tree, animal);
    }
    else
    {
        error();
    }
}
