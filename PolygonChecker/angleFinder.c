#include <math.h>
#define PI 3.14159265358979323846

void anglefinder(int side1, int side2, int side3, double* angleA, double* angleB, double* angleC) {
    *angleA = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)) * 180.0 / PI;
    *angleB = acos((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1 * side3)) * 180.0 / PI;
    *angleC = acos((side2 * side2 + side1 * side1 - side3 * side3) / (2.0 * side1 * side2)) * 180.0 / PI;
}
