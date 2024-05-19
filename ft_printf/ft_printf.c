/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:00:59 by ychbily           #+#    #+#             */
/*   Updated: 2023/12/13 00:45:12 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_help(int i, int *count, const char *form)
{
	write(1, &form[i], 1);
	*count += 1;
}

static void	ft_printf_helper(va_list args, const char *form, int *count, int *i)
{
	if (form[*i] == 's' || form[*i] == 'c')
		*count += ft_str(args, form, *i);
	else if (form[*i] == 'p' || form[*i] == 'x' || form[*i] == 'X' )
		*count += ft_hexa(args, form, *i);
	else if (form[*i] == 'd' || form[*i] == 'i' || form[*i] == 'u')
		*count += ft_num(args, form, *i);
	else if (form[*i] == '%')
		*count += write(1, "%", 1);
	else if (form[*i] == '\0')
		return ;
	else
		*count += write(1, &form[*i], 1);
	(*i)++;
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (write(1, " ", 0) == -1)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, form);
	while (form[i] != '\0')
	{
		if (form[i] == '%')
		{
			i++;
			ft_printf_helper (args, form, &count, &i);
		}
		else if (form[i] != '%')
		{
			ft_help(i, &count, form);
			i++;
		}
	}
	return (va_end(args), count);
}
