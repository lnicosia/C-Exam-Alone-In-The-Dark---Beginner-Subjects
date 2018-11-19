/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:00:02 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 16:02:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*moment(unsigned int duration);

void	putstr(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(int ac, char **av)
{
	(void)ac;
	putstr(moment(atoi(av[1])));
	return (0);
}
