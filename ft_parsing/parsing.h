#ifndef RAY_CASTING_42_STRUCTURES_H
#define RAY_CASTING_42_STRUCTURES_H

#ifndef MAX_LINE
#define MAX_LINE 4096
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_parsing
{
    char *north;
    char *south;
    char *west;
    char *east;

    int floor;
    int ceil;

    char *map[MAX_LINE];
    int map_x;
    int map_y;
    char direction;
}t_parsing;

typedef struct s_parsing_helper
{
    int no_found;
    int so_found;
    int ea_found;
    int we_found;
    int c_found;
    int f_found;
    int player_found;
}t_parsing_helper;

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

int         ft_parsing(char *argument, t_parsing *data);
void        ft_free_parsing(int flag, t_parsing *data);
char        **get_file(char *string);
void	    read_and_update_buffer(char **buffer, ssize_t *bytes, int fd,
		        char **new_buffer);
int	        ft_memchr_line(char *s, char c);
char	    *ft_strdup_line(const char *s1, int j);
char	    *get_next_line(int fd);
char	    *ft_strjoin(char *s1, char *s2);
void	    *ft_memcpy(void *dest, const void *src, size_t n);
size_t      ft_strlen(char *str);
char	    *ft_strdup(const char *s1);
int         ft_strcmp(char *s1, char *s2);
char	    *ft_substr(char *str);
char	**ft_split(char const *str, char c);
void    free_buffer(char **buffer, int flag);
char **ft_verify_content(char **file, t_parsing *data);
int ft_verify_data(char **file, t_parsing *data);
int ft_verify_textures(char **buffer, t_parsing *data, t_parsing_helper *helper);
int buffer_counting(char **string);
int ft_verify_floor_ceil(char **buffer, t_parsing *data, t_parsing_helper *helper);
int is_wall(char c);
int is_space(char c);
int is_empty_space(char c);
int is_orientation(char c);
int ft_check_entity(char c);
int ft_verify_map(t_parsing *data);
int ft_normalize_map(t_parsing *data);
#endif