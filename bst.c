#include <string.h>
#include "bst.h"

// uproszczony struct Tree - wykorzystywany w funkcji remove_min
typedef struct
{
    char *name;
    Tree content;
} Entity;

Tree insert(Tree *tree_pointer, char *name)
{
    Tree tree = *tree_pointer;

    if (tree == NULL)
    {
        tree = (Tree)malloc(sizeof(struct Node));
        if (!tree)
        {
            exit(1);
        }
        tree->name = (char *)malloc(sizeof(char) * strlen(name) + 1);
        if (!tree->name)
        {
            exit(1);
        }
        strcpy(tree->name, name);
        tree->content = NULL;
        tree->left = tree->right = NULL;
        *tree_pointer = tree;
        return tree;
    }
    else
    {
        int cmp = strcmp(name, tree->name);
        if (cmp < 0)
        {
            return insert(&tree->left, name);
        }
        else if (cmp > 0)
        {
            return insert(&tree->right, name);
        }
        else
        {
            return tree;
        }
    }
}

void print_all(Tree tree)
{
    if (tree != NULL)
    {
        print_all(tree->left);
        printf("%s\n", tree->name);
        print_all(tree->right);
    }
}

// Usuwa z drzewa wskazywanego przez tree_pointer najmniejszą wartość
// i zwraca ją jako wynik.
// Zaklada ze drzewo jest niepuste
Entity remove_min(Tree *tree_pointer)
{
    Tree tree = *tree_pointer;

    if (tree->left == NULL)
    {
        *tree_pointer = tree->right;
        Entity ret = {tree->name, tree->content};
        free(tree);
        return ret;
    }
    else
    {
        return remove_min(&tree->left);
    }
}

void remove_value(Tree *tree_pointer, char *name)
{
    Tree tree = *tree_pointer;

    if (tree != NULL)
    {
        int cmp = strcmp(name, tree->name);
        if (cmp < 0)
        {
            remove_value(&tree->left, name);
        }
        else if (cmp > 0)
        {
            remove_value(&tree->right, name);
        }
        else
        {
            if (tree->right == NULL)
            {
                *tree_pointer = tree->left;
                remove_all(&tree->content);
                free(tree->name);
                free(tree);
            }
            else
            {
                Entity min = remove_min(&tree->right);
                remove_all(&tree->content);
                free(tree->name);
                tree->name = min.name;
                tree->content = min.content;
            }
        }
    }
}

void remove_all(Tree *tree_pointer)
{
    Tree tree = *tree_pointer;
    if (tree != NULL)
    {
        remove_all(&tree->left);
        remove_all(&tree->right);
        remove_all(&tree->content);
        free(tree->name);
        free(tree);
        *tree_pointer = NULL;
    }
}

Tree find(Tree tree, char *name)
{
    if (tree != NULL)
    {
        int cmp = strcmp(name, tree->name);
        if (cmp < 0)
        {
            return find(tree->left, name);
        }
        else if (cmp > 0)
        {
            return find(tree->right, name);
        }
        else
        {
            return tree;
        }
    }
    else
    {
        return NULL;
    }
}

Tree find_in_content(Tree tree, char *name_in_content)
{
    Tree ret = NULL;
    if (tree)
    {
        ret = find(tree->content, name_in_content);
        if (ret == NULL)
        {
            ret = find_in_content(tree->left, name_in_content);
        }
        if (ret == NULL)
        {
            find_in_content(tree->right, name_in_content);
        }
    }
    return ret;
}
