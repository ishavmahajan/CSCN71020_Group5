#include <math.h>

double RectanglesideLength(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double rectangleArea(double side1, double side2) {
	return side1 * side2;
}

double rectanglePerimeter(double side1, double side2, double side3, double side4) {
	return side1 + side2 + side3 + side4;
}

void printSideLengths(double side1, double side2, double side3, double side4) {
	printf("Side lengths are: \n");
	printf("Side 1: %.2lf\n", side1);
	printf("Side 2: %.2lf\n", side2);
	printf("Side 3: %.2lf\n", side3);
	printf("Side 4: %.2lf\n", side4);
}

double RectangleDiagonalLength(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

char* analyzeRectangle(double side1, double side2, double side3, double side4, double diagonal1, double diagonal2) {
		
	if (side1 == side3 && side2 == side4 && diagonal1 == diagonal2 && (side1 * side1 + side2 * side2 == diagonal1 * diagonal1, 0.001)) {
		return "Valid rectangle"; //also added pythragorean theorem check
	}
	else {
		return "Invalid rectangle";
	}
}

