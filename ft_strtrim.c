/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:59:09 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/09 14:51:10 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		y;
	int		z;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	x = 0;
	z = 0;
	while (s1[x] && check_set(s1[x], set))
		x++;
	y = ft_strlen(s1);
	while (y > x && check_set(s1[y - 1], set))
		y--;
	str = (char *)malloc(sizeof(char) * (y - x + 1));
	if (!str)
		return (NULL);
	while (x < y)
		str[z++] = s1[x++];
	str[z] = '\0';
	return (str);
}
