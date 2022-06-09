/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:13:00 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/19 03:13:00 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*tmp;

	f_lst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&f_lst, tmp);
		lst = lst->next;
	}
	return (f_lst);
}
