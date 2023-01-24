/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:34:14 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/24 13:38:26 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

//count the substr len
static int	ft_len_substr(const char *str, char c, int pos)
{
	int	len;

	len = 0;
	while (str[pos] && str[pos] != c)
	{
		len++;
		pos++;
	}
	return (len);
}

//free in case of error
static void	ft_free_tab(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

//reactor heart of split
static int	ft_split_aux(char **tabstr, const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (j < ft_count(str, c))
		{
			tabstr[j] = malloc((ft_len_substr(str, c, i) + 1));
			if (!tabstr[j])
			{
				ft_free_tab(tabstr, j);
				return (0);
			}
			ft_strlcpy(tabstr[j], str + i, ft_len_substr(str, c, i) + 1);
			i += ft_len_substr(str, c, i);
			j++;
		}
	}
	tabstr[j] = NULL;
	return (1);
}

//main function
char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		nb_strs;

	if (!s)
		return (NULL);
	nb_strs = ft_count(s, c);
	tab = (char **)malloc((nb_strs + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (ft_split_aux(tab, s, c) == 0)
		return (NULL);
	return (tab);
}
