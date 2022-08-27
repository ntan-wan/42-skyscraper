/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:01:07 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/27 10:28:52 by ntan-wan         ###   ########.fr       */
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
		putstr_fd(c, 1);
		putstr_fd("|", 1);
	}
	free(c);
}

int	main(int ac, char **av)
{
	//remember to free
	int		*int_clues;
	//remember to free
	char	**splitted_clues;
	//remember to free
	t_cell	**board;
	//remember to free
	//int		*cell_indicies;
	
	splitted_clues = ft_split(av[1], ' ');
	int_clues = atoi_clues(splitted_clues);
	init_board(&board);
	init_values(&board);
	solve_edge_clues(&board, int_clues);
	util_print_board(&board);
	//cell_indicies = get_cell_indices_clue_index(0
	//, N);
	//print_arr(cell_indicies);
	return (0);
}