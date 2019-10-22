#include "cmake-build-debug/fonction.h"

#define ENTER 10
#define ESC 27

int main() {
    int etatMenu;
    etatMenu = afficherMenu(0);
    return 0;
}

int afficherMenu(int i) {
    system("clear");
    printf("\n\n");
    printf("   Bienvenue dans le cinema PATHE !\n\n");
    switch (i) {
        case 0:
            printf("  ->Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("    Quitter\n\n");
            break;
        case 1:
            printf("    Liste des films\n");
            printf("  ->Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("    Quitter\n\n");
            break;
        case 2:
            printf("    Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("  ->Rechercher un film\n");
            printf("    Quitter\n\n");
            break;
        case 3:
            printf("    Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("  ->Quitter\n\n");
            break;
        default:
            break;
    }
    int key;
    do {
        key = getchar();
        putchar(key);
        if (key == 'z')
            switch (i) {
                case 0:
                    afficherMenu(2);
                    break;
                default:
                    afficherMenu(i - 1);
                    break;
            }
        if (key == 's')
            switch (i) {
                case 2:
                    afficherMenu(0);
                    break;
                default:
                    afficherMenu(i + 1);
                    break;
            }
        if (key == ENTER)
            switch (i) {
                default:
                    return i;
                case 2:
                    exit(0);
            }
    } while (key != 'z' || key != 's' || key != ENTER);
    return 2;
}