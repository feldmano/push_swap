/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five_and_three.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/01 11:52:02 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/13 15:01:27 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ordered_to_sorted(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top->num == min(ptr, c))
		return ;
	while (top->num != min(ptr, c))
	{
		if (short_path_to_min(ptr, c) == 1)
			rotate(ptr, c);
		else if (short_path_to_min(ptr, c) == -1)
			r_rotate(ptr, c);
		top = fetch_top(ptr, c);
	}
}

void	sort_three(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top == NULL)
		return ;
	if (ordered(ptr, c) == false)
		swap(ptr, c);
	ordered_to_sorted(ptr, c);
}

void	sort_five(t_ptr *ptr, char c)
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
				rotate(ptr, c);
			else if (short_path_to_min(ptr, c) == -1)
				r_rotate(ptr, c);
		}
		push(ptr, fetch_char(c, 1));
	}
	sort_three(ptr, c);
	while (fetch_top(ptr, fetch_char(c, 1)) != NULL)
		pull_min_max(ptr, c);
	ordered_to_sorted(ptr, c);
}
