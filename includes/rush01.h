/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan-wan <ntan-wan@42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:21:51 by ntan-wan          #+#    #+#             */
/*   Updated: 2022/08/27 00:27:02 by ntan-wan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define N 4
# define TOTAL_ROWS N 
# define TOTAL_COLS N 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cell
{
	int	possible_num[N];
} t_cell;

t_cell	*insert_row(void);
void	init_board(t_cell ***board);
void	init_values(t_cell ***board);
int		*atoi_clues(char **splitted_clues);
void	util_print_board(t_cell ***board);
int		*get_cell_indicies_row_index(int row_index, int n);
int		*get_cell_indicies_col_index(int col_index, int n);

/*  */
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
#endif