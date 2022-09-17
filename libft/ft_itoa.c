/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:54:37 by kcomic            #+#    #+#             */
/*   Updated: 2021/10/24 19:13:00 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_count(int n)
{
	int	len;

	if (n == -2147483648)
		len = 11;
	else
	{
		len = 1;
		if (n < 0)
		{
			len++;
			n = -n;
		}
		while (n >= 10)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

static void	filling_ptr(char *ptr, int n, int len)
{
	if (n == -2147483648)
	{
		ptr[0] = '-';
		ptr[1] = '2';
		n = 147483648;
	}
	if (n < 0)
		ptr[0] = '-';
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		ptr[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	ptr[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ans;

	len = len_count(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	ans[len] = '\0';
	len--;
	filling_ptr(ans, n, len);
	return (ans);
}
