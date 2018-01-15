#ifndef FT_21sh_H
# define FT_21sh_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct	s_cmds
{
	char		**cmd;
	bool		r_out;
	bool		r_in;
	bool		start;
	bool		append;
	bool		heredoc;
	char		*file;
	char		*file2;
	int			fildes[2];
	struct s_cmds *next;
}				t_cmds;

typedef struct	s_red
{
	char		*tmp;
	int			res;
}				t_red;
int				ft_check_redirections(char **cmd, t_cmds **node);
t_cmds			*ft_new_cmd(char *cmd);
int				ft_add_cmds(t_cmds **hd, t_cmds *new_node);

#endif