#include "cmake-build-debug/fonction.h"

#define ENTER 13
#define ESC 27

int main() {
    int etatMenu;
    etatMenu = afficherMenu(0);
    system("clear");
    //TODO
    //Faire le code

    return 0;
}

int afficherMenu(int i) {
    system("/bin/stty raw >nul 2>nul");
    system("clear");
    printf("\n\n");
    printf("  Bienvenue dans le cinema PATHE !\n\n");
    switch (i) {
        case 0:
            printf("  ->Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("    Ajouter des données\n");
            printf("    Quitter\n\n");
            break;
        case 1:
            printf("    Liste des films\n");
            printf("  ->Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("    Ajouter des données\n");
            printf("    Quitter\n\n");
            break;
        case 2:
            printf("    Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("  ->Rechercher un film\n");
            printf("    Ajouter des données\n");
            printf("    Quitter\n\n");
            break;
        case 3:
            printf("    Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("  ->Ajouter des données\n");
            printf("    Quitter\n\n");
            break;
        case 4:
            printf("    Liste des films\n");
            printf("    Liste des realisateurs\n");
            printf("    Rechercher un film\n");
            printf("    Ajouter des données\n");
            printf("  ->Quitter\n\n");
            break;
        default:
            break;
    }
    printf("Utilisez Z et S pour naviguer. \n");
    int key;
    do {
        key = getchar();
        if (key == 'z')
            switch (i) {
                case 0:
                    return afficherMenu(4);
                default:
                    return afficherMenu(i - 1);
            }
        if (key == 's')
            switch (i) {
                case 3:
                    return afficherMenu(0);
                default:
                    return afficherMenu(i + 1);
            }
        if (key == ENTER) {
            return i;
        }

    } while (key != 'z' || key != 's' || key != ENTER);
    return 0;
}


char saisieTexte(void) {
    char saisie;
    fflush(stdin);
    printf("[Rechercher]: ");
    scanf("%c", &saisie);
    fflush(stdin);
    return saisie;
}