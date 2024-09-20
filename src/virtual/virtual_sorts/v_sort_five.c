/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_sort_five.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/01 11:52:02 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 16:49:25 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	v_ordered_to_sorted(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top->num == min(ptr, c))
		return ;
	while (top->num != min(ptr, c))
	{
		if (short_path_to_min(ptr, c) == 1)
			v_rotate(ptr, c);
		else if (short_path_to_min(ptr, c) == -1)
			v_r_rotate(ptr, c);
		top = fetch_top(ptr, c);
	}
}

void	v_sort_three(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top == NULL)
		return ;
	if (ordered(ptr, c) == false)
		v_swap(ptr, c);
	v_ordered_to_sorted(ptr, c);
}

void	v_sort_five(t_ptr *ptr, char c)
{
	t_node	*top;

	if (fetch_top(ptr, c) == NULL)
		return ;
	while (ordered(ptr, c) == false && count(ptr, c) > 3)
	{
		top = fetch_top(ptr, c);
		while (fetch_top(ptr, c)->num != min(ptr, c))
		{
			if (short_path_to_min(ptr, c) == 1)
				v_rotate(ptr, c);
			else if (short_path_to_min(ptr, c) == -1)
				v_r_rotate(ptr, c);
		}
		v_push(ptr, fetch_char(c, 1));
	}
	v_sort_three(ptr, c);
	while (fetch_top(ptr, fetch_char(c, 1)) != NULL)
		v_pull_min_max(ptr, c);
	v_ordered_to_sorted(ptr, c);
}
