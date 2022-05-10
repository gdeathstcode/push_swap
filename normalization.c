/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 03:38:06 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/10 03:38:08 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *array, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				array[j] = array[j] + array[j + 1];
				array[j + 1] = array[j] - array[j + 1];
				array[j] = array[j] - array[j + 1];
			}
			j++;
		}
		i++;
	}
}

static int	get_index(int *src, int size, int to_find)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (src[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

void	normalization(t_array *stack)
{
	int	*sub_array;
	int	i;

	sub_array = (int *) ft_emalloc(sizeof (int) * stack->size);
	ft_memcpy(sub_array, stack->values, sizeof(int) * stack->size);
	bubble_sort(sub_array, stack->size);
	i = 0;
	while (i < stack->size)
	{
		stack->values[i] = get_index(sub_array, stack->size, stack->values[i]);
		i++;
	}
	free(sub_array);
}
