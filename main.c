#include "cmake-build-debug/fonction.h"

#define ENTER 13
#define ESC 27

int main() {

    afficherMenu(0);
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
    Realisateur* real;

    real = (Realisateur) malloc(sizeof(Realisateur));
    system("clear");
    printf("Liste de tous les realisateurs : \n");
    FILE* F;
    F = fopen("Realisateurs.bin","rb");
    printf("-- lecture1\n");
    while()
    fread(&real,sizeof(struct Realisateur), 1, F);
    printf("nom = %s\n",real.nom);
    fclose(F);
    while (1){

    }
}

/*
void lecture(FILE* F) {

}
void ecriture(FILE* F){


}

void creerActeur(){

    Acteur act;
    act.cle = 0;
    strcpy(act.dateNaissance, "06/12/1353");
    strcpy(act.nom, "Bush");
    strcpy(act.prenom, "Georges");
    strcpy(act.nationalite, "Irlandais");
}

void creerFilm(){
    Film movie;
    movie.acteurs[0] = act;
    strcpy(movie.nom, "Vendetta");
    movie.anneeSortie = 1745;
    movie.real = real;
}
*/
void creerRealisateur(){

    FILE* F;
    Realisateur real;
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char dateNaissance[50];
    system("clear");
    printf("\nCreation d'un realisateur : \n");
    printf("Nom : ");
    scanf(" %s", &nom);
    printf("\nPrenom : ");
    scanf(" %s", &prenom);
    printf("\nNationalite : ");
    scanf(" %s", &nationalite);
    printf("\nDate de naissance (jj/mm/aaaa) : ");
    scanf(" %s", &dateNaissance);
    real.cle = 0;
    strcpy(real.dateNaissance, dateNaissance);
    strcpy(real.nationalite, nationalite);
    strcpy(real.nom, nom);
    strcpy(real.prenom, prenom);

    F = fopen("realisateurs.bin", "wb");
    fwrite(&real, sizeof(struct Realisateur), 1, F);
    fclose(F);
}

int choixSousMenu(int i) {
    switch(i){
        case 0:
            creerRealisateur();
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

void rechercheFilm(char nom) {
    FILE *fptr;
    //fptr = fopen('data/films.bin', 'rb');

}

void saveStruct(void *structure, char fileName){
    FILE *fptr;
    fptr = fopen(fileName, "ab");
    fwrite(&structure, sizeof(structure), 1, fptr);
    fclose(fptr);
}

void retrieveDataFromFile(char fileName, int type){
    FILE *fptr;
    fptr = fopen(&fileName, "r");

    Acteur *act;
    Realisateur *real;
    Film *movie;

    switch(type){
        case 0:
            fread(act, sizeof(Acteur), 1, fptr);
        case 1:
            fread(real, sizeof(Realisateur), 1, fptr);
        case 2:
            fread(movie, sizeof(Film), 1, fptr);
    }
    //printf ("Nom = %s name = %s %s\n", lefilm.nom, lefilm.acteurs[0].nom, lefilm.real.nom)
}

void rechercherFilm(char ouestcharlie)
{
    Film movies[30];
    for (int i = 0; i < 30; i++)
    {
        char str = movies[i].nom;
        char *ptr = strstr(str, ouestcharlie);
        if (ptr != NULL)
        {
            afficherFilm(movies[i]);
        }
    }
}

void afficherFilm(Film the_movie)
{

}