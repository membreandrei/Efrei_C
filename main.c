#include "cmake-build-debug/fonction.h"

#define ENTER 13
#define ESC 27

int main() {
    afficherMenu(0);
    //system("clear");
    //TODO

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
                case 4:
                    return afficherMenu(0);
                default:
                    return afficherMenu(i + 1);
            }
        if (key == ENTER) {
            return choixMenu(i);
        }

    } while (key != 'z' || key != 's' || key != ENTER);
}

int afficherSousMenu(int i) {
        system("/bin/stty raw >nul 2>nul");
        system("clear");
        printf("\n\n");
        printf("  Ajouter des données \n\n");
        switch (i) {
            case 0:
                printf("  ->Ajouter un realisateur\n");
                printf("    Ajouter un Acteur\n");
                printf("    Ajouter un Film\n");
                printf("    Retour\n\n");
            break;
            case 1:
                printf("    Ajouter un realisateur\n");
                printf("  ->Ajouter un Acteur\n");
                printf("    Ajouter un Film\n");
                printf("    Retour\n\n");
            break;
            case 2:
                printf("    Ajouter un realisateur\n");
                printf("    Ajouter un Acteur\n");
                printf("  ->Ajouter un Film\n");
                printf("    Retour\n\n");
            break;
            case 3:
                printf("    Ajouter un realisateur\n");
                printf("    Ajouter un Acteur\n");
                printf("    Ajouter un Film\n");
                printf("  ->Retour\n\n");
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
                        return afficherSousMenu(3);
                    default:
                        return afficherSousMenu(i - 1);
                }
            if (key == 's')
                switch (i) {
                    case 3:
                        return afficherSousMenu(0);
                    default:
                        return afficherSousMenu(i + 1);
                }
            if (key == ENTER) {
                return choixSousMenu(i);
            }

        } while (key != 'z' || key != 's' || key != ENTER);
}

int choixMenu(int i) {
    switch(i){
        case 0:
            //listerFilms();
            break;
        case 1:
            listerRealisateurs();
            break;
        case 2:
            //rechercherFilm();
            break;
        case 3:
            return afficherSousMenu(0);
        case 4:
            break;
        default:
            break;
    }
}

void listerRealisateurs() {

    system("clear");
    printf("Liste de tous les realisateurs : \n");
    FILE* F;
    F = fopen("Realisateurs.bin","rb");
}

void lecture1(FILE* F) {
    int a;
    int b;
    double d;
    printf("-- lecture1\n");

    fread(&a,sizeof(int),1,F);
    fread(&d,sizeof(double),1,F);
    fread(&b,sizeof(int),1,F);
    printf("a = %d ; d = %lf ; b = %d\n",a,d,b);
    fclose(F);
}

int choixSousMenu(int i) {
    switch(i){
        case 0:
            //listerFilms();
            break;
        case 1:
            //listerRealisateurs();
            break;
        case 2:
            //rechercherFilm();
            break;
        case 3:
            return afficherMenu(0);
        default:
            break;
    }
}

char saisieTexte(void) {
    char saisie;
    fflush(stdin);
    printf("[Rechercher]: ");
    scanf("%c", &saisie);
    fflush(stdin);
    return saisie;
}