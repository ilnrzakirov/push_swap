/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:42:43 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/29 11:00:00 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	print_error(void)
{
	write(1, "Error", 5);
	exit (0);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*el;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	el = *lst;
	while (el->next)
		el = el->next;
	el->next = new;
}

int	ft_reverse_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*second;

	if (!(*lst) || (*lst)->next == NULL)
		return (1);
	second = *lst;
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	last = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->next = second;
	last->next = NULL;
	return (0);
}

int	ft_push_back_b(t_stack **stack, int *min)
{
	int	max_ind;
	int	flag;

	flag = stack[0]->flag;
	max_ind = stack[0]->ind;
	while (stack[0]->flag == flag && flag != -1)
	{
		if (stack[0]->ind == *min)
			ft_min_rotate(stack, min);
		else if (stack[0]->ind == *min + 1 && stack[0]->next->ind == *min)
			ft_min_plus_rotate(stack, min);
		else
		{
			if (max_ind < stack[0]->ind)
				max_ind = stack[0]->ind;
			push_stack_ab(&stack[0], &stack[1], 'b');
		}
	}
	return (max_ind);
}
