/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 12:14:04 by exam              #+#    #+#             */
/*   Updated: 2018/08/24 12:53:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_is_prime(int nb)
{
	int		div;

	div = 2;
	while (div < nb)
	{
		if (nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		nb;
	int		first;
	int		i;

	nb = 0;
	i = 2;
	first = 0;
	if (argc == 2)
	{
		nb = atoi(argv[1]);

		if (nb > 0)
		{
			if (ft_is_prime(nb))
			{
				printf("%d\n",nb);
				return (0);
			}
			while (i <= nb)
			{
				if (ft_is_prime(i) && (nb % i == 0))
				{
					if (first)
						printf("*");
					else
						first++;
					printf("%d",i);
					nb = nb / i;
				}
				else
					i++;
			}
		}
	}
	printf("\n");
	return (0);
}
