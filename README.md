# 42 Get Next Line

## Description

Get Next Line (GNL) est un projet de l'école 42 dont l'objectif est de créer une fonction capable de lire une ligne depuis un descripteur de fichier, quelle que soit sa taille. Ce projet permet de manipuler des buffers, des fichiers et de gérer les retours multiples à travers les lectures successives, tout en respectant les contraintes de la norme 42.

La fonction get_next_line vous aide à mieux comprendre la gestion de la mémoire dynamique et la lecture asynchrone de fichiers en C.
Fonctionnalités

  Lecture ligne par ligne d'un fichier ou d'une entrée standard.
  Gestion dynamique de buffers de taille variable.
  Manipulation de fichiers ouverts avec gestion des descripteurs multiples.

## Installation

1. Clonez le dépôt :

```bash

git clone https://github.com/Demiaeuw/42_gnl.git
```

2. Accédez au répertoire du projet :

```bash

cd 42_gnl
```

3. Compilez le projet avec make :

```bash

make
```

4. Utilisez la fonction get_next_line dans vos propres projets ou pour tester dans des fichiers sources.

## Utilisation
### Prototype

La fonction a le prototype suivant :

```c

int	get_next_line(int fd, char **line);
```
  fd : Le descripteur de fichier à partir duquel lire.
  line : Un pointeur vers une chaîne de caractères allouée, où la ligne lue sera stockée.

La fonction renvoie :

1 lorsqu'une ligne a été lue avec succès.

0 lorsque la fin du fichier a été atteinte.

-1 en cas d'erreur.

### Exemple d'utilisation

```c

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("fichier.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("Ligne lue : %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
```
Dans cet exemple, le programme lit le fichier fichier.txt ligne par ligne et affiche chaque ligne.

### Variables de compilation

Pour utiliser get_next_line dans votre projet, vous pouvez inclure les fichiers get_next_line.c et get_next_line_utils.c dans votre propre Makefile ou compilation. Voici un exemple de compilation manuelle :

```bash

gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl
```

## Dépendances

Aucune dépendance externe n'est requise. Le projet utilise uniquement les bibliothèques standard de C.
## Contributeurs

[Adrien Cabarbaye](https://github.com/Demiaeuw)

## Licence

Ce projet est sous la licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus d'informations.
