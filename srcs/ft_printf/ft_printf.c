/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:40:07 by panger            #+#    #+#             */
/*   Updated: 2023/12/02 14:29:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_numb(char c, va_list args, int *count)
{
	if (c == 'd' || c == 'i')
	{
		if (ft_putnbr(va_arg(args, int), count) == -1)
			return (-1);
	}
	else if (c == 'p')
	{
		if (ft_putadr_hexa(va_arg(args, unsigned long), count) == -1)
			return (-1);
	}
	else if (c == 'u')
	{
		if (ft_putnbr_unsigned((va_arg(args, int)), count) == -1)
			return (-1);
	}
	else if (c == 'x' || c == 'X')
	{
		if (ft_putstr_hexa(va_arg(args, unsigned long),
				(c == 'X'), count) == -1)
			return (-1);
	}
	return (1);
}

int	redirecting(char c, va_list args, int *count)
{
	if (c == 'c')
	{
		if (ft_putchar((unsigned char)va_arg(args, int), count) == -1)
			return (-1);
	}
	else if (c == 's')
	{
		if (ft_putstr(va_arg(args, char *), count) == -1)
			return (-1);
	}
	else if (c == 'u' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'd' || c == 'i')
	{
		if (redirect_numb(c, args, count) == -1)
			return (-1);
	}
	else if (c == '%')
	{
		if (ft_putchar('%', count) == -1)
			return (-1);
	}
	else if (c == '\0')
		return (-1);
	return (1);
}

int	reading_loop(const char *str, va_list args, int *count)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (redirecting(str[i], args, count) == -1)
				return (-1);
		}
		else
		{
			if (write(2, &str[i], 1) == -1)
				return (-1);
			*count += 1;
		}
		if (str[i])
			i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ptr;
	int				count;

	count = 0;
	if (!str)
		return (-1);
	va_start(ptr, str);
	if (reading_loop(str, ptr, &count) == -1)
	{
		va_end(ptr);
		exit(EXIT_FAILURE);
	}
	va_end(ptr);
	return (count);
}
