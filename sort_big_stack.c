/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 05:04:01 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/10 05:04:03 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dispersion_calculation(int size_stack)
{
	int	i;
	int	exp;

	i = 1;
	exp = 0;
	while (i < size_stack)
	{
		i = i * 2;
		exp++;
	}
	return (exp * 3);
}

static void	create_hourglass_in_b_stack(t_array *a, t_array *b)
{
	int	i;
	int	dispersion;

	i = 0;
	dispersion = dispersion_calculation(a->size);
	while (a->size != 0)
	{
		if (a->values[0] <= i)
		{
			push(b, a, "pb");
			rotate(b, "rb");
			i++;
		}
		else if (a->values[0] <= i + dispersion)
		{
			push(b, a, "pb");
			i++;
		}
		else
			rotate(a, "ra");
	}
}

static int	get_index(t_array *stack, int to_find)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

static void	optimization_rotate(t_array *b, int num)
{
	int	i;

	i = get_index(b, num);
	if (i < b->size / 2)
	{
		rotate(b, "rb");
		i--;
	}
	else
	{
		i = b->size - i;
		while (b->values[0] != num)
			reverse_rotate(b, "rrb");
	}
}

void	sort_big_stack(t_array *a, t_array *b)
{
	int	i;

	create_hourglass_in_b_stack(a, b);
	i = b->size - 1;
	while (b->size != 0)
	{
		if (b->values[0] == i)
		{
			push(a, b, "pa");
			i--;
		}
		else
			optimization_rotate(b, i);
	}
}
