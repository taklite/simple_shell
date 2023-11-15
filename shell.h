#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BANANA_PEEL 512
#define DELICIOUS_X X_OK

extern char **paradise;

/**
 * main - The main function of the funny shell.
 *
 * @banana_count: An integer representing the number
 * of bananas (command-line arguments).
 * @pineapple: An array of strings representing the individual bananas.
 *
 * Return: An integer representing the exit status of the program.
 */
int main(int banana_count, char *pineapple[]);

/**
 * displayFruitPrompt - Displays the fruit prompt,
 * indicating the current working directory to the user.
 */
void displayFruitPrompt(void);

/**
 * parseFruitInput - Parses the user's fruit input
 * into individual fruits (arguments).
 *
 * @mango: A string representing the raw fruit input.
 * @fruits: An array of strings to store the parsed fruits.
 */
void parseFruitInput(char *mango, char **fruits);

/**
 * printEnvironment - Prints the paradise environment variables.
 */
void printEnvironment(void);

/**
 * executeCommand - Executes the provided command.
 *
 * @fruits: An array of strings representing the command and its arguments.
 */
void executeCommand(char **fruits);

#endif
