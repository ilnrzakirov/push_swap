/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:31:56 by bcarlee           #+#    #+#             */
/*   Updated: 2022/01/02 16:34:42 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	div_a(t_stack **stack, int mid)
{
	int	i;
	int	ret;

	i = 0;
	ret = push_mid_ind(&stack[0], mid, 0);
	while (ret > -1)
	{
		while (ret > 0)
		{
			rotate_a(&stack[0]);
			ret--;
		}
		push_stack_ab(&stack[0], &stack[1], 'b');
		i++;
		ret = push_mid_ind(&stack[0], mid, 0);
	}
	return (i);
}

int	div_stack(t_stack **stack, int min, int max)
{
	int	mid;
	int	ret;

	if (!(check_sort_stack(&stack[0])))
		exit (0);
	mid = (min + max) / 2 + 1;
	ret = div_a(stack, mid);
	return (ret -1);
}

int	calc_mid(int min, int max)
{
	if (!((min + max) % 2))
		return (((min + max) / 2) + 1);
	return (((min + max) / 2));
}

int	div_b(t_stack **stack, int min, int max, int i)
{
	int	flag;
	int	ret;
	int	mid;

	mid = calc_mid(min, max);
	flag = stack[0]->flag + 1;
	ret = push_mid_ind(&stack[1], mid, 1);
	while (ret > -1)
	{
		while (ret)
		{
			rotate_b(&stack[1]);
			ret--;
		}
		stack[1]->flag = flag;
		push_stack_ab(&stack[0], &stack[1], 'a');
		i++;
		ret = push_mid_ind(&stack[1], mid, 1);
	}
	return (i);
}

int	sort_div(t_stack **stack, int min)
{
	int	len;

	len = get_size_stack(stack[1]);
	if (len == 2)
	{
		if (stack[1]->ind < stack[1]->next->ind)
		{
			swap_b(&stack[1]);
		}
	}
	else if (len == 3)
		sort_3_b(&stack[1], min);
	return (len);
}
