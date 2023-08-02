/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:12:19 by ride-sou          #+#    #+#             */
/*   Updated: 2023/07/31 15:06:01 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_init(char **av, int i)
{
	t_stack	*stack_a;
	t_stack	*head_a;

	head_a = NULL;
	stack_a = ft_new_stack(ft_atoi_mod(av[i]));
	head_a = stack_a;
	i++;
	while (av[i])
	{
		stack_a->next = ft_new_stack(ft_atoi_mod(av[i]));
		stack_a = stack_a->next;
		i++;
	}
	return (head_a);
}

t_stack	*ft_new_stack(long nbr)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = nbr;
	node->next = NULL;
	return (node);
}

long	ft_atoi_mod(const char *str)
{
	int			sign;
	long int	nbr;
	int			i;

	sign = 1;
	nbr = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (sign * nbr);
}

void	ft_free_list(t_stack **lst)
{
	t_stack	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

int	ft_lstsize_ps(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
