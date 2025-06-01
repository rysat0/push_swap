/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:31:33 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 22:05:41 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_copy(t_stack *stack)
{
	int		*array;
	ssize_t	i;
	t_node	*ref;

	i = 0;
	array = malloc(sizeof(int) * stack->size);
	if (array == NULL)
		return (NULL);
	ref = stack->top;
	while (i < stack->size)
	{
		array[i] = ref->value;
		ref = ref->next;
		i++;
	}
	return (array);
}

int	sort_and_dupli_check(int *array, t_stack *stack)
{
	ssize_t	i;
	ssize_t	j;
	int		tmp;

	i = 0;
	tmp = 0;
	while (i < stack->size)
	{
		j = i;
		while (j > 0 && array[j] < array[j - 1])
		{
			tmp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = tmp;
			j--;
		}
		if (array[j] == array[j - 1])
			return (-1);
		i++;
	}
	return (0);
}

ssize_t	search_rank(int value, int *array)
{
	ssize_t	rank;

	rank = 0;
	while (value != array[rank])
		rank++;
	return (rank);
}
void	change_to_rank(t_stack *stack, const int *array)
{
	ssize_t	i;
	t_node	*ref;

	ref = stack->top;
	i = 0;
	while (i < stack->size)
	{
		ref->value = search_rank(ref->value, array);
		i++;
		ref = ref->next;
	}
}

void	make_rank(t_stack *stack)
{
	int	*array;

	array = array_copy(stack);
	if (array == NULL)
	{
		put_error_invalid(stack);
		return ;
	}
	if (sort_and_dupli_check(array, stack) == -1)
	{
		put_error_invalid(stack);
		return ;
	}
	change_to_rank(stack, array);
	//もとの配列free
	return ;
}

int	fill_stack_a(int argc, char **argv, t_stack *stack)
{
	ssize_t		i;
	ssize_t	tmp;
	t_node		*target;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atol(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (put_error_invalid(stack), -1); //エラー処理でstackfreeしたい
		target = make_new_node((int)tmp);
		if (target == NULL)
			return (put_error_invalid(stack), -1); //エラー処理でstackfreeしたい
		push_first(stack, target);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a->top = fill_array(argc, argv);
	make_rank(stack_a);
}
//コマンドライン引数でint配列受取(long)
//引数なしエラー処理(argc == 1)
//双方向循環リストとスタックをまとめる構造体を定義
// Aスタックのリストに先頭から数値を入れていく
//順位付け（座標圧縮）
//圧縮用の配列(malloc)にAリストコピー
//自力で一旦圧縮用配列を昇順でソート ここでの並び方は頭からランクになる
//ここで重複値,int範囲外チェックエラーならfreeしてエラー出す
//元の数値を渡したらランクを返す関数を作成(二分探索)
// Aスタックのリストに入っている数値をすべてランクに置換
//圧縮用の配列はfree<-----------------------------------いまここ
// swap動作関数をそれぞれ定義,出力と操作を同時に行うように
//ブール型でis_sorted関数を作成
//この段階（初期）でのAランクリストの要素数(サイズ)が5個以下なら特別パターンで最短ソート
//要素数が6以上ならチャンクソート開始
//チャンク幅決定
// Aの先頭を見て、決めたチャンク幅内の数値であればpbでBの先頭に送る
// Aの先頭を見て、チャンク範囲外であればraで一旦後回し
// pbしたあと、送った数値がチャンクの中央値以下であればrb実行でBを軽い降順にしておく
//最初のチャンク幅の数値をすべてBに送り終わったら次のチャンク幅を考える
// Aが空になるとき、Bは完璧ではないが軽い降順になっている
//ランクの最大値をBから探し、最短手順(rbかrrb)で先頭に持ってきて、paでAに送る
//次に大きい値をBから探し、最短手順で先頭に回し、Aに送る
//これをBが空になるまで行うと自動的に昇順でAが完成する
