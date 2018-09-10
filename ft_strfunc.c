/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:58:06 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/03 21:22:18 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int dif;

	if ((s1 == NULL) && (s2 == NULL))
		return (0);
	else if ((s1 == NULL) && (s2 != NULL))
		return (-1);
	else if ((s1 != NULL) && (s2 == NULL))
		return (1);
	while (*s1 || *s2)
	{
		dif = (unsigned char)*s1++ - (unsigned char)*s2++;
		if (dif != 0)
			return (dif);
	}
	return (0);
}

size_t	ft_strlen(char *c)
{
	size_t res;

	res = 0;
	while (*c)
	{
		res++;
		c++;
	}
	return (res);
}
