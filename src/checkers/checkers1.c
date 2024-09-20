/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 16:37:05 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/17 10:05:55 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	fetch_char(char c, int i)
{
	char	stack_id;

	stack_id = c;
	if (i == 1)
	{
		if (c == 'a')
			stack_id = 'b';
		else if (c == 'b')
			stack_id = 'a';
	}
	return (stack_id);
}

int	max(t_ptr *ptr, char c)
{
	t_node	*top;
	int		maximum;
	int		i;

	top = fetch_top(ptr, c);
	i = -1;
	maximum = top->num;
	while (++i < ptr->args)
	{
		if (top->num > maximum)
		{
			maximum = top->num;
		}
		if (top->next != NULL)
			top = top->next;
		else
			break ;
	}
	return (maximum);
}

int	min(t_ptr *ptr, char c)
{
	t_node	*top;
	int		minimum;
	int		i;

	top = fetch_top(ptr, c);
	i = -1;
	minimum = top->num;
	while (++i < ptr->args)
	{
		if (top->num < minimum)
			minimum = top->num;
		if (top->next != NULL)
			top = top->next;
		else
			break ;
	}
	return (minimum);
}

int	count(t_ptr *ptr, char c)
{
	t_node	*top;
	t_node	*temp;
	int		count;

	count = 0;
	top = fetch_top(ptr, c);
	if (top == NULL)
		return (0);
	temp = top->next;
	while (temp != NULL && temp != top)
	{
		count++;
		temp = temp->next;
	}
	count++;
	return (count);
}

bool	ordered(t_ptr *ptr, char c)
{
	t_node	*top;
	int		i;

	top = fetch_top(ptr, c);
	if (top->next == NULL)
		return (true);
	i = 0;
	while (i < max(ptr, c))
	{
		if (top->num > top->next->num)
			if (!(top->num == max(ptr, c) && top->next->num == min(ptr, c)))
				return (false);
		top = top->next;
		i++;
	}
	return (true);
}
