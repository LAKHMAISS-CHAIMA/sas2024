#include <stdio.h>// Requise pour les entrées/sorties.
#include <string.h>//
#define max_Tache 200
typedef struct{
int jour;
int mois;
int annee;
}Date;

typedef struct{
char titre[20];
char description[100];
int  priorite;//0 est low, 1 est high
int status;//0 est incomplete, 1 est complete
Date dt;
}Tache;
Tache DB[max_Tache]; //Base de données des tâches
int taches = 0;
void ajouter() {
    printf(" entrer les détails de tâche : \n " );

    // ajouter le titre :
    printf("le titre :  ");
    getchar(); // Consomme le '\n' restant
    fgets(DB[taches].titre, 20, stdin);
    DB[taches].titre[strcspn(DB[taches].titre, "\n")] = '\0';

    //ajouter la description :
    printf("la description :  ");
    getchar(); // pour consommer les sauts de ligne. 
    fgets(DB[taches].description, 100, stdin);
    DB[taches].description[strcspn(DB[taches].description, "\n")] = '\0';

    // ajouter la priorité :
    printf("la priorité : \n ");
    do {
        printf("Priorité (0 : low, 1 : high) : ");
        scanf("%d", &DB[taches].priorite);
    } while (DB[taches].priorite < 0 || DB[taches].priorite > 1);
    
    // ajouter le status :
    do {
        printf("Status (0 : incomplete, 1 : complete) : ");
        scanf("%d", &DB[taches].status);
    } while (DB[taches].status < 0 || DB[taches].status > 1);


    // ajouter la date :
    printf("Entrez la date :\n");
    do {
        printf("Jour (1-31) : ");
        scanf("%d", &DB[taches].dt.jour);
    } while (DB[taches].dt.jour < 1 || DB[taches].dt.jour > 31);

    do{
        printf("mois (1-12) : ");
        scanf("%d", &DB[taches].dt.mois);
    } while (DB[taches].dt.mois < 1 || DB[taches].dt.mois > 12);

    printf("Année : ");
    scanf("%d", &DB[taches].dt.annee);

    taches++; // Incrémenter le compteur
    printf("Tâche ajoutée avec succès !\n");
}
void afficher(){

     int i;
     for (i = 0; i < taches; i++){
     printf("affichage de la tache : \n ");
     printf("le titre est :%s\n",DB[i].titre);
     printf("la description est :%s\n",DB[i].description);
     printf("la priorité est :%s\n",DB[i].priorite ? "high" : "low");
     printf("le status est :%s\n",DB[i].status ? "complete" : "incomplete");
     /*L'opérateur ? : est utilisé ici pour effectuer une évaluation conditionnelle sur les valeurs priorité et status.
      Si la condition est vraie (1), la première valeur est utilisée ("high" ou "complete").
      Si elle est fausse (0), la deuxième valeur est utilisée ("low" ou "incomplete").*/
     printf("Date d'échéance (jour/mois/année) : %d/%d/%d \n", DB[i].dt.jour,DB[i].dt.mois,DB[i].dt.annee);
 }
}
void modifier(){
    int choix;
    printf("Entrez votre choix de la tâche à modifier : ");
    scanf("%d", &choix);
    getchar(); // Consomme le '\n' restant
    
    if(choix < 0 || choix >= taches) {
		printf("choix invalide.\n");
        return;
    }
        printf("Modifier les détails de la tâche existante :\n");
        // modifier le titre :
        printf("entrer le nouveau titre (actuel : %s\n)", DB[choix].titre);
        fgets(DB[choix].titre, 20, stdin);
        DB[choix].titre[strcspn(DB[choix].titre, "\n")] = '\0'; // Supprime le '\n'

        
        // modifier la description :
        printf("entrer la nouvelle description (actuelle : %s\n)", DB[choix].description);
        fgets(DB[choix].description, 100, stdin);
        DB[choix].description[strcspn(DB[choix].description, "\n")] = '\0';


        // modifier la priorité :
        do {
        printf("modifier la prioreté (actuelle : %s\n) (0 : low, 1 : high) ",
        DB[choix].priorite ? "high" : "low");
        scanf("%d",&DB[choix].priorite);
        } while (DB[choix].priorite < 0 || DB[choix].priorite > 1);


        // modifier le status :
        do {
        printf("modifier le status (actuel : %s\n) (0 : incomplete, 1 : complete) ",
        DB[choix].status ? "complete" : "incomplete");
        scanf("%d",&DB[choix].status);
        } while (DB[choix].status < 0 || DB[choix].status > 1);


        // modifier la date :
        printf("Entrer la nouvelle date (actuelle : %d/%d/%d) :\n",
           DB[choix].dt.jour, DB[choix].dt.mois, DB[choix].dt.annee);

    do {
        printf("Jour (1-31) : ");
        scanf("%d", &DB[choix].dt.jour);
    } while (DB[choix].dt.jour < 1 || DB[choix].dt.jour > 31);

    do {
        printf("Mois (1-12) : ");
        scanf("%d", &DB[choix].dt.mois);
    } while (DB[choix].dt.mois < 1 || DB[choix].dt.mois > 12);

    printf("Année : ");
    scanf("%d", &DB[choix].dt.annee);

    printf("Tâche mise à jour avec succès !\n");
}
void supprimer() {
    int i;
    int count;
     printf("entrez la tache à supprimer:");
     scanf("%d",&count);
        if(count <0  || count >= taches){
                printf("choix invalide !\n");
       }else{
            for( i= count; i < taches - 1 ;i++){
 //la taches - 1 est utilisé pour éviter d'accéder à une position hors des limites du tableau lors du décalage des éléments.               

                DB[i] = DB[i+1];
            }
               taches--;
                printf("Supprimé avec succès !\n");
       }
}
void filtrer(){
    int i;
    int priorite;
    int n = 0; // Variable pour suivre si une tâche est trouvée

    do {
        printf("Entrez la priorité de la tâche : ");
        scanf("%d", &priorite);
        if (priorite != 0 && priorite != 1) {
            printf("Choix invalide. Utilisez 0 pour low priorité et 1 pour high priorité.\n");
        }
    } while (priorite != 0 && priorite != 1);

    printf("Vous avez choisi la priorité : %s\n", priorite == 1 ? "high" : "low");

    for (i = 0; i < taches; i++) {
        if (DB[i].priorite == priorite) {
            printf("Titre de la tâche : %s\n", DB[i].titre);
            printf("Description : %s\n", DB[i].description);
            printf("Date : %02d/%02d/%04d\n", DB[i].dt.jour, DB[i].dt.mois, DB[i].dt.annee);
            printf("Statut : %s\n\n", DB[i].status == 1 ? "complete" : "incomplete");
            n = 1;
        }
    }

    if (n == 0) {
        printf("Aucune tâche trouvée avec cette priorité.\n");
    }
}

int main(){
int choix;
	do{
		printf("\n  Menu \n");
		printf("1-ajouter \n");
		printf("2-afficher \n");
		printf("3-modifier \n ");	
		printf("4-Supprimer \n");
        printf("5-filtrer \n");
        printf("6-quitter \n");
		printf("Enter votre choix : ");
		scanf("%d",&choix);
		switch(choix){
             case 1:ajouter();
             break;
             case 2:afficher();
             break;
              case 3:modifier();
             break; 
             case 4:supprimer();
             break;
             case 5:filtrer();
             break;
             case 6: printf("bye bye");
             break;
             default : printf("choix invalide");
        }
        }while(choix!=2);//// Boucle tant que l'utilisateur ne choisit pas de quitter

}




