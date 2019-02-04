/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:39:28 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 19:24:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_long(unsigned char *p, size_t size, int i)
{
	size_t	j;
	char	*base = "0123456789abcdef";
	
	j = 0;
	while (j < 16 && j + i < size)
	{
		write(1, base + *(p + i + j) / 16 % 16, 1);
		write(1, base + *(p + i + j) % 16, 1);
		if (j % 2 == 1)
			write (1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
			write (1, " ", 1);
		j++;
	}
}

void	print_char(unsigned char *p, size_t size, int i)
{
	size_t	j;
	
	j = 0;
	while (j < 16 && j + i < size)
	{
		if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
			write(1, p + i + j, 1);
		else
			write(1, ".", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		print_long((unsigned char *)addr, size, i);
		print_char((unsigned char *)addr, size, i);
		i += 16;
	}
}
