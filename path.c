#include "shell.h"

/**
* iscmd - fn name
* @info: el fehha
* @path: bos ba2a
*
* Return: ua wad
*/

int iscmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
* duplicatechars - fn name
* @pathstring: bs keda
* @s: el feha
* @st: be ba2a
*
* Return: success
*/

char *duplicatechars(char *pathstring, int s, int st)
{
	static char buffer[1024];
	int i = 0, kilo = 0;

	for (kilo = 0, i = s; i < st; i++)
		if (pathstring[i] != ':')
			buffer[kilo++] = pathstring[i];
	buffer[kilo] = 0;
	return (buffer);

}

/**
* find_path - fn name
* @info: arg
* @pathstring: bs keda
* @cmd: el feha
*
* Return: success
*/

char *find_path(info_t *info, char *pathstring, char *cmd)
{
	int i = 0, current_position = 0;
	char *path;

	if (!pathstring)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (iscmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstring[i] || pathstring[i] == ':')
		{
			path = duplicatechars(pathstring, current_position, i);
			if (!path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (iscmd(info, path))
				return (path);
			if (!pathstring[i])
				break;
			current_position = i;
		}
		i++;
	}
	return (NULL);
}
