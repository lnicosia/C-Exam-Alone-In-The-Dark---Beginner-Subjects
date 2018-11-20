/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:18:49 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/20 13:25:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int));

int croissant(int a, int b)
{
		return (a <= b);
}

int		main(void)
{
	t_list *lst1 = (t_list*)malloc(sizeof(*lst1));
	lst1->data = 654;
	t_list *lst2 = (t_list*)malloc(sizeof(*lst2));
	lst2->data = 42;
	lst1->next = lst2;
	lst2->next = NULL;
	t_list *lst3 = sort_list(lst1, &croissant);
	while (lst3)
	{
		printf("%d\n", lst3->data);
		lst3 = lst3->next;
	}
	return (0);
}
