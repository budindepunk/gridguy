#ifndef GRIDGUY_H
# define GRIDGUY_H

# include <stdio.h>
# include <termios.h>
# include <stdlib.h>
# include <ctype.h>

# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"
# define reset "\e[0m"

int my_getchar(void);
void print_horizontal(int grid_size);
void handle_flag(int flag);
int check_full(int *cells, int grid_size);

#endif