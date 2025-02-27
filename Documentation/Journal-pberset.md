## Parsing the file

- Combien de lignes ? inconnu en avance.
- Parcourir le fichier ligne par ligne avance le fd et perdu une fois la fin atteinte.
- so_long -> taille connue par les inputs au lancement du programme
- miniRT -> seulement le fichier en args

- get next line et stocker la ligne en linked list ?
	- puis traiter élément par élément tranquillement ?

- get next line et split ?
	- Lire une fois la ligne et remplacer tous les isspace par ' ' (ascii 32)
	- ft_split(line, ' ') = la ligne découpée avec seulement les éléments intéressants
	- on la stocke dans une linked list et on lit la ligne suivante ?
	- On parcours la linked list pour savoir combien de malloc on fait pour les éléments de la scene
	-> a l'air bruteforce
	-> occupe beaucoup de mémoire

- get next line et compter les éléments de chaque type ligne par ligne
	- si pas d'identifier en première donnée de la ligne -> error
	- si un des 3 éléments obligatoires != 1 -> error
	- fini close (fd)
	- malloc les éléments pertinents dans la scene 
		- array pour les 3 objets, unique pour les 3 obligatoires
	- open(file)
	- get next line et assigner ligne par ligne aux éléments de la scene
	- Si à la fin d'une ligne il reste des éléments non lus ou il manque des variables non assignées -> error
	- fini close(fd)

