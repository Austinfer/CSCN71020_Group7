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
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            d[k++] = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
        }
    }

    double d_max = 0, d_min = d[0];
    for (int i = 0; i < 6; i++) {
        if (d[i] > d_max) d_max = d[i];
        if (d[i] < d_min) d_min = d[i];
    }

    int count_max = 0, count_min = 0;
    for (int i = 0; i < 6; i++) {
        if (d[i] == d_max) count_max++;
        if (d[i] == d_min) count_min++;
    }

    return count_max == 2 && count_min == 4;
}

void calculate_perimeter_area(double points[4][2], double* perimeter, double* area) {
    double side1 = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
    double side2 = distance(points[1][0], points[1][1], points[2][0], points[2][1]);
    *perimeter = 2 * (side1 + side2);
    *area = side1 * side2;
}