#include "includes/ft_21sh.h"

static int 		ft_redirects(char *cmd, t_cmds **node)
{
	char *tmp;

	if ((tmp = ft_strstr(cmd, " > ")))
	{
		(*node)->r_out = true;
		(*node)->file = ft_strsub(tmp + 3, 0, ft_strlenc(tmp + 3, ' '));
	}
	if ((tmp = ft_strstr(cmd, " < ")))
	{
		(*node)->r_in = true;
		if (!(*node)->file)
			(*node)->file = ft_strsub(tmp + 3, 0, ft_strlenc(tmp + 3, ' '));
		else
			(*node)->file2 = ft_strsub(tmp + 3, 0, ft_strlenc(tmp + 3, ' '));
	}
	if ((tmp = ft_strstr(cmd, " >> ")))
	{
		(*node)->append = true;
		(*node)->file = ft_strsub(tmp + 4, 0, ft_strlenc(tmp + 4, ' '));
	}
	if ((tmp = ft_strstr(cmd, " << ")))
		(*node)->heredoc = true;
	return (1);
}

int				ft_check_redirections(char **cmd, t_cmds **node)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	ft_redirects(*cmd, node);
	tmp2 = *cmd;
	tmp = ft_strchr(*cmd, '<');
	tmp3 = ft_strchr(*cmd, '>');
	if (tmp && tmp3 && (tmp3 < tmp))
		tmp = tmp3;
	else if (!tmp && tmp3)
		tmp = tmp3;
	*cmd = ft_strsub(*cmd, 0, tmp - *cmd); 
	//ft_strdel(tmp);
	return (1);
}

int main()
{
	char *file;
	t_cmds *hd = NULL;
	char *cmd = "ls -a < data > data3";
	char *cmd2 = "ls -l -a >> data2";
	
	ft_add_cmds(&hd, ft_new_cmd(cmd));
	ft_add_cmds(&hd, ft_new_cmd(cmd2));
	ft_execute_cmd(hd);
	while (hd)
	{
		printf("cmd: %s, file: %s, file2: %s,append: %d, input: %d, output: %d\n", hd->cmd[0], 
			hd->file, hd->file2, hd->append, hd->r_in, hd->r_out);
		hd = hd->next;
	}
	
	return (1);
}
