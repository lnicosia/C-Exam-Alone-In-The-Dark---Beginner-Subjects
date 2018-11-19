/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:24:12 by exam              #+#    #+#             */
/*   Updated: 2018/11/19 14:54:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_getlen(int nbr, int base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

void	ft_fillstr(int nb, int baselen, int len, char *str)
{
	int		i;
	char	*base = "0123456789ABCDEF";

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
		str[len - 1] = base[nb % baselen];
		nb = nb / baselen;
		len--;
	}
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;

	if (value < 0 && base != 10)
		value = -value;
	len = ft_getlen(value, base);
	if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
		return (0);
	ft_fillstr(value, base, len, str);
	return (str);
}
