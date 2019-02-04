/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:12:51 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 16:23:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int		check(long *addresses, long tmp, int len)
{
	int	i;

	if (!addresses)
		return (0);
	i = 0;
	while (i < len)
	{
		if (addresses[i] == tmp)
			return (1);
		i++;
	}
	return (0);
}

long	*cp(long *addresses, int len)
{
	int		i;
	long	*res;

	i = 0;
	res = (long*)malloc(sizeof(*res) * len);
	while (i < len - 1)
	{
		res[i] = addresses[i];
		i++;
	}
	free(addresses);
	return (res);
}

int		cycle_detector(const t_list *list)
{
	long	*addresses;
	int		i;
	int		len;
	t_list *tmp;

	if (!list)
		return (0);
	i = 0;
	len = 0;
	tmp = (t_list*)list;
	addresses = NULL;
	while (tmp)
	{
		if (check(addresses, (long)tmp, len) == 1)
			return (1);
		len++;
		addresses = cp(addresses, len);
		addresses[len - 1] = (long)tmp;
		tmp = tmp->next;
	}
	return (0);
}
