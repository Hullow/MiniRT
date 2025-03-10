# Chain of thought P-BOT-E
## Parsing the file

- Combien de lignes ? inconnu en avance.
- Parcourir le fichier ligne par ligne avance le fd et perdu une fois la fin atteinte.
- so_long -> taille connue par les inputs au lancement du programme
- miniRT -> seulement le fichier en args

- get next line et compter les éléments de chaque type ligne par ligne
	- si pas d'identifier en première donnée de la ligne -> error
	- si un des 3 éléments obligatoires != 1 -> error
	- fini close (fd)
	- malloc les éléments pertinents dans la scene 
		- array pour les 3 objets, unique pour les 3 obligatoires
	- open(file)
	- get next line et split
		- Lire une fois la ligne et remplacer tous les isspace par ' ' (ascii 32)
		- ft_split(line, ' ') = la ligne découpée avec seulement les éléments intéressants
	- Si à la fin d'une ligne il reste des éléments non lus ou il manque des variables non assignées -> error
	- fini close(fd)

## Assignation

- Détecter l'id
- assigner les valeurs selon l'objet détecté
	- multivalues = split par ','
	- colors = float (!!! normalement int ]0;255[ -> float ]0.000xxx;255.000xxx[ -> float ]0.000xxx;1.000xxx[)
		- Perte de précision et risques de valeurs glichées ? à surveiller
- Valeurs non valides
	- atof ne permet pas de savoir si la veleur retournée est valide ou non
		- investiguer strtof -> errno
			- ERANGE: Used for out-of-range errors.
				- <math.h>: isinf()
			- EINVAL: Used for invalid arguments.
	- contrôle d'erreur long et fastidieux en fin de processus
		- loop sur le split de valeurs et convertir à la volée
		- passage en argument pour les fonctions d'assignation
	- usage de `errno` generalisable -> fine tuning plus tard

## Colors

- Opérations
	- Additionner deux couleurs
	- Soustraire deux couleurs
	- Multiplier une couleur par un scalaire
	- Multiplier une couleur par une autre couleur
	- Dans l'étape de calcul, pas besoin de clamp les valeurs à 0 et 1
- Post processing
	- tone mapping
		- Linear scaling : diviser toutes les valeurs par la plus haute, pour tout normaliser proportionnellement -> perte de détails et précision -> cheum
		- Reinhard Tone Mapping -> échelle logarithmique -> la plus commune en JV
			- `Ld​ = L / (1 + L)​` where L is the luminance of the pixel
		- Exposure and Gamma Correction -> simulation d'exposition de caméra réelle -> la plus belle sans tuer le CPU dans notre cas spécifique
			- Formula: `Ld = 1 − exp⁡(−L * exposure)`, followed by `Ld' = Ld'^(1/y)​`
		- Filmic Tone Mapping -> va tuer notre CPU
