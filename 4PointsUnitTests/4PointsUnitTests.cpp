#include "pch.h"
#include "CppUnitTest.h"

extern "C" bool is_valid_point(double x, double y);
extern "C" bool is_rectangle(double points[4][2]);
extern "C" void calculate_perimeter_area(double points[4][2], double* perimeter, double* area);
extern "C" double distance(double x1, double y1, double x2, double y2);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverTests
{
    TEST_CLASS(RectangleSolverTests)
    {
    public:

        // Test for the `distance` function
        TEST_METHOD(DistanceCalculation)
        {
            Assert::AreEqual(distance(0, 0, 3, 4), 5.0, L"Distance calculation failed.");
            Assert::AreEqual(distance(1, 1, 4, 5), 5.0, L"Distance calculation failed.");
            Assert::AreEqual(distance(-1, -1, -4, -5), 5.0, L"Distance calculation failed.");
        }

        // Test for `is_rectangle` with valid rectangle points
        TEST_METHOD(ValidRectangle)
        {
            double points[4][2] = {
                {0, 0}, {4, 0}, {4, 3}, {0, 3}
            };
            Assert::IsTrue(is_rectangle(points), L"The points should form a valid rectangle.");
        }

        // Test for `is_rectangle` with invalid rectangle points
        TEST_METHOD(InvalidRectangle)
        {
            double points[4][2] = {
                {0, 0}, {4, 0}, {4, 3}, {2, 2}
            };
            Assert::IsFalse(is_rectangle(points), L"The points should not form a valid rectangle.");
        }

        // Test for `calculate_perimeter_area` with a rectangle
        TEST_METHOD(CalculatePerimeterAndArea)
        {
            double points[4][2] = {
                {0, 0}, {4, 0}, {4, 3}, {0, 3}
            };
            double perimeter = 0, area = 0;
            calculate_perimeter_area(points, &perimeter, &area);

            Assert::AreEqual(perimeter, 14.0, L"Perimeter calculation failed.");
            Assert::AreEqual(area, 12.0, L"Area calculation failed.");
        }

        // Test for `calculate_perimeter_area` with a square
        TEST_METHOD(CalculatePerimeterAndAreaSquare)
        {
            double points[4][2] = {
                {0, 0}, {2, 0}, {2, 2}, {0, 2}
            };
            double perimeter = 0, area = 0;
            calculate_perimeter_area(points, &perimeter, &area);

            Assert::AreEqual(perimeter, 8.0, L"Perimeter calculation for square failed.");
            Assert::AreEqual(area, 4.0, L"Area calculation for square failed.");
        }
    };
}
