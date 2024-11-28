/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:02:55 by fhassane          #+#    #+#             */
/*   Updated: 2024/11/27 21:01:29 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	len2;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	len2 = 0;
	if (start < s_len)
		len2 = s_len - start;
	if (start > s_len)
		return (ft_strdup(""));
	if (len2 > len)
		len2 = len;
	str = (char *)malloc(sizeof(char) * (len2 + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len2 + 1);
	return (str);
}
