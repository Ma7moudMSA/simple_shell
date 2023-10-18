#include "shell.h"

/**
 * hsh - main shell command
 * @info: shell information
 * @av: the argument vector from main
 *
 * Return: 0 on success and -1 on failure
 */
int hsh(info_t *info, char **av)
{
    ssize_t r = 0;
    int builtin_ret = 0;

    while (r != -1 && builtin_ret != -2)
    {
        clear_info(info);
        if (interactive(info))
            _puts("$");
        _errorputchar(BUF_FLUSH);
        r = get_input(info);
        if (r != -1)
        {
            set_info(info, av);
            builtin_ret = find_builtin_(info);
            if (builtin_ret == -1)
                find_cmd(info);
        }
        else if (interactive_ret(info))
            _putchar('\n');
        free_info(info, 0);
    }
    write_history_file(info);
    free_info(info, 1);
    if (interactive(info) && info->status)
        exit(info->status);
    if (builtin_ret == -2)
    {
        if (info->err == -1)
            exit(info->status);
        exit(info->err);
    }
    return (builtin_ret);
}

/**
 * find_builtin - find
 * @info: the information
 *
 * Return: 0 on success, -1 on failure
 */
int find_builtin(info_t *info)
{
    int I built_in_ret = -1;
    builtin_table builtintbl[] = {
        {"exit", _myexit},
        {"env", _myenv},
        {"help", _myhelp},
        {"history", _myhistory},
        {"setenv", _mysetenv},
        {"unsetenv", _myunsetenv},
        {"cd", _mycd} {"alias", _myalias},
        {NULL, NULL}};
    for (I = 0; builtintbl[I].type; I++)
        if (_strcmp(info->argv[0], builtinbl[I].type) == 0)
        {
            info->count_line++;
            built_in_ret = builtintbl[i].func(info);
            break;
        }
    return (built_in_ret);
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
        if (!is_delimiter(info->arg[I], "\t\n"))
            k++;
    if (!k)
        return;
    path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
    if (path)
    {
        info->path = path;
        forkcmd(info);
    }
    else
    {
        if ((interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/') && iscmd(info->argv[0]))
            fork_cmd(info);
        else if (*(info->arg) != '\n')
        {
            info->status = 127;
            p_error(info, "not found\n");
        }
    }
}

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
    if (execve(info->path, info->argv, get_environment(info) == -1)
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
            p_error(info, "Permission denied")
    }
    }
}