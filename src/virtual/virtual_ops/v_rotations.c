/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_rotations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 18:09:12 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 09:51:28 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	v_rotate(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top->next == NULL)
		return ;
	if (c == 'a')
		ptr->a_top = top->next;
	else if (c == 'b')
		ptr->b_top = top->next;
	ptr->steps++;
}

void	v_r_rotate(t_ptr *ptr, char c)
{
	t_node	*top;

	top = fetch_top(ptr, c);
	if (top->next == NULL)
		return ;
	if (c == 'a')
		ptr->a_top = top->prior;
	else if (c == 'b')
		ptr->b_top = top->prior;
	ptr->steps++;
}

void	v_rr(t_ptr *ptr)
{
	t_node	*top;

	top = fetch_top(ptr, 'a');
	if (top->next != NULL)
		ptr->a_top = fetch_top(ptr, 'a')->next;
	top = fetch_top(ptr, 'b');
	if (top->next != NULL)
		ptr->b_top = fetch_top(ptr, 'b')->next;
	ptr->steps++;
}

void	v_rrr(t_ptr *ptr)
{
	t_node	*top;

	top = fetch_top(ptr, 'a');
	if (top->next != NULL)
		ptr->a_top = fetch_top(ptr, 'a')->prior;
	top = fetch_top(ptr, 'b');
	if (top->next != NULL)
		ptr->b_top = fetch_top(ptr, 'b')->prior;
	ptr->steps++;
}
