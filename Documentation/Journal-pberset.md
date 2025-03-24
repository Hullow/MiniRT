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

## Matrix transformation

### Translation

- t_point transform()
	- transform = translation(x, y, z) // t_matrix
	- inv = inverse(transform) // pour la fonction de translation inverse
	- t_point point(x, y, z) // origine de l'objet / du vecteur
	- return multiply_matrix(transform * tuple_to_matrix(point))
	- return multiply_matrix(inv * tuple_to_matrix(point))
- t_point translate()
	- La fonction translation n'affecte pas les vecteurs
		- elle affecte l'origine du vecteur (point) si c'est ce qu'on a passé
		- Elle n'affecte pas la direction, ni la longueur
			- multiply_matrix(transform, tuple_to_matrix(v)) = tuple_to_matrix(v)
		- Le vecteur a 0 en valeur w
			- la matrice 4x4 est donc annulée
- t_matrix translation
	- matrice identité
		- Dernière colonne contient [x, y, z, 1]

### Scaling

- t_point transform()
	- transform = scale(x, y, z) // t_matrix
	- soit inv = inverse(transform)
	- soit point
	- soit vector
		- return multiply_matrix(transform, tuple_to_matrix(point))
		- return multiply_matrix(transform, tuple_to_matrix(vector))
		- return multiply_matrix(inv, tuple_to_matrix(point))
		- return multiply_matrix(inv, tuple_to_matrix(vector))
- t_matrix scaling
	- Matrice identité
		- Diagonale contient [x, y, z, 1]
		- un scaling négatif est un mirroir

### Rotation

- t_point transform()
	- transform = rotation(x, y, z) // t_matrix
p.47

### Transform

- Il faut une fonction générale transform((t_matrix *)(*rot)(float), (t_matrix *)(*mov)(t_tuple *), (t_matrix *)(*shear)(float *))
	- à tester...

## Ray casting

- Create a struct ray
	- un ray est un point de départ et un vecteur de direction
- Calculer une distance
	- soit un ray
	- la fonction distance calcule la distance à partir d'un point de départ dans la direction du ray
	- distance(t_ray ray, float t)
	- multiplication d'un vecteur par un scalaire
	- retourne un point : le point à la distance t du point de départ du ray dans la direction du vecteur du ray
	- return ray.origin + ray.direction * t

### Sphere intersect

- Need of a sphere creation function
	- créer une sphère
		- coord, diameter, color
- Calcul des intersections
	- soient une sphère et un rayon
		- Cas 1
			- le Rayon pointe dans la direction du centre de la sphère
			- il existe deux et seulement deux points d'intersections entre la sphere et le rayon
				- L'un au plus proche de l'origine du rayon et à diameter/2 distance du centre de la sphère
				- L'autre au plus loin de l'origine du rayon et également à diameter/2 du centre de la sphère
			- Intersect(t_ray ray, t_sphere sphere)
				- count = 2
				- return t0 ; return t1 ?
				- return point 0; return point 1 ?
		- Cas 2
			- l'origine du rayon se situe à y + diameter/2 par rapport à l'origine de la sphère
			- le rayon est tangeant à la sphère
			- il existe un et un seul point d'intersection avec la sphère
			- Intersect(t_ray ray, t_sphere sphere)
				- count = 2 -> notre fonction de calcul retourne deux fois la même valeur
				- return i[0] = t0 ; return i[1] = t0 ?
				- return point 0; return point 0 ?
		- Cas 3
			- les paramètres du rayons sont tels qu'il n'existe aucun point de contact avec la sphère
			- Intersect(t_ray ray, t_sphere sphere)
				- count = 0
				- t ou point ne sont pas retournés
		- Edge case 1
			- L'origine du rayon se trouve à l'intérieur de la sphère
			- il existe deux et seulement deux points d'intersections entre la sphere et le rayon
				- L'un dans la direction du rayon
				- L'autre dans la direction inverse du rayon
			- Intersect(t_ray ray, t_sphere sphere)
				- count = 2
				- return i[0] = -t0 ; return i[1] = t1 ? 
					- t0 est une distance négative car inverse à la direction du rayon
				- return point 0; return point 1 ?
		- Edge case 2
			- La direction du rayon est opposé à la direction de la sphère
			- il existe deux et seulement deux points d'intersections entre la sphere et le rayon
				- les deux points dans la direction opposée du rayon
			- Intersect(t_ray ray, t_sphere sphere)
				- count = 2
				- return i[0] = -t0 ; return i[1] = -t1 ? 
					- t0 et t1 sont des distances négatives car inverse à la direction du rayon
					- t0 et t1 sont espacés de diameter
					- t0 est la distance entre l'origine du rayon et la surface de la sphère
				- return point 0; return point 1 ?
- Discriminant
	- Indique si le rayon a des intersections avec la sphère
		- Positif : au moins une intersection
		- Négatif : aucune intersection
	- soient une sphère et un rayon
		- sphere_to_ray = ray.origin - sphere.origin
		- a = dot_product(ray.direction, ray.direction)
		- b = 2 * dot_product(ray.direction, sphere_to_ray)
		- c = dot_product(sphere_to_ray, sphere_to_ray) - 1
		- discriminant = powf(b, 2) - 4 * a * c
		- if discriminant < 0
			return ()
- Après calcul du déterminant, retour sur la fonction intersect()
	- t0 = (-b - sqrt(discriminant)) / (2 * a)
	- t1 = (-b + sqrt(discriminant)) / (2 * a)
	- return (t0, t1)
- Itersect retourne donc deux scalaires float[2]
	- ils représentent les deux distances des intersections à partir du point de départ du rayon
	- si le déterminant est négatif, on ne retourne rien
		- pas d'intersection : oublions ce rayon
		- Je devrais utiliser errno pour distinguer 0 ou des valeurs négatives valides d'une absence d'intersection

### Multiple objects

- Il nous faut une structure t_intersect
	- void *object;
		- t_sphere, t_cylinder, t_plane
	- float[t0, t1]
	- Nous ferons un tableau de ces intersections pour connaître toutes les intersections de notre scène et les dessiner plus tard
	- Nous allons utiliser la fonction intersect pour cette struct

### The "hit"

- Un "hit" est une intersection visible depuis l'origine du rayon
	- N'est pas derrière l'origine du rayon
	- N'est pas caché derrière un autre hit
		- un hit est l'intersection avec la plus petite valeur positive pour t
- Nous gardons les autres valeurs t
	- sera utile pour les réflexion et les réfractions !

### Transformations

- Déplacer la sphère; déplacer le rayon
	- Quelle importance ?
	- La distance entre les deux a été modifiée
- Agrandir la sphère; réduire le rayon
	- La distance entre la sphère et le rayon est réduite
	- On redimensionne le rayon par l'inverse de la quantité d'agrandissement de la sphère
- Rotation d'un plan / cylindre; rotation du rayon autour de l'objet
- quelle que soit la transfrmation recherchée
	- Appliquer l'inverse de la transformation de l'objet sur le rayon à la place
	- une matrice de transformation est comme une co version des points entre le système global et le système local
		- World coordinates
		- Object coordinates
	- prendre un point en local et le multipiler avec une matrice le convertit en point du système global
	- multiplier ce point global par l'inverse de cette matrice le rapporte au système local
- Convertir un rayon du système global par l'inverse de l'opération recherchée sur l'objet
	- le rayon se trouve dans l'espace local de l'objet

### Sur le rayon

- soit un rayon
- soit une matrice de rotation
	- translation
		- transform(rayon, matrice)
			- origin  = point avec les nouvelles coordonnées
			- direction = vector avec les nouvelles données
	- scaling
		- transform(rayon, matrice)
			- origin  = point avec les nouvelles coordonnées
			- direction = vector avec les nouvelles données 
	- Ne surtout pas normaliser les valeurs
		- On veut savoir si on a inversé la direction du rayon, par exemple
	
### Sur les objets

- Soit un objet
	- sa transform = matrice identité
- soit une matrice translation
	- set_transform(objet, matrice)
	- objet.transform = nouvelle matrice
- soit le rayon qui intersect l'objet
	- set_transform(objet, transformation_function)
	- intersection(objet, rayon)
		- intersect = int // si 0, plus d'intersection, 2 si oui
		- t0 = float
		- t1 = float
