/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:28:20 by arlee             #+#    #+#             */
/*   Updated: 2023/08/14 13:28:22 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dt;
	unsigned char	*s;
	size_t			i;

	i = 0;
	dt = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dt && !s)
		return (NULL);
	while (i < len)
	{
		dt[i] = s[i];
		i++;
	}
	return (dst);
}
