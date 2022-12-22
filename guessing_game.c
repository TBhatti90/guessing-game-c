#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int secret;
	int guess;
	int countdown;
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

	countdown = 3;

	/* Initializes pseudo-random number generator using the current time. */
	srand((unsigned)time(&t));
	secret = (rand() % 10) + 1;

	/* DeMorgan's Law */
	while (!(strcmp(input, "YES") && strcmp(input, "Yes") && strcmp(input, "yes") && strcmp(input, "Y") && strcmp(input, "y")))
	{

		printf("Please enter your guess from 1 - 10, you have %d tries remaining: ", countdown);
		if (fgets(buf, 20, stdin) == NULL)
			return -1;
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		else
			while ((c = getchar()) != EOF && c != '\n')
				;
		if (sscanf(buf, "%d", &guess) == EOF)
			return -1;

		if (guess < 1 || guess > 10)
		{
			printf("Error, please enter a number from the correct range.\n");
			continue;
		}

		--countdown;

		if (guess == secret)
		{
			printf("You got it! The secret was %d\n", secret);
			/* If user guessed correctly, randomize the new secret value. */
			secret = (rand() % 10) + 1;
			countdown = 3;
		}
		else
		{
			printf("Aww you missed.\n");
			if (countdown <= 0)
			{
				printf("The correct value was %d.\n", secret);
				printf("Thank you very much for playing! Please try again some other time.\n");
				break;
			}
		}

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
