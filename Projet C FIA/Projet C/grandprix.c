#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "pilote.h"
void afficherHeure(struct GrandPrix *Enregistrer_GrandPrix, int gp);
void afficherDate(struct GrandPrix *Enregistrer_GrandPrix, int gp);
void afficher_grandprix(struct GrandPrix *Enregistrer_GrandPrix, int gp);
//ajouter un Grand Prix
void ajouter_Grand_Prix(struct Pilote *Enregistrer_Pilotes, struct GrandPrix *Enregistrer_GrandPrix,int n, int *gp) {
    int choix; //Enregistre le choix des pilotes de l'utilisateur
    int i = 0; //Variable destiné à faire des boules
    getchar(); //supprime le saut à la ligne
    if (*gp > 20) {
        printf("Places insuffisantes pour enregistrer plus de pilotes! \n"); //Vérifie que le tableau ne déborde pas
        return;
    }
    printf("Veuillez saisir le nom du circuit : \n"); //ajouter le nom du circuit
    fgets(Enregistrer_GrandPrix[*gp].nomCircuit,sizeof(Enregistrer_GrandPrix[*gp].nomCircuit),stdin);
    Enregistrer_GrandPrix[*gp].nomCircuit[strcspn(Enregistrer_GrandPrix[*gp].nomCircuit,"\n")] = '\0';

    printf("Veuillez saisir le pays où se fera le circuit :\n"); //ajouter le nom du pays où se fera la course
    fgets(Enregistrer_GrandPrix[*gp].Pays,sizeof(Enregistrer_GrandPrix[*gp].Pays),stdin);
    Enregistrer_GrandPrix[*gp].Pays[strcspn(Enregistrer_GrandPrix[*gp].Pays,"\n")] = '\0';

    //ajouter le nombre de tours que fera le circuit
    do {
        printf("Veuillez entrer le nombre de tours de ce circuit :\n");
        scanf("%d", &Enregistrer_GrandPrix[*gp].nombreTours);
        if (Enregistrer_GrandPrix[*gp].nombreTours < 10 || Enregistrer_GrandPrix[*gp].nombreTours > 100) {
            printf("Erreur, seulement un nombre de tours entre 10 et 100 est autorise\n");
        }
    } while (Enregistrer_GrandPrix[*gp].nombreTours < 10 || Enregistrer_GrandPrix[*gp].nombreTours > 100);
    //ajoute l'heure
    afficherHeure(Enregistrer_GrandPrix, *gp);
    //ajoute la date
    afficherDate(Enregistrer_GrandPrix, *gp);
    //ajoute le nombre de participants au Grand Prix
    do {
        printf("Nombre de participants au Grand Prix\n");
        scanf("%d", &Enregistrer_GrandPrix[*gp].nombreResultats);
    } while (Enregistrer_GrandPrix[*gp].nombreResultats < 0 || Enregistrer_GrandPrix[*gp].nombreResultats > 20);
    //Enregistrer les participants au Grand Prix
    do {
    int j, deja_selec = 0; //deja_selec est une variable booléenne de vérification si un pilote a déjà été ajouté ou non
        do {
            printf("Veuillez enregistrer les participants de cette course (choisissez le numero du pilote) : \n");
            Afficher_pilotes(Enregistrer_Pilotes,n);
            scanf("%d", &choix);
        }while(choix < 1 || choix > n);

        for ( j=0; j < n; j++) {
            if (*Enregistrer_Pilotes[choix-1].nom == *Enregistrer_GrandPrix[*gp].Resultats[j].nomPilote &&
                *Enregistrer_Pilotes[choix-1].prenom == *Enregistrer_GrandPrix[choix-1].Resultats[j].prenomPilote) {
                printf("Pilote deja selectionne veuillez en choisir un autre \n");
                deja_selec = 1;
            }

            }
        if (deja_selec == 0) {
                strcpy(Enregistrer_GrandPrix[*gp].Resultats[i].nomPilote,Enregistrer_Pilotes[choix-1].nom);
                strcpy(Enregistrer_GrandPrix[*gp].Resultats[i].prenomPilote,Enregistrer_Pilotes[choix-1].prenom);
                strcpy(Enregistrer_GrandPrix[*gp].Resultats[i].nationalite,Enregistrer_Pilotes[choix-1].nationalite);
                printf("Ajout de %s %s du pays %s\n", Enregistrer_GrandPrix[*gp].Resultats[i].nomPilote,Enregistrer_GrandPrix[*gp].Resultats[i].prenomPilote,
                    Enregistrer_GrandPrix[*gp].Resultats[i].nationalite);
                i++;
        }
    } while (i < Enregistrer_GrandPrix[*gp].nombreResultats);

    do { //ajouter le statut du Grand Prix
        printf("Statut du Grand Prix (1 = actif, 0 = inactif) : \n");
        scanf("%d", &Enregistrer_GrandPrix[*gp].Actif);
        if (Enregistrer_GrandPrix[*gp].Actif != 0 && Enregistrer_GrandPrix[*gp].Actif != 1) {
            printf("Erreur veuillez resaisir le chiffre (1 = Actif et 0 = Inactif\n");
        }
    } while (Enregistrer_GrandPrix[*gp].Actif != 0 && Enregistrer_GrandPrix[*gp].Actif != 1);
    printf("Le grand Prix %s a été ajouté!\n", Enregistrer_GrandPrix[*gp].nomCircuit);
    (*gp)++;
}
//Gère l'heure de commencement d'un Grand Prix
void afficherHeure(struct GrandPrix *Enregistrer_GrandPrix, int gp) {
    //ajoute l'heure
    do {
        printf("Saisir une heure (format HH): ");
        scanf("%d", &Enregistrer_GrandPrix[gp].Horaire.heure);
        if (Enregistrer_GrandPrix[gp].Horaire.heure < 0 || Enregistrer_GrandPrix[gp].Horaire.heure > 23) {
            printf("Erreur, veuillez entrer des valeurs valides \n");
        }
    } while (Enregistrer_GrandPrix[gp].Horaire.heure < 0 || Enregistrer_GrandPrix[gp].Horaire.heure > 23);
    //ajoute les minutes
    do {
        printf("Saisir une minute (format MM): ");
        scanf("%d", &Enregistrer_GrandPrix[gp].Horaire.min);
        if (Enregistrer_GrandPrix[gp].Horaire.min < 0 || Enregistrer_GrandPrix[gp].Horaire.min > 23) {
            printf("Erreur, veuillez entrer des valeurs valides \n");
        }
    } while (Enregistrer_GrandPrix[gp].Horaire.min < 0 || Enregistrer_GrandPrix[gp].Horaire.min > 59);

    printf("L'heure est : {%02d,%02d}\n", Enregistrer_GrandPrix[gp].Horaire.heure, Enregistrer_GrandPrix[gp].Horaire.min);

}
//Gère la date des Grand Prix
void afficherDate(struct GrandPrix *Enregistrer_GrandPrix, int gp){
    //ajoute le jour
    do {
        printf("Saisir un jour : ");
        scanf("%d", &Enregistrer_GrandPrix[gp].Date.jour);
    } while (Enregistrer_GrandPrix[gp].Date.jour < 1 || Enregistrer_GrandPrix[gp].Date.jour > 31);
    //ajoute le mois
    do {
        printf("Saisir un mois(entier): ");
        scanf("%d", &Enregistrer_GrandPrix[gp].Date.mois);
    } while (Enregistrer_GrandPrix[gp].Date.mois < 1 || Enregistrer_GrandPrix[gp].Date.mois > 12);
    //ajoute l'année
    do {
        printf("Saisir une annee : ");
        scanf("%d", &Enregistrer_GrandPrix[gp].Date.annee);
    } while (Enregistrer_GrandPrix[gp].Date.annee < 1900 || Enregistrer_GrandPrix[gp].Date.annee > 2100);

    printf("La date est : {%02d,%02d,%d}\n", Enregistrer_GrandPrix[gp].Date.jour, Enregistrer_GrandPrix[gp].Date.mois, Enregistrer_GrandPrix[gp].Date.annee);
}
//Permet de mettre à jour les résultats des pilotes
void mettre_à_jour_résultat (struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecurie,struct GrandPrix *Enregistrer_GrandPrix,  int n,int gp, int nbEcurie) {
    afficher_grandprix(Enregistrer_GrandPrix, gp);
    int position = 1, choix,choix_pilote, i=0, j = 0; //position est une variable qui va de 1 et aller jusqu'à 20 qui représente les positions d'arrivé des pilotes
    //choix stock le numéro du Grand Prix sélectionné
    //choix_pilote stock la position du pilote dans ce Grand Prix

    if (gp == 0) { //Vérifie si au moins un Grand Prix est présent
        return;
    }
    else {
            printf("Choisissez un GrandPrix : \n"); //Sélectionner un Grand Prix dont on veut emttre à jour les résultats
            scanf("%d", &choix);
            if (Enregistrer_GrandPrix[choix-1].Resultats[Enregistrer_GrandPrix[choix-1].nombreResultats-1].Position==Enregistrer_GrandPrix[choix-1].nombreResultats) {
                printf("Le Grand Prix est complet!\n");
                return;
            }
            for (j=0; j<Enregistrer_GrandPrix[choix-1].nombreResultats;j++) { //Affiche les différents pilotes participants à ce Grand Prix
                for (i = 0; i < Enregistrer_GrandPrix[choix-1].nombreResultats;i++) {
                    printf("%d Pilote : %s %s du pays %s\n",i+1,Enregistrer_GrandPrix[choix-1].Resultats[i].nomPilote
                        ,Enregistrer_GrandPrix[choix-1].Resultats[i].prenomPilote,Enregistrer_GrandPrix[choix-1].Resultats[i].nationalite);
                }
                printf("Quel pilote a termine a la position %d?\n", position); //Demande à l'utilisateur la position des pilotes dans la course//Variable booléenne vérifiant si une position n'a pas été donné deux fois dans une même course
                int verif = 0;
                do {
                    verif = 0;
                    scanf("%d", &choix_pilote);
                    for (int k = 0; k < Enregistrer_GrandPrix[choix-1].nombreResultats; k++) { //vérifier si la position n'a pas été donné plusieurs fois à plusieurs pilotes
                        if (k == choix_pilote-1) {
                            continue;

                        }
                        if (position == Enregistrer_GrandPrix[choix-1].Resultats[k].Position) {
                                printf("Un pilote par position!\n");
                                verif = 1;
                                break;
                            }
                    }
                } while (verif == 1);
                Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].Position = choix_pilote; //Demander le temps qui a été fait par le pilote
                getchar();
                printf("Quel temps realise?(format 0:00:00.000)\n");
                fgets(Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].tempsRealise,
                    sizeof(Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].tempsRealise),stdin);
                Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].tempsRealise
                [strcspn(Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].tempsRealise,"\n")] = '\0';
                switch (position) {
                    case 1:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 25;
                        break;
                    case 2:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 18;
                        break;
                    case 3:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 15;
                        break;
                    case 4:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 12;
                        break;
                    case 5:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 10;
                        break;
                    case 6:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 8;
                        break;
                    case 7:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 6;
                        break;
                    case 8:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 4;
                        break;
                    case 9:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 2;
                        break;
                    case 10:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 1;
                        break;
                    default:
                        Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus = 0;
                        break;
                }
                int l = 0;
                int m = 0;
                for (l = 0; l < n; l++) {
                    if (strcmp(Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].nomPilote,Enregistrer_Pilotes[l].nom)==0) {
                        Enregistrer_Pilotes[l].points += Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus;
                    }
                }
                for (m = 0; m < nbEcurie; m++) {
                    if (strcmp(Enregistrer_Pilotes[l].ecurie,Enregistrer_Ecurie[m].Nom) ==0 ) {
                        Enregistrer_Ecurie[m].Points += Enregistrer_GrandPrix[choix-1].Resultats[choix_pilote-1].pointsObtenus;
                    }
                }
                position++;
            }
    }

}
//afficher le calendrier des Grand Prix
void afficher_grandprix(struct GrandPrix *Enregistrer_GrandPrix, int gp) {
    if (gp == 0) {
        printf("Erreur : aucun Grand Prix enregistré.\n");
    }
    else {
        printf("========== Liste des Grands Prix enregistrés ==========\n\n");
        for (int i = 0; i < gp; i++) {
            printf("Grand Prix #%d\n", i + 1);
            printf("Nom du circuit       : %s\n", Enregistrer_GrandPrix[i].nomCircuit);
            printf("Pays                 : %s\n", Enregistrer_GrandPrix[i].Pays);
            printf("Nombre de tours      : %d\n", Enregistrer_GrandPrix[i].nombreTours);
            printf("Date                 : {%02d,%02d,%04d}\n",
                   Enregistrer_GrandPrix[i].Date.jour,
                   Enregistrer_GrandPrix[i].Date.mois,
                   Enregistrer_GrandPrix[i].Date.annee);
            printf("Horaire              : {%02d,%02d}\n",
                   Enregistrer_GrandPrix[i].Horaire.heure,
                   Enregistrer_GrandPrix[i].Horaire.min);
            printf("Statut               : %s\n", Enregistrer_GrandPrix[i].Actif ? "Actif" : "Inactif");
            printf("--------------------------------------------------------\n");
        }
    }
}
//supprimer un Grand Prix
void supprimer_grandprix(struct GrandPrix *Enregistrer_GrandPrix,int *gp) {
    int index; //numéro du Grand Prix à supprimer
    char choix; //stock le choix de l'utilisateur pour supprimer ou non un Grand Prix
    afficher_grandprix(Enregistrer_GrandPrix, *gp);
    do { //Vérifie si au moins un Grand Prix est présent
        if (*gp == 0) {
            printf("Aucun Grand Prix dans la base de donnees\n");
            return;
        }
        printf("Etes-vous sûr de vouloir supprimer un Grand Prix? (Y ou N) : \n"); //vérifie si l'utilisateur veut supprimer un Grand Prix
        scanf(" %c", &choix);
        if (choix == 'Y') {
            do { //Demande à l'utilisateur quel Grand Prix supprimé
                printf("Quel Grand Prix voulez-vous supprimer?\n");
                scanf("%d", &index);
                if (index < 1 || index > *gp) {
                    printf("Erreur, veuillez saisir un numero valide\n");
                }
            } while (index < 1 || index > *gp);
            for (int i=index-1; i < *gp; i++) {
                Enregistrer_GrandPrix[i] = Enregistrer_GrandPrix[i+1];
            }
            (*gp)--;
            printf("Nouvelle liste\n");
            afficher_grandprix(Enregistrer_GrandPrix, *gp);
        }
        if (choix == 'N') {
            return;
        }
    } while (choix != 'N');
}