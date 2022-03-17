/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:10:47 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:10:51 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_func(t_stack *a, t_stack *b)
{
	if (a)
		free(a->arr);
	if (b)
		free(b->arr);
}

int	ok(t_stack *a, t_stack *b)
{
	free_func(a, b);
	ft_putstr("OK\n");
	return (0);
}

int	ko(t_stack *a, t_stack *b)
{
	free_func(a, b);
	ft_putstr("KO\n");
	return (1);
}

int	std_read(t_stack *a, t_stack *b)
{
	char	*call;
	int		inst;

	inst = 0;
	while (1)
	{
		call = get_next_line(0);
		if (!call)
			break ;
		if (do_process(call, a, b))
			return (-1);
		else
			inst++;
	}
	return (inst);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		inst;

	if (argc == 1)
		return (SUCCESS);
	i = argc;
	if (check_nums(argc, argv, 1))
		return (err(0));
	init_stack(&a, argc - 1, 'a');
	init_stack(&b, argc - 1, 'b');
	i = -1;
	while (++i < argc - 1)
		a.arr[argc - 2 - i] = ft_atoi(argv[i + 1]);
	inst = std_read(&a, &b);
	if (inst == -1 || !sorted(&a) || b.size > 0)
		return (ko(&a, &b));
	return (ok(&a, &b));
}
