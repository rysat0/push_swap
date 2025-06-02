/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:23:53 by rysato            #+#    #+#             */
/*   Updated: 2025/06/02 14:23:53 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int define_chunk_width(t_stack *stack_a, size_t *span)
{
	int quantity;

	quantity = 1;
	if(stack_a->size <= 150 && quantity)
	{
		*span = stack_a->size / 5;
		return(5);
	}
	quantity = ((stack_a->size / 50) + 8);
	*span = stack_a->size / quantity;
	return(quantity);
}

static void push_to_b(t_stack *stack_a, t_stack *stack_b, int span, int chunk_qua)
{
	int low;//該当span範囲内最低ランク
	int high;//該当span範囲内最高ランク
	int index;//今何番目のチャンクを参照しているか
	int pushed;//1index内でBに送った数

	index = 0;
	while(index < chunk_qua)
	{
		pushed = 0;
		low = index * span;
		high = ((index + 1) * span) - 1;
		while(pushed < span && (stack_a->size != 0))
		{
			if(stack_a->top->value >= low && stack_a->top->value <= high)
			{
				pb(stack_a, stack_b);
				pushed++;
				if(stack_b->top->value < ((low + high) / 2))
					rb(stack_b);
			}
			else
				ra(stack_a);
		}
		index++;
	}
}

void chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int span;//1チャンクあたりのランクの幅
	int chunk_qua;//ソートで使用するチャンク総数
	chunk_qua = define_chunk_width(stack_a, &span);
	push_to_b(stack_a, stack_b, span, chunk_qua);
	push_to_a(stack_a, stack_b);
}
