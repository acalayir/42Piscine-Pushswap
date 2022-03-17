/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:10:58 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:11:04 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 0;
	while (++i < size)
	{
		key = arr[i];
		j = i;
		while (--j >= 0 && arr[j] > key)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}
/*
 * siralamaya göre indexliyor.
 */

void	simplify(int *arr, int size)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		tmp[i] = arr[i];
	sort(tmp, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (arr[i] == tmp[j])
			{
				arr[i] = j;
				break ;
			}
		}
	}
	free(tmp);
}

void	init_a(t_stack *from, t_stack *to, int chunk_size)
{
	int	i;
	int	j;
	int	mid_num;

	if (chunk_size <= 2)
		return ;
	i = 0;
	j = 0;
	mid_num = mid(from, chunk_size);
	while (i++ < chunk_size)
	{
		if (from->type == 'a' && from->arr[from->size - 1] <= mid_num)
		{
			j++;
			push(from, to, 0);
		}
		else
			rotate(from, 0);
	}
	init_a(from, to, chunk_size - j);
}

void	init_stack(t_stack *stack, int size, char type)
{
	stack->max_size = size;
	if (type == 'a')
		stack->size = size;
	else
		stack->size = 0;
	stack->type = type;
	stack->arr = (int *)malloc(sizeof(int) * size);
}
