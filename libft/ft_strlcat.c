/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:38:20 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/12 20:38:20 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = 0;
	return (dst_len + src_len);
}
