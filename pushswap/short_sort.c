/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:13:40 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:13:45 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * indexler sagdan sola göre siralanir. 
 * FILO -> First In Last Out
 *
 */
void	sort_minimal(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		return (ft_putstr("sa\n"));
	if (!sorted(a))
	{
		if (a->arr[2] == b->size)
			ft_putstr("sa\nra\n");
		else if (a->arr[0] == 2 + b->size)
			ft_putstr("sa\n");
		else if (a->arr[1] == 2 + b->size)
			ft_putstr("rra\n");
		else if (a->arr[1] == 1 + b->size)
			ft_putstr("ra\nsa\n");
		else
			ft_putstr("ra\n");
	}
	while (b->size > 0)
		push(b, a, 0);
}

void	short_sort2(t_stack *a, t_stack *b)
{
	if (a->arr[2] == b->size)
		rotate(a, 0);
	else if (a->arr[1] == b->size)
	{
		rotate(a, 0);
		rotate(a, 0);
	}
	else if (a->arr[0] == b->size)
		rev_rotate(a, 0);
	push(a, b, 0);
	sort_minimal(a, b);
}

void	short_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		return (sort_minimal(a, b));
	if (a->size == 4)
		return (short_sort2(a, b));
	if (a->arr[3] == 0)
		rotate(a, 0);
	else if (a->arr[2] == 0)
	{
		rotate(a, 0);
		rotate(a, 0);
	}
	else if (a->arr[1] == 0)
	{
		rev_rotate(a, 0);
		rev_rotate(a, 0);
	}
	else if (a->arr[0] == 0)
		rev_rotate(a, 0);
	push(a, b, 0);
	short_sort2(a, b);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(*s1 - *s2));
}
