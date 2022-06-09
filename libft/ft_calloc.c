/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:13:44 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/16 15:13:44 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = malloc(size * nmemb);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (size * nmemb));
	return (tmp);
}
