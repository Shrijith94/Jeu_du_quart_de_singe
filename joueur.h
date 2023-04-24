/**
* @nom du fichier: jeu.h
* @auteur: SANTHAKUMAR Shrijith et Charles BOUVIER
* @brief: contient toutes les structures utiles au jeu
* @version: 1.0   06/01/2023
*/

#ifndef SINGE_JOUEUR_H
#define SINGE_JOUEUR_H
#pragma warning(disable : 4996)
#include"dictionnaire.h"
/*Structure permettant de définir des joueurs par le nom et nombre de quart de singe*/
struct Joueur
{
    float nbQSinge;// leur nombre de quart de singe
    char Nom;// le nom donc le genre du joueur si c'est un homme ou un robot

};
/*Structure permettant de stocker des joueurs dans un tableau*/
struct Conteneur
{
    unsigned int nb_joueurs;//la taille du conteneur défini par le nombre de jouer
    Joueur* tab;//le tableau contenant les joueurs 
};



#endif //SINGE_JOUEUR_H
