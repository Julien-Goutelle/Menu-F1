//
// Created by Natha on 31/10/2025.
//

#ifndef UNTITLED1_MAIN_H
#define UNTITLED1_MAIN_H
struct Date {
    int jour;
    int mois;
    int annee;
};

struct Heure {
    int heure;
    int min;
};

struct Pilote {
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char ecurie[50];
    int points;
    int numero;
    int Age;
    int Actif;
};

struct Ecurie {
    char Nom[50];
    char Pays[50];
    int Points;
    int anneeCreation;
    char Directeur[50];
    int Actif;
};

struct ResultatCourse {
    char nomPilote[50];
    char prenomPilote[50];
    char nationalite[50];
    int Position;
    char tempsRealise[20];
    int pointsObtenus;
};

struct  GrandPrix {
    char nomCircuit[50];
    char Pays[50];
    int nombreTours;
    struct Date Date;
    struct Heure Horaire;
    struct  ResultatCourse Resultats[20];
    int nombreResultats;
    int Actif;
};

#endif //UNTITLED1_MAIN_H