#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

#define PI 3.14159265

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
     else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
     result = "Not a triangle";
    }
    else if (side1 == side2 && side1 == side3) {
     result = "Equilateral triangle";
    }
    else if (side1 == side2 || side1 == side3 || side2 == side3) {
     result = "Isosceles triangle";
    }
    else {
     result = "Scalene triangle";
    }
    return result;
}

void calculateTriangleAngles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3) {
    *angle1 = acos((double)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3)) * 180 / PI;
    *angle2 = acos((double)(side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3)) * 180 / PI;
    *angle3 = 180.0 - *angle1 - *angle2;
}

bool is_valid_triangle(int side1, int side2, int side3) {
    return (side1 > 0 && side2 > 0 && side3 > 0 &&
        side1 + side2 > side3 &&
        side1 + side3 > side2 &&
        side2 + side3 > side1);
}