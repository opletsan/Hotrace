/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:34:49 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/03 22:23:36 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static unsigned int	ft_strhash(char *str)
{
	unsigned int	res;

	res = 0;
	if (ft_strlen(str) > 20)
		while (*str)
		{
			res += (unsigned int)*str + ((res << 6) + res) + (res << 16) - res;
			str++;
		}
	else
		while (*str)
		{
			res += (unsigned int)*str;
			str++;
		}
	return ((res > 40000000) ? (res >> 8) : res);
}

static t_key		**ft_readbase(unsigned int *bsize)
{
	t_key			**base;
	char			*key;
	char			*val;
	unsigned int	hash;

	base = NULL;
	while (get_next_line(0, &key) > 0)
	{
		if (key == NULL || key[0] == 0 || get_next_line(0, &val) <= 0)
			break ;
		hash = ft_strhash(key);
		while (hash >= *bsize)
		{
			base = ft_memrealloc(base, (sizeof(t_key*) * *bsize),
				(sizeof(t_key*) * (BASE_STEP + 1)));
			*bsize += BASE_STEP;
		}
		ft_lstadd(&(base[hash]), ft_lstnew(key, val));
		if (val[0] == 0)
			break ;
	}
	return (base);
}

static char			*ft_findkey(t_key **base, unsigned int bsize, char *skey)
{
	unsigned int	hash;

	hash = ft_strhash(skey);
	if (hash < bsize)
		return (ft_lstsearch(base[hash], skey));
	return (NULL);
}

int					main(void)
{
	char			*skey;
	char			*res;
	t_key			**base;
	unsigned int	bsize;

	if ((base = ft_readbase(&bsize)))
		while (get_next_line(0, &skey) > 0)
		{
			if (skey[0] == 0)
				break ;
			res = ft_findkey(base, bsize, skey);
			if (res != NULL && res[0] != 0)
			{
				write(1, res, ft_strlen(res));
				write(1, "\n", 1);
			}
			else
			{
				write(1, skey, ft_strlen(skey));
				write(1, " Not found.\n", 12);
			}
			ft_memdel((void*)&skey);
		}
	ft_basedel(base, bsize);
	return (0);
}
