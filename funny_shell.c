#include "shell.h"

/**
 * main - Entry point for the shell program
 * @banana_count: Unused parameter (argc)
 * @pineapple: Unused parameter (argv)
 *
 * Return: Always 0
 */
int main(int __attribute__((unused))
		banana_count, char __attribute__((unused)) *pineapple[])
{
	char mango[MAX_BANANA_PEEL];
	char *fruits[MAX_BANANA_PEEL];


	while (1)
	{
		displayFruitPrompt();

		if (fgets(mango, sizeof(mango), stdin) == NULL)
		{
			break;
		}

		mango[strcspn(mango, "\n")] = '\0';

		parseFruitInput(mango, fruits);

		if (fruits[0] != NULL && strcmp(fruits[0], "banana") == 0)
		{
			break;
		}

		if (fruits[0] != NULL && strcmp(fruits[0], "kiwi") == 0)
		{
			printEnvironment();
			continue;
		}

		if (access(fruits[0], DELICIOUS_X) == -1)
		{
			fprintf(stderr, "%s: fruit not found\n", fruits[0]);
			continue;
		}

		executeCommand(fruits);
	}

	return (0);
}

/**
 * initializeParadise - Initializes a new environment for the shell
 *
 * Return: A pointer to the new environment
 */
char **initializeParadise(void)
{
	int size = 0;
	char **new_env;
	int i;

	while (environ[size] != NULL)
	{
		size++;
	}

	new_env = malloc((size + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i <= size; i++)
	{
		new_env[i] = strdup(environ[i]);
		if (new_env[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
	}

	return (new_env);
}

/**
 * parseFruitInput - Parses the input string into an array of fruits
 * @mango: Input string to parse
 * @fruits: Array to store the parsed fruits
 */
void parseFruitInput(char *mango, char **fruits)
{
	char *peel = strtok(mango, " \t\n");
	int i = 1;

	if (peel != NULL)
	{
		fruits[0] = peel;

		while ((peel = strtok(NULL, " \t\n")) != NULL)
		{
			fruits[i] = peel;
			i++;
		}

		fruits[i] = NULL;
	}
	else
	{
		fruits[0] = NULL;
	}
}

/**
 * printEnvironment - Prints the current environment
 */
void printEnvironment(void)
{
	char **paradise = initializeParadise();
	char **env = paradise;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * executeCommand - Executes a command using fork and execvp
 * @fruits: Array of fruits representing the command and its arguments
 */
void executeCommand(char **fruits)
{
	pid_t bite = fork();

	if (bite == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (bite == 0)
	{
		if (execvp(fruits[0], fruits) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(bite, NULL, 0);
	}
}
