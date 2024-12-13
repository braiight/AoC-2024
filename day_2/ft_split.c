/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:35:38 by gumallet          #+#    #+#             */
/*   Updated: 2024/12/13 16:10:49 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	wc;
	int	flag;

	wc = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			flag = 0;
			wc++;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (wc);
}

static void	ft_free_all(char **tab_of_tab, int j)
{
	while (j >= 0)
	{
		free(tab_of_tab[j]);
		tab_of_tab[j] = NULL;
		j--;
	}
	free(tab_of_tab);
}

static char	**ft_strong(char **tab_of_tab, char const *s, char c, int i)
{
	int	j;
	int	size;

	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			size = 0;
			while (s[i] != c && s[i])
			{
				i++;
				size++;
			}
			tab_of_tab[j] = ft_substr(s, (i - size), size);
			if (!tab_of_tab[j])
				return (ft_free_all(tab_of_tab, j), (NULL));
			j++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	tab_of_tab[j] = (NULL);
	return (tab_of_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_of_tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab_of_tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab_of_tab)
		return (NULL);
	tab_of_tab = ft_strong(tab_of_tab, s, c, i);
	return (tab_of_tab);
}
