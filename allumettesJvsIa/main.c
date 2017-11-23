#include <stdio.h>
#include <stdlib.h>

//Prototypes
//Laetitia Monnier
int verifNbAllumette(int , int);
int ia(int);
void tour(int , int*);

int main()
{
    int joueur1 = 0, total = 21;

    printf("Jeu des allumettes\n");
    do{
        if (joueur1 == 0) joueur1 = 1;
        else joueur1 = 0;

        tour(joueur1, &total);
    } while(total > 0);

    if (joueur1 == 0) printf("Joueur 1 : Vous avez perdu !\n");
    else printf("Joueur 1 : Vous avez gagn\x82 !\n");

    system("pause");
    return 0;
}

//BUT : Cette fonction vérifie que le joueur entre bien un chiffre en 1 et 3.
//SORTIE : Vrai ou faux.
int verifNbAllumette(int nbAllumette, int total)
{
    int resultat = 0;

    if ((nbAllumette >= 1) && (nbAllumette <= 3)){
        if (total- nbAllumette >= 0) resultat = 1;
    }
    return resultat;
}

//BUT : Cette fonction gère le tour de l'IA.
int ia(int total)
{
    int resultat = 0;

    if (total > 4) resultat = rand() % 3 + 1;
    else if (total > 1) resultat = total - 1;
    else resultat = 1;
    return resultat;
}

//BUT : Cette procédure gère le tour de jeu.
void tour(int joueur1, int *total)
{
    int nbAllumette;

    printf("Il reste %d", *total);
    printf(" allumettes.\n");

    if (joueur1 == 0){
        printf("Joueur 1 : Faites votre tirage de 1/2/3 allumettes.\n");
        scanf("%d", &nbAllumette);
    }
    else{
        printf("-- Tour de l'ordinateur --\n");
        nbAllumette = ia(*total);
    }

    if (verifNbAllumette(nbAllumette, *total) == 1) *total = *total - nbAllumette;
    else{
        printf("Erreur, veuillez recommencer votre tirage.\n");
        tour(joueur1, total);
    }

}
