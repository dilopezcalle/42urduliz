/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:39:48 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/15 14:36:56 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	ft_putnbr_base(long int nbr, char *base)
{
	int		i;
	int		size;
	int		bytes;
	char	str_nbr[18];

	i = 0;
	size = 0;
	bytes = 0;
	while (base[size] != '\0')
		size++;
	ft_generate_str(str_nbr, base, nbr, size);
	ft_rev_string(str_nbr);
	while (str_nbr[i] != '\0')
	{
		bytes += write(1, &str_nbr[i], 1);
		i++;
	}
	return (bytes);
}

void	ft_generate_str(char *str_nbr, char *base, long int nbr, int size)
{
	long int	nbr_loop;
	int			i;

	i = 0;
	nbr_loop = nbr;
	if (nbr < 0)
		nbr_loop = -nbr_loop;
	while (nbr_loop > 0)
	{
		str_nbr[i] = base[nbr_loop % size];
		nbr_loop = nbr_loop / size;
		i++;
	}
	if (nbr <= 0)
	{
		if (nbr < 0)
			str_nbr[i] = '-';
		else
			str_nbr[i] = '0';
		i++;
	}
	str_nbr[i] = '\0';
}

void	ft_rev_string(char *tab)
{
	int		i;
	int		size;
	char	temp;
	int		loopsize;

	i = 0;
	size = 0;
	while (tab[size])
		size++;
	loopsize = size / 2;
	i = 0;
	if (size > 1)
	{
		while (loopsize > i)
		{
			temp = tab[size - 1];
			tab[size - 1] = tab[i];
			tab[i] = temp;
			i++;
			size--;
		}
	}
}
/*
int	main(void)
{
	long int		nbr;
	char			*base = "0123456789";
	int				bytes;

	nbr = -2482783569246587;
	bytes = ft_putnbr_base(nbr, base);
	printf("\nbytes: %d\n", bytes);
	return (0);
}
*/
