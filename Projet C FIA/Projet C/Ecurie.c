#include <stdio.h>
#include <string.h>
#include "main.h"
#include "Ecurie.h"

/* ============================
   AJOUTER UNE ÉCURIE
   ============================ */
void ajouter_Ecurie(struct Ecurie *Enregistrer_Ecuries, int *nbEcuries) { // créer une structure dans la fonction ajouter
    getchar(); // enlève le saut à la ligne à cause de la sucession scanf puis gets
    if (*nbEcuries > 20) {
        printf("Places insuffisantes pour enregistrer plus de pilotes! \n"); //Vérifie que le tableau ne déborde pas
        return;
    }
    printf("\n--- AJOUT D’UNE NOUVELLE ECURIE ---\n");
    // fgets = scanf pour les string.h finie par stdin
    printf("Nom de l'ecurie : ");
    fgets(Enregistrer_Ecuries[*nbEcuries].Nom, sizeof(Enregistrer_Ecuries[*nbEcuries].Nom), stdin);
    Enregistrer_Ecuries[*nbEcuries].Nom[strcspn(Enregistrer_Ecuries[*nbEcuries].Nom, "\n")] = '\0';

    printf("Pays d'origine : ");
    fgets(Enregistrer_Ecuries[*nbEcuries].Pays, sizeof(Enregistrer_Ecuries[*nbEcuries].Pays), stdin);
    Enregistrer_Ecuries[*nbEcuries].Pays[strcspn(Enregistrer_Ecuries[*nbEcuries].Pays, "\n")] = '\0';

    do {
        printf("Annee de creation (1900 - 2025) : ");
        scanf("%d", &Enregistrer_Ecuries[*nbEcuries].anneeCreation);
        if (Enregistrer_Ecuries[*nbEcuries].anneeCreation < 1900 || Enregistrer_Ecuries[*nbEcuries].anneeCreation > 2025)
            printf("Erreur : annee invalide !\n");
    } while (Enregistrer_Ecuries[*nbEcuries].anneeCreation < 1900 || Enregistrer_Ecuries[*nbEcuries].anneeCreation > 2025);

    getchar();
    printf("Nom du directeur : ");
    fgets(Enregistrer_Ecuries[*nbEcuries].Directeur, sizeof(Enregistrer_Ecuries[*nbEcuries].Directeur), stdin);
    Enregistrer_Ecuries[*nbEcuries].Directeur[strcspn(Enregistrer_Ecuries[*nbEcuries].Directeur, "\n")] = '\0';

    do {
        printf("Statut (1 = Actif, 0 = Inactif) : ");
        scanf("%d", &Enregistrer_Ecuries[*nbEcuries].Actif);
        if (Enregistrer_Ecuries[*nbEcuries].Actif != 0 && Enregistrer_Ecuries[*nbEcuries].Actif != 1)
            printf("Erreur, veuillez saisir 1 ou 0.\n");
    } while (Enregistrer_Ecuries[*nbEcuries].Actif != 0 && Enregistrer_Ecuries[*nbEcuries].Actif != 1);

    Enregistrer_Ecuries[*nbEcuries].Points = 0;

    printf("ecurie %s creee avec succes !\n\n", Enregistrer_Ecuries[*nbEcuries].Nom);
    (*nbEcuries)++;
}

/* ============================
   AFFICHER LES ÉCURIES
   ============================ */
void afficher_Ecuries(struct Ecurie *Enregistrer_Ecuries, int nbEcuries) {
    if (nbEcuries == 0) {
        printf("Aucune ecurie enregistree.\n");
        return;
    }

    printf("\n=== LISTE DES ECURIES ===\n");
    printf("============================================\n");
    for (int i = 0; i < nbEcuries; i++) {
        printf("Ecurie num %d : %s\n", i + 1, Enregistrer_Ecuries[i].Nom);
        printf("Pays : %s\n", Enregistrer_Ecuries[i].Pays);
        printf("Annee : %d\n", Enregistrer_Ecuries[i].anneeCreation);
        printf("Directeur : %s\n", Enregistrer_Ecuries[i].Directeur);
        printf("Points : %d\n", Enregistrer_Ecuries[i].Points);
        printf("Statut : %s\n", Enregistrer_Ecuries[i].Actif ? "Active" : "Inactive");
        printf("============================================\n");
    }
}

/* ============================
   SUPPRIMER UNE ÉCURIE
   ============================ */
void supprimer_Ecurie(struct Ecurie *Enregistrer_Ecuries, int *nbEcuries) {
    int index;
    char choix;

    if (*nbEcuries == 0) {
        printf("Aucune ecurie a supprimer.\n");
        return;
    }

    afficher_Ecuries(Enregistrer_Ecuries, *nbEcuries);
    printf("Supprimer une ecurie ? (Y/N) : ");
    scanf(" %c", &choix);

    if (choix == 'Y' || choix == 'y') {
        do {
            printf("Numero de l'ecurie a supprimer : ");
            scanf("%d", &index);
            if (index < 1 || index > *nbEcuries)
                printf("Numero invalide.\n");
        } while (index < 1 || index > *nbEcuries);

        for (int i = index - 1; i < *nbEcuries - 1; i++) {
            Enregistrer_Ecuries[i] = Enregistrer_Ecuries[i + 1];
        }
        (*nbEcuries)--;
        printf("Ecurie supprimee avec succes.\n");
    }
    else {
        printf("Annulation.\n");
    }
}

/* ============================
   MISE À JOUR DES POINTS
   ============================ */
void mettre_a_jour_points(struct Ecurie *Enregistrer_Ecuries, int nbEcuries,struct Pilote *Enregistrer_Pilotes, int nbPilotes) {
    for (int i = 0; i < nbEcuries; i++) {
        int total = 0;
        for (int j = 0; j < nbPilotes; j++) {
            if (strcmp(Enregistrer_Pilotes[j].ecurie, Enregistrer_Ecuries[i].Nom) == 0) {
                total += Enregistrer_Pilotes[j].points;
            }
        }
        Enregistrer_Ecuries[i].Points = total;
    }
    printf("Points des ecuries mis a jour avec succes.\n");
}





