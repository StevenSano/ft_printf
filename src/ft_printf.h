/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 01:06:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/12 02:05:45 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include "../libft/libft.h"
# include <stdarg.h>


#define F '%'
#define BUFPF 1024

int		ft_printf(const char *format, ...);

/*
** flags c s i 
*/
void	flag_c(va_list args, int *fin_size);
void	flag_s(va_list args, int *fin_size);
void	flag_i(va_list args, int *fin_size);

#endif
