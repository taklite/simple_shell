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
extern char **environ;

char **initializeParadise(void);

int main(int banana_count, char *pineapple[]);

void displayFruitPrompt(void);

void parseFruitInput(char *mango, char **fruits);

void printEnvironment(void);

void executeCommand(char **fruits);

#endif
