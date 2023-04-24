/**
* @nom du fichier: jeu.h
* @auteur: SANTHAKUMAR Shrijith et Charles BOUVIER
* @brief: contient toutes les fonctions du jeu.cpp qui sera utilisé dans le main
* @version: 1.0   06/01/2023
*/

#ifndef SINGE_JEU_H
#define SINGE_JEU_H
#pragma warning(disable : 4996)
#include "joueur.h"

/**
 * @brief Initialise un conteneur de joueurs en créant un tableau de joueurs
	et en initialisant chaque joueur avec un nom et leur nombre de quart de singe à 0.
 * @param[in-out]: total Le conteneur à initialiser.
 * @param[in]: taille La taille du tableau de joueurs à créer.
 * @param[in]: argc Un tableau de noms de joueurs.
 */
void Initialiser(Conteneur& total, int taille, const char* argc);

/**
 * @brief Vérifie si un mot appartient à un dictionnaire.
 * @param[in]: d Le dictionnaire à utiliser.
 * @param[in]: mot Le mot à vérifier.
 * @return true si le mot appartient au dictionnaire, false sinon.
 */
bool verifier_mot(const Dictionnaire& d, const char* mot);
/**
 * @brief Convertit tous les caractères d'une chaîne de caractères en majuscule.
 * @param[in-out] argc La chaîne de caractères à convertir.
 * @param[in] taille La taille de la chaîne de caractères.
 */
void convertir(char* argc, unsigned int taille);
/**
 * @brief Vérifie si une chaîne de caractères ne contient que des 'H' et des 'R'.
 * @param[in] argc La chaîne de caractères à analyser.
 * @param[in] taille La taille de la chaîne de caractères.
 * @return 0 si la chaîne ne contient que des 'H' et des 'R', 1 sinon.
 */
int analyser(const char* argc, unsigned int taille);
/**
 * @brief Fait jouer le robot en utilisant un dictionnaire de mots et il doit
	faire en sorte de chosir une lettre qui lui soit favorable
 * @param[in] d Le dictionnaire à utiliser.
 * @param[in] mot Le mot en cours de construction.
 * @param[in] mot_robot Un mot trouvé par le joueur virtuel.
 * @param[in] c Le conteneur de joueurs.
 * @param[in] nb_tour Le numéro de tour actuel.
 * @return La lettre choisie par le joueur virtuel pour compléter le mot sans le faire perdre
	sinon ? si le mot n'esixte pas ou si il n'a aucune possibilité.
 */
char bot(const Dictionnaire& d, char* mot, char* mot_robot, const Conteneur& c, int nb_tour);
/**
 * @brief Affiche le score de chaque joueur contenu dans un conteneur.
 * @param[in] c Le conteneur de joueurs à afficher.
 */
void affichage_score(const Conteneur& c);
/**
 * @brief Affiche un message d'abandon de manche et de prise d'un quart de singe pour un joueur donné.
 * @param[in] c Le conteneur de joueurs.
 * @param[in] indice L'indice du joueur dans le conteneur.
 */
void exclamation(const Conteneur& c,const  int indice);
/**
 * @brief Demande au joueur précédent de saisir un mot et le convertit en majuscule.
 * @param[in] mot Le mot à saisir.
 * @param[in] c Le conteneur de joueurs.
 * @param[in] indice_precedent L'indice du joueur précédent.
 */
void interrogation(char* mot, const Conteneur& c, unsigned int indice_precedent);

/**
 * @brief Implémente le jeu du quart de singe en gérant 
	les différents tours et la gestion des événements
	(donc si il pose des questions ou si le mots s'est formé et si le joueur abandonne).
 * @param c[in] Le conteneur de joueurs.
 * @param argc[in] Le tableau de noms des joueurs.
 */
void jeu(Conteneur& c,char *argc);

#endif //SINGE_JEU_H
