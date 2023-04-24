/*
* @nom du fichier: jeu.cpp
* @auteur: SANTHAKUMAR Shrijith et Charles BOUVIER
* @brief: toutes les fonctions utile pour jouer au quart de singe 
* @version: 1.0   06/01/2023
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "jeu.h"
#include <cassert>



using namespace std;
bool verifier_mot( const Dictionnaire &d, const char *mot) {
    int debut, mil, fin;
    debut = 0;
    fin = d.capacite;
    while (debut <= fin) {
        mil = (debut + fin) / 2;
        if (strcmp(d.tab[mil], mot) == 0 && strlen(mot) > 2) {
            return true;
        } else if (strcmp(d.tab[mil], mot) < 0 && strlen(mot)>2) {
            debut = mil + 1;
        } else {
            fin = mil - 1;
        }
    }
    return false;
}
void Initialiser(Conteneur &total, int taille, const char *argc) {
    total.tab = new Joueur[taille];
    total.nb_joueurs = 0;
    for (int i = 0; i < taille; i++) {
        total.tab[i].nbQSinge = 0.f;
        total.tab[i].Nom = argc[i];
        total.nb_joueurs += 1;
    }
}
void convertir(char *argc, unsigned int taille) {
    for (int i = 0; i < taille; ++i) {
        argc[i] = toupper(argc[i]);
    }
}
int analyser(const char *argc, unsigned int taille) {
    for (int i = 0; i < taille; ++i) {
        if (argc[i] != 'H' && argc[i] != 'R') {
            return 1;
        }
    }
    return 0;
}
char bot( const Dictionnaire& d,  char *mot,char* mot_robot, const Conteneur& c,int nb_tour) {
    int debut, mil, fin;
    char lettre_choisi;
    debut = 0;
    fin = d.capacite;
    char mot_existe[26];
    if (nb_tour==0) {
        lettre_choisi=(rand() % 26) + 65;
        assert(lettre_choisi >= 65 && lettre_choisi <= 90);
        return lettre_choisi;

        
    }
    while (debut <= fin) {
        mil = (debut + fin) / 2;
        if (strncmp(d.tab[mil], mot, strlen(mot)) == 0 ) {
            strcpy(mot_robot, d.tab[mil]);
            strcpy(mot_existe, mot);
            mot_existe[strlen(mot)]=mot_robot[strlen(mot)];
            while (strncmp(mot_robot,mot, strlen(mot))==0 && mil<d.capacite){
                if((strlen(mot_robot)- strlen(mot)+1)%c.nb_joueurs!=0){
                    strcpy(mot_robot, d.tab[mil]);
                    strcpy(mot_existe, mot);
                    mot_existe[strlen(mot)] = mot_robot[strlen(mot)];
                    mot_existe[strlen(mot)+1] = '\0';
                    if(!verifier_mot(d,mot_existe)){
                        strcpy(mot_robot,d.tab[mil]);
                        lettre_choisi=mot_robot[strlen(mot)];
                        return lettre_choisi;
                    }
                }
                strcpy(mot_robot,d.tab[mil+1]);
                mil+=1;
            }
            
            strcpy(mot_robot,d.tab[mil-1]);
            strcpy(mot_existe, mot);
            lettre_choisi=mot_robot[strlen(mot)];
            mot_existe[strlen(mot)] = lettre_choisi;
            mot_existe[strlen(mot) + 1] = '\0';
            if (verifier_mot(d, mot_existe)) {
                return '?';
            }
            else {
                return lettre_choisi;
            }
            
        }
        else if (strncmp(d.tab[mil], mot, strlen(mot)) < 0) {
            debut = mil + 1;
        }
        else{
            fin = mil - 1;
        }
    }
    return '?';

}
void affichage_score(const Conteneur &c) {
    for (int i = 0; i < c.nb_joueurs; ++i) {
        if (i == c.nb_joueurs - 1) {
            cout << i + 1 << c.tab[i].Nom << " " << ":" << " " << c.tab[i].nbQSinge << " ";
        } else {
            cout << i + 1 << c.tab[i].Nom << " " << ":" << " " << c.tab[i].nbQSinge << ";" << " ";
        }
    }
    cout << endl;
}

void exclamation( const Conteneur &c,const int indice) {
    cout << "le joueur" << " " << indice + 1 << c.tab[indice].Nom << " "
         << "abandonne la manche et prend un quart de singe" << endl;
}

void interrogation(char *mot, const Conteneur &c, unsigned int indice_precedent) {
    cout << indice_precedent + 1 << c.tab[indice_precedent].Nom << "," << " " << "saisir le mot" << " " << ">" << " ";
    convertir(mot, strlen(mot));
    cin >> mot;
}

void jeu(Conteneur &c, char *argc) {
    Dictionnaire d;
    dictionnaire(d);
    unsigned int i = 0;
    unsigned int i_mot = 0;
    unsigned int i_premier = 0;
    char entree;
    char entree_precedent;
    unsigned int nb_tour=0;
    const int MAX = 26;
    char mot_saisir[MAX]="";
    int nb_lettre = 0;
    int taille = 26;
    
    convertir(argc, strlen(argc));
    assert(analyser(argc, strlen(argc)) == 0);  
    if (analyser(argc, strlen(argc)) == 1) {
        cerr << "erreur sur les noms des joueurs" << endl;
        exit(1);//permet de quitter le programme
    }
    char* mot;
    mot = new char[MAX];
    for (int i = 0; i < MAX; i++)
    {
        mot[i] = NULL;
    }
    Initialiser(c, strlen(argc), argc);
    assert(c.nb_joueurs > 1);
    unsigned int i_precedent = strlen(argc)-1;
    while (c.tab[i].nbQSinge != 1) {
        if(c.tab[i].Nom=='H'){
            std::cout << i + 1 << c.tab[i].Nom << ", (" << mot << ")" << " > ";
            cin >> entree;
            entree = toupper(entree);
            cin.ignore(INT_MAX,'\n');
        }
        else{
            entree=bot(d,mot,mot_saisir,c,nb_tour);
            cout << i + 1 << c.tab[i].Nom << ", (" << mot << ")" << " > "<<entree<<endl;
        }
        nb_tour+=1;
        if (entree == '?') {
            if(c.tab[i_precedent].Nom=='H'){
                interrogation(mot_saisir, c, i_precedent);
                convertir(mot_saisir, strlen(mot_saisir));
            }
            else{
                cout << i_precedent + 1 << c.tab[i_precedent].Nom << "," << " " << "saisir le mot" << " " << ">" << " "<<mot_saisir<<endl;
            }
            if (strncmp(mot_saisir, mot, strlen(mot)) != 0) {
                cout << "le mot" << " " << mot_saisir << " "
                     << "ne commence pas par les lettres attendues," << " " << "le joueur " << i_precedent + 1
                     << c.tab[i_precedent].Nom << " " << "prend un quart de singe" << endl;
                c.tab[i_precedent].nbQSinge += 0.25;
                affichage_score(c);
                i_mot = 0;
                mot[i_mot] = '\0';
                i = i_precedent-1;
                i_premier = i;
                nb_tour=0;
            } else {
                if (strlen(mot_saisir) <= 2 || !verifier_mot(d, mot_saisir) ) {
                    cout << "le mot" << " " << mot_saisir << " " << "n\'existe pas," << " " << i_precedent + 1
                         << c.tab[i_precedent].Nom << " " << "prend un quart de singe" << endl;
                    c.tab[i_precedent].nbQSinge += 0.25;
                    affichage_score(c);
                    i_mot = 0;
                    mot[i_mot] = '\0';
                    i = i_precedent-1;
                    i_premier = i;
                    nb_tour=0;
                } else {
                    cout << "le mot" << " " << mot_saisir << " " << "existe," << " " << "le joueur " << i + 1
                         << c.tab[i].Nom << " "
                         << "prend un quart de singe" << endl;
                    c.tab[i].nbQSinge += 0.25;
                    affichage_score(c);
                    i_mot = 0;
                    mot[i_mot] = '\0';
                    i = i_precedent;
                    i_premier = i;
                    nb_tour=0;
                }
            }
         

        } else if (entree == '!') {
            exclamation(c, i);
            c.tab[i].nbQSinge += 0.25;
            affichage_score(c);
            i=i-1;
            i_mot = 0;
            mot[i_mot] = '\0';
            nb_tour=0;
        }
        if(entree!='!' && entree!='?'){
            
            mot[i_mot] = entree;
            mot[i_mot + 1] = '\0';
            i_mot = i_mot + 1;
            nb_lettre += 1;
        }
        if (verifier_mot(d, mot)&& strlen(mot)>2){
                cout << "le mot" << " " << mot << " " << "existe," << " " << "le joueur " << i + 1 << c.tab[i].Nom
                     << " " << "prend un quart de singe" << endl;
                c.tab[i].nbQSinge += 0.25;
                affichage_score(c);
                i_mot = 0;
                mot[i_mot] = '\0';
                i = i - 1;
                i_premier = i;
                nb_tour=0;
        }
        i_precedent = i;
        i+=1;


        if (i >= c.nb_joueurs) {
            i = 0;
        }
        if (i_mot >= taille ) {
            int NewTaille = i_mot * 2;
            char* newTab = new char[NewTaille];
            for (int i = 0; i < i_mot; i++)
            {
                newTab[i] = mot[i];
            }

            taille = NewTaille;
            mot = newTab;
            for (int i = i_mot; i < taille; i++)
            {
                mot[i] = NULL;
            }
        }
        
    }
    bool verifier_nbQuartDeSinge = false;
    for (int j = 0; j < c.nb_joueurs; j++)
    {
        if (c.tab[j].nbQSinge == 1) {
            verifier_nbQuartDeSinge = true;
        }
    }
    assert(verifier_nbQuartDeSinge);
    cout << "La partie est finie";
    delete[]mot;
    delete[] *d.tab;
    delete[]c.tab;
}



