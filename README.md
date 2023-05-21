# Présentation du projet
	Cette application permet à un ensemble d’au moins deux joueurs de disputer une partie de quart de singe.  
  L’application assurera le respect des règles du jeu dans sa totalité.  
  Des joueurs robots qui joueront automatiquement du mieux possible peuvent être ajoutés à la partie afin de pouvoir y jouer avec plus de joueurs.
Afin de lancer une partie, il faudra exécuter la commande “singe”, suivie de la nature et l’ordre de chaque joueur :  
‘H’ et ‘R’ signifiant respectivement humain et robot. Par exemple, la commande « singe HRHR » lancera une partie où 4 joueurs dont 2 robots s’affrontent ;  
le premier et troisième joueur seront des humains tandis que les autres seront des robots.
À chaque tour de la partie, les joueurs sont désignés suivant leur numéro d’ordre, ainsi que leur nature, suivi des lettres déjà annoncées (par exemple «1H (ABAC) > »).  
Le joueur courant pourra alors annoncer une lettre (non accentuées et en majuscule ou minuscule) pour compléter le mot,  
ou bien le caractère ‘ ?’ pour demander au joueur précédent à quel mot il pense, ou encore ‘ !’ pour abandonner la manche.
Si la lettre annoncée termine le mot, alors l’application préviendra les joueurs et donnera un quart de singe ayant perdu la manche.  
Si un joueur saisit le caractère ‘ ?’, le joueur précédent devra alors annoncer le mot complet auquel il pensait. Si le mot n’existe pas, ce joueur perd donc la manche,  
sinon, le joueur ayant demandé le mot la perd.
À chaque fin de manche, le score de chaque joueur est affiché de la manière suivante : «1H : 0,25 ; 2R : 0 ; 3H : 0,75 ; 4R : 0 ».  
Si aucun joueur n’a quatre quarts de singes, une nouvelle manche commence. Sinon, la partie se termine.
Ce document dispose d’un dictionnaire de 369085 mots. Seuls les mots de plus de 2 lettres comptent.
