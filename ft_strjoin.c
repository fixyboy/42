/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:12:43 by fhassane          #+#    #+#             */
/*   Updated: 2024/11/23 14:54:21 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	lenstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	lenstr = lens1 + lens2;
	str = (char *)malloc(sizeof(char) * (lenstr + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lenstr + 1);
	return (str);
}
/*
int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "World!";
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Concatenated String: %s\n", result);
		free(result); // Free the allocated memory
	}
	else
	{
		printf("Memory allocation failed.\n");
	}

	return (0);
}*/
