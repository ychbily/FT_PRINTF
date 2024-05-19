/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:13:47 by ychbily           #+#    #+#             */
/*   Updated: 2023/12/02 19:05:45 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num(va_list args, const char *form, int i)
{
	int				count;
	int				nbr;

	count = 0;
	if (form[i] == 'd' || form[i] == 'i')
	{
		nbr = va_arg(args, int);
		count += ft_putnbr_fd(nbr, 1);
	}
	else if (form[i] == 'u')
	{
		nbr = va_arg(args, unsigned int);
		if (nbr < 0)
			count += ft_putnbr_fd((unsigned int)(nbr), 1);
		else
			count += ft_putnbr_fd((unsigned int)nbr, 1);
	}
	return (count);
}
