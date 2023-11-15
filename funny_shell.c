#include "shell.h"
char **paradise;

/**
 *main - The main function of the funny shell.
 *
 *@banana_count: An integer representing the number.
 *@pineapple: An array of strings representing the bananas.
 *
 *Return: integer representing the exit status of the program.
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
 *displayFruitPrompt - Displays the fruit prompt,
 *indicating the current working directory to the user.
 */
void displayFruitPrompt(void)
{
	char basket[1024];

	if (getcwd(basket, sizeof(basket)) != NULL)
	{
		printf("%s $ ", basket);
	}
	else
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
}

/**
 *parseFruitInput - Parses the user's fruit input
 * into individual fruits (arguments).
 *
 *@mango: A string representing the raw fruit input.
 *@fruits: An array of strings to store the parsed fruits.
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
 *printEnvironment - Prints the paradise environment variables.
 */
void printEnvironment(void)
{
	char **env = paradise;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 *executeCommand - Executes the provided command.
 *
 *@fruits: An array of strings representing
 *the command and its arguments.
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
