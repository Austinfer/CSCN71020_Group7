#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void calculateTriangleAngles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3);
extern "C" bool is_valid_triangle(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleUnitTest
{
    TEST_CLASS(triangleUnitTest)
    {
    public:
        TEST_METHOD(TestAnalyzeTriangle)
        {
            // Invalid triangles
            Assert::AreEqual("Not a triangle", analyzeTriangle(0, 1, 1));
            Assert::AreEqual("Not a triangle", analyzeTriangle(-1, 1, 1));
            Assert::AreEqual("Not a triangle", analyzeTriangle(1, 2, 3));
            Assert::AreEqual("Not a triangle", analyzeTriangle(1, 10, 12));

            // Equilateral triangle
            Assert::AreEqual("Equilateral triangle", analyzeTriangle(5, 5, 5));

            // Isosceles triangle
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(5, 5, 3));
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(3, 5, 5));
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(5, 3, 5));

            // Scalene triangle
            Assert::AreEqual("Scalene triangle", analyzeTriangle(3, 4, 5));
        }

        TEST_METHOD(TestCalculateTriangleAngles)
        {
            double angle1, angle2, angle3;

            // 3-4-5 triangle
            calculateTriangleAngles(3, 4, 5, &angle1, &angle2, &angle3);
            Assert::IsTrue(fabs(angle1 - 36.87) < 0.01);
            Assert::IsTrue(fabs(angle2 - 53.13) < 0.01);
            Assert::IsTrue(fabs(angle3 - 90.00) < 0.01);

            // Equilateral triangle
            calculateTriangleAngles(5, 5, 5, &angle1, &angle2, &angle3);
            Assert::IsTrue(fabs(angle1 - 60.00) < 0.01);
            Assert::IsTrue(fabs(angle2 - 60.00) < 0.01);
            Assert::IsTrue(fabs(angle3 - 60.00) < 0.01);
        }

        TEST_METHOD(TestIsValidTriangle)
        {
            // Valid triangles
            Assert::IsTrue(is_valid_triangle(3, 4, 5));
            Assert::IsTrue(is_valid_triangle(5, 5, 5));
            Assert::IsTrue(is_valid_triangle(5, 5, 3));

            // Invalid triangles
            Assert::IsFalse(is_valid_triangle(1, 2, 3));
            Assert::IsFalse(is_valid_triangle(0, 1, 1));
            Assert::IsFalse(is_valid_triangle(-1, 1, 1));
        }
    };
}