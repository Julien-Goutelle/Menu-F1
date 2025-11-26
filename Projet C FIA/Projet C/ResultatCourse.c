#include <stdio.h>
#include <string.h>
#include "main.h"
#include "ResultatCourse.h"
void trier_pilotes_par_points(struct Pilote *Enregistrer_Pilotes, int n);
/* =============================
   CLASSEMENT D'UNE COURSE
   ============================= */
void classement_course(struct GrandPrix *Enregistrer_GrandPrix, int gp) {
    if (gp == 0) {
        printf("Aucun Grand Prix enregistre.\n");
        return;
    }

    int choix;
    printf("\n=== CLASSEMENT D'UNE COURSE ===\n");
    for (int i = 0; i < gp; i++) {
        printf("%d - %s (%s)\n", i + 1, Enregistrer_GrandPrix[i].nomCircuit, Enregistrer_GrandPrix[i].Pays);
    }

    printf("Choisissez le numero du Grand Prix : ");
    scanf("%d", &choix);

    if (choix < 1 || choix > gp) {
        printf("Numero invalide.\n");
        return;
    }

    choix--;

    printf("\nResultats du Grand Prix de %s (%s)\n", Enregistrer_GrandPrix[choix].nomCircuit, Enregistrer_GrandPrix[choix].Pays);
    printf("----------------------------------------------------\n");

    for (int i = 0; i < Enregistrer_GrandPrix[choix].nombreResultats; i++) {
        printf("%2d. %-15s %-15s | %s | %s | Points : %d\n", // %-15s permet d'aligner
               Enregistrer_GrandPrix[choix].Resultats[i].Position,
               Enregistrer_GrandPrix[choix].Resultats[i].prenomPilote,
               Enregistrer_GrandPrix[choix].Resultats[i].nomPilote,
               Enregistrer_GrandPrix[choix].Resultats[i].nationalite,
               Enregistrer_GrandPrix[choix].Resultats[i].tempsRealise,
               Enregistrer_GrandPrix[choix].Resultats[i].pointsObtenus);
    }
}

/* =============================
   CLASSEMENT GÉNÉRAL PILOTES
   ============================= */
void classement_pilotes(struct Pilote *Enregistrer_Pilotes, int n) {
    if (n == 0) {
        printf("Aucun pilote enregistre.\n");
        return;
    }

    // Tri décroissant par points
    trier_pilotes_par_points(Enregistrer_Pilotes, n);

    printf("\n=== CLASSEMENT GENERAL DES PILOTES ===\n");
    printf("============================================\n");
    for (int i = 0; i < n; i++) {
        if (Enregistrer_Pilotes[i].Actif) {
            printf("%2d. %-15s %-15s | %s | %s | Points : %d\n",
                   i + 1,
                   Enregistrer_Pilotes[i].prenom,
                   Enregistrer_Pilotes[i].nom,
                   Enregistrer_Pilotes[i].nationalite,
                   Enregistrer_Pilotes[i].ecurie,
                   Enregistrer_Pilotes[i].points);
        }
    }
}

/* =============================
   CLASSEMENT CONSTRUCTEURS
   ============================= */
void classement_constructeurs(struct Pilote *Enregistrer_Pilotes,struct Ecurie *Enregistrer_Ecuries ,int n,int nbEcuries) {

    // Regroupe les écuries depuis les pilotes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nbEcuries; j++) {
            if (strcmp(Enregistrer_Ecuries[j].Nom, Enregistrer_Pilotes[i].ecurie) == 0) {
                Enregistrer_Ecuries[j].Points += Enregistrer_Pilotes[i].points;
                break;
            }
        }
    }

    // Tri décroissant par points
    for (int i = 0; i < nbEcuries - 1; i++) {
        for (int j = i + 1; j < nbEcuries; j++) {
            if (Enregistrer_Ecuries[i].Points < Enregistrer_Ecuries[j].Points) {
                struct Ecurie temp = Enregistrer_Ecuries[i];
                Enregistrer_Ecuries[i] = Enregistrer_Ecuries[j];
                Enregistrer_Ecuries[j] = temp;
            }
        }
    }

    printf("\n=== CLASSEMENT CONSTRUCTEURS ===\n");
    printf("============================================\n");
    for (int i = 0; i < nbEcuries; i++) {
        printf("%2d. %-20s | Points : %d\n", i + 1, Enregistrer_Ecuries[i].Nom, Enregistrer_Ecuries[i].Points);
    }
    for (int i = 0; i < nbEcuries; i++) {
        Enregistrer_Ecuries[i].Points = 0;
    }

}

/* =============================
   TRI PILOTES PAR POINTS
   ============================= */
void trier_pilotes_par_points(struct Pilote *Enregistrer_Pilotes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Enregistrer_Pilotes[i].points < Enregistrer_Pilotes[j].points) {
                struct Pilote temp = Enregistrer_Pilotes[i];
                Enregistrer_Pilotes[i] = Enregistrer_Pilotes[j];
                Enregistrer_Pilotes[j] = temp;
            }
        }
    }
}
