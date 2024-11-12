#include <math.h>
#include "stdbool.h"
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
	for (int i = 0; i < 4; j++) {
		d[k++] = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
	}
}