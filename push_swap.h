/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:30:55 by ride-sou          #+#    #+#             */
/*   Updated: 2023/08/08 16:23:48 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	long				data;
	struct s_stack		*next;
}					t_stack;

typedef struct s_info
{
	long	data;
	int		index;
	int		size;
}				t_info;

// push_swap.c
void	ft_ps_args(t_stack *stack_a, t_stack *stack_b, int ac);
t_stack	*ft_split_ac2(t_stack *stack_a, char **av, int flag, int *ac);
void	ft_free_split(char **av);
int		count_ac(char **av);
void	ft_free_split(char **av);
// ps_checks.c
void	ft_check_args(char **av, int flag, int i);
void	ft_check_dup(t_stack *stack_a);
int		ft_check_sorted(t_stack *stack_a);
int		ft_check_pos(t_stack *lst, int target);
void	ft_check_int(t_stack *stack_a);
// ps_others.c
int		ft_error_exit(t_stack *stack_a, int i);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
int		nbr_moves_aux(int b, int a);
int		ft_index_ab_above_0(t_info inf_a, t_info inf_b, int nbr_mvs);
// ps_lists.c
t_stack	*ft_stack_init(char **av, int i);
t_stack	*ft_new_stack(long nbr);
long	ft_long_atoi(const char *str);
void	ft_free_list(t_stack **lst);
int		ft_lstsize_ps(t_stack *lst);
// ps_moves.c
void	ft_sa(t_stack **stack_a, int i);
void	ft_sb(t_stack **stack_b, int i);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
// ps_moves_1.c 
void	ft_ra(t_stack **stack_a, int i);
void	ft_rb(t_stack **stack_b, int i);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a, int i);
void	ft_rrb(t_stack **stack_b, int i);
//ps_sort.c
void	sort_up_to_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	min_four(t_stack **stack_a, t_stack **stack_b, int i);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
// ps_sort_aux.c
int		ft_min(t_stack *lst);
int		ft_max(t_stack *lst);
int		index_min_sa(t_stack **stack_a);
void	min_five(t_stack **stack_a, t_stack **stack_b, int i);
// ps_sort_big.c
void	sort_above_five(t_stack **stack_a, t_stack **stack_b);
t_info	nbr2move_sa(t_stack *stack_a, t_stack *stack_b, t_info inf_ab);
int		ft_min_max(t_stack *stack_b, t_info inf_ab);
int		btw_min_max(t_stack *stack_b, int data_a, t_info inf_ab);
int		nbr_moves(t_info inf_a, t_info inf_b);
// ps_sort_big_1.c
t_info	target_nbr_sb(t_stack *stack_b, int data_a);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, \
				t_info a_nbr2sort, t_info b_target);
void	top_sa_sb(t_stack **stack_a, t_stack **stack_b, \
				t_info a_nbr2sort, t_info b_target);
void	top_sa(t_stack **stack_a, t_info a_nbr2sort);
void	top_sb(t_stack **stack_b, t_info b_target);
// ps_sort_big_2.c
void	put_all_a(t_stack **stack_a, t_stack **stack_b);
void	sort_min_max(t_stack **stack_a, t_stack **stack_b, int size);
void	sort_btw_min_max(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_rotate_stack_a(t_stack **stack_a);

#endif