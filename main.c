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

bool detecteMarque(case_tableau tab[TAILLE][TAILLE], bool veriftot) { 
    int ol, oc; // optimisation fin du k en ligne et colonne
    bool verif = 0;
    veriftot = 0;   //booléen ppur vérifier qu'il ne reste aucune ligne ou colonne de 3 ou plus
    int i, j, k,l,m,o;
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
                    veriftot=1;
                }
                if ((compteurinf >= 3&&compteur<=1)){
                    tab[i][0].variable=1; // remplacer du premier éléments par un "O"
                    for (int k = 11-compteurinf; k < 10 ; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                    ol=10-compteurinf; //optimisation fin de ligne
                    veriftot=1;
                }
                if (compteurinf+compteur>4&&compteur>=1&&compteurinf>=1){
                    for (int k = 0; k < compteur; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                    for (int k = 11-compteurinf; k<10 ; k++) {
                        tab[i][k].variable=1; // remplacer les éléments par des "O"
                    }
                    ol=10-compteurinf; //optimisation fin de ligne
                    veriftot=1;
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
                        veriftot=1;
                        
                    }
                }
                if (compteurinf >= 3&&compteur==1){
                    tab[0][j].variable=1; // remplacer du premier éléments par un "O"
                    for (int k = 11-compteurinf; k <10 ; k++) {
                        tab[k][j].variable=1; // remplacer les éléments par des "O"
                        veriftot=1;
                        
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
                veriftot=1;
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
                    veriftot=1;
                }
                compteur = 1; // réinitialisation du compteur à 1
                while (i + compteur < 10 && tab[i + compteur][j].caractere == tab[i][j].caractere) {
                    compteur++; // compter le nombre d'éléments égaux vers le bas
                }
                if (compteur >= 3) { // si on a trouvé une série d'au moins 3 éléments égaux
                    for (int k = 0; k < compteur; k++) {
                        tab[i+k][j].variable=1; // remplacer les éléments par des "O"
                    }
                    veriftot=1;
                }
            }
        }        
    }
    return veriftot;
}


void DeplacerGauche(case_tableau tab[TAILLE][TAILLE]) {
    int i,j,k;
    bool vérif=0;
    
    
    
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (tab[i][j].variable == 1) {
                k = j;
                while (k > 0 && tab[i][k - 1].variable == 0) {
                    // Échanger le caractère (avec son booléen précédent!!!!)
                    char tempCaractere = tab[i][k - 1].caractere;
                    int tempVariable = tab[i][k - 1].variable;
                    tab[i][k - 1].caractere = tab[i][k].caractere;
                    tab[i][k - 1].variable = tab[i][k].variable;
                    tab[i][k].caractere = tempCaractere;
                    tab[i][k].variable = tempVariable;
                    k--;
                }
            }
        }
    }


    

}

void remplacement(case_tableau tab[TAILLE][TAILLE]){
    int i, j, k;
    bool vérif=0;
    bool vériftot;
    
    
    do{             // remplacement de tout les caractères avec un booléen = 1 
        vériftot=detecteMarque(tab,vériftot); // vériftot ici sert à détecter si le programme detecteMarque change une variable d'un caractère 
        DeplacerGauche(tab);
        for(i=0;i<TAILLE;i++){
            vérif=0;
            for(k=0;k<TAILLE;k++){ // Génération aléatoire des caractères
                if(tab[i][k].variable==1){
                    vérif=1;
                    tab[i][k].caractere='A'+rand()%6; // 6 symboles différents
                    tab[i][k].variable=0; // variable à zero pour le compteur
                }
            }
        }
        
    }while(vérif==1 || vériftot==1);    //le do while ici sert pour ne pas sortir de la boucle tant que un des deux booléens est égale à 1
}

void Affichage(case_tableau tab[TAILLE][TAILLE]){ // Affichage du tableau
int i,j,k;
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


void Affichagemoji(case_tableau tab[TAILLE][TAILLE]){ // Affichage du tableau
int i,j,k;
    for(i=0;i<TAILLE;i++){
        printf("\n \n");
        if(i==0){
        printf("   0.   1.   2.   3.   4.   5.   6.   7.   8.   9.\n");
        }
        else{
        printf(" +----+----+----+----+----+----+----+----+----+----+\n"); // Ligne supérieure de séparation
        }
        for(k=0;k<TAILLE;k++){
            if(k==0){
                printf("%d",i);   
            }
            if(tab[i][k].variable==1){
                printf("|");
                printf("\x1b[31m O ");
                printf(PCOLOR("%d"),0);
                
            }
            else if(tab[i][k].caractere=='A'){
                printf("|");
                printf(" 🍐 ");
                
            }
            else if(tab[i][k].caractere=='B'){
                printf("|");
                printf(" 🍉 ");
            }
            else if(tab[i][k].caractere=='C'){
                printf("|");
                printf(" 🥝 ");
                
            }
            else if(tab[i][k].caractere=='D'){
                printf("|");
                printf(" 🍇 ");
                
            }
            else if(tab[i][k].caractere=='E'){
                printf("|");
                printf(" 🧁 ");
                printf(PCOLOR("%d"),0);
            }
            else if(tab[i][k].caractere=='F'){
                printf("|");
                printf(" 🥕 ");
                printf(PCOLOR("%d"),0);
            }
        }
        printf("|"); // Barre de fin
    } 
    printf("\n +----+----+----+----+----+----+----+----+----+----+\n"); // Ligne inférieure de séparation
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
    Affichage(tab);
    remplacement(tab);
    Affichagemoji(tab);
    
    return 0;
}




















