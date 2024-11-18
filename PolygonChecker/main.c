#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rectangleSolver.h"
#include "main.h"
#include "triangleSolver.h"
#define _CRT_SECURE_NO_WARNINGS


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
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

void analyzeTriangleFlow() {  // Renamed to avoid conflict
    int triangleSides[3];
    getTriangleSides(triangleSides);

    char* result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]); // Correct function call
    printf("%s\n", result);

    if (is_valid_triangle(triangleSides[0], triangleSides[1], triangleSides[2])) {
        double angle1, angle2, angle3;
        calculateTriangleAngles(triangleSides[0], triangleSides[1], triangleSides[2], &angle1, &angle2, &angle3);
        printf("The angles of the triangle are: %.2f, %.2f, %.2f\n", angle1, angle2, angle3);
    }
}


void analyzeRectangle() {
    double points[4][2];
    for (int i = 0; i < 4; i++) {
        printf("Enter x coordinate of point %d: ", i + 1);
        scanf_s("%lf", &points[i][0]);
        printf_s("Enter y coordinate of point %d: ", i + 1);
        scanf_s("%lf", &points[i][1]);
    }

    if (!is_rectangle(points)) {
        printf("The given points do not form a rectangle.\n");
        return;
    }

    double perimeter, area;
    calculate_perimeter_area(points, &perimeter, &area);
    printf("The perimeter of the rectangle is: %.2f\n", perimeter);
    printf("The area of the rectangle is: %.2f\n", area);
}
int main() {
    bool continueProgram = true;
    printWelcome();
    while (continueProgram) {
        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            analyzeTriangleFlow(); 
            break;
        case 2:
            analyzeRectangle();
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf("Invalid value entered.\n");
            break;
        }
    }

    return 0;
}