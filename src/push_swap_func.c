/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:01:27 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/28 14:48:32 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_index(t_stack *stack_a, int *arr, int i)
{
	while (stack_a)
	{
		i = 0;
		while (stack_a->nbr != arr[i])
			i++;
		stack_a->ind = i;
		stack_a = stack_a->next;
	}
}

int	check_sort_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	reverse_rotate_a(t_stack **lst)
{
	if (ft_reverse_rotate(lst))
		return ;
	write(1, "rra\n", 4);
}

int	ft_rotate(t_stack **lst)
{
	t_stack	*tmp1;

	if (!(*lst) || (*lst)->next == NULL)
		return (1);
	tmp1 = ft_pop(lst);
	ft_lstadd_back(lst, tmp1);
	return (0);
}

int	push_mid_ind(t_stack **stack, int mid, int ab)
{
	t_stack	**tmp;
	int		i;

	i = 0;
	tmp = stack;
	while ((*tmp))
	{
		if (ab == 0)
		{
			if ((*tmp)->ind < mid)
				return (i);
		}
		else if ((*tmp)->ind > mid)
			return (i);
		i++;
		tmp = &(*tmp)->next;
	}
	return (-1);
}
