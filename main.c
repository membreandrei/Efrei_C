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
    switch (i) {
        case 0:
            listerFilms();
            afficherMenu(0);
            break;
        case 1:
            listerRealisateurs();
            afficherMenu(0);
            break;
        case 2:
            rechercheFilm();
            afficherMenu(0);
            break;
        case 3:
            return afficherSousMenu(0);
        case 4:
            exit(0);
            break;
        default:
            break;
    }
}

void listerRealisateurs() {
    Realisateur real;
    int i = 1;
    system("clear");
    printf("Liste de tous les realisateurs : \n\n\n");
    FILE *F;
    F = fopen("Realisateurs.bin", "rb");
    while (1) {
        fread(&real, sizeof(struct Realisateur), 1, F);
        if (feof(F)) {
            break;
        }
        printf("Realisateur n %d : \n\n", i);
        printf("nom = %s\n", real.nom);
        printf("Prenom = %s\n", real.prenom);
        printf("Nationalite = %s\n", real.nationalite);
        printf("Date de naissance = %s\n\n\n", real.dateNaissance);
        i++;

    }
    fclose(F);
    int key;
    while (key != ENTER) {
        printf("Appuyez sur Entrer pour quitter\n\n");
        key = getchar();
    }

}

void listerFilms() {
    Film movie;
    int i = 1;
    int j;
    system("clear");
    printf("Liste de tous les Films : \n\n\n");
    FILE *F;
    F = fopen("Films.bin", "rb");
    while (1) {
        fread(&movie, sizeof(struct Film), 1, F);
        if (feof(F)) {
            break;
        }
        printf("Film n %d : \n\n", i);
        printf("Nom = %s\n", movie.nom);
        printf("Annee de Sortie = %s\n", movie.anneeSortie);
        printf("Realisateur = {Nom = %s , Prenom = %s}\n", movie.real.nom, movie.real.prenom);

        for (j = 0; j < 2; j++) {
            if (movie.acteurs[j].nom[0] == 0) {
                break;
            }
            printf("Acteurs = {Nom = %s , Prenom = %s}\n", movie.acteurs[j].nom, movie.acteurs[j].prenom);
        }
        printf("\n\n");
        i++;

    }
    fclose(F);
    int key;
    while (key != ENTER) {
        printf("Appuyez sur Entrer pour quitter\n\n");
        key = getchar();
    }
}

void listerActeur() {
    Acteur act;
    int i = 1;
    system("clear");
    printf("Liste de tous les Acteurs : \n\n\n");
    FILE *F;
    F = fopen("Acteurs.bin", "rb");
    while (1) {
        fread(&act, sizeof(struct Acteur), 1, F);
        if (feof(F)) {
            break;
        }
        printf("Acteur n %d : \n\n", i);
        printf("nom = %s\n", act.nom);
        printf("Prenom = %s\n", act.prenom);
        printf("Nationalite = %s\n", act.nationalite);
        printf("Date de naissance = %s\n\n\n", act.dateNaissance);
        i++;

    }
    fclose(F);
    int key;
    while (key != ENTER) {
        printf("Appuyez sur Entrer pour quitter\n\n");
        key = getchar();
    }

}

void creerActeur() {

    FILE *F;
    Acteur act;
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char dateNaissance[50];
    system("clear");
    printf("\nCreation d'un Acteur : \n\n");
    printf("Nom : ");
    scanf(" %s", &nom);
    printf("\nPrenom : ");
    scanf(" %s", &prenom);
    printf("\nNationalite : ");
    scanf(" %s", &nationalite);
    printf("\nDate de naissance (jj/mm/aaaa) : ");
    scanf(" %s", &dateNaissance);
    act.cle = 0;
    strcpy(act.dateNaissance, dateNaissance);
    strcpy(act.nationalite, nationalite);
    strcpy(act.nom, nom);
    strcpy(act.prenom, prenom);

    F = fopen("Acteurs.bin", "ab");
    fwrite(&act, sizeof(struct Acteur), 1, F);
    fclose(F);

    viderBuffer();

}

Realisateur chercheReal(int choix) {
    Realisateur real;
    int i = 1;
    FILE *F;
    F = fopen("Realisateurs.bin", "rb");
    while (1) {
        fread(&real, sizeof(struct Realisateur), 1, F);

        if (feof(F) || i == choix) {
            break;
        }

        i++;
    }
    fclose(F);
    return real;
}

Acteur *chercheActeur(int nbActeur) {

    Acteur currentAct;
    Acteur *actFile;
    Acteur *act;
    actFile = malloc(sizeof(Acteur));
    act = malloc(sizeof(Acteur));
    int i = 0;
    int j;
    int choix;
    FILE *F;
    F = fopen("Acteurs.bin", "rb");

    while (1) {
        fread(&currentAct, sizeof(struct Acteur), 1, F);
        i++;
        actFile = realloc(actFile, (i + 1) * sizeof(struct Acteur));

        actFile[i] = currentAct;

        if (feof(F)) {
            break;
        }
    }
    for (j = 0; j < nbActeur; j++) {
        printf("Tapez le numero de vos Acteurs ( acteur n %d) :\n", j + 1);
        scanf("%d", &choix);

        act = realloc(act, (j + 1) * sizeof(struct Acteur));
        act[j] = actFile[choix];

    }
    fclose(F);
    free(actFile);
    return act;
}

void creerFilm() {

    FILE *F;
    Film movie;
    char nom[50];
    char anneeSortie[50];
    int choix;
    int nb;

    system("clear");
    printf("\nCreation d'un Film : \n\n");
    printf("Nom : ");
    scanf(" %s", &nom);
    printf("\nAnne de sortie du Film : ");
    scanf(" %s", &anneeSortie);


    strcpy(movie.nom, nom);
    strcpy(movie.anneeSortie, anneeSortie);

    listerRealisateurs();

    printf("Tapez le numéro de réalisateur que vous voulez : \n");
    scanf(" %d", &choix);

    movie.real = chercheReal(choix);

    viderBuffer();

    printf("Tapez combien d'Acteurs jouent dans votre film: \n");
    scanf(" %d", &nb);

    listerActeur();


    Acteur *actor = chercheActeur(nb);
    memcpy(movie.acteurs, actor, sizeof(movie.acteurs));


    F = fopen("Films.bin", "ab");
    fwrite(&movie, sizeof(movie), 1, F);
    fclose(F);

    viderBuffer();

    afficherSousMenu(0);
}

void creerRealisateur() {

    FILE *F;
    Realisateur real;
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char dateNaissance[50];
    system("clear");
    printf("\nCreation d'un realisateur : \n\n");
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

    F = fopen("realisateurs.bin", "ab");
    fwrite(&real, sizeof(struct Realisateur), 1, F);
    fclose(F);

    viderBuffer();

    afficherSousMenu(0);

}

int choixSousMenu(int i) {
    switch (i) {
        case 0:
            creerRealisateur();
            afficherSousMenu(0);
            break;
        case 1:
            creerActeur();
            afficherSousMenu(0);
            break;
        case 2:
            creerFilm();
            afficherSousMenu(0);
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

void rechercheFilm() {
    Film movie[50];
    int k = 0;
    system("clear");
    FILE *F;
    F = fopen("Films.bin", "rb");
    while (1) {
        fread(&movie[k], sizeof(struct Film), 1, F);
        if (feof(F)) {
            break;
        }
        k += 1;
    }
    fclose(F);
    int key;
    char choix[50];
    printf("Tapez une partie du nom du film que vous recherchez : \n");
    scanf(" %s", &choix);
    viderBuffer();

    for (int i = 0; i < 50; i++) {
        if (strchr(movie[i].nom, *choix) != NULL) {
            afficherFilm(movie[i]);
        }
    }

    while (key != ENTER) {
        printf("Appuyez sur Entrer pour quitter\n\n");
        key = getchar();
    }
}

void saveStruct(void *structure, char fileName) {
    FILE *fptr;
    fptr = fopen(fileName, "ab");
    fwrite(&structure, sizeof(structure), 1, fptr);
    fclose(fptr);
}

void retrieveDataFromFile(char fileName, int type) {
    FILE *fptr;
    fptr = fopen(&fileName, "r");

    Acteur *act;
    Realisateur *real;
    Film *movie;

    switch (type) {
        case 0:
            fread(act, sizeof(Acteur), 1, fptr);
        case 1:
            fread(real, sizeof(Realisateur), 1, fptr);
        case 2:
            fread(movie, sizeof(Film), 1, fptr);
    }
    //printf ("Nom = %s name = %s %s\n", lefilm.nom, lefilm.acteurs[0].nom, lefilm.real.nom)
}

void rechercherFilm(char ouestcharlie) {
    Film movies[30];
    for (int i = 0; i < 30; i++) {
        char str = movies[i].nom;
        char *ptr = strstr(str, ouestcharlie);
        if (ptr != NULL) {
            afficherFilm(movies[i]);
        }
    }
}

void viderBuffer() {
    int c = 0;
    while (c != ENTER && c != EOF) {
        c = getchar();
    }
}

void afficherFilm(Film the_movie) {
    Film movie = the_movie;
    int j = 0;
    system("clear");
    printf("Film: \n\n");
    printf("Nom = %s\n", movie.nom);
    printf("Annee de Sortie = %s\n", movie.anneeSortie);
    printf("Realisateur = {Nom = %s , Prenom = %s}\n", movie.real.nom, movie.real.prenom);
    for (j = 0; j < 2; j++) {
        if (movie.acteurs[j].nom[0] == 0) {
            break;
        }
        printf("Acteurs = {Nom = %s , Prenom = %s}\n", movie.acteurs[j].nom, movie.acteurs[j].prenom);
    }
    printf("\n\n");
}