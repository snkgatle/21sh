#include "includes/ft_21sh.h"

t_cmds				*ft_new_cmd(char *cmd)
{
	t_cmds *new_node;

	if (!(new_node = (t_cmds*)malloc(sizeof(t_cmds))))
		return (NULL);
	new_node->r_out = false;
	new_node->r_in = false;
	new_node->file = NULL;
	new_node->file2 = NULL;
	ft_check_redirections(&cmd, &new_node);
	new_node->cmd = ft_strsplit(cmd, ' ');
	ft_strdel(&cmd);
	new_node->next = NULL;
	return (new_node);
}

int				ft_add_cmds(t_cmds **hd, t_cmds *new_node)
{
	t_cmds *p_cmds;

	p_cmds = *hd;
	if (!*hd)
	{
		if (!(*hd = (t_cmds *)malloc(sizeof(t_cmds))))
			return (0);
		*hd = new_node;
	}
	else
	{
		while (p_cmds->next)
			p_cmds = p_cmds->next;
		p_cmds->next = new_node;
	}
	return (1);
}