#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 4

//Laetitia Monnier
//Prototype
int verifNbAllumette(int , int);
void affichePyramide(int[TAILLE]);
int iaTirage(int);
int iaLigne(int[TAILLE]);
void tour(int, int[TAILLE], int*);

int main()
{
    int tabPy[TAILLE];
    int compteur = 0, totalPyramide = 0, joueur1 = 0;
    printf("Jeu des allumettes - Pyramide -\n");

    //Initialisation de la pyramide.
    for(compteur = 0; compteur < TAILLE; compteur++){
        tabPy[compteur] = 2 * compteur + 1;
        totalPyramide = 16;
    }

    do{
        if (joueur1 == 0)
            joueur1 = 1;
        else joueur1 = 0;

        tour(joueur1, tabPy, &totalPyramide);
    } while (totalPyramide > 0);

    if (joueur1 == 1)
        printf("Vous avez perdu Joueur 1.\n");
    else
        printf("Vous avez gagn\x82 Joueur 1.\n");

    system("pause");
    return 0;
}

//BUT :vérifie que le joueur entre bien le nombre d'allumette demandé.
int verifNbAllumette(int nbAllumette, int total)
{
    int resultat = 0;

    if ((nbAllumette >= 1) && (nbAllumette <= 3)){
        if (total - nbAllumette >= 0)
            resultat = 1;
    }

    return resultat;
}

//BUT : Affiche de la pyramide.
void affichePyramide(int tabPy[TAILLE])
{
    int compteur = 0;

    for (compteur = 0; compteur < TAILLE; compteur++)
        printf("%d\n",tabPy[compteur]);
}

//BUT : Tirage du nombre d'allumette de l'IA.
int iaTirage(int total)
{
   int resultat = 0;

    if (total > TAILLE)
        resultat = rand() % 3 + 1;

   else if (total > 1)
    resultat = total - 1;
   else
    resultat = 1;

   return resultat;
}

//BUT : L'IA choisi la ligne dans laquelle elle enlevera une/des allumettes.
int iaLigne(int tabPy[TAILLE])
{
    int resultat = 0;

    do{
        resultat = rand() % 3;
    } while((tabPy[resultat] < 0) && (tabPy[resultat] > 3));

    return resultat;
}

//BUT : Cette procèdure gère le tour de jeu.
void tour(int joueur1, int tabPy[TAILLE], int *totalPyramide)
{
    int nbAllumette = 0, ligne = 0;

    srand(time(NULL));
    affichePyramide(tabPy);
    if (joueur1 == 1){
        printf("Joueur 1 : Choisissez une ligne (0/1/2/3).\n");
        scanf("%d", &ligne);
        printf("Joueur 1 : Faites votre tirage (1/2/3).\n");
        scanf("%d", &nbAllumette);
        printf("\n");
    }
    else {
        printf("-- Tour de l'ordinateur --\n");
        ligne = iaLigne(tabPy);
        nbAllumette = iaTirage(tabPy[ligne]);
        printf("\n");
    }

    /*Cette condition est valable pour l'IA. Si elle se trompe,
    la procèdure tour() sera appelée automatiquement jusqu'a ce que l'IA trouve la bonne combinaison
    (comme si c'était un joueur qui s'était trompé).*/
     if (verifNbAllumette(nbAllumette, tabPy[ligne]) == 1) {
        tabPy[ligne] = tabPy[ligne] - nbAllumette;
        *totalPyramide = *totalPyramide - nbAllumette;
        }
    else {
        printf("Erreur, veuillez recommencer votre tirage.\n");
        tour(joueur1, tabPy, totalPyramide);
    }

}
