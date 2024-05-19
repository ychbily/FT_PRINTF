/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:10:47 by ychbily           #+#    #+#             */
/*   Updated: 2023/12/13 20:41:58 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	handle_str(char *str)
{
	if (str != NULL)
		return (ft_putstr(str));
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

static int	handle_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(va_list args, const char *form, int i)
{
	int		count;

	count = 0;
	if (form[i] == 's')
		count += handle_str(va_arg(args, char *));
	else if (form[i] == 'c')
		count += handle_char(va_arg(args, int));
	return (count);
}
