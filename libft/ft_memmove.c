/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:38:02 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/10 18:38:02 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == 0 && src == 0)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}
