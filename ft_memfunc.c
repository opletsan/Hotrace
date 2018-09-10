/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:06:30 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/03 16:35:50 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_bzero(void *s, size_t n)
{
	uint8_t *res;

	if (s != NULL)
	{
		res = (uint8_t*)s;
		while (n--)
			*res++ = 0;
	}
}

void	*ft_memalloc(size_t size)
{
	uint8_t *res;

	if (size == 0)
		return (NULL);
	if (!(res = (uint8_t*)malloc(size)))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t *res;
	uint8_t *s;

	if ((dst == NULL) || (src == NULL))
		return (NULL);
	res = (uint8_t*)dst;
	s = (uint8_t*)src;
	while (n--)
		*res++ = *s++;
	return (dst);
}

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		if (*ap)
			free(*ap);
		*ap = NULL;
	}
}

void	*ft_memrealloc(void *src, size_t len, size_t extralen)
{
	void *res;

	if (len + extralen == 0)
		return (src);
	if (!(res = ft_memalloc(len + extralen)))
		return (NULL);
	if (src == NULL)
		return (res);
	res = ft_memcpy(res, src, len);
	ft_memdel(&src);
	return (res);
}
