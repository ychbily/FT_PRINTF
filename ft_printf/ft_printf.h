/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:02:40 by ychbily           #+#    #+#             */
/*   Updated: 2023/12/13 20:41:04 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include <stdarg.h>

int			ft_printf(const char *form, ...);
int			ft_hexa(va_list args, const char *form, int i);
int			ft_num(va_list args, const char *form, int i);
int			ft_str(va_list args, const char *form, int i);
void		ft_putchar_fd(char c, int fd);
int			ft_putnbr_fd(long n, int fd);

#endif
