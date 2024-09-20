/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_uitils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 22:06:29 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/13 14:53:25 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	initialize(t_ptr *ptr)
{
	int		i;
	t_node	*top;

	ptr->a_top = ft_calloc(1, sizeof(t_node));
	if (ptr->a_top == NULL)
		return (free(ptr->array), false);
	top = ptr->a_top;
	top->num = ptr->norm_array[0];
	i = 0;
	while (++i < ptr->args)
	{
		top->next = ft_calloc(1, sizeof(t_node));
		if (top->next == NULL)
			return (free_stack(ptr, 'a', i), false);
		top->next->prior = top;
		top->next->num = ptr->norm_array[i];
		if (i < ptr->args)
			top = top->next;
	}
	top->next = ptr->a_top;
	ptr->a_top->prior = top;
	return (true);
}

void	free_stack(t_ptr *ptr, char c, int i)
{
	t_node	*top;
	t_node	*next;

	top = fetch_top(ptr, c);
	if (!top)
		return ;
	while (i-- > 0)
	{
		next = top->prior;
		free (top);
		top = next;
	}
	top = NULL;
}

void	readout(t_ptr *ptr, char c)
{
	t_node	*top;
	int		num;
	int		i;

	top = fetch_top(ptr, c);
	if (top == NULL)
	{
		write(1, "[empty]\n", 8);
		return ;
	}
	num = count(ptr, c);
	printf("count:[%d]\n", num);
	i = 0;
	while (i < num)
	{
		ft_printf("[%d][%d]\n", i, top->num);
		if (top->next != NULL)
			top = top->next;
		i++;
	}
	write(1, "\n", 1);
}
