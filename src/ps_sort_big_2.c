/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:14:33 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/02 13:11:19 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_all_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	while (*stack_b)
	{
		size_a = ft_lstsize_ps(*stack_a);
		if ((*stack_b)->data > ft_max(*stack_a) || \
			(*stack_b)->data < ft_min(*stack_a))
			sort_min_max(stack_a, stack_b, size_a);
		else if ((*stack_b)->data < ft_max(*stack_a) && \
			(*stack_b)->data > ft_min(*stack_a))
			sort_btw_min_max(stack_a, stack_b, size_a);
	}
}

void	sort_min_max(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	int	pos;

	pos = ft_check_pos(*stack_a, ft_min(*stack_a));
	while ((*stack_a)->data != ft_min(*stack_a))
	{
		if (pos > size_a / 2)
			ft_rra(stack_a, 0);
		else
			ft_ra(stack_a, 0);
	}
	ft_pa(stack_a, stack_b);
}

void	sort_btw_min_max(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	t_stack	*temp_a;
	int		pos;
	int		target;

	target = ft_max(*stack_a);
	temp_a = *stack_a;
	while (temp_a != NULL)
	{
		if (target > temp_a->data && temp_a->data > (*stack_b)->data)
			target = temp_a->data;
		temp_a = temp_a->next;
	}
	pos = ft_check_pos(*stack_a, target);
	while ((*stack_a)->data != target)
	{
		if (pos > size_a / 2)
			ft_rra(stack_a, 0);
		else
			ft_ra(stack_a, 0);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_rotate_stack_a(t_stack **stack_a)
{
	int	size_a;
	int	pos;

	pos = ft_check_pos(*stack_a, ft_min(*stack_a));
	size_a = ft_lstsize_ps(*stack_a);
	while ((*stack_a)->data != ft_min(*stack_a))
	{
		if (pos > size_a / 2)
			ft_rra(stack_a, 0);
		else
			ft_ra(stack_a, 0);
	}
}
