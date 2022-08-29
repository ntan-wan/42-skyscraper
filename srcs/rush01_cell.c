/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_cell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 08:51:58 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/29 12:36:01 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

void	remove_all_left_one(t_cell **board, int cell_index, int num)
{
	int	i;

	i = -1;
	while (++i < TOTAL_COLS)
	{
		if ((*board)[cell_index].nums[i] != num)
			(*board)[cell_index].nums[i] = 0;
	}
	init_size(board, cell_index);
}

int	remove_dup_num(t_cell **board, int cell_index, int *row_col, int num)
{
	int	i;
	int	j;
	int	removed;

	i = -1;
	removed = 0;
	while (row_col[++i])
	{
		j = -1;
		while (++j < TOTAL_COLS)
		{
			if (row_col[i] != cell_index && (*board)[row_col[i]].nums[j] == num)
			{
				(*board)[row_col[i]].nums[j] = 0;
				removed++;
			}
		}
		init_size(board, row_col[i]);
	}
	return (removed);
}