/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalayir <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:13:16 by acalayir          #+#    #+#             */
/*   Updated: 2022/02/22 18:13:20 by acalayir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct stack
{
	int		*arr;
	int		size;
	char	type;
	int		max_size;
}	t_stack;

void	short_sort(t_stack *a, t_stack *b);
int		get_min_ind(t_stack *a);
int		get_pos(t_stack *a, int num);
int		mid(t_stack *s, int length);
void	get_to_top(t_stack *s, int i);
void	find_least_process(t_stack *a, t_stack *b, int *i, int *j);
void	push(t_stack *from, t_stack *to, int checker);
void	rotate(t_stack *s, int checker);
void	rev_rotate(t_stack *s, int checker);
void	swap(t_stack *s, int checker);
void	init_stack(t_stack *stack, int size, char type);
void	init_a(t_stack *from, t_stack *to, int chunk_size);
void	simplify(int *arr, int size);
void	sort(int *arr, int size);
int		check_nums(int argc, char **args, int checker);
int		sorted(t_stack *a);
void	rec(t_stack *a, t_stack *b);
int		err(int checker);
int		is_valid(char *str);
int		do_process(char *call, t_stack *a, t_stack *b);
void	ft_putnbr(int num);
int		ft_strcmp(char *s1, char *s2);
int		check_nums_2(int argc, char **args, int checker);

# define SUCCESS 0
# define ERROR 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647
#endif
