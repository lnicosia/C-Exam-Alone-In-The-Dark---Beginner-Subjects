/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:19:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 16:24:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int		cycle_detector(const t_list *list);

int		main(void)
{
	t_list *list = (t_list*)malloc(sizeof(t_list));
	list->data = 0;
	t_list *list1 = (t_list*)malloc(sizeof(t_list));
	list1->data = 1;
	t_list *list2 = (t_list*)malloc(sizeof(t_list));
	list2->data = 2;
	t_list *list3 = (t_list*)malloc(sizeof(t_list));
	list3->data = 3;
	list->next = list1;
	list1->next = list2;
	list2->next = list3;
	//list3->next = NULL;
	list3->next = list;
	list = NULL;
	printf("res = %d\n", cycle_detector(list));
	return (0);
}
