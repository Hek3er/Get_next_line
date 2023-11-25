/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:46:07 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/25 23:40:46 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		joined = ft_strdup(s2);
		return (joined);
	}
	i = 0;
	j = 0;
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (free(s1), NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

int	n_search(char *s)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
