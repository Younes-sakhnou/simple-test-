#include "shellix.h"

void env_arguments(char **args);

/**
 * _getenv - Get the value of an environment variable.
 * @variable_name: Pointer to a null-terminated string representing
 * the name of the environment variable.
 *
 * Return: NULL pointer.
 */
char *_getenv(char *variable_name)
{
	int i;
	size_t name_length = _strlen(variable_name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], variable_name, name_length) == 0
			&& environ[i][name_length] == '=')
		{
			return (environ[i] + name_length + 1);
		}
	}

	return (NULL);
}

/**
 * env_arguments - Print environment variables.
 * @args: Double pointer to an array of strings containing arguments.
 *
 * Return: void.
 */
void env_arguments(char **args)
{
	char **env, *str;
	ssize_t y;

	(void) y;
	if (args[1] != NULL)
	{
		str = "env: ‘";
		y = write(STDERR_FILENO, str, _strlen(str));
		y = write(STDERR_FILENO, args[1], _strlen(args[1]));
		str = "’: No such file directory\n";
		y = write(STDERR_FILENO, str, _strlen(str));
	}
	else
	{
		env = environ;
		while (*env)
		{
			y = write(1, *env, _strlen(*env));
			y = write(1, "\n", 2);
			env++;
		}
	}
}
