/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:49:24 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/30 01:15:28 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

void	utils_putstr_fd(char *c, int fd)
{
	write(fd, c, utils_strlen(c));
}

size_t	utils_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	utils_dup_check(t_cell **board, int cell_index, int *row_col, int num)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{
			if (row_col[i] != cell_index && (*board)[row_col[i]].nums[j] == num)
				return (1);
		}
	}
	return (0);
}

void	utils_print_board(t_cell **board)
{
	int		i;
	int		j;
	char	*c;

	i = -1;
	while (++i < TOTAL_CELLS)
	{
		j = -1;
		//while (++j < TOTAL_COLS)
		while ((*board)[i].nums[++j])
		{
			c = ft_itoa((*board)[i].nums[j]);
			utils_putstr_fd(c, 1);
			free(c);
		}
		if ((i + 1) % N == 0)
			utils_putstr_fd("\n", 1);
		else
			utils_putstr_fd(" ", 1);
	}
}

void	utils_free_all(t_cell **board, char ***splitted_clues, int **int_clues)
{
	int	i;

	if (*int_clues)
		free(*int_clues);
	if (*board)
		free(*board);
	i = -1;
	while (*splitted_clues && (*splitted_clues)[++i])
		free((*splitted_clues)[i]);
	free(*splitted_clues);
}
