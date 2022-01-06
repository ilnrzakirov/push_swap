/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:36:14 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/29 11:19:26 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_quicksort_a(t_stack **stack, int max_ind)
{
	if (stack[0]->ind == max_ind + 1)
	{
		stack[0]->flag = -1;
		rotate_a(&stack[0]);
		return (1);
	}
	if (stack[0]->next->ind == max_ind + 1)
	{
		swap_a(&stack[0]);
		stack[0]->flag = -1;
		rotate_a(&stack[0]);
		return (1);
	}
	return (0);
}

int	ft_quick_check(t_stack **stack)
{
	int		ind;
	t_stack	**tracer;

	ind = 0;
	tracer = stack;
	while (*tracer)
	{
		if ((*tracer)->ind == ind)
			ind++;
		else
			return (0);
		tracer = &(*tracer)->next;
	}
	return (1);
}

int	ft_rotate_a(t_stack **stack, int len, int max_ind)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[0]->flag = -1;
		rotate_a(&stack[0]);
		i++;
	}
	while (ft_quicksort_a(stack, max_ind))
		max_ind++;
	return (max_ind);
}

int	ft_check_a(t_stack **stack, int max)
{
	int	i;

	i = 0;
	if (stack[0]->next->ind == max + 1)
	{
		swap_a(&stack[0]);
		i++;
	}
	if (i && stack[0]->next->ind == max + 2)
		i++;
	return (i);
}

int	sort_a_and_push(t_stack **stack, int ret)
{
	int	i;
	int	j;
	int	max_ind;

	i = 0;
	max_ind = stack[1]->ind;
	j = ft_check_a(stack, max_ind);
	while (i < ret)
	{
		push_stack_ab(&stack[0], &stack[1], 'a');
		i++;
	}
	if (ft_quick_check(&stack[0]))
		return (max_ind + j);
	i = ft_rotate_a(stack, ret + j, max_ind + j);
	return (i);
}
