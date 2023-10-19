#include "shell.h"

/**
 * fork_cmd - fork a command
 * @info: the info structure
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				p_error(info, "Permission denied");
		}
	}
}

/**
 * find_cmd - find a command
 * @info: the information
 *
 * Return: the command
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int I, k;

	info->path = info->argv[0];
	if (info->count_line_flag == 1)
	{
		info->count_line++;
		info->count_line_flag = 0;
	}
	for (I = 0, k = 0; info->arg[I]; I++)
		if (!isdelim(info->arg[I], " \t\n"))
			k++;
	if (!k)
		return;
	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interact(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && iscmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			p_error(info, "not found\n");
		}
	}
}
