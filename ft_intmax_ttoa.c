/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:57:21 by hvillasa          #+#    #+#             */
/*   Updated: 2016/11/15 00:23:59 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdint.h>

static	intmax_t	get_len(intmax_t n)
{
	intmax_t		len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_intmax_ttoa(intmax_t n)
{
	size_t	len;
	char	*str;

	len = get_len(n);
	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

#include <stdio.h>
int main(void)
{


	intmax_t i = (signed char)128;
	char *s = ft_intmax_ttoa(i);
	printf("%s\n%ji\n", s, i);
	return (0);
}
