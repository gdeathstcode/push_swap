/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:45:38 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/07 07:45:40 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_elements(t_array *a)
{
	if (a->values[0] < a->values[2])
		swap(a, "sa");
	else
		rotate(a, "ra");
	if (a->values[0] > a->values[2])
		rotate(a, "ra");
	else if (a->values[0] > a->values[1])
		swap(a, "sa");
}

static void	sort_four_elements(t_array *a, t_array *b)
{
	while (a->values[0] != MIN)
		rotate(a, "ra");
	push(b, a, "pb");
	sort_three_elements(a);
	push(a, b, "pa");
}

static void	sort_five_elements(t_array *a, t_array *b)
{
	while (a->size != 3)
	{
		if (a->values[0] == MIN || a->values[0] == MAX)
			push(b, a, "pb");
		else
			rotate(a, "ra");
	}
	sort_three_elements(a);
	push(a, b, "pa");
	push(a, b, "pa");
	if (a->values[0] == MIN)
		swap(a, "sa");
	rotate(a, "ra");
}

void	sort(t_array *a)
{
	t_array	*b;

	b = create_stack(a->size);
	normalization(a);
	if (a->size == 2)
		swap(a, "sa");
	else if (a->size == 3)
		sort_three_elements(a);
	else if (a->size == 4)
		sort_four_elements(a, b);
	else if (a->size == 5)
		sort_five_elements(a, b);
	else
		sort_big_stack(a, b);
	destroy_stack(b);
}
