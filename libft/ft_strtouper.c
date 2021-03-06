
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:37:50 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:24:33 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char		*ft_strtouper(char *toup)
{
	int		i;

	i = 0;
	while (*toup)
	{
		if (*toup >= 'a' && *toup <= 'z')
			*toup = ft_toupper(*toup);
		toup++;
		i++;
	}
	return (toup - i);
}
