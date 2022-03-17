/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:11:13 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:11:16 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to, int checker)
{
	from->size--;
	to->arr[to->size] = from->arr[from->size];
	to->size++;
	if (!checker)
	{
		if (to->type == 'a')
			ft_putstr("pa\n");
		else
			ft_putstr("pb\n");
	}
}

void	rotate(t_stack *s, int checker)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * s->max_size);
	i = -1;
	while (++i < s->size)
		new_arr[(i + 1) % s->size] = s->arr[i];
	if (!checker)
	{
		if (s->type == 'a')
			ft_putstr("ra\n");
		else
			ft_putstr("rb\n");
	}
	free(s->arr);
	s->arr = new_arr;
}

void	rev_rotate(t_stack *s, int checker)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * s->max_size);
	i = -1;
	while (++i < s->size)
		new_arr[i] = s->arr[(i + 1) % s->size];
	if (!checker)
	{
		if (s->type == 'a')
			ft_putstr("rra\n");
		else
			ft_putstr("rrb\n");
	}
	free(s->arr);
	s->arr = new_arr;
}

void	swap(t_stack *s, int checker)
{
	int	tmp;

	tmp = s->arr[s->size - 2];
	s->arr[s->size - 2] = s->arr[s->size - 1];
	s->arr[s->size - 1] = tmp;
	if (!checker)
	{
		if (s->type == 'a')
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
}

void	rec(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	while (b->size > 0)
	{
		find_least_process(a, b, &i, &j);
		get_to_top(b, i);
		get_to_top(a, j);
		push(b, a, 0);
	}
	get_to_top(a, get_min_ind(a));
}
