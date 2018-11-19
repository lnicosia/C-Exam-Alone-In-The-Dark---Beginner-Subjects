/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:48:54 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 18:34:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *tmp;
	t_list *res;
	int		inttmp;

	res = lst;
	while (lst)
	{
		tmp = lst;
		while (tmp)
		{
			if (tmp->next)
				if (cmp(tmp->data, tmp->next->data) == 0)
				{
					inttmp = tmp->data;
					tmp->data = tmp->next->data;
					tmp->data = inttmp;
				}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (res);
}
