#include <stdio.h>

void acceptRectanglePoints(int* xpoints, int* ypoints)
{
	for (int i = 0; i < 4; i++)
	{
		printf("Enter x for point %d(Integer only): ", i + 1);
		while (scanf_s("%d", &xpoints[i]) != 1)
		{
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');

		printf("Enter y for point %d(Interger only): ", i + 1);
		while (scanf_s("%d", &ypoints[i]) != 1)
		{
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
}