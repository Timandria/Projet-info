#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h> //pour les booléens

#define TAILLE 10
#define S "0"//reSet color
#define L "1"//add light to the color
#define D "2"//assombrie les caractère
#define E "22"//anule les effet L et D
#define V "31"//rouge car R est déja pris
#define G "32"//vert 
#define Y "33"//jaune
#define B "34"//bleu 
#define M "35"//magenta
#define C "36"//cyan
#define W "37"//blanc

#define PCOLOR(X) "\x1b["X"m"    //macro pour ajouter la couleur facilement, le X est l'emplacement du code couleur, au forma "nombre"
typedef struct case_tableau {
    char caractere;
    bool variable;
} case_tableau;



void TriBulle(case_tableau tab[TAILLE][TAILLE]){   //TriBulle pour simuler une gravité à droite pas fonctionnelle voir le cours pour appeller et déclarer correctement 
bool desordre; //BOOLEEN
int i;
int k;
char temp;
int noEtape;
noEtape=k-1;
do{
    desordre = 0;
    for(i=0;i<9;i++){
        for(k=0;k<9;k++){   //noCase de 0 à noEtape
            if (tab[i][k+1].variable==1){    //ajustement à faire pour une gravité à droite
                desordre=1;
                temp = tab[i][k].caractere;
                tab[i][k].caractere=tab[i][k+1].caractere;
                tab[i][k+1].caractere = temp;
            }
        }
    }
}while (desordre==1);
for(i=0;i<TAILLE;i++){
        printf("\n \n");
        printf("+---+---+---+---+---+---+---+---+---+---+\n"); // Ligne supérieure de séparation
        for(k=0;k<TAILLE;k++){
            if(tab[i][k].variable==1){
                printf("|");
                printf("\x1b[31m O ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='A'){
                printf("|");
                printf("\x1b[32m A ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='B'){
                printf("|");
                printf("\x1b[33m B ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='C'){
                printf("|");
                printf("\x1b[34m C ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='D'){
                printf("|");
                printf("\x1b[35m D ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='E'){
                printf("|");
                printf("\x1b[36m E ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='F'){
                printf("|");
                printf("\x1b[37m F ");
                printf(PCOLOR("%d"),0);
            }
        }
        printf("|"); // Barre de fin
    } 
    printf("\n+---+---+---+---+---+---+---+---+---+---+\n"); // Ligne inférieure de séparation
}



int main()
{
    int ol,oc; //optimisation fin du k en ligne et colonne 
    case_tableau tab[TAILLE][TAILLE]; // Définition du tableau
    srand(time(NULL)); // Génération aléatoire
    int i,k,j;
    for(i=0;i<TAILLE;i++){
        for(k=0;k<TAILLE;k++){ // Génération aléatoire des caractères
            tab[i][k].caractere='A'+rand()%6; // 6 symboles différents
            tab[i][k].variable=0; // variable à zero pour le compteur
        }
    }
    for(i=0;i<TAILLE;i++){
        printf("\n \n");
        printf("+---+---+---+---+---+---+---+---+---+---+\n"); // Ligne supérieure de séparation
        for(k=0;k<TAILLE;k++){
            printf("| %c ",tab[i][k].caractere);
        }
        printf("|"); // Barre de fin
    } 
    printf("\n+---+---+---+---+---+---+---+---+---+---+\n"); // Ligne inférieure de séparation
    for (int i = 0; i < 10; i++) {
        ol=10;
        for (int j = 0; j < ol; j++) {
            if(j==0){
                oc=10;
                int compteur = 1; // initialisation des compteurs à 1
                int compteurinf=1;
                while (compteur < 10 && tab[i][compteur].caractere == tab[i][j].caractere) {
                compteur++; // compter le nombre d'éléments égaux vers la droite
                }
                while (10-compteurinf >=0 && tab[i][10 - compteurinf].caractere == tab[i][0].caractere) {
                compteurinf++; // compter le nombre d'éléments égaux vers la droite
                }
                if (compteur >= 3&&compteurinf<=1) { // si on a trouvé une série d'au moins 3 éléments égaux
                    for (int k = 0; k < compteur; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                }
                if ((compteurinf >= 3&&compteur<=1)){
                    tab[i][0].variable=1; // remplacer du premier éléments par un "O"
                    for (int k = 11-compteurinf; k < 10 ; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                    ol=10-compteurinf; //optimisation fin de ligne
                }
                if (compteurinf+compteur>4&&compteur>=1&&compteurinf>=1){
                    for (int k = 0; k < compteur; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                    for (int k = 11-compteurinf; k<10 ; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                    ol=10-compteurinf; //optimisation fin de ligne
                }
            }
            if(i==0){
                int compteur = 1; // réinitialisation des compteurs à 1
                int compteurinf=1; 
                while (10-compteurinf >=0 && tab[10 - compteurinf][j].caractere == tab[i][j].caractere) {
                compteurinf++; // compter le nombre d'éléments égaux vers la droite
                }
                while (compteur < 10 && tab[i + compteur][j].caractere == tab[i][j].caractere) {
                    compteur++; // compter le nombre d'éléments égaux vers le bas
                }
                if (compteur >= 3&&compteurinf==1) { // si on a trouvé une série d'au moins 3 éléments égaux
                    for (int k = 0; k < compteur; k++) {
                        tab[k][j].variable=1; // remplacer les éléments par des "O"
                        
                    }
                }
                if (compteurinf >= 3&&compteur==1){
                    tab[0][j].variable=1; // remplacer du premier éléments par un "O"
                    for (int k = 11-compteurinf; k <10 ; k++) {
                        tab[k][j].variable=1; // remplacer les éléments par des "O"
                        
                    }
                oc=10-compteurinf;
                }
                if (compteurinf+compteur>4&&compteur!=1&&compteurinf!=1){
                    for (int k = 0; k < compteur; k++) {
                        tab[k][j].variable=1; // remplacer les éléments par des "O"
                    }
                    for (int k = 11-compteur; k < 10; k++) {
                        tab[k][j].variable=1; // remplacer les éléments par des "O"
                       
                    }
                oc=10-compteurinf; //optimisation fin de ligne
                }
            }
            int compteur = 1; // initialisation du compteur à 1
            while (j + compteur < 10 && tab[i][j + compteur].caractere == tab[i][j].caractere) {
                compteur++; // compter le nombre d'éléments égaux vers la droite
            }
            if (compteur >= 3) { // si on a trouvé une série d'au moins 3 éléments égaux
                for (int k = 0; k < compteur; k++) {
                    tab[i][j+k].variable=1; // remplacer les éléments par des "O"
                }
            }
            compteur = 1; // réinitialisation du compteur à 1
            while (i + compteur < 10 && tab[i + compteur][j].caractere == tab[i][j].caractere) {
                compteur++; // compter le nombre d'éléments égaux vers le bas
            }
            if (compteur >= 3) { // si on a trouvé une série d'au moins 3 éléments égaux
                for (int k = 0; k < compteur; k++) {
                    tab[i+k][j].variable=1; // remplacer les éléments par des "O"
                }
            }
        
        
        
            for (int j = 0; j < 10; j++) {
                int compteur = 1; // initialisation du compteur à 1
                while (j + compteur < 10 && tab[i][j + compteur].caractere == tab[i][j].caractere) {
                    compteur++; // compter le nombre d'éléments égaux vers la droite
                }
                if (compteur >= 3) { // si on a trouvé une série d'au moins 3 éléments égaux
                    for (int k = 0; k < compteur; k++) {
                        tab[i][j+k].variable=1; // remplacer les éléments par des "O"
                    }
                }
                compteur = 1; // réinitialisation du compteur à 1
                while (i + compteur < 10 && tab[i + compteur][j].caractere == tab[i][j].caractere) {
                    compteur++; // compter le nombre d'éléments égaux vers le bas
                }
                if (compteur >= 3) { // si on a trouvé une série d'au moins 3 éléments égaux
                    for (int k = 0; k < compteur; k++) {
                        tab[i+k][j].variable=1; // remplacer les éléments par des "O"
                    }
                }
            }
        }        
    }

    // Affichage du tableau
    for(i=0;i<TAILLE;i++){
        printf("\n \n");
        printf("+---+---+---+---+---+---+---+---+---+---+\n"); // Ligne supérieure de séparation
        for(k=0;k<TAILLE;k++){
            if(tab[i][k].variable==1){
                printf("|");
                printf("\x1b[31m O ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='A'){
                printf("|");
                printf("\x1b[32m A ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='B'){
                printf("|");
                printf("\x1b[33m B ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='C'){
                printf("|");
                printf("\x1b[34m C ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='D'){
                printf("|");
                printf("\x1b[35m D ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='E'){
                printf("|");
                printf("\x1b[36m E ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='F'){
                printf("|");
                printf("\x1b[37m F ");
                printf(PCOLOR("%d"),0);
            }
        }
        printf("|"); // Barre de fin
    } 
    printf("\n+---+---+---+---+---+---+---+---+---+---+\n"); // Ligne inférieure de séparation
    TriBulle(tab);//ajustement à faire pour un bon appel
    
    
    return 0;
}


















