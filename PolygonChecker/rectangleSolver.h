#pragma once

bool is_valid_point(double x, double y);
bool is_rectangle(double points[4][2]);
void calculate_perimeter_area(double points[4][2], double* perimeter, double* area);
double distance(double x1, double y1, double x2, double y2);