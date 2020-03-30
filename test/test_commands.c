#include <assert.h>
#include <stdio.h>
#include "bst.h"
#include "commands.h"

void test_check_tree()
{
    printf("-- test_check_tree: ");
    Tree world = NULL;
    add_tree(&world, "Sokolicha", "Sosna");

    // jest
    assert(check_tree(world, "Sokolicha", "Sosna"));

    // nie ma
    assert(check_tree(world, "Nie ma lasu", "Sosna") == 0);
    assert(check_tree(world, "Sokolicha", "Nie ma drzewa") == 0);

    printf("OK\n");
}

void test_check_animal()
{
    printf("-- test_check_animal: ");
    Tree world = NULL;
    add_animal(&world, "Sokolicha", "Sosna", "Wrona");
    //print_all(world->content->content);

    // jest
    // printf("Jest dobrze (powinno być 1): %d\n", check_animal(world, "Sokolicha", "Sosna", "Wrona") != 0);

    // // nie ma
    // printf("Nie ma zwierza (powinno być 1): %d\n", check_animal(world, "Sokolicha", "Sosna", "Nie ma zwierza") == 0);
    // printf("Nie ma drzewa (powinno być 1): %d\n", check_animal(world, "Sokolicha", "Nie ma drzewa", "Wrona") == 0);

    // jest
    assert(check_animal(world, "Sokolicha", "Sosna", "Wrona"));

    // nie ma
    assert(check_animal(world, "Sokolicha", "Sosna", "Nie ma zwierza") == 0);
    assert(check_animal(world, "Sokolicha", "Nie ma drzewa", "Wrona") == 0);

    printf("OK\n");
}

void test_del_animal()
{
    printf("====== test_del_animal ====== \n");
    Tree world = NULL;
    add_animal(&world, "Sokolicha", "Sosna", "Wrona");
    printf("przed usunięciem zwierza: \n");
    print_all(world);                   // wypisuje las
    print_all(world->content);          // wypisuje drzewo
    print_all(world->content->content); // wypisuje zwierze
    del_animal(&world, "Sokolicha", "Sosna", "Wrona");

    //del_tree(&world, "Sokolicha", "Sosna"); // do testow tree

    printf("po usunięciu zwierza: \n");
    print_all(world);                   // wypisuje las
    print_all(world->content);          // wypisuje drzewo
    print_all(world->content->content); // nie ma zwierza
    printf("\n=====test_del_animal - koniec=====\n");
}

void test_print_animal()
{
    printf("\n======test_print_animal===== \n");
    Tree world = NULL;
    add_animal(&world, "Sokolicha", "Sosna", "Wrona");
    add_animal(&world, "Sokolicha", "Swierk", "Wrobel");
    add_animal(&world, "Sokolicha", "Sosna", "Dzik");
    add_animal(&world, "Sokolicha", "Sosna", "Jastrząb");
    add_animal(&world, "Kozie_gory", "Klon", "Sojka");
    add_animal(&world, "Kozie_gory", "Sosna", "Krolik");

    printf("\nlasy: \n");
    print_world(world);

    printf("\ndrzewa: \n");
    print_forest(world, "Sokolicha");

    printf("\nzwierzęta: \n");
    print_tree(world, "Sokolicha", "Sosna");

    // printf("Sosna anywhere: %d\n", check_tree_anywhere(world, "Klonek"));

    printf("\n======test_print_animal===== KONIEC\n\n");
}
