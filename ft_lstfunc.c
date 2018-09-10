/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:14:29 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/03 20:40:06 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_key	*ft_lstnew(char *name, char *val)
{
	t_key *res;

	if (!(res = (t_key*)malloc(sizeof(t_key))))
		return (NULL);
	res->next = NULL;
	res->name = name;
	res->val = val;
	return (res);
}

char	*ft_lstsearch(t_key *root, char *skey)
{
	while (root != NULL)
	{
		if (ft_strcmp(root->name, skey) == 0)
			return (root->val);
		root = root->next;
	}
	return (NULL);
}

void	ft_lstadd(t_key **alst, t_key *new)
{
	if (alst != NULL)
	{
		if (new != NULL)
			new->next = *alst;
		*alst = new;
	}
}

void	ft_lstdel(t_key *alst)
{
	t_key *nxt;

	if (alst != NULL)
		while (alst)
		{
			nxt = (alst)->next;
			ft_memdel((void*)&(alst->name));
			ft_memdel((void*)&(alst->val));
			ft_memdel((void*)&alst);
			alst = nxt;
		}
}

void	ft_basedel(t_key **base, unsigned int bsize)
{
	if (base != NULL)
		while (bsize--)
		{
			if (base[bsize] != NULL)
				ft_lstdel(base[bsize]);
		}
	ft_memdel((void*)base);
}
