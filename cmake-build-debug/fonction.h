#include <stdio.h>
#include <stdlib.h>

int COMPTEURREALISATEUR = 0;
int COMPTEURACTEUR = 0;

typedef struct Realisateur {
    int cle;
    char nom[100];
    char prenom[100];
    char dateNaissance[100];
    char nationalite[100];
} Realisateur;

typedef struct Acteur {
    int cle;
    char nom[100];
    char prenom[100];
    char dateNaissance[100];
    char nationalite[100];
} Acteur;

typedef struct Film {
    char nom[100];
    int anneeSortie;
    Realisateur real;
    Acteur acteurs[3];
} Film;

Realisateur getRealisateur(char *nom);

void afficherRealisateur(Realisateur real);

Acteur getActeur(char *nom);

void afficherActeur(Acteur act);

Film getFilm(char *nom);

void afficherFilm(Film film);

void listerFilms();

void listerRealisateurs();

void listerActeurs();

void quitter();

int afficherMenu(int hint);

int afficherSousMenu(int hint);

int choixMenu(int i);

int choixSousMenu(int i);

void creerActeur();

void creerRealisateur();

void lecture1();

char saisieTexte(void);