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
            
        }
        }while(choix!=2);//// Boucle tant que l'utilisateur ne choisit pas de quitter

}




