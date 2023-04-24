#include"dictionnaire.h"
#include <iostream>
#include <fstream>
void dictionnaire(Dictionnaire& d) {
    std::ifstream file("ods4.txt", std::ios::ate); //ouverture à la fin du fichier
    if (!file) {
        std::cerr << "impossible d'ouvrir le fichier\n";
    }

    int sz = file.tellg(); //notre position (à la fin) == nombre d'octets du fichier

    char* data = new char[sz]; //1ere allocation mémoire
    //std::cout<<data;
    file.seekg(0, std::ios::beg); //retour au début du fichier
    file.read(data, sz); //écriture du contenu de tout le fichier dans le buffer
    file.close(); //optionnel
    //comptage du nombre de mots; on en profite pour remplacer les \n par des \0
    int compteurDeMots = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (data[i] == '\n')
        {
            data[i] = '\0';
            compteurDeMots++;
        }
    }
    d.capacite = compteurDeMots;
    d.tab = new char* [compteurDeMots]; //2e allocation
    int motsEnregistres = 0;
    for (int i = 0; i < sz; i++)
    {
        if (i == 0 || data[i - 1] == '\0')
        {
            d.tab[motsEnregistres] = data + i;
            motsEnregistres++;
        }
    }
}