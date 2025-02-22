/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:39 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/19 12:44:54 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "mlx.h"

typedef struct a_data
{
	char	**heapptr_map;
	int		y_pos;
	int		x_pos;
	int		c_s;
	int		e_x;
	int		mapline_len;
	int		nb_lines;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;
	int		nb_m;
	int		c_s;
	char	**heapptr_map;
	void	*img_p1;
	void	*img_p2;
	void	*img_p3;
	void	*img_p4;
	void	*img_p5;

}	t_game;

void	ft_alloc_map2(t_game *game, char **map);
void	save_position(t_game *game, char **map);
void	check_map_walls(char **map);
void	check_map_walls2(char **map);
void	put_error(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_getline(int fd);
void	rendring_game(char **map);
char	*ft_strchr( const char *str, int c);
char	**reading_map(int fd);
size_t	ft_strlen(const char *str);
int		check_map_chars(char **map, char c);
void	cheaking_map(char **map);
void	save_p_pos(t_data *data, char **map);
void	alloc_map(t_data *data, char **map);
void	path_image(t_game *game);
void	put_to_window(t_game *game, char **map, int x, int y);
void	func_move(int keycode, int x, int y, t_game *game);
char	*ft_itoa(int n);
int		collec_check(t_game *game);
int 	path_is_valid(char	**map, int zo);
int		nb_of_c(char **map);
int		move_player(t_data *data, int y, int x, int i);
void	cheaking_path(t_data *data, int y, int x, int i);
void	ft_free(char **s);
void	extention_checker(char *str);
int		keyhook(int keycode, t_game *game);
void	free_data(t_data *data);
int		func_hook(t_game *game);
void	check_newlines(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	check_xpm(void *s, t_game *game);
void	destroy_game(t_game *game);
void	free_data_map(t_data *data, char **map);

#endif
