#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			if ((strcmp(result, "Equilateral triangle") == 0) || (strcmp(result, "Isosceles triangle") == 0) || (strcmp(result, "Scalene triangle") == 0)) {
				double angleA = 0, angleB = 0, angleC = 0;
				anglefinder(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angleA, &angleB, &angleC);
				printf_s("Angle A: %.2lf degrees\n", angleA);
				printf_s("Angle B: %.2lf degrees\n", angleB);
				printf_s("Angle C: %.2lf degrees\n", angleC);
			}
			break;
		case 2:
			printf("Rectangle selected.\n");
			int xpoints[4] = { 0,0,0,0 };
			int ypoints[4] = { 0,0,0,0 };
			acceptRectanglePoints( xpoints, ypoints); // validation has been added as well in this. 
			//Do not change the above case 2**************

		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;
	printf_s("Enter number: ");
	if (scanf_s("%d", &shapeChoice) != 1) {
		while (getchar() != '\n');
		return -1; 
	}
	return shapeChoice; 
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++) {
		printf_s("Side %d: ", i + 1);
		if (scanf_s("%d", &triangleSides[i]) != 1) {
			printf_s("Invalid input! Please enter a number.\n");
			while (getchar() != '\n'); // clear invalid input
			triangleSides[i] = 0; // mark invalid
		}
	}
	
	return triangleSides;
}