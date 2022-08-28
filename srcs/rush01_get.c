/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:35:12 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/28 22:28:27 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

static void	reverse_indices_arr(int	**arr)
{
	int	start;
	int	end;
	int	temp;
	int	length;

	length = -1;
	while ((*arr)[++length] != -1)
		;
	start = -1;
	end = length;
	while (++start < --end)
	{
		temp = (*arr)[start];
		(*arr)[start] = (*arr)[end];
		(*arr)[end] = temp;
	}
}

int	*get_cell_indices_row_index(int row_index)
{	
	int	i;
	int	*cell_indicies;

	cell_indicies = malloc(sizeof(int) * (N + 1));
	if (!cell_indicies)
		return (NULL);
	cell_indicies[N] = -1;
	i = -1;
	while (++i < TOTAL_COLS)
		cell_indicies[i] = row_index * N + i;
	return (cell_indicies);
}

int	*get_cell_indices_col_index(int col_index)
{	
	int	i;
	int	*cell_indicies;

	cell_indicies = malloc(sizeof(int) * (N + 1));
	if (!cell_indicies)
		return (NULL);
	cell_indicies[N] = -1;
	i = -1;
	while (++i < TOTAL_COLS)
		cell_indicies[i] = col_index + i * N;
	return (cell_indicies);
}

int	*get_cell_indices_clue_index(int clue_index)
{
	int	*cell_indices;

	if (clue_index < N)
		cell_indices = get_cell_indices_col_index(clue_index);
	else if (clue_index >= N && clue_index < 2 * N)
	{
		cell_indices = get_cell_indices_col_index(clue_index - N);
		reverse_indices_arr(&cell_indices);
	}
	else if (clue_index >= 2 * N && clue_index < 3 * N)
		cell_indices = get_cell_indices_row_index(clue_index - (2 * N));
	else if (clue_index >= 3 * N && clue_index < 4 * N)
	{
		cell_indices = get_cell_indices_row_index(clue_index - (3 * N));
		reverse_indices_arr(&cell_indices);
	}
	else
		return (NULL);
	return (cell_indices);
}
