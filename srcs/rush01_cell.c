/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_cell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 08:51:58 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/30 01:04:42 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

/*void	remove_all_left_one(t_cell **board, int cell_index, int num)
{
	int	i;

	i = -1;
	while (++i < TOTAL_COLS)
	{
		if ((*board)[cell_index].nums[i] != num)
			(*board)[cell_index].nums[i] = 0;
	}
	init_size(board, cell_index);
}*/

//rememeber to free
void	remove_all_left_one(t_cell **board, int cell_index, int num)
{
	int	*new;

	free((*board)[cell_index].nums);
	new = malloc(sizeof(int) * (1 + 1));
	new[0] = num;
	new[1] = 0;
	(*board)[cell_index].nums = new;
}

//remember to free
void	remove_num(t_cell **board, int cell_index, int num)
{
	int	i;
	int	j;
	int	*new;

	i = -1;
	j = 0;
	new = malloc(sizeof(int) * (N - 1 + 1));
	new[N] = 0;
	while (++i < TOTAL_COLS - 1)
	{
		if (++j != num)
			new[i] = j;
		else
			i--;
	}
	(*board)[cell_index].nums = new;
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
				free((*board)[row_col[i]].nums);
				remove_num(board, row_col[i], (*board)[row_col[i]].nums[j]);
				//(*board)[row_col[i]].nums[j] = 0;
				removed++;
			}
		}
		init_size(board, row_col[i]);
	}
	return (removed);
}

/*int	remove_dup_num(t_cell **board, int cell_index, int *row_col, int num)
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
}*/