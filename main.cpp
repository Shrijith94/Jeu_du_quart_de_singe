/*
* @nom du fichier: main.cpp
* @auteur: SANTHAKUMAR Shrijith et Charles BOUVIER
* @brief: le main permet d'éxécuter toutes les fonction pour le jeu du quart de singe
* @version: 1.0   06/01/2023
*/



#include <iostream>
#include <string.h>
using namespace std;
#include <iostream>
#include "jeu.h"

int main(int argv, char* argc[])
{
    srand(time(NULL));
    Conteneur total;
    jeu(total,argc[1]);
    
    return 0;
}

