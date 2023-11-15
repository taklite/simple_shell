#include "shell.h"

#define MAX_PATH 1024

/**
 * displayFruitPrompt - Displays the prompt for the shell
 *	The prompt includes the current working directory.
 */
void displayFruitPrompt(void)
{
	char basket[MAX_PATH];

	if (getcwd(basket, sizeof(basket)) != NULL)
	{
		printf("%s $ ", basket);
	}
	else
	{
		perror("getcwd");
	}
}
