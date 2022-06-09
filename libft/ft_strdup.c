/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:19:16 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/16 15:19:16 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = 0;
	return (str);
}
