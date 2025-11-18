#include <stdio.h>

void acceptRectanglePoints(int* xpoints, int* ypoints)
{
	printf("Write all the x pointers:\n");
	for (int i = 0; i < 4; i++)
	{
		while (scanf_s("%d", &xpoints[i]) != 1)
		{
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
		}
	}

	printf("Write all the y pointers:\n");
	for (int i = 0; i < 4; i++)
	{
		while (scanf_s("%d", &ypoints[i]) != 1)
		{
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
		}
	}

	printf("xpoints are: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", xpoints[i]);
	}
	printf("\n");

	printf("ypoints are: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", ypoints[i]);
	}
	printf("\n");
}