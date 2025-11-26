#include <stdio.h>
#include <stdlib.h>
#include "Pilote.h"
#include "main.h"
#include "grandprix.h"
#include "Ecurie.h"
#include "ResultatCourse.h"
// Created by Natha on 29/10/2025.
void Menu_principal(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries, struct GrandPrix *Enregistrer_GrandPrix, int*n, int*gp, int *nbEcuries);
//Fonction gérant l'accès aux fonctionnalités des pilotes
void Gestion_des_pilotes(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries, int*n,int*nbEcuries) {
    char choix; /* Variable pour sélectionner une option du menu */
    /* Accès aux fonctionnalités */
    do {
        printf("\tGestion des pilotes\n");
        printf("============================================\n");
        printf("1 - Ajouter un pilote\n");
        printf("2 - Mettre à jour les points\n");
        printf("3 - Supprimer un pilote\n");
        printf("4 - Afficher la liste\n");
        printf("5 - Revenir au menu principal\n");
        printf("============================================\n");
        scanf(" %c",&choix);

        switch (choix) {
            /* Accès aux autres menus */
            case '1':
                ajouterPilote(Enregistrer_Pilotes,Enregistrer_Ecuries,n,*nbEcuries);
                break;
            case '2':
                modifier_points(Enregistrer_Pilotes,*n);
                break;
            case '3':
                supprimer_pilotes(Enregistrer_Pilotes, n);
                break;
            case '4':
                Afficher_pilotes(Enregistrer_Pilotes, *n);
                break;
            case '5':
                return;
            default:
                printf("Erreur! Veuillez choisir une option proposee dans le menu\n");

                break;
        }
    }while (choix != '5');
}
//Fonction gérant l'accès aux fonctionnalités des écuries
void Gestion_des_écuries(struct Pilote *Enregistrer_Pilotes, struct Ecurie *Enregistrer_Ecuries, int*nbEcuries, int n) {
    char choix; /* Variable pour sélectionner une option du menu */
    /* Accès aux fonctionnalités */
    do {
        printf("\tGestion des ecuries\n");
        printf("============================================\n");
        printf("1 - Ajouter une ecurie\n");
        printf("2 - Mettre à jour les points\n");
        printf("3 - Supprimer une ecurie\n");
        printf("4 - Afficher la liste\n");
        printf("5 - Revenir au menu principal\n");
        printf("============================================\n");
        scanf(" %c",&choix);

        switch (choix) { /* Accès aux autres menus */
            case '1':
                ajouter_Ecurie(Enregistrer_Ecuries,nbEcuries);
                break;
            case '2':
                mettre_a_jour_points(Enregistrer_Ecuries,*nbEcuries, Enregistrer_Pilotes, n);
                break;
            case '3':
                supprimer_Ecurie(Enregistrer_Ecuries,nbEcuries);
                break;
            case '4':
                afficher_Ecuries(Enregistrer_Ecuries,*nbEcuries);
                break;
            case '5':
                return;
            default:
                printf("Erreur! Veuillez choisir une option proposee dans le menu\n");
                break;
        }
    }while (choix != '5');
}
//Fonction gérant l'accès aux fonctionnalités des Grand Prix
void Gestion_des_Grands_Prix(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries, struct GrandPrix *Enregistrer_GrandPrix, int*n, int*gp, int *nbEcuries) {

    char choix; /* Variable pour sélectionner une option du menu */
    /* Accès aux fonctionnalités */
    do {
        printf("\tGestion des Grands Prix\n");
        printf("============================================\n");
        printf("1 - Ajouter un Grand Prix\n");
        printf("2 - Mettre à jour les resultats\n");
        printf("3 - Supprimer un Grand Prix\n");
        printf("4 - Afficher la liste\n");
        printf("5 - Revenir au menu principal\n");
        printf("============================================\n");
        scanf(" %c",&choix);

        switch (choix) { /* Accès aux fonctionnalités */
            case '1':
                ajouter_Grand_Prix(Enregistrer_Pilotes,Enregistrer_GrandPrix,*n,gp);
                break;
            case '2':
                mettre_à_jour_résultat (Enregistrer_Pilotes,Enregistrer_Ecuries,Enregistrer_GrandPrix,*n,*gp,*nbEcuries);
                break;
            case '3':
                supprimer_grandprix(Enregistrer_GrandPrix,gp);
                break;
            case '4':
                afficher_grandprix(Enregistrer_GrandPrix,*gp);
                break;
            case '5':
                return;
            default:
                printf("Erreur! Veuillez choisir une option proposee dans le menu\n");
                break;
        }
    }while (choix != '5');
}
//Fonction gérant les fonctionnalités des classements
void Affichages_et_Classements(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries, struct GrandPrix *Enregistrer_GrandPrix, int*n, int*gp, int *nbEcuries) {
    char choix; /* Variable pour sélectionner une option du menu */
    /*Affiche le menu */
    do {
        printf("\tAffichages et Classements\n");
        printf("============================================\n");
        printf("1 - Classement d'une course\n");
        printf("2 - Classement general pilotes\n");
        printf("3 - Classement constructeurs\n");
        printf("4 - Revenir au menu principal\n");
        printf("============================================\n");
        scanf(" %c",&choix);

        switch (choix) { /* Accès aux autres menus */
            case '1':
                classement_course(Enregistrer_GrandPrix,*gp);
                break;
            case '2':
                classement_pilotes(Enregistrer_Pilotes,*n);
                break;
            case '3':
                classement_constructeurs(Enregistrer_Pilotes,Enregistrer_Ecuries,*n,*nbEcuries);
                break;
            case '4':
                return;
            default:
                printf("Erreur! Veuillez choisir une option proposee dans le menu\n");
                break;
        }
    }while (choix != '5');
}

//Fonction gérant le menu principal
void Menu_principal(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries, struct GrandPrix *Enregistrer_GrandPrix, int*n, int*gp, int *nbEcuries) {
    char choix; /* Variable pour sélectionner une option du menu */
    /*Affiche le menu */
    do {
        printf("\tMenu\n");
        printf("============================================\n");
        printf("1 - Gestion des pilotes\n");
        printf("2 - Gerer les ecuries\n");
        printf("3 - Gerer les Grands Prix\n");
        printf("4 - Faire un classement\n");
        printf("5 - Arret de l'application\n");
        printf("============================================\n");
        scanf(" %c",&choix);

        switch (choix) {
            /* Accès aux autres menus */
            case '1':
                Gestion_des_pilotes(Enregistrer_Pilotes,Enregistrer_Ecuries, n,nbEcuries);
                break;
            case '2':
                Gestion_des_écuries(Enregistrer_Pilotes,Enregistrer_Ecuries,nbEcuries,*n);
                break;
            case '3':
                Gestion_des_Grands_Prix(Enregistrer_Pilotes,Enregistrer_Ecuries,Enregistrer_GrandPrix,n,gp,nbEcuries);
                break;
            case '4':
                Affichages_et_Classements(Enregistrer_Pilotes,Enregistrer_Ecuries,Enregistrer_GrandPrix,n,gp,nbEcuries);
                break;
            case '5':
                printf("Arrêt de l'application");
                    free(Enregistrer_Pilotes);
                    free(Enregistrer_GrandPrix);
                    free(Enregistrer_Ecuries);
                break;
            default:
                printf("Erreur! Veuillez choisir une option proposee dans le menu\n");
                break;
        }
    } while (choix != '5');
}