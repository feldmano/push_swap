/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 21:59:48 by opelman       #+#    #+#                 */
/*   Updated: 2024/09/19 12:09:32 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	populate_quoted(t_ptr *ptr)
{
	int	i;
	int	len;

	len = 0;
	while (ptr->char_array[len])
		len++;
	ptr->args = len;
	ptr->array = ft_calloc(ptr->args + 1, sizeof(double));
	if (ptr->array == NULL)
		return (false);
	i = -1;
	while (ptr->char_array[++i])
	{
		if (ft_isdigit_str(ptr->char_array[i]) == false)
			return (free (ptr->array), false);
		(ptr->array)[i] = ft_atof(ptr->char_array[i]);
		if ((ptr->array)[i] > INT_MAX || (ptr->array)[i] < INT_MIN)
			return (free (ptr->array), false);
	}
	(ptr->array)[len] = NAN;
	return (free_dbl(ptr->char_array), true);
}

bool	populate_un_quoted(t_ptr *ptr, char **argv, int argc)
{
	int	i;

	ptr->args = argc - 1;
	ptr->array = ft_calloc(ptr->args + 1, sizeof(double));
	if (ptr->array == NULL)
		return (false);
	i = -1;
	while (++i < ptr->args)
	{
		if (ft_isdigit_str(argv[i + 1]) == false)
			return (free (ptr->array), false);
		(ptr->array)[i] = ft_atof(argv[i + 1]);
		if ((ptr->array)[i] > INT_MAX || (ptr->array)[i] < INT_MIN)
			return (free (ptr->array), false);
	}
	(ptr->array)[i] = NAN;
	return (true);
}

int	main(int argc, char *argv[])
{
	t_ptr	ptr;

	ptr = (t_ptr){};
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (argc == 2)
	{
		ptr.char_array = ft_split(argv[1], ' ');
		if (ptr.char_array == NULL)
			return (write(2, "Error\n", 6), 1);
		if (populate_quoted(&ptr) == false)
			return (free_dbl(ptr.char_array), write(2, "Error\n", 6), 1);
	}
	else if (argc > 2)
		if (populate_un_quoted(&ptr, argv, argc) == false)
			return (write(2, "Error\n", 6), 1);
	if (array_has_no_dupes(&ptr) == false || norm_array(&ptr) == false)
		return (free (ptr.array), write(2, "Error\n", 6), 1);
	if (sort(&ptr) == false)
		return (free(ptr.norm_array), write(2, "Error\n", 6), 1);
	free(ptr.norm_array);
	return (0);
}
