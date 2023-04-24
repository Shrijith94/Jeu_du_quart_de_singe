
#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#pragma warning(disable : 4996)
/*structure permettant de stocker tous les mots du dictionnaire dans un tableau dynamique*/
struct Dictionnaire {
    char** tab;// tableau dynamique
    unsigned int capacite = 0;// capacite du tableau
};
/**
 * @brief Construit un dictionnaire en lisant un fichier et en stockant chaque
    ligne dans un tableau de cha�nes de caract�res.
 * @param [in-out]d Un dictionnaire vide, qui sera rempli par la fonction.
 * @pre le fichier ods4.txt ne dois pas �tre vide
 */
void dictionnaire(Dictionnaire& d);
#endif //DICTIONNAIRE_H