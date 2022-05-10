/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 03:39:52 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/10 03:39:53 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_array *stack, char *message)
{
	int	first_value;

	if (stack->size > 1)
	{
		first_value = stack->values[0];
		ft_memmove(
			stack->values,
			stack->values + 1,
			sizeof (int) * (stack->size - 1));
		stack->values[stack->size - 1] = first_value;
		ft_printf("%s\n", message);
	}
}

void	reverse_rotate(t_array *stack, char *message)
{
	int	last_value;

	if (stack->size > 1)
	{
		last_value = stack->values[stack->size - 1];
		ft_memmove(
			stack->values + 1,
			stack->values,
			sizeof(int) * (stack->size - 1));
		stack->values[0] = last_value;
		ft_printf("%s\n", message);
	}
}

void	push(t_array *dst, t_array *src, char *message)
{
	int	value_to_push;

	if (src->size > 0)
	{
		value_to_push = src->values[0];
		ft_memmove(
			src->values,
			src->values + 1,
			sizeof (int) * (src->size - 1));
		ft_memmove(dst->values + 1, dst->values, sizeof (int) * dst->size);
		dst->values[0] = value_to_push;
		src->size--;
		dst->size++;
		ft_printf("%s\n", message);
	}
}

void	swap(t_array *stack, char *message)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->values[0];
		stack->values[0] = stack->values[1];
		stack->values[1] = tmp;
		ft_printf("%s\n", message);
	}
}
