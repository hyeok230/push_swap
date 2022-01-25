/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:16:28 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 17:32:47 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fail(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

int	ft_isdeli(char c, char deli)
{
	if (c == deli || c == '\0')
		return (1);
	return (0);
}

int	ft_count(char *s, char c)
{
	int		count;
	char	*next;
	char	*previous;

	count = 0;
	next = s;
	previous = s;
	while (1)
	{
		if (!ft_isdeli(s[0], c) && ft_isdeli(s[1], c))
		{
			count++;
			next = &s[1];
			previous = &s[1];
		}
		if (ft_isdeli(*s, c))
			next = s;
		if (next - previous > 1)
			count++;
		if (*s == '\0')
			break ;
		previous = next;
		s++;
	}
	return (count);
}

char	*ft_cpy(char *s, char c, int *offset)
{
	char	*ret;
	char	*start;
	int		len;

	len = 0;
	while (ft_isdeli(s[*offset], c) && s[*offset])
		*offset += 1;
	if (!(ft_isdeli(s[*offset], c)) && s[*offset])
		start = &s[*offset];
	while (!(ft_isdeli(s[*offset], c)) && s[*offset])
	{
		*offset += 1;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	return (ft_cpy2(len, ret, start));
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		offset;
	char	**ret;

	if (!s)
		return (NULL);
	count = ft_count((char *)s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	offset = 0;
	while (count--)
	{
		ret[i] = ft_cpy((char *)s, c, &offset);
		if (ret[i] == NULL)
		{
			ft_fail(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
