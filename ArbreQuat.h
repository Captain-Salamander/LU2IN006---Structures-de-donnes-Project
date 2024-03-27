/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#ifndef __ARBRE_QUAT_H__
#define __ARBRE_QUAT_H__

#include"Hachage.h"

/* Arbre quaternaire contenant les noeuds du reseau */
typedef struct arbreQuat{
    double xc, yc;          /* Coordonnees du centre de la cellule */	
    double coteX;           /* Longueur de la cellule */
    double coteY;           /* Hauteur de la cellule */
    Noeud* noeud;           /* Pointeur vers le noeud du reseau */
    struct arbreQuat *so;   /* Sous-arbre sud-ouest, pour x < xc et y < yc */
    struct arbreQuat *se;   /* Sous-arbre sud-est, pour x >= xc et y < yc */
    struct arbreQuat *no;   /* Sous-arbre nord-ouest, pour x < xc et y >= yc */
    struct arbreQuat *ne;   /* Sous-arbre nord-est, pour x >= xc et y >= yc */
} ArbreQuat;

//Question 5.1
void chaineCoordMinMax(Chaines* C, double* xmin, double* ymin, double* xmax, double* ymax);

//Question 5.2
ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY);
void liberer_ArbreQuat(ArbreQuat *a);

//Question 5.3
ArbreQuat** direction(double x, double y, ArbreQuat *a);
void insererNoeudArbre(Noeud* n, ArbreQuat** a, ArbreQuat* parent);

//Question 5.4
Noeud* insererNoeudReseau(double x, double y, Reseau* R);
Noeud* rechercheCreeNoeudArbre(Reseau* R, ArbreQuat** a, ArbreQuat* parent, double x, double y);

//Question 5.5
Reseau* reconstitueReseauArbre(Chaines* C);

#endif
