/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:19:14 by fhassane          #+#    #+#             */
/*   Updated: 2024/11/27 21:19:15 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char			*dest2;
	const unsigned char		*src2;
	size_t					i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dest2 = (unsigned char *)dest;
	src2 = (const unsigned char *)src;
	if (dest2 > src2)
	{
		while (len-- > 0)
			dest2[len] = src2[len];
	}
	else
	{
		while (i < len)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
