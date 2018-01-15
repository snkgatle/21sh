#include "includes/ft_21sh.h"

static size_t   ft_2darray_cnt(char **arr)
{
    size_t cnt;

    cnt = 0;
    if (!arr || !(*arr))
        return (0);
    while (*arr++)
        cnt++;
    return (cnt);
}

static char     *ft_return_path(char **cmd)
{
    char    **tmp;
    char    *tmp_2;
    char    *tmp_3;

    if (!cmd || !(*cmd))
        return (NULL);
    tmp = ft_strsplit(getenv("PATH"), ':');
    if (!ft_2darray_cnt(tmp))
        return (NULL);
    while (*tmp)
    {
        tmp_2 = ft_strjoin(*tmp, "/");
        tmp_3 = ft_strjoin(tmp_2, *cmd);
        printf("Path: %s\n", tmp_3);
        ft_strdel(&tmp_2);
        if (!access(tmp_3, F_OK | X_OK))
        {
            //Free 2d array
            return (tmp_3);
        }
        ft_strdel(&tmp_3);
        tmp = tmp + 1;
    }
    ft_putendl("Error: No such file in path / permission denied\n");
    return (NULL);
}

int             ft_execute_cmd(t_cmds *cmd)
{
    pid_t   pid;
    char    *path;

    //if (ft_builtins(cmd) == 1)
      //  return (1);
    path = ft_return_path(cmd->cmd);
    pid = fork();
    if (path && pid == 0)
    {
        if (execve(path, cmd->cmd, NULL) == -1)
            ft_putendl("Command does not exists or you dont have permission");
    }
    else if (path)
    {
        wait(NULL);
        ft_strdel(&path);
    }
    else
        return (0);
}
