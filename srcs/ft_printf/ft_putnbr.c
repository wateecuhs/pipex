/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:00:56 by panger            #+#    #+#             */
/*   Updated: 2023/11/29 11:05:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		if (write(2, "-2147483648", 11) == -1)
			return (-1);
		*count += 11;
		return (1);
	}
	if (nb > 9)
	{
		if (ft_putnbr(nb / 10, count) == -1)
			return (-1);
		if (ft_putnbr(nb % 10, count) == -1)
			return (-1);
	}
	else if (nb < 0)
	{
		if (ft_putchar('-', count) == -1)
			return (-1);
		if (ft_putnbr(-nb, count) == -1)
			return (-1);
	}
	else if (nb >= 0)
		if (ft_putchar(nb + 48, count) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_unsigned(int n, int *count)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb > 9)
	{
		if (ft_putnbr_unsigned(nb / 10, count) == -1)
			return (-1);
		if (ft_putnbr_unsigned(nb % 10, count) == -1)
			return (-1);
	}
	else
		if (ft_putchar(nb + 48, count) == -1)
			return (-1);
	return (1);
}

int	ft_putstr_hexa(int n, int caps, int *count)
{
	char			*base;
	char			*base2;
	char			tab[16];
	int				i;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	i = 15;
	while ((unsigned int)n >= 16 && i > 0)
	{
		if (caps)
			tab[i] = base2[((unsigned int)n) % 16];
		else
			tab[i] = base[((unsigned int)n) % 16];
		i--;
		n = (unsigned int)n / 16;
	}
	if (caps)
		tab[i] = base2[((unsigned int)n) % 16];
	else
		tab[i] = base[((unsigned int)n) % 16];
	if (write(2, &tab[i], -(i - 16)) == -1)
		return (-1);
	*count += -(i - 16);
	return (1);
}
