/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:24:12 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 11:51:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_getlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_fillstr(int nb, int len, char *str)
{
	int		i;

	i = 0;
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		nb = 147483648;
		i = 2;
	}
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		i++;
	}
	while (len > i)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;

	len = ft_getlen(nbr);
	if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
		return (0);
	ft_fillstr(nbr, len, str);
	return (str);
}
