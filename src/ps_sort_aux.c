/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:04:48 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/02 16:54:45 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min(t_stack *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	ft_max(t_stack *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	index_min_sa(t_stack **stack_a)
{
	t_stack	*temp;
	int		i;
	int		min_stack;

	i = 0;
	temp = *stack_a;
	min_stack = ft_min(*stack_a);
	while (temp->data != min_stack)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	min_five(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i <= 2)
		min_four(stack_a, stack_b, i);
	else if (i == 3)
	{
		ft_rra(stack_a, 0);
		ft_rra(stack_a, 0);
		if (ft_check_sorted(*stack_a))
			return ;
		ft_pb(stack_a, stack_b);
	}
	else if (i == 4)
	{
		ft_rra(stack_a, 0);
		if (ft_check_sorted(*stack_a))
			return ;
		ft_pb(stack_a, stack_b);
	}
}
