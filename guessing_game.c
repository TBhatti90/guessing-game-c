#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int secret;
	int guess = -1;
	int c;
	char buf[20];
	char input[20];
	time_t t;

	printf("Welcome, would you like to play a guessing game?\n");
	if (fgets(buf, 20, stdin) == NULL)
		return -1;
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	else
		while ((c = getchar()) != EOF && c != '\n')
		;
	if (sscanf(buf, "%s", input) == EOF)
		return -1;

	/* DeMorgan's Law */
	while (!(strcmp(input, "YES") && strcmp(input, "Yes") && strcmp(input, "Y") && strcmp(input, "y")))
	{
		/* Initializes pseudo-random number generator using the current time. */
		srand((unsigned)time(&t));
		secret = rand();

		printf("Please enter your guess: ");
		if (fgets(buf, 20, stdin) == NULL)
			return -1;
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		else
			while ((c = getchar()) != EOF && c != '\n')
				;
		if (sscanf(buf, "%d", &guess) == EOF)
			return -1;

		if (guess == secret)
			printf("You got it! The secret was %d\n", secret);
		else
			printf("Aww you missed.\n");

		printf("Would you like to try again?\n");
		if (fgets(buf, 20, stdin) == NULL)
			return -1;
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		else
			while ((c = getchar()) != EOF && c != '\n')
				;
		if (sscanf(buf, "%s", input) == EOF)
			return -1;
	}

	return 0;
}
