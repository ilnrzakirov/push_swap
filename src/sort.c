/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:32:46 by bcarlee           #+#    #+#             */
/*   Updated: 2022/01/02 16:35:43 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack, int a, int b, int c)
{
	a = (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if ((b > c) && (c > a))
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if ((b > a) && (a > c))
		reverse_rotate_a(stack);
	else if ((c > a) && (a > b))
		swap_a(stack);
	else if ((a > c) && (c > b))
		rotate_a(stack);
	else if ((a > b) && (b > c))
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
}

void	sort_3_b(t_stack **stack, int min)
{
	if (min == (*stack)->ind)
		return (ft_sort_bmin(stack, min));
	else if (min + 1 == (*stack)->ind)
		return (ft_sort_bmax(stack, min));
	else if (min + 2 == (*stack)->ind)
	{
		if (min + 1 != (*stack)->next->ind)
		{
			swap_b(stack);
			rotate_b(stack);
		}
		return ;
	}
}

void	mid_sort(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	j;

	while (i > 3)
	{
		rotate_min(stack_a, i, 0);
		push_stack_ab(stack_a, stack_b, 'b');
		i--;
	}
	sort_3(stack_a, 0, 0, 0);
	j = get_size_stack(*stack_b);
	while (j--)
		push_stack_ab(stack_a, stack_b, 'a');
}

void	big_sort(t_stack **stack, int max, int min)
{
	int	ret;

	ret = 0;
	while (get_size_stack(stack[1]) > 3)
	{
		ret = div_b(stack, min, max, 0);
		max = max - ret;
	}
	ret = sort_div(stack, min);
	min = sort_a_and_push(stack, ret) + 1;
	if (ft_quick_check(&stack[0]))
		return ;
	max = ft_push_back_b(stack, &min);
	big_sort(stack, max, min);
}
