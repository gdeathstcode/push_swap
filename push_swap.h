/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:50:31 by gdeathst          #+#    #+#             */
/*   Updated: 2022/04/23 17:50:32 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

/**
 ** CONSTANT
 */
# define MIN 0
# define MAX 4
# define MAX_DIGITS_IN_INT 12

/**
 ** STRUCTURES
 */
typedef struct s_array
{
	int	*values;
	int	size;
}	t_array;

/**
 ** PARSER
 */
t_array	*parse_arguments(int argc, char **argv);

/**
 ** ALGORITHM
 */
void	normalization(t_array *stack);
void	sort(t_array *stack);
void	sort_big_stack(t_array *a, t_array *b);

/**
 ** OPERATIONS
 */
void	rotate(t_array *stack, char *message);
void	reverse_rotate(t_array *stack, char *message);
void	push(t_array *dst, t_array *src, char *message);
void	swap(t_array *stack, char *message);

/**
 ** ADD_TO_LIBC
 */
int		ft_isint(char *str);
void	*ft_emalloc(size_t size);

/**
 ** UTILS
 */
void	err_exit(char *str);
t_array	*create_stack(int size);
void	destroy_stack(t_array *stack);
bool	is_sorted(t_array *stack);
bool	has_dublicates(t_array *stack);

#endif
