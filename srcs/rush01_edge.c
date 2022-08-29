/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:22:05 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/30 01:11:22 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

static void	edge_clue_min(t_cell **board, int *cell_indices)
{
	//free((*board)[cell_indices[0]].nums);
	remove_all_left_one(board, cell_indices[0], N);
	/*int	j;

	j = -1;
	while (++j < TOTAL_COLS)
	{
		if ((*board)[cell_indices[0]].nums[j] != N)
			(*board)[cell_indices[0]].nums[j] = 0;
	}
	init_size(board, cell_indices[0]);*/
}

static void	edge_clue_mid(t_cell **board, int clue, int *cell_indices)
{
	int	i;
	int	j;
	int	values_to_eliminate;

	i = -1;
	while (cell_indices[++i] != -1)
	{
		j = -1;
		values_to_eliminate = N - clue + 2 + i;
		//free((*board)[cell_indices[i]].nums);
		while (values_to_eliminate <= N)
		{
			remove_num(board, cell_indices[i], values_to_eliminate);
			values_to_eliminate++;
		}
		/*while (++j < TOTAL_COLS)
		{
			if ((*board)[cell_indices[i]].nums[j] >= values_to_eliminate)
				(*board)[cell_indices[i]].nums[j] = 0;
		}*/
		init_size(board, cell_indices[i]);
	}
}

static void	edge_clue_max(t_cell **board, int *cell_indices)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	n = 0;
	while (cell_indices[++i] != -1)
	{	
		n++;
		//free((*board)[cell_indices[i]].nums);
		remove_all_left_one(board, cell_indices[i], n);
		//j = -1;
		//while (++j < TOTAL_COLS)
	//	{
			//if ((*board)[cell_indices[i]].nums[j] != n)
				//(*board)[cell_indices[i]].nums[j] = 0;
		//}
		init_size(board, cell_indices[i]);
	}	
}

void	edge_clues(t_cell **board, int *int_clues)
{
	int	i;
	int	*cell_indices;

	i = -1;
	while (int_clues[++i])
	{
		cell_indices = get_cell_indices_clue_index(i);
		if (int_clues[i] == 1)
			edge_clue_min(board, cell_indices);
		else if (int_clues[i] == N)
			edge_clue_max(board, cell_indices);
		else if (1 < int_clues[i] && int_clues[i] < N)
			edge_clue_mid(board, int_clues[i], cell_indices);
		free(cell_indices);
	}
}
