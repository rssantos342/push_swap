/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:47:15 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/02 12:39:22 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error_exit(t_stack *stack_a, int i)
{
	write(2, "Error\n", 6);
	if (i == 0)
		ft_free_list(&stack_a);
	exit(EXIT_FAILURE);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	ft_printf("rrr\n");
}

int	nbr_moves_aux(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
