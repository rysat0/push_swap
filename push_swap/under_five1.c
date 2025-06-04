/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:52:48 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:52:48 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	sort_two(t_stack *stack_a)
{
	sa(stack_a); //ソート済みパターンは既に除外済み
	return ;
}

static void	sort_three(t_stack *stack_a)
{
	t_node *ref;

	ref = stack_a->top;
	if (ref->value == 0) //一番上が0のパターンは1通りで確定
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (ref->value == 1 && ref->next->value == 0)
		sa(stack_a);
	else if (ref->value == 1 && ref->next->value == 2)
		rra(stack_a);
	else if (ref->value == 2 && ref->next->value == 0)
		ra(stack_a);
	else if (ref->value == 2 && ref->next->value == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

static void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	// 0がトップに来るまでra or ref->prev == 0ならrra
	// 0をpb
	// sort_three_ver4でAスタックを成型
	// 0をpaして終了
	t_node *ref;

	ref = stack_a->top;
	if (ref->value == 0)
		pb(stack_a, stack_b);
	else if (ref->prev->value == 0)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (stack_a->top->value != 0)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three_ver4(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	// 0を一番上までraかrraでもってきてpb
	// 1を一番上までraかrraでもってきてpb
	// sort_three_var5でAスタックを形成
	// pa2回で終了
	if (stack_a->top->next->value == 0)
		ra(stack_a);
	else if (stack_a->top->next->next->value == 0)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (stack_a->top->prev->prev->value == 0)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (stack_a->top->prev->value == 0)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four_ver5(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	under_five_pattern(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}
