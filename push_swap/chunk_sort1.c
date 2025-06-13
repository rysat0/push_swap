/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/06/04 16:53:53 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:53:53 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	define_chunk_width(t_stack *stack_a, int *span)
{
	int quantity;

	quantity = 1;
	if (stack_a->size <= 150 && quantity)
		quantity = 5;
	else
		quantity = 9;
	*span = ((stack_a->size + quantity - 1) / quantity);
	if (*span == 0)
		*span = 1;
	return (quantity);
}

int	search_shortest_a(t_stack *stack_a, int low, int high)
{
	int ra_idx;
	int rra_idx;
	t_node *ref;

	ra_idx = 0;
	rra_idx = 0;
	ref = stack_a->top;
	while (!(ref->value >= low && ref->value <= high))
	{
		ra_idx++;
		ref = ref->next;
	}
	ref = stack_a->top;
	while (!(ref->value >= low && ref->value <= high))
	{
		rra_idx++;
		ref = ref->prev;
	}
	if (ra_idx <= rra_idx)
		return (ra_idx);
	return (-(rra_idx));
}
void	rotate_a(t_stack *stack_a, int low, int span)
{
	int times;
	times = search_shortest_a(stack_a, low, low + span - 1);
	if (times > 0)
	{
		ra(stack_a);
		times--;
	}
	else if (times < 0)
	{
		rra(stack_a);
		times++;
	}
	return ;
}

void	push_to_b(t_stack *a, t_stack *b, int span, int k)
{
	int idx;    /* 1 */
	int pushed; /* 2 */
	int goal;   /* 3 */

	for (idx = 0; idx < k && a->size; idx++)
	{
		goal = span;
		if (idx == k - 1) /* 最後は残り全部 */
			goal = a->size;
		pushed = 0;
		while (pushed < goal && a->size)
		{
			if (is_in_chunk(a->top->value, idx * span, span))
			{
				pb(a, b);
				pushed++;
				if (b->size > 1 && b->top->value <= idx * span + span / 3)
					rb(b);
			}
			else
				rotate_a(a, idx * span, span);
		}
	}
}

// static void	push_to_b(t_stack *stack_a, t_stack *stack_b, int span,
// 		int chunk_qua)
// {
// 	int low;    //該当span範囲内最低ランク
// 	int high;   //該当span範囲内最高ランク
// 	int index;  //今何番目のチャンクを参照しているか
// 	int pushed; // 1index内でBに送った数

// 	index = 0;
// 	while (index <= chunk_qua)
// 	{
// 		pushed = 0;
// 		low = index * span;
// 		high = ((index + 1) * span) - 1;
// 		while (pushed < span && (stack_a->size != 0))
// 		{
// 			if (stack_a->top->value >= low && stack_a->top->value <= high)
// 			{
// 				pb(stack_a, stack_b);
// 				pushed++;
// 				if (stack_b->top->value < ((low + high) / 2))
// 					rb(stack_b);
// 			}
// 			else
// 				// rotate_a(stack_a, search_shortest_a(stack_a, low, high));
// 				ra(stack_a);//ここ
// 		}
// 		index++;
// 	}
// }

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int span;      // 1チャンクあたりのランクの幅
	int chunk_qua; //ソートで使用するチャンク総数
	chunk_qua = define_chunk_width(stack_a, &span);
	push_to_b(stack_a, stack_b, span, chunk_qua);
	push_to_a(stack_a, stack_b);
}
