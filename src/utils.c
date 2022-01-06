/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:42:24 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/28 14:17:14 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
	{
		*lst = new;
	}
	new -> next = *lst;
	*lst = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list -> nbr = content;
	list -> ind = -1;
	list -> flag = 0;
	list -> next = NULL;
	return (list);
}

int	ft_atoi(const char *s)
{
	int						i;
	int						si;
	long long int			result;

	i = 0;
	si = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			si = -1;
	}
	result = 0;
	while (s[i] >= '0' && s[i] <= '9' )
		result = (result * 10) + (s[i++] - '0');
	result = result * si;
	if (result < -2147483648 || result > 2147483647)
		print_error();
	return (result);
}

char	*ft_substr(char const *str, unsigned int s, size_t l)
{
	size_t	i;
	size_t	k;
	char	*res;

	if (!str)
		return (0);
	if (ft_strlen(str) <= s || s < 0)
		return (ft_strdup(""));
	if (ft_strlen(str) < (s + l))
		l = ft_strlen(str) - s;
	res = malloc((sizeof(char) * (l + 1)));
	if (!res)
		return (NULL);
	k = 0;
	if (s >= 0 && (ft_strlen((char *)str) > s))
	{
		i = s;
		while (str[i] && k < l)
			res[k++] = str[i++];
		res[k] = '\0';
		return (res);
	}
	res[k] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		len;

	len = ft_strlen((char *)s);
	p = (char *)malloc(sizeof(*s) * (len + 1));
	if (p == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		p[len] = s[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}
