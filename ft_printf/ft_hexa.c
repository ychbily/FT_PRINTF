/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:09:39 by ychbily           #+#    #+#             */
/*   Updated: 2023/12/13 20:38:21 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex(unsigned long long nbr)
{
	char	*hexa;
	int		count;

	count = 0;
	hexa = "0123456789abcdef";
	if (nbr != 0)
	{
		count += put_hex(nbr / 16);
		write(1, &hexa[nbr % 16], 1);
		count += 1;
	}
	return (count);
}

static int	put_hex_maj_min(unsigned long long nbr, const char *form, int i)
{
	char	*hexa1;
	char	*hexa2;
	int		count;

	count = 0;
	hexa1 = "0123456789ABCDEF";
	hexa2 = "0123456789abcdef";
	if (nbr != 0)
	{
		count += put_hex_maj_min(nbr / 16, form, i);
		if (form[i] == 'x')
		{
			write(1, &hexa2[nbr % 16], 1);
			count += 1;
		}
		if (form[i] == 'X')
		{
			write(1, &hexa1[nbr % 16], 1);
			count += 1;
		}
	}
	return (count);
}

static int	ft_hexa_helper(const char *form, va_list args,
	unsigned int ptr2, int i)
{
	int	count;

	count = 0;
	if (form[i] == 'x')
	{
		ptr2 = va_arg(args, unsigned int);
		if (ptr2 == 0)
		{
			write(1, "0", 1);
			return (count += 1);
		}
		count += put_hex_maj_min(ptr2, form, i);
	}
	else if (form[i] == 'X')
	{
		ptr2 = va_arg(args, unsigned int);
		if (ptr2 == 0)
		{
			write(1, "0", 1);
			return (count += 1);
		}
		count += put_hex_maj_min(ptr2, form, i);
	}
	return (count);
}

int	ft_hexa(va_list args, const char *form, int i)
{
	void			*ptr;
	unsigned int	ptr2;
	int				count;

	count = 0;
	ptr2 = 0;
	if (form[i] == 'p')
	{
		ptr = va_arg(args, void *);
		write(1, "0x", 2);
		if (ptr == NULL)
		{
			write(1, "0", 1);
			count += 1;
		}
		else
			count += put_hex((unsigned long long)ptr);
		return (count + 2);
	}
	else if (form[i] == 'x')
		count += ft_hexa_helper(form, args, ptr2, i);
	else if (form[i] == 'X')
		count += ft_hexa_helper(form, args, ptr2, i);
	return (count);
}
