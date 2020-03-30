#include <stdio.h>
#include "bst.h"

void test_insert()
{
    printf("==== test_insert ====\n");

    Tree tree = NULL;

    insert(&tree, "ala");
    insert(&tree, "ma");
    insert(&tree, "kota");

    print_all(tree);

    printf("==== koniec test_insert ====\n");
}

void test_remove()
{
    printf("==== test_remove ====\n");

    Tree tree = NULL;

    insert(&tree, "ala");
    insert(&tree, "ma");
    insert(&tree, "kota");

    remove_value(&tree, "kota");

    print_all(tree);

    printf("==== koniec test_remove====\n");
}

void test_remove_all()
{
    printf("==== test_remove_all ====\n");

    Tree tree = NULL;

    insert(&tree, "ala");
    insert(&tree, "ma");
    insert(&tree, "kota");

    remove_all(&tree);

    print_all(tree);

    printf("==== koniec test_remove_all ====\n");
}

void test_find()
{
    printf("==== test_find ====\n");

    Tree tree = NULL;

    insert(&tree, "ala");
    insert(&tree, "ma");
    insert(&tree, "kota");

    printf("W drzewie jest ala (powinno byc 1) - %d\n", find(tree, "ala") != NULL);
    printf("W drzewie jest bolek (powinno byc 0) - %d\n", find(tree, "bolek") != NULL);

    printf("==== koniec test_find ====\n");
}
