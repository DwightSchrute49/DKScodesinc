#include <stdio.h>
#include <math.h>

// Function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to determine type of triangle
void triangleType(float side1, float side2, float side3) {
    if (side1 == side2 && side2 == side3)
        printf("It is an equilateral triangle.\n");
    else if (side1 == side2 || side1 == side3 || side2 == side3)
        printf("It is an isosceles triangle.\n");
    else
        printf("It is a scalene triangle.\n");
}

// Function to calculate area of triangle using Heron's formula
float triangleArea(float side1, float side2, float side3) {
    float s = (side1 + side2 + side3) / 2; // semi-perimeter
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    
    // Input coordinates
    printf("Enter coordinates of first point (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter coordinates of second point (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter coordinates of third point (x3 y3): ");
    scanf("%f %f", &x3, &y3);
    
    // Calculate distances between points
    float side1 = distance(x1, y1, x2, y2);
    float side2 = distance(x2, y2, x3, y3);
    float side3 = distance(x3, y3, x1, y1);
    
    // Check if triangle is valid
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        printf("These points can form a triangle.\n");
        
        // Determine type of triangle
        triangleType(side1, side2, side3);
        
        // Calculate area of triangle
        float area = triangleArea(side1, side2, side3);
        printf("Area of the triangle: %.2f square units\n", area);
    } else {
        printf("These points cannot form a triangle.\n");
    }
    
    return 0;
}
