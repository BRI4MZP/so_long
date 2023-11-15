/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 02:17:59 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 19:02:53 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert(char *s1, char *s2)
{
	char	*dest;
	size_t	ca;
	size_t	cb;

	ca = -1;
	cb = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) +1, sizeof(char));
	if (!dest)
		return (free(dest), NULL);
	if (s1)
		while (s1[++ca])
			dest[ca] = s1[ca];
	while (s2[cb])
		dest[ca++] = s2[cb++];
	free(s1);
	return (dest);
}
