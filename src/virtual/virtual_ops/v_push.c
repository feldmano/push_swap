/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v_push.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/07 14:02:46 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 09:53:02 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	v_push(t_ptr *ptr, char target)
{
	char	home;
	t_node	*top;
	t_node	*target_top;

	home = fetch_char(target, 1);
	top = fetch_top(ptr, home);
	target_top = fetch_top(ptr, target);
	set_top_at_home(ptr, home, top->next);
	set_top_at_target(ptr, target, top);
	ptr->steps++;
}
