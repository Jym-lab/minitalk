/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:30 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/16 15:32:30 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	if (ft_strlen(s) <= start)
	{	
		sub[0] = 0;
		return (sub);
	}
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
