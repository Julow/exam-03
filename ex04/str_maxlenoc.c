/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 10:24:46 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 10:47:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct	s_sub
{
	char			*str;
	int				len;
}				t_sub;

#define SUB(s,l)	(t_sub){s, l}

static int		ft_strstr(const t_sub *sub, const char *s2)
{
	int				i;

	while (*s2 != '\0')
	{
		i = 0;
		while (sub->str[i] == s2[i] && i < sub->len)
			i++;
		if (i == sub->len)
			return (1);
		s2++;
	}
	return (0);
}

static int		ft_strstrs(const t_sub *sub, char **strs)
{
	while (*strs != NULL)
	{
		if (!ft_strstr(sub, *strs))
			return (0);
		strs++;
	}
	return (1);
}

static t_sub	str_maxlenoc(char **strs)
{
	t_sub			max;
	t_sub			sub;

	sub = SUB(strs[0], 0);
	max = sub;
	while (sub.str[0] != '\0')
	{
		while (ft_strstrs(&sub, strs))
		{
			if (sub.len > max.len)
				max = sub;
			sub.len++;
		}
		sub.len = 0;
		sub.str++;
	}
	return (max);
}

int				main(int argc, char **argv)
{
	t_sub			sub;

	if (argc > 2)
	{
		sub = str_maxlenoc(argv + 1);
		write(1, sub.str, sub.len);
	}
	write(1, "\n", 1);
	return (0);
}
