/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:10:29 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:10:34 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err(int checker)
{
	if (!checker)
		ft_putstr("Error\n");
	return (ERROR);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_atoi(str) == 2147483648 || ft_atoi(str) == -2147483649)
		return (0);
	return (str[i] == '\0');
}

int	sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (++i < a->size)
		if (a->arr[i - 1] < a->arr[i])
			return (0);
	return (1);
}

int	check_nums_2(int argc, char **args, int checker)
{
	int	i;
	int	j;

	i = argc;
	while (i > 0)
	{
		j = 0;
		if (!is_valid(args[i - 1]))
			return (err(checker));
		while (++j < i)
			if (ft_atoi(args[i - 1]) == ft_atoi(args[j - 1]))
				return (err(checker));
		i--;
	}
	return (SUCCESS);
}

int	check_nums(int argc, char **args, int checker)
{
	int	i;
	int	j;

	i = argc;
	while (--i > 0)
	{
		j = 0;
		if (!is_valid(args[i]))
			return (err(checker));
		while (++j < i)
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (err(checker));
	}
	return (SUCCESS);
}
