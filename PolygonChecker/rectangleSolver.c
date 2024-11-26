#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"


bool is_valid_point(double x, double y) {
    return true; 
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool is_rectangle(double points[4][2]) {
    double d[6];
    int k = 0;

    // Calculate all pairwise distances
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            d[k++] = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
        }
    }

    // Sort distances
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (d[i] > d[j]) {
                double temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    // Identify sides and diagonals
    double side1 = d[0];
    double side2 = d[2];
    double diagonal = d[4];

    // Check if sides and diagonals match rectangle conditions
    // Use Pythagorean theorem: diagonal^2 == side1^2 + side2^2
    return (d[0] == d[1]) &&      // Two shorter sides are equal
        (d[2] == d[3]) &&      // Two longer sides are equal
        (d[4] == d[5]) &&      // Two diagonals are equal
        (diagonal * diagonal == side1 * side1 + side2 * side2); // Pythagorean theorem
}

void calculate_perimeter_area(double points[4][2], double* perimeter, double* area) {
    double side1 = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
    double side2 = distance(points[1][0], points[1][1], points[2][0], points[2][1]);
    *perimeter = 2 * (side1 + side2);
    *area = side1 * side2;
}