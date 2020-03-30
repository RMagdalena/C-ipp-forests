#include <stdio.h>
#include "bst.h"
#include "commands.h"

Tree add_forest(Tree *world_pointer, char *forest_name)
{
    return insert(world_pointer, forest_name);
}

Tree add_tree(Tree *world_pointer, char *forest_name, char *tree_name)
{
    Tree forest = add_forest(world_pointer, forest_name);
    return insert(&forest->content, tree_name);
}

Tree add_animal(Tree *world_pointer, char *forest_name, char *tree_name, char *animal_name)
{
    Tree tree = add_tree(world_pointer, forest_name, tree_name);
    return insert(&tree->content, animal_name);
}

int check_forest(Tree world, char *forest_name)
{
    return find(world, forest_name) != NULL;
}

int check_tree(Tree world, char *forest_name, char *tree_name)
{
    Tree forest = find(world, forest_name);
    if (forest)
    {
        return find(forest->content, tree_name) != NULL;
    }
    return 0;
}

int check_animal(Tree world, char *forest_name, char *tree_name, char *animal_name)
{
    Tree forest = find(world, forest_name);
    if (forest)
    {
        Tree tree = find(forest->content, tree_name);
        if (tree)
        {
            return find(tree->content, animal_name) != 0;
        }
        return 0;
    }
    return 0;
}

int check_tree_anywhere(Tree world, char *tree_name)
{
    return find_in_content(world, tree_name) != NULL;
}

int check_animal_anywhere(Tree world, char *animal_name)
{
    int ret = 0;
    if (world)
    {
        ret = find_in_content(world->content, animal_name) != 0;
        if (ret == 0)
        {
            ret = check_animal_anywhere(world->left, animal_name) != 0;
        }
        if (ret == 0)
        {
            ret = check_animal_anywhere(world->right, animal_name) != 0;
        }
    }
    return ret;
}

int check_animal_any_forest(Tree world, char *tree_name, char *animal_name)
{
    int ret = 0;
    if (world)
    {
        Tree tree = find(world->content, tree_name);
        if (tree)
        {
            ret = find(tree->content, animal_name) != 0;
        }
        if (ret == 0)
        {
            ret = check_animal_any_forest(world->left, tree_name, animal_name) != 0;
        }
        if (ret == 0)
        {
            ret = check_animal_any_forest(world->right, tree_name, animal_name) != 0;
        }
    }
    return ret;
}

int check_animal_any_tree(Tree world, char *forest_name, char *animal_name)
{
    Tree forest = find(world, forest_name);
    if (forest)
    {
        return find_in_content(forest->content, animal_name) != NULL;
    }
    return 0;
}

void del_all(Tree *world_pointer)
{
    remove_all(world_pointer);
}

void del_forest(Tree *world_pointer, char *forest_name)
{
    remove_value(world_pointer, forest_name);
}

void del_tree(Tree *world_pointer, char *forest_name, char *tree_name)
{
    Tree forest = find(*world_pointer, forest_name);
    if (forest)
    {
        remove_value(&forest->content, tree_name);
    }
}

void del_animal(Tree *world_pointer, char *forest_name, char *tree_name, char *animal_name)
{
    Tree forest = find(*world_pointer, forest_name);
    if (forest)
    {
        Tree tree = find(forest->content, tree_name);
        if (tree)
        {
            remove_value(&tree->content, animal_name);
        }
    }
}

void print_world(Tree world)
{
    print_all(world);
}

void print_forest(Tree world, char *forest_name)
{
    Tree forest = find(world, forest_name);
    if (forest)
    {
        print_all(forest->content);
    }
}

void print_tree(Tree world, char *forest_name, char *tree_name)
{
    Tree forest = find(world, forest_name);
    if (forest)
    {
        Tree tree = find(forest->content, tree_name);
        if (tree)
        {
            print_all(tree->content);
        }
    }
}
