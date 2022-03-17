/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:12:37 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:12:41 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_func(t_stack *a, t_stack *b)
{
	if (a)
		free(a->arr);
	if (b)
		free(b->arr);
	return (SUCCESS);
}

int	take_args_multiple(int argc, char **argv, t_stack *st_a, t_stack *st_b)
{
	int	i;

	i = argc;
	if (check_nums(argc, argv, 0) == ERROR)
		return (ERROR);
	init_stack(st_a, argc - 1, 'a');
	init_stack(st_b, argc - 1, 'b');
	i = -1;
	while (++i < argc - 1)
		st_a->arr[argc - 2 - i] = ft_atoi(argv[i + 1]);
	return (i);
}

int	take_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		counter;
	char	**ret_val;

	ret_val = ft_split(argv[1], ' ');
	i = ft_wdcounter(argv[1], ' ');
	if (i == 1)
	{
		if (take_args_multiple(argc, argv, stack_a, stack_b) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (check_nums_2(i, ret_val, 0) == ERROR)
		return (ERROR);
	init_stack(stack_a, i, 'a');
	init_stack(stack_b, i, 'b');
	counter = -1;
	while (counter < i && counter + 1 != i)
	{
		counter ++;
		stack_a->arr[i - 1 - counter] = ft_atoi(ret_val[counter]);
	}
	return (i);
}

int	main(int argc, char **args)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = argc;
	if (argc == 2)
	{		
		if (take_args(argc, args, &a, &b) == ERROR)
			return (-1);
	}
	else
		if (take_args_multiple(argc, args, &a, &b) == ERROR)
			return (-1);
	if (sorted(&a))
		return (free_func(&a, &b));
	simplify(a.arr, a.size);
	if (a.size <= 5)
		short_sort(&a, &b);
	else
	{
		init_a(&a, &b, a.size);
		rec(&a, &b);
	}
	return (free_func(&a, &b));
}
