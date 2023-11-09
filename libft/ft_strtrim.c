/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:31:02 by arlee             #+#    #+#             */
/*   Updated: 2023/08/14 13:31:05 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	first;
	size_t	last;

	first = 0; 
	new_s = NULL;
	if (!s1 || !set)
		return (NULL);
	last = ft_strlen(s1);
	while (s1[first] != '\0' && ft_strchr(set, s1[first]))
		first++;
	while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && last > first)
		last--;
	new_s = (char *)malloc(sizeof(char) * (last - first + 1));
	if (new_s)
		ft_strlcpy(new_s, s1 + first, last - first + 1);
	return (new_s);
}
