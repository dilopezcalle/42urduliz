#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	size;
	int			find;
	int			i;

	find = 0;
	i = 0;
	size = ft_strlen(s);
	if (size <= n)
		return ft_strchr(s, c);
	else
	{
		while (n-- > 0 && find == 0)
		{
			if (((char *)s)[i] == c)
				find = 1;
			else
				i++;
		}
	}
	if (find == 0)
		return (NULL);
	return (&((void *)s)[i]);
}
/*
int	main(void)
{
	char	s[] = "hola";

	printf("Original function: %s\n", memchr(s, 'o', 2));
	printf("My function: %s\n", ft_memchr(s, 'o', 2));
	return (0);
}
*/
