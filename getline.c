#include "shell.h"

/**
 * siginthandler - blocks CTRL + C
 * @sig_num: number of
 *
 * Return: void
 */
void siginthandler(__attribute__((unused)) int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * input_buf -  buffer
 * @info: struct paramterter
 * @buf: address to the buffer
 * @len: length of the address of the var
 *
 * Return:read of the bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t read = 0;
	size_t len_read = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, siginthandler);
#if USE_GILINE
		read = getline(buf, &len_read, stdin);
#else
		read = _getline(info, buf, &len_read);
#endif
		if (read > 0)
		{
			if ((*buf)[read - 1] == '\n')
			{
				(*buf)[read - 1] = '\0';
				read--;
			}
			info->count_line_flag = 1;
			rmv_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			
			{
				*len = read;
				info->ptr_buf_cmd = buf;
			}
		}
	}
	return (read);
}

/**
 * get_input - get input
 * @info: information
 *
 *Return: read
*/
ssize_t get_input(info_t *info)
{
	static char *buf; 
	static size_t I, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = I;
		p = buf + I;

		checkforchain(info, buf, &j, I, len);
		while (j < len)
		{
			if (ischaining(info, buf, &j))
				break;
			j++;
		}
		I = j + 1;
		if (I >= len)
		{
			I = len = 0;
			info->type_cmd_buf = 0;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (r);
}

/**
 * read_buf - read a buffer
 * @info: information
 * @buf: buffer to read
 * @I: size
 *
 * Return: r;
 */
ssize_t read_buf(info_t *info, char *buf, size_t *I)
{
	ssize_t r = 0;

	if (*I)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	return (r);
}

/**
 * _getline - gets next line
 * @info: the info structure
 * @ptr: the prt structure
 * @length: the length of the
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t I, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (len == I)
		I = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + I, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		_strncat(new_p, buf + I, k - I);
	else
		_strncat(new_p, buf + I, k - I + 1);

	s += k - I;
	I = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
