/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:29:11 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/07 12:29:50 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_emalloc(size_t size)
{
	char	*mem;

	mem = (char *) malloc(size);
	if (mem == NULL)
	{
		write(2, "No more memory!\n", 16);
		exit(EXIT_FAILURE);
	}
	return ((void *)mem);
}
