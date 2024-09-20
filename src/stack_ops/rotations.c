/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 18:09:12 by opelman       #+#    #+#                 */
/*   Updated: 2024/08/23 16:24:19 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top->next == NULL)
		return ;
	if (c == 'a')
	{
		ptr->a_top = top->next;
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		ptr->b_top = top->next;
		write(1, "rb\n", 3);
	}
}

void	r_rotate(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top->next == NULL)
		return ;
	if (c == 'a')
	{
		ptr->a_top = top->prior;
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		ptr->b_top = top->prior;
		write(1, "rrb\n", 4);
	}
}

void	rr(t_ptr *ptr)
{
	t_node	*top;

	top = fetch_top(ptr, 'a');
	if (top->next != NULL)
		ptr->a_top = fetch_top(ptr, 'a')->next;
	top = fetch_top(ptr, 'b');
	if (top->next != NULL)
		ptr->b_top = fetch_top(ptr, 'b')->next;
	write(1, "rr\n", 3);
}

void	rrr(t_ptr *ptr)
{
	t_node	*top;

	top = fetch_top(ptr, 'a');
	if (top->next != NULL)
		ptr->a_top = fetch_top(ptr, 'a')->prior;
	top = fetch_top(ptr, 'b');
	if (top->next != NULL)
		ptr->b_top = fetch_top(ptr, 'b')->prior;
	write(1, "rrr\n", 4);
}
