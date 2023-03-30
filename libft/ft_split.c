/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:50:04 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/23 12:11:00 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			compt++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		else
			i++;
	}
	return (compt);
}

static void	ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static char	*ft_split3(char const *s, char c)
{
	while ((*s != c) == 1 && *s)
		s++;
	return ((char *) s);
}

static int	ft_split2(char const *s, char c, int i, char **tab)
{
	char	*memory;
	int		j;

	while (*s)
	{
		if ((*s != c) == 1)
		{
			memory = (char *) s;
			s = ft_split3(s, c);
			tab[i] = malloc(((s - memory) + 1) * sizeof(char ));
			if (tab[i] == NULL)
			{
				ft_free(tab, i);
				return (0);
			}
			j = -1;
			memory--;
			while (j++, ++memory < s)
				tab[i][j] = *memory;
			tab[i++][j] = '\0';
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	tab = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = ft_split2(s, c, i, tab);
	tab[i] = NULL;
	return (tab);
}
