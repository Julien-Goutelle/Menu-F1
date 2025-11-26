#include <stdio.h>
#include "Pilote.h"
#include "main.h"
#include "string.h"
#include "Ecurie.h"
//Fonction gérant l'ajout des pilotes
void ajouterPilote(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries, int* n, int nbEcuries) {
    if (*n > 20) {
        printf("Places insuffisantes pour enregistrer plus de pilotes! \n"); //Vérifie que le tableau ne déborde pas
        return;
    }
    int test_point = 0; //Variable de test pour vérifier si le numero d'une voiture est bien unique
    getchar(); //supprime le saut à la lagne
    printf("Nom de famille du pilote : "); //ajouter le nom du pilote
    fgets(Enregistrer_Pilotes[*n].nom,sizeof(Enregistrer_Pilotes[*n].nom),stdin);
    Enregistrer_Pilotes[*n].nom[strcspn(Enregistrer_Pilotes[*n].nom,"\n")]='\0';

    printf("Prenom du pilote : "); //ajouter le prénom du pilote
    fgets(Enregistrer_Pilotes[*n].prenom,sizeof(Enregistrer_Pilotes[*n].prenom), stdin);
    Enregistrer_Pilotes[*n].prenom[strcspn(Enregistrer_Pilotes[*n].prenom,"\n")]='\0';

    printf("Pays de representation : "); //ajouter le pays de représentation
    fgets(Enregistrer_Pilotes[*n].nationalite,sizeof(Enregistrer_Pilotes[*n].nationalite),stdin);
    Enregistrer_Pilotes[*n].nationalite[strcspn(Enregistrer_Pilotes[*n].nationalite,"\n")]='\0';
    int choix; //stock le choix du numero de l'écurie
    do {

        afficher_Ecuries(Enregistrer_Ecuries, nbEcuries);
        printf("Numero de l'ecurie d'appartenance : "); //ajouter l'écurie d'appartenance
        scanf("%d", &choix);
        if (choix < 1 || choix > nbEcuries) { //vérifie que l'écurie existe
            printf("Numero invalide.\n");
        }
        else {
            strcpy(Enregistrer_Pilotes[*n].ecurie,Enregistrer_Ecuries[choix-1].Nom);
        }
    } while (choix < 1 || choix > nbEcuries);

    do {
        printf("Point accumules durant la saison : "); //Permet d'entrer un nombre de points en dur
        scanf("%d", &Enregistrer_Pilotes[*n].points);
        if (Enregistrer_Pilotes[*n].points < 0) {
            printf("Erreur veuillez resaisir le nombre de points (superieur à 0)");
        }
    } while (Enregistrer_Pilotes[*n].points < 0);

    do { //ajouter le numero de la voiture
        test_point = 0;
        printf("Numero de la voiture unique : ");
        scanf("%d", &Enregistrer_Pilotes[*n].numero);
        if (Enregistrer_Pilotes[*n].numero < 1 || Enregistrer_Pilotes[*n].numero > 99) { //Détecter si le numero n'est pas compris entre 1 et 99
            printf("Erreur veuillez resasisir le numero de la voiture (entre 1 et 99)\n");
        }
        for (int i=0; i < *n; i++) { //Vérifie si un numéro a déjà été utilisé
            if (Enregistrer_Pilotes[*n].numero == Enregistrer_Pilotes[i].numero) {
                printf("Le numero est deja pris, veuillez prendre un autre numero \n");
                test_point = 1;
                printf("Rappel des numeros pris : ");
                for (i = 0; i < *n; i++) {
                    printf("%d ", Enregistrer_Pilotes[i].numero);
                }
                printf("\n");
                break;
            }
        }
    } while (Enregistrer_Pilotes[*n].numero < 1 || Enregistrer_Pilotes[*n].numero > 99 || test_point == 1);

    do { //ajoute l'age du pilote
        printf("Age du pilote en annees : ");
        scanf("%d", &Enregistrer_Pilotes[*n].Age);
        if (Enregistrer_Pilotes[*n].Age < 18 || Enregistrer_Pilotes[*n].Age > 50) {
            printf("Erreur veuillez resasisir l'age du pilote (entre 18 et 50 ans)\n");
        }
    } while (Enregistrer_Pilotes[*n].Age < 18 || Enregistrer_Pilotes[*n].Age > 50);

    do { //Entrer l'activité du pilote
        printf("Statut du pilote (1 = actif, 0 = inactif) : ");
        scanf("%d", &Enregistrer_Pilotes[*n].Actif);
        if (Enregistrer_Pilotes[*n].Actif != 0 && Enregistrer_Pilotes[*n].Actif != 1) {
            printf("Erreur veuillez resaisir le chiffre (1 = Actif et 0 = Inactif\n");
        }
    } while (Enregistrer_Pilotes[*n].Actif != 0 && Enregistrer_Pilotes[*n].Actif != 1);

    printf("%s %s from %s financer par %s !\n", Enregistrer_Pilotes[*n].nom, Enregistrer_Pilotes[*n].prenom, Enregistrer_Pilotes[*n].nationalite, Enregistrer_Pilotes[*n].ecurie);
    printf(" POINT : %d  NUMERO : %d  age : %d  actif : %d\n", Enregistrer_Pilotes[*n].points, Enregistrer_Pilotes[*n].numero, Enregistrer_Pilotes[*n].Age, Enregistrer_Pilotes[*n].Actif);
    (*n)++;
}
//Afficher les pilotes
void Afficher_pilotes(struct Pilote *Enregistrer_Pilotes, int n) {
    if (n == 0) {
        printf("Aucun pilote dans la base de donnee\n");
    }
    else {
        printf("============================================\n");
        for (int i=0; i < n; i++) {
            printf("Pilote numero %d\n",i+1);
            printf("%s %s from %s financer par %s !\n", Enregistrer_Pilotes[i].nom, Enregistrer_Pilotes[i].prenom, Enregistrer_Pilotes[i].nationalite, Enregistrer_Pilotes[i].ecurie);
            printf(" POINT : %d\nNUMERO : %d\nage : %d\nactif : %d\n", Enregistrer_Pilotes[i].points, Enregistrer_Pilotes[i].numero, Enregistrer_Pilotes[i].Age, Enregistrer_Pilotes[i].Actif);
            printf("--------------------------------------------------------\n");
        }
    }
}
//supprimer les pilotes
void supprimer_pilotes(struct Pilote *Enregistrer_Pilotes, int* n) {
    int index; //choix du pilotes à supprimer
    char choix; //stock le message de confirmation de l'utilisateur
    Afficher_pilotes(Enregistrer_Pilotes, *n);

    do { //Vérifie qu'il y a bien au moins un pilote enregistré
        if (*n == 0) {
            printf("Aucun pilote dans la base de donnees\n");
            return;
        }
    printf("Etes-vous sûr de vouloir supprimer un pilote? (Y ou N) : \n"); //Demande à l'utilisateur s'il veut supprimer un pilote
    scanf(" %c", &choix);
        if (choix == 'Y') {
            do {
                printf("Quel pilote voulez-vous supprimer?\n"); //Demande à l'utilisateur quel pilote supprimer
                scanf("%d", &index);
                if (index < 1 || index > *n) {
                    printf("Erreur, veuillez saisir un numero valide\n");
                }
            } while (index < 1 || index > *n);
            for (int i=index-1; i < *n; i++) {
                Enregistrer_Pilotes[i] = Enregistrer_Pilotes[i+1];
            }
            (*n)--;
            printf("Nouvelle liste\n"); //Affiche la nouvelle liste
            Afficher_pilotes(Enregistrer_Pilotes, *n);
        }
        if (choix == 'N') {
            return;
        }


    }while (choix != 'N' || choix != 'Y');
}
//modifie le nombre de points
void modifier_points(struct Pilote *Enregistrer_Pilotes, int n) {
    int index;
    if (n == 0) {
        printf("Aucun pilote dans la base de donnee\n");
    }
        Afficher_pilotes(Enregistrer_Pilotes,n);
        do { //Demande à l'utilisateur quel pilote dont il faut modifier les points
            printf("Choisissez le pilote dont vous voulez modifier les points : \n");
            scanf("%d", &index);
            if (index < 0 || index > n) { //Vérifie que le numéro du pilote existe bien
                printf("Erreur veuillez saisir un numero valide\n");
            }
        } while (index < 0 || index > n);
        printf("Entrez la nouvelle valeur de points pour le pilote %s %s", Enregistrer_Pilotes[index].nom, Enregistrer_Pilotes[index].prenom);
        scanf("%d", &Enregistrer_Pilotes[index-1].points);
        Afficher_pilotes(Enregistrer_Pilotes,n);
}
