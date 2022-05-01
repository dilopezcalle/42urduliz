/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:13:47 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/20 11:49:26 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}
/*
int	main(void)
{
	printf("Original function: %c\n", tolower('A'));
	printf("My function: %c\n", ft_tolower('A'));
	return (0);
}
*/
