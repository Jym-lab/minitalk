/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:10:13 by yjoo              #+#    #+#             */
/*   Updated: 2021/12/08 19:37:01 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int n)
{
	int	num_cnt;

	num_cnt = 0;
	if (n <= 0)
		num_cnt++;
	while (n)
	{
		n = n / 10;
		num_cnt++;
	}
	return (num_cnt);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		num_cnt;
	int		i;

	num_cnt = num_count(n);
	num_str = (char *)malloc(sizeof(char) * (num_cnt + 1));
	if (!num_str)
		return (NULL);
	num_str[num_cnt] = 0;
	i = 0;
	if (n < 0)
	{
		num_str[i] = '-';
		i++;
	}
	while (num_cnt-- > i)
	{
		if (n < 0)
			num_str[num_cnt] = n % 10 * (-1) + '0';
		else
			num_str[num_cnt] = n % 10 + '0';
		n /= 10;
	}
	return (num_str);
}
