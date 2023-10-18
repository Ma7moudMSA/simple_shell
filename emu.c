#include "shell.h"

/**
 * _myex - exit shell
 * @inf: the strduct
 *
 * Return: status
 */

int _myex(info_t *info)
{
	int excheck;

	if (info->argv[1])
	{
		excheck = _erroratoi(info->argv[1]);
		if (excheck == -1)
		{
			info->status = 2;
			p_error(info, "Illegal number: ");
			_eputs(info->ergv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erroratoi(info->argv[1]);
		return (-2);
	}
	info->err_num;
	= -1;
	return (-2);
}

/**
 * _mycurrentdir - chdir
 * @info: argument
 *
 * Return: 0 always
 */

int _mycurrentdir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int changedir;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			changedir = chdir((dir = _getenv(info, "PWD= ")) ? dir : "/");
		else
			changedir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		changedir = chdir((dir = _getenv(info, "OLDPWD= ")) ? dir : "/");
	}
	else
		changedir = chdir(info->argv[1]);
	if (changedir == -1)
	{
		p_error(info, "can't cd to");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD"));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - fn name
 * @info: args
 *
 * Return: always zero
 */

int _help(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
