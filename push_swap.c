/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:08:11 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/05 21:08:13 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array	*stack;

	stack = parse_arguments(argc - 1, argv + 1);
	if (has_dublicates(stack))
		err_exit("Error\n");
	if (!is_sorted(stack))
		sort(stack);
	destroy_stack(stack);
	return (EXIT_SUCCESS);
}
