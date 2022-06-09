/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:18:37 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/18 21:18:37 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	if (lst->next == NULL)
		size++;
	return (size);
}
