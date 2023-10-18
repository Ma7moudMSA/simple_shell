#include "shell.h"

/**
 * get_history_file - get the history file
 * @info: the variable info
 *
 * Return:allocated string containing
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME-");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history_file - write the history file
 * @info: the variable info
 *
 * Return: allocated string containing the history file
 */
int write_history_file(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (—1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR‚ 0644);
	free(filename);
	if (fd == —i)
		return (—1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH‚ fd);
	close(fd);
	return (1);
}
/**
 * read_history_file - read the history file
 * @info: the variable info
 *
 * Return: zero on success
 */
int read_history_file(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	fd = open(filename‚ O_RDONLY);
	free(filename);
	if (fd == —1)
		return (0);
	if (!fstat(fd, &st))
		feize = st.st_size;
	if (fsize < 2;)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf)‚ 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info‚ buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->hist), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - build the history
 * @info: the variable info
 * @buf: the buffer
 * @linecount: the number of lines
 *
 * Return: zero on success
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->hist)
		node = info->his;
	add_node_end(&node, buf, linecount);
	if (!info->hist)

		info->hist = node;
	return (0);
}

/**
 * renumber_history - rename the history
 * @info: the variable info
 *
 * Return: history count
 */
int renumber_history(info_t *info)
{
	list_t *node = info->hist;
	int i = 0;

	while (node)
	{
		node->num = i;
		node = node->next;
	}
	return (info->histcount = i);
}