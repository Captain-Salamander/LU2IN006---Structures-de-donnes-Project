/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#include"Chaine.h"

int main(int argc, char** argv){
    if(argc<2){
        printf("Trop peu d'arguments\nUsage: %s nom_fichier\n", argv[0]);
        return 1;
    }

    //Lecture fichier
    FILE* f1 = fopen(argv[1], "r");
    if(f1==NULL){
        printf("Erreur ouverture fichier %s\n", argv[1]);
        return 2;
    }

    Chaines* C = lectureChaines(f1);
    fclose(f1);

    //Ecriture fichier
    FILE *f2 = fopen("testEcriture.cha", "w");
    if(f2==NULL){
        printf("Erreur ouverture fichier testEcriture.cha\n");

        return 2;
    }

    ecrireChaines(C, f2);
    fclose(f2);

    //Creation fichier SVG
    afficheChainesSVG(C, "affichageChainesSVG");

    //Calcul longueur totale
    double longueur = longueurTotale(C);
    printf("Longueur totale = %.2lf\n", longueur);

    //Comptage de points
    int nbPoints = comptePointsTotal(C);
    printf("Nombre de points au total: %d\n", nbPoints);

    /*Tests Question 6.2*/
    Chaines *Caleatoire = generationAleatoire(5, 5, 100, 100);
    FILE *f3 = fopen("testEcritureCAleatoire.cha", "w");
    if(f3==NULL){
        printf("Erreur ouverture fichier testEcritureCAleatoire.cha\n");
        return 2;
    }

    ecrireChaines(Caleatoire, f3);
    fclose(f3);

    afficheChainesSVG(Caleatoire, "affichageCAleatoireSVG");
    int nbPointsAl = comptePointsTotal(Caleatoire);
    printf("Nombre de points au total pour chaine aleatoire: %d\n", nbPointsAl);

    liberer_chaines(C);
    liberer_chaines(Caleatoire);

}