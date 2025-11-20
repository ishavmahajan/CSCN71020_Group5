#include <math.h>

void rectangleSideLength(int xpoints[], int ypoints[]) {
	// Calculate the lengths of the sides
	double side1 = sqrt(pow(xpoints[1] - xpoints[0], 2) + pow(ypoints[1] - ypoints[0], 2));
	double side2 = sqrt(pow(xpoints[2] - xpoints[1], 2) + pow(ypoints[2] - ypoints[1], 2));
	double side3 = sqrt(pow(xpoints[3] - xpoints[2], 2) + pow(ypoints[3] - ypoints[2], 2));
	double side4 = sqrt(pow(xpoints[0] - xpoints[3], 2) + pow(ypoints[0] - ypoints[3], 2));

}

void rectangleSidePrint(int side1, int side2, int side3, int side4) {
	printf_s("Side lengths:\n");
	printf_s("Side 1: %.2lf\n", side1);
	printf_s("Side 2: %.2lf\n", side2);
	printf_s("Side 3: %.2lf\n", side3);
	printf_s("Side 4: %.2lf\n", side4);
}

double rectangleArea(double side1, double side2) {
	return side1 * side2;
}

double rectanglePerimeter(double side1, double side2, double side3, double side4) {
	return side1 + side2 + side3 + side4;
}
