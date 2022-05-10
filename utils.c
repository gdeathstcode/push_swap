/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:45:42 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/07 07:45:44 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit(char *str)
{
	ft_putstr_fd(str, stderr->_file);
	exit(EXIT_FAILURE);
}

t_array	*create_stack(int size)
{
	t_array	*stack;

	stack = (t_array *) ft_emalloc(sizeof (t_array));
	stack->values = (int *) ft_emalloc(sizeof (int) * size);
	stack->size = 0;
	return (stack);
}

void	destroy_stack(t_array *stack)
{
	if (stack)
	{
		if (stack->values)
			free(stack->values);
		free(stack);
	}
}

bool	is_sorted(t_array *stack)
{
	bool	is_sorted;
	int		i;
	int		j;

	is_sorted = true;
	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->values[i] > stack->values[j])
				is_sorted = false;
			j++;
		}
		i++;
	}
	return (is_sorted);
}

bool	has_dublicates(t_array *stack)
{
	bool	dublicates;
	int		i;
	int		j;

	dublicates = false;
	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->values[i] == stack->values[j])
				dublicates = true;
			j++;
		}
		i++;
	}
	return (dublicates);
}
