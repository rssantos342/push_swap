/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:04:27 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/01 12:24:49 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **stack_a, int i)
{
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	if (i == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b, int i)
{
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	if (i == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	ft_printf("rr\n");
}

void	ft_rra(t_stack **stack_a, int i)
{
	t_stack	*temp;

	if (stack_a != NULL)
	{
		temp = *stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *stack_a;
		*stack_a = temp->next;
		temp->next = NULL;
		if (i == 0)
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack **stack_b, int i)
{
	t_stack	*temp;

	if (stack_b != NULL)
	{
		temp = *stack_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *stack_b;
		*stack_b = temp->next;
		temp->next = NULL;
		if (i == 0)
			ft_printf("rrb\n");
	}
}
