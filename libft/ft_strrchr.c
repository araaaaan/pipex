/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:30:55 by arlee             #+#    #+#             */
/*   Updated: 2023/08/14 13:30:58 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*finder;

	finder = NULL;
	if ((unsigned char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (unsigned char)c)
			finder = (char *)s;
		s++;
	}
	return (finder);
}
