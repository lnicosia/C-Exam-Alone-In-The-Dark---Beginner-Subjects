/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:42:36 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 10:47:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	unsigned int	nb;
	int				i;

	if (ac == 2)
	{
		nb = atoi(av[1]);
		if (nb == 1)
			printf("1");
		else
		{
			i = 1;
			while (nb > 1)
			{
				if (nb % ++i == 0)
				{
					printf("%d", i);
					nb /= i;
					if (nb > 1)
						printf("*");
					i--;
				}
			}
		}
	}
	printf("\n");
	return (0);
}
