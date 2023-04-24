/**
* @nom du fichier: jeu.h
* @auteur: SANTHAKUMAR Shrijith et Charles BOUVIER
* @brief: contient toutes les fonctions du jeu.cpp qui sera utilis� dans le main
* @version: 1.0   06/01/2023
*/

#ifndef SINGE_JEU_H
#define SINGE_JEU_H
#pragma warning(disable : 4996)
#include "joueur.h"

/**
 * @brief Initialise un conteneur de joueurs en cr�ant un tableau de joueurs
	et en initialisant chaque joueur avec un nom et leur nombre de quart de singe � 0.
 * @param[in-out]: total Le conteneur � initialiser.
 * @param[in]: taille La taille du tableau de joueurs � cr�er.
 * @param[in]: argc Un tableau de noms de joueurs.
 */
void Initialiser(Conteneur& total, int taille, const char* argc);

/**
 * @brief V�rifie si un mot appartient � un dictionnaire.
 * @param[in]: d Le dictionnaire � utiliser.
 * @param[in]: mot Le mot � v�rifier.
 * @return true si le mot appartient au dictionnaire, false sinon.
 */
bool verifier_mot(const Dictionnaire& d, const char* mot);
/**
 * @brief Convertit tous les caract�res d'une cha�ne de caract�res en majuscule.
 * @param[in-out] argc La cha�ne de caract�res � convertir.
 * @param[in] taille La taille de la cha�ne de caract�res.
 */
void convertir(char* argc, unsigned int taille);
/**
 * @brief V�rifie si une cha�ne de caract�res ne contient que des 'H' et des 'R'.
 * @param[in] argc La cha�ne de caract�res � analyser.
 * @param[in] taille La taille de la cha�ne de caract�res.
 * @return 0 si la cha�ne ne contient que des 'H' et des 'R', 1 sinon.
 */
int analyser(const char* argc, unsigned int taille);
/**
 * @brief Fait jouer le robot en utilisant un dictionnaire de mots et il doit
	faire en sorte de chosir une lettre qui lui soit favorable
 * @param[in] d Le dictionnaire � utiliser.
 * @param[in] mot Le mot en cours de construction.
 * @param[in] mot_robot Un mot trouv� par le joueur virtuel.
 * @param[in] c Le conteneur de joueurs.
 * @param[in] nb_tour Le num�ro de tour actuel.
 * @return La lettre choisie par le joueur virtuel pour compl�ter le mot sans le faire perdre
	sinon ? si le mot n'esixte pas ou si il n'a aucune possibilit�.
 */
char bot(const Dictionnaire& d, char* mot, char* mot_robot, const Conteneur& c, int nb_tour);
/**
 * @brief Affiche le score de chaque joueur contenu dans un conteneur.
 * @param[in] c Le conteneur de joueurs � afficher.
 */
void affichage_score(const Conteneur& c);
/**
 * @brief Affiche un message d'abandon de manche et de prise d'un quart de singe pour un joueur donn�.
 * @param[in] c Le conteneur de joueurs.
 * @param[in] indice L'indice du joueur dans le conteneur.
 */
void exclamation(const Conteneur& c,const  int indice);
/**
 * @brief Demande au joueur pr�c�dent de saisir un mot et le convertit en majuscule.
 * @param[in] mot Le mot � saisir.
 * @param[in] c Le conteneur de joueurs.
 * @param[in] indice_precedent L'indice du joueur pr�c�dent.
 */
void interrogation(char* mot, const Conteneur& c, unsigned int indice_precedent);

/**
 * @brief Impl�mente le jeu du quart de singe en g�rant 
	les diff�rents tours et la gestion des �v�nements
	(donc si il pose des questions ou si le mots s'est form� et si le joueur abandonne).
 * @param c[in] Le conteneur de joueurs.
 * @param argc[in] Le tableau de noms des joueurs.
 */
void jeu(Conteneur& c,char *argc);

#endif //SINGE_JEU_H
