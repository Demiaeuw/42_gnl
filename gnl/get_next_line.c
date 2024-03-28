/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:06:55 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/27 18:44:39 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = gnl_ad_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = gnl_line(stash);
	stash = gnl_clean_static(stash);
	return (line);
}

//lire et ajoute a la variable static en fonction de BUFFER_SIZE
char	*gnl_ad_to_stash(int fd, char *stash)
{
	char	*s;
	int		readed;

	readed = 1;
	s = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (readed != 0)
	{
		readed = read(fd, s, BUFFER_SIZE);
		if (readed == -1)
		{
			free(s);
			return (NULL);
		}
		s[readed] = 0;
		stash = gnl_strjoin(stash, s);
		if (gnl_strchr(s, '\n'))
			break ;
	}
	free(s);
	return (stash);
}

//appel de la fonction qui lit et save de 0 a '\n'  dans une variable stash
char	*gnl_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = gnl_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

//fonction qui clean la static et garde de '\n' a la fin 
char	*gnl_clean_static(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = gnl_calloc((gnl_strlen(stash) - i + 1), sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	free(stash);
	return (new_stash);
}
