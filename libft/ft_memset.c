/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:49:30 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/09 02:49:30 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*tmp;

	tmp = s;
	while (n-- > 0)
		*(unsigned char *)tmp++ = (unsigned char)c;
	return (s);
}
