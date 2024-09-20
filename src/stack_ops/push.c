/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/07 14:02:46 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 09:53:18 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*fetch_top(t_ptr *ptr, char c)
{
	t_node	*top;

	if (c == 'a')
		top = ptr->a_top;
	if (c == 'b')
		top = ptr->b_top;
	return (top);
}

void	set_top_at_home(t_ptr *ptr, char home, t_node *new_top)
{
	t_node	*top;

	top = fetch_top(ptr, home);
	if (new_top != NULL && new_top->next != NULL && new_top->next != top)
	{
		new_top->prior = top->prior;
		new_top->prior->next = new_top;
	}
	else if (new_top != NULL && new_top->next == top)
	{
		new_top->next = NULL;
		new_top->prior = NULL;
	}
	if (home == 'a' && new_top != NULL)
		ptr->a_top = &(*new_top);
	else if (home == 'a')
		ptr->a_top = NULL;
	if (home == 'b' && new_top != NULL)
		ptr->b_top = &(*new_top);
	else if (home == 'b')
		ptr->b_top = NULL;
}

void	set_top_at_target(t_ptr *ptr, char target, t_node *top)
{
	t_node	*target_top;

	target_top = fetch_top(ptr, target);
	if (target == 'a')
		ptr->a_top = top;
	else if (target == 'b')
		ptr->b_top = top;
	top->next = NULL;
	top->prior = NULL;
	if (target_top != NULL)
	{
		if (target_top->next != NULL)
			top->prior = target_top->prior;
		else
			top->prior = target_top;
		top->prior->next = top;
		target_top->prior = top;
		top->next = target_top;
	}
}

void	push(t_ptr *ptr, char target)
{
	char	home;
	t_node	*top;
	t_node	*target_top;

	home = fetch_char(target, 1);
	top = fetch_top(ptr, home);
	target_top = fetch_top(ptr, target);
	set_top_at_home(ptr, home, top->next);
	set_top_at_target(ptr, target, top);
	if (target == 'a')
		write(1, "pa\n", 3);
	else if (target == 'b')
		write(1, "pb\n", 3);
}
