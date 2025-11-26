#include <stdio.h>
#include "main.h"
#include "Menus.h"
#include <stdlib.h>
#include <string.h>
/*Déclaration de toutes les structures */

int main() {
    //Déclaration des variables principales, les variables représentent respectivement:
    //n = le nombre de pilotes, gp = le nombre de Grand Prix et nbEcuries = le nombre d'écurie
    int n = 0, gp = 0, nbEcuries = 0;
    //déclaration de tous les tableaux pour enregistrer les pilotes, Grand Prix et écuries
    struct Pilote *Enregistrer_Pilotes = (struct Pilote *)malloc( 20*sizeof(struct Pilote));
    struct GrandPrix *Enregistrer_GrandPrix = (struct GrandPrix *)malloc(20 * sizeof(struct GrandPrix));
    struct Ecurie *Enregistrer_Ecuries = (struct Ecurie*) malloc(20*sizeof(struct Ecurie));
    //Déclaration de toutes les données préinitialisées
    //Pilotes
    struct Pilote Liste_pilote[10] = { {"Verstappen", "Max", "Pays-Bas", "Red Bull Racing", 0, 1, 27, 1}, {"Perez",
    "Sergio", "Mexique", "Red Bull Racing", 0, 11, 34, 1}, {"Leclerc", "Charles", "Monaco",
        "Scuderia Ferrari", 0, 16, 27, 1}, {"Sainz","Carlos", "Espagne", "Scuderia Ferrari", 0, 55,
    30, 1}, {"Hamilton", "Lewis", "Royaume-Uni", "Mercedes-AMG", 0, 44, 39, 1},
    {"Russell", "George", "Royaume-Uni", "Mercedes-AMG", 0, 63, 26, 1}, {"Norris",
    "Lando", "Royaume-Uni", "McLaren Racing", 0, 4, 25, 1}, {"Piastri", "Oscar",
    "Australie", "McLaren Racing", 0, 81, 23, 1}, {"Alonso", "Fernando", "Espagne", "Aston Martin"
        , 0, 14, 43, 1}, {"Stroll", "Lance", "Canada", "Aston Martin", 0, 18, 26, 1} };
    for(int i = 0; i< 10; i++) {
        Enregistrer_Pilotes[i] = Liste_pilote[i];
        n++;
    }
    //écuries
    struct Ecurie ecuries[5]  = { {"Red Bull Racing", "Autriche", 0, 2005,
        "Christian Horner", 1}, {"Scuderia Ferrari", "Italie", 0, 1950,
            "Frederic Vasseur", 1}, {"Mercedes-AMG", "Allemagne", 0, 2010,
                "TotoWolff", 1},{"McLaren Racing", "Royaume-Uni", 0, 1966,
                    "Andrea Stella", 1}, {"Aston Martin", "Royaume-Uni", 0, 2021,
                        "Mike Krack", 1} };
    for (int i = 0; i < 5; i++) {
        Enregistrer_Ecuries[i] = ecuries[i];
        nbEcuries++;
    }
    //Grand Prix
    strcpy(Enregistrer_GrandPrix[gp].nomCircuit, "Circuit de Monaco");
    strcpy(Enregistrer_GrandPrix[gp].Pays, "Monaco");
    Enregistrer_GrandPrix[gp].nombreTours = 78;
    Enregistrer_GrandPrix[gp].Date = (struct Date){26, 5, 2024};
    Enregistrer_GrandPrix[gp].Horaire = (struct Heure){15, 0};
    Enregistrer_GrandPrix[gp].nombreResultats = 10; Enregistrer_GrandPrix[gp].Actif = 1;

    //Résultat du premier Grand Prix
        struct ResultatCourse resultats[10] = { {"Verstappen", "Max", "Pays-Bas", 1, "1:44:12.456",
    25},
{"Leclerc", "Charles", "Monaco", 2, "1:44:18.234", 18},
{"Hamilton","Lewis","Royaume-Uni", 3, "1:44:25.678", 15},
{"Norris", "Lando", "Royaume-Uni", 4,"1:44:32.123", 12},
{"Sainz", "Carlos", "Espagne", 5, "1:44:39.456", 10},
{"Russell","George", "Royaume-Uni", 6, "1:44:45.789", 8},
{"Perez", "Sergio", "Mexique", 7,"1:44:52.234", 6},
{"Alonso", "Fernando", "Espagne", 8, "1:44:58.567", 4},
{"Piastri","Oscar", "Australie", 9, "1:45:04.890", 2},
{"Stroll", "Lance", "Canada", 10,"1:45:11.123", 1} };
    for(int i = 0; i< 10; i++) {
        Enregistrer_GrandPrix[gp].Resultats[i] = resultats[i];
    }
    gp++;
    //Grand Prix 2
    strcpy(Enregistrer_GrandPrix[gp].nomCircuit, "Circuit de Paris");
    strcpy(Enregistrer_GrandPrix[gp].Pays, "France");
    Enregistrer_GrandPrix[gp].nombreTours = 100;
    Enregistrer_GrandPrix[gp].Date = (struct Date){19, 7, 2020};
    Enregistrer_GrandPrix[gp].Horaire = (struct Heure){13, 0};
    Enregistrer_GrandPrix[gp].nombreResultats = 10; Enregistrer_GrandPrix[gp].Actif = 1;

    struct ResultatCourse resultats2[10] = {
        {"Norris", "Lando", "Royaume-Uni", 1, "1:43:58.321", 25},
        {"Hamilton", "Lewis", "Royaume-Uni", 2, "1:44:03.789", 18},
        {"Verstappen", "Max", "Pays-Bas", 3, "1:44:10.456", 15},
        {"Leclerc", "Charles", "Monaco", 4, "1:44:17.234", 12},
        {"Russell", "George", "Royaume-Uni", 5, "1:44:23.678", 10},
        {"Sainz", "Carlos", "Espagne", 6, "1:44:30.123", 8},
        {"Alonso", "Fernando", "Espagne", 7, "1:44:36.456", 6},
        {"Piastri", "Oscar", "Australie", 8, "1:44:42.789", 4},
        {"Stroll", "Lance", "Canada", 9, "1:44:49.234", 2},
        {"Perez", "Sergio", "Mexique", 10, "1:44:55.567", 1}
    };
    for(int i = 0; i< 10; i++) {
        Enregistrer_GrandPrix[gp].Resultats[i] = resultats2[i];
    }
    gp++;
    //Grand Prix 3
    strcpy(Enregistrer_GrandPrix[gp].nomCircuit, "Circuit d'Italie");
    strcpy(Enregistrer_GrandPrix[gp].Pays, "Italie");
    Enregistrer_GrandPrix[gp].nombreTours = 90;
    Enregistrer_GrandPrix[gp].Date = (struct Date){12, 1, 2019};
    Enregistrer_GrandPrix[gp].Horaire = (struct Heure){16, 0};
    Enregistrer_GrandPrix[gp].nombreResultats = 10; Enregistrer_GrandPrix[gp].Actif = 1;
    struct ResultatCourse resultats3[10] = {
        {"Leclerc", "Charles", "Monaco", 1, "1:44:01.789", 25},
        {"Verstappen", "Max", "Pays-Bas", 2, "1:44:06.234", 18},
        {"Russell", "George", "Royaume-Uni", 3, "1:44:12.567", 15},
        {"Sainz", "Carlos", "Espagne", 4, "1:44:18.890", 12},
        {"Hamilton", "Lewis", "Royaume-Uni", 5, "1:44:25.123", 10},
        {"Norris", "Lando", "Royaume-Uni", 6, "1:44:31.456", 8},
        {"Piastri", "Oscar", "Australie", 7, "1:44:37.789", 6},
        {"Stroll", "Lance", "Canada", 8, "1:44:44.234", 4},
        {"Alonso", "Fernando", "Espagne", 9, "1:44:50.567", 2},
        {"Perez", "Sergio", "Mexique", 10, "1:44:56.890", 1}
    };
    for(int i = 0; i< 10; i++) {
        Enregistrer_GrandPrix[gp].Resultats[i] = resultats3[i];
    }
    for (int k = 0; k < 3; k++) {
        for (int j = 0; j<10; j++) {
            for (int i = 0; i<n; i++) {
                if (strcmp(Enregistrer_Pilotes[i].nom, Enregistrer_GrandPrix[k].Resultats[j].nomPilote) == 0) {
                    switch (Enregistrer_GrandPrix[k].Resultats[j].Position) {
                        case 1:
                            Enregistrer_Pilotes[i].points += 25;
                            break;
                        case 2:
                            Enregistrer_Pilotes[i].points += 18;
                            break;
                        case 3:
                            Enregistrer_Pilotes[i].points += 15;
                            break;
                        case 4:
                            Enregistrer_Pilotes[i].points += 12;
                            break;
                        case 5:
                            Enregistrer_Pilotes[i].points += 10;
                            break;
                        case 6:
                            Enregistrer_Pilotes[i].points += 8;
                            break;
                        case 7:
                            Enregistrer_Pilotes[i].points += 6;
                            break;
                        case 8:
                            Enregistrer_Pilotes[i].points += 4;
                            break;
                        case 9:
                            Enregistrer_Pilotes[i].points += 2;
                            break;
                        case 10:
                            Enregistrer_Pilotes[i].points += 1;
                            break;
                        default:
                            Enregistrer_Pilotes[i].points += 0;
                            break;
                    }
                }
            }
        }
    }

    gp++;


    //Fonction permettant d'accèder au menu principal
    Menu_principal(Enregistrer_Pilotes,Enregistrer_Ecuries,Enregistrer_GrandPrix, &n,&gp,&nbEcuries);
}