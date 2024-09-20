/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 16:42:10 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/13 17:02:22 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	readout_a(double *array)
{
	int	i;

	i = 0;
	while (array[i] == array[i])
	{
		printf("[%f]\n", array[i]);
		i++;
	}
}

void	free_dbl(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free (array[i]);
	free (array);
	array = NULL;
}

bool	array_has_no_dupes(t_ptr *ptr)
{
	int	i;
	int	j;
	int	incidence;

	i = -1;
	while (++i < ptr->args)
	{
		incidence = 0;
		j = -1;
		while (++j < ptr->args)
		{
			if (ptr->array[i] == ptr->array[j])
			{
				incidence++;
				if (incidence == 2)
					return (false);
			}
		}
	}
	return (true);
}

bool	norm_array(t_ptr *ptr)
{
	int		height;
	int		i;
	int		j;

	ptr->norm_array = ft_calloc(ptr->args + 1, sizeof(double));
	if (ptr->norm_array == NULL)
		return (false);
	i = -1;
	while (++i < ptr->args)
	{
		height = 1;
		j = -1;
		while (++j < ptr->args)
		{
			if (ptr->array[i] > ptr->array[j] && j != i)
				height++;
		}
		(ptr->norm_array)[i] = height;
	}
	(ptr->norm_array)[ptr->args] = NAN;
	free(ptr->array);
	ptr->array = NULL;
	return (true);
}
