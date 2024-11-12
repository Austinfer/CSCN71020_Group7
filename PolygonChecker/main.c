#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rectangleSolver.h"
#include "main.h"
#include "triangleSolver.h"

// Function prototypes
void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
void analyzeTriangle();
void analyzeRectangle();





void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
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