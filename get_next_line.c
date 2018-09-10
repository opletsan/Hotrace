/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:17:12 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/03 16:38:29 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_fd		*ft_fdinit(t_fd *fdb)
{
	t_fd	*tmp;

	if (fdb != NULL)
		return (fdb);
	if (!(tmp = (t_fd*)ft_memalloc(sizeof(t_fd))))
		return (NULL);
	tmp->start = 0;
	tmp->buflen = 0;
	tmp->isfull = 0;
	if (!(tmp->buf = (uint8_t*)ft_memalloc(sizeof(uint8_t) * (BUFF_SIZE + 1))))
		return (NULL);
	return (tmp);
}

static int		ft_makeres(char **res, size_t *reslen, t_fd *fd, uint8_t *isupd)
{
	long	addlen;

	if ((fd->isfull == 0) || (fd->buflen > 0 && fd->start == fd->buflen))
		return (1);
	if (fd->buflen <= 0)
		return (0);
	addlen = 0;
	while (((fd->start + addlen) < fd->buflen) &&
		(fd->buf[fd->start + addlen] != '\n'))
		addlen++;
	if (addlen > 0)
	{
		*res = ft_memrealloc(*res, *reslen, (addlen + 1));
		ft_memcpy((*res + *reslen), (fd->buf + fd->start), addlen);
	}
	fd->start += (fd->start + addlen < fd->buflen) ? addlen + 1 : addlen;
	*reslen += addlen;
	*isupd = 1;
	if ((fd->start == fd->buflen) && (fd->buf[fd->start - 1] != '\n'))
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*fdb = NULL;
	uint8_t			isupd;
	size_t			reslen;

	isupd = 0;
	reslen = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = (char*)ft_memalloc(1);
	if ((fdb = ft_fdinit(fdb)))
		while (ft_makeres(line, &reslen, fdb, &isupd))
		{
			fdb->start = 0;
			if ((fdb->buflen = read(fd, fdb->buf, BUFF_SIZE)) <= 0)
			{
				ft_memdel((void*)&(fdb->buf));
				return ((fdb->buflen < 0) ? -1 : isupd);
			}
			fdb->isfull = 1;
		}
	return (1);
}
