/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:08:17 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/29 16:34:37 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}

int	ft_isdigit_char(char *arr_av, int i)
{
	if (arr_av[0] == '\0')
		print_error();
	while (arr_av[++i])
	{
		if (arr_av[i] == '-' && ft_isdigit(arr_av[i + 1]))
			i++;
		if (!ft_isdigit(arr_av[i]))
			print_error();
	}
	return (1);
}

void	do_while(int *s_arr, int *left, int *right, int middle)
{
	int	tmp;
	int	l;
	int	r;

	l = *left;
	r = *right;
	while (s_arr[l] < middle)
		l++;
	while (s_arr[r] > middle)
		r--;
	if (l <= r)
	{
		tmp = s_arr[l];
		s_arr[l] = s_arr[r];
		s_arr[r] = tmp;
		l++;
		r--;
	}
	*left = l;
	*right = r;
}

void	qs(int *s_arr, int first, int last, int left)
{
	int	right;
	int	middle;

	if (first < last)
	{
		right = last;
		middle = s_arr[(left + right) / 2];
		do_while(s_arr, &left, &right, middle);
		while (left <= right)
			do_while(s_arr, &left, &right, middle);
		qs(s_arr, first, right, first);
		qs(s_arr, left, last, left);
	}
}

void	ft_check_dup2(t_stack *stack_a, int count, int i)
{
	int		*array;
	t_stack	*tmp;

	tmp = stack_a;
	array = malloc(4 * count);
	if (!array)
		print_error();
	while (stack_a)
	{
		array[i++] = stack_a->nbr;
		stack_a = stack_a->next;
	}
	qs(array, 0, count - 1, 0);
	i = -1;
	while (++i < count - 1)
	{
		if (array[i] >= array[i + 1])
			print_error ();
	}
	stack_a = tmp;
	get_index(stack_a, array, 0);
	free(array);
}
