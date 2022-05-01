/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:02:31 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/20 11:49:12 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}
/*
int	main(void)
{
	printf("Original function: %c\n", toupper('Z'));
	printf("My function: %c\n", ft_toupper('Z'));
	return (0);
}
*/
