/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:29:18 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/23 14:59:52 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*f_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	f_str = ft_strdup(s);
	if (!f_str)
		return (NULL);
	while (f_str[i])
	{
		f_str[i] = f(i, s[i]);
		i++;
	}
	return (f_str);
}
