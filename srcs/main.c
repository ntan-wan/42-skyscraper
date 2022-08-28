/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:01:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/28 22:14:44 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"


void	print_arr(int *arr)
{
	int		i;;
	char	*c;

	if (!arr)
		return ;
	i = -1;
	while (++i < N)
	//while (arr[++i] != -1)
	//while (arr[++i])
	{
		c = ft_itoa(arr[i]);
		utils_putstr_fd(c, 1);
		utils_putstr_fd("|", 1);
	}
	free(c);
}

int	*atoi_clues(char **splitted_clues)
{
	int	i;
	int	*int_clues;

	int_clues = malloc(sizeof(int) * (TOTAL_CELLS + 1));
	i = -1;
	while (splitted_clues[++i])
		int_clues[i] = ft_atoi(splitted_clues[i]);
	int_clues[TOTAL_CELLS] = 0;
	return (int_clues);
}

int	main(int ac, char **av)
{
	//remember to free
	int		*int_clues;
	//remember to free
	char	**splitted_clues;
	//remember to free
	t_cell	*board;
	//remember to free
	
	splitted_clues = ft_split(av[1], ' ');
	int_clues = atoi_clues(splitted_clues);
	init_board(&board);
	init_values(&board);
	edge_clues(&board, int_clues);
	propagate_constraint(&board);
	//int arr[4] = {0,1,2,3};
	//printf("%d\n", duplicate_check(&board, arr, 4, 3));
	process_elimination(&board);
	util_print_board(&board);
	//cell_indicies = get_cell_indices_clue_index(0
	//, N);
	//print_arr(cell_indicies);
	return (0);
}