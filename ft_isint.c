/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:48:52 by gdeathst          #+#    #+#             */
/*   Updated: 2022/05/07 07:48:53 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isint(char *str)
{
	bool	is_int;
	char	*num_in_str;
	int		num;
	int		i;

	is_int = false;
	num = ft_atoi(str);
	num_in_str = (char *) ft_emalloc(sizeof(char) * MAX_DIGITS_IN_INT);
	num_in_str = (char *)ft_itoa(num, num_in_str, 10);
	i = 0;
	if (str[i] == '+')
		i++;
	if (ft_strncmp(str + i, num_in_str, ft_strlen(str)) == 0)
		is_int = true;
	free(num_in_str);
	return (is_int);
}
