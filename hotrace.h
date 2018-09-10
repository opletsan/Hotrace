/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:52:29 by akokoshk          #+#    #+#             */
/*   Updated: 2017/12/03 22:35:41 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFF_SIZE 2048
# define BASE_STEP 2000000

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fd
{
	long	buflen;
	long	start;
	uint8_t	isfull;
	uint8_t	*buf;
}				t_fd;

typedef struct	s_key
{
	char			*name;
	char			*val;
	struct s_key	*next;
}				t_key;

void			*ft_memalloc(size_t size);
void			*ft_memrealloc(void *src, size_t len, size_t extralen);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				get_next_line(const int fd, char **line);
int				ft_strcmp(const char *s1, const char *s2);
t_key			*ft_lstnew(char *name, char *val);
char			*ft_lstsearch(t_key *root, char *skey);
void			ft_lstadd(t_key **alst, t_key *new);
void			ft_basedel(t_key **base, unsigned int bsize);
size_t			ft_strlen(char *c);

#endif
