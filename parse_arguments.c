/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:45:33 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/07 07:45:34 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*concatenation(char *initial, const char *to_add)
{
	char	*str;

	str = ft_strjoin(initial, to_add);
	if (str == NULL)
		err_exit("Error\n");
	free(initial);
	return (str);
}

static char	*parse_arguments_to_string(int argc, char **argv)
{
	char	*options;
	char	*space;
	int		i;

	space = " ";
	options = ft_strjoin(space, "");
	if (options == NULL)
		err_exit("Error\n");
	i = 0;
	while (i != argc)
	{
		options = concatenation(options, argv[i]);
		options = concatenation(options, space);
		i++;
	}
	return (options);
}

static void	fill_stack_by_values(t_array *stack, char **values)
{
	int	i;

	i = 0;
	while (values[i])
		i++;
	stack->size = i;
	stack->values = (int *) ft_emalloc(sizeof (int) * stack->size);
	i = 0;
	while (values[i])
	{
		if (!ft_isint(values[i]))
			err_exit("Error\n");
		stack->values[i] = ft_atoi(values[i]);
		i++;
	}
}

static void	destroy_string_vector_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

t_array	*parse_arguments(int argc, char **argv)
{
	t_array	*stack;
	char	*arguments;
	char	**string_vector_values;

	arguments = parse_arguments_to_string(argc, argv);
	stack = (t_array *) ft_emalloc(sizeof(t_array));
	string_vector_values = ft_split(arguments, ' ');
	if (string_vector_values == NULL)
		err_exit("Error\n");
	free(arguments);
	fill_stack_by_values(stack, string_vector_values);
	destroy_string_vector_values(string_vector_values);
	return (stack);
}
