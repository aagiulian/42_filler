/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:18:12 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/30 21:20:12 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, unsigned int n)
{
	char			*s_n;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_strndup(s2, n));
	i = 0;
	j = 0;
	s_n = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s_n == NULL)
		return (NULL);
	while (*s1)
		s_n[i++] = *s1++;
	while (*s2 && j < n)
	{
		s_n[i++] = *s2++;
		j++;
	}
	free((char*)s1);
	s_n[i] = '\0';
	return (s_n);
}
