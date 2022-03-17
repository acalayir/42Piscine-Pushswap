/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:12:59 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:13:04 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_ind(t_stack *a)
{
	int	j;
	int	i;
	int	min;

	if (!a->size)
		return (0);
	min = INT_MAX;
	i = -1;
	j = 0;
	while (++i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			j = i;
		}
	}
	return (j);
}

int	get_pos(t_stack *a, int num)
{
	int	j;
	int	i;
	int	max;
	int	tmp;

	if (!a->size)
		return (1);
	max = INT_MIN;
	j = -1;
	i = -1;
	while (++i < a->size)
	{
		tmp = num - a->arr[i];
		if (tmp < 0 && tmp > max)
		{
			j = i;
			max = tmp;
		}
	}
	if (j == -1)
		j = get_min_ind(a);
	return (j);
}

void	find_least_process(t_stack *a, t_stack *b, int *i, int *j)
{
	int	tmp[2];
	int	m;
	int	n;
	int	min;

	min = INT_MAX;
	m = b->size;
	while (--m >= 0)
	{
		n = get_pos(a, b->arr[m]);
		if (m + 1 > b->size - m - 1)
			tmp[0] = b->size - m - 1;
		else
			tmp[0] = m + 1;
		if (n > a->size - n)
			tmp[1] = a->size - n;
		else
			tmp[1] = n;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*i = m;
			*j = n;
		}
	}
}

void	get_to_top(t_stack *s, int i)
{
	int	counter;

	if (i + 1 > s->size - i - 1)
	{
		counter = s->size - i - 1;
		while (counter-- > 0)
			rotate(s, 0);
	}
	else
	{
		counter = i + 1;
		while (counter-- > 0)
			rev_rotate(s, 0);
	}
}

int	mid(t_stack *s, int length)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (i++ < length)
	{
		if (s->arr[s->size - i] > max)
			max = s->arr[s->size - i];
		if (s->arr[s->size - i] < min)
			min = s->arr[s->size - i];
	}
	return ((max + min) / 2);
}
