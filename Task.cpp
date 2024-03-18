#include <iostream>
#include <cmath>
#include <algorithm>

struct Point {
    double x, y;
};


//Func to find square of triangle
double square_of_Triangle(Point A, Point B, Point C) {
    return 0.5 * std::abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)));
}

//Func to find min value
double min(double a, double b, double c) {
    return std::min(std::min(a, b), c);
}

//Func to fin max value
double max(double a, double b, double c) {
    return std::max(std::max(a, b), c);
}

double IntersectionArea(Point A1, Point B1, Point C1, Point A2, Point B2, Point C2) {
    double area1 = square_of_Triangle(A1, B1, C1);
    double area2 = square_of_Triangle(A2, B2, C2);

    double minX1 = min(A1.x, B1.x, C1.x);
    double maxX1 = max(A1.x, B1.x, C1.x);
    double minY1 = min(A1.y, B1.y, C1.y);
    double maxY1 = max(A1.y, B1.y, C1.y);

    double minX2 = min(A2.x, B2.x, C2.x);
    double maxX2 = max(A2.x, B2.x, C2.x);
    double minY2 = min(A2.y, B2.y, C2.y);
    double maxY2 = max(A2.y, B2.y, C2.y);

    double crossMinX = std::max(minX1, minX2);
    double crossMaxX = std::min(maxX1, maxX2);
    double crossMinY = std::max(minY1, minY2);
    double crossMaxY = std::min(maxY1, maxY2);

    double intersectsquare = square_of_Triangle({ crossMinX, crossMinY }, { crossMaxX, crossMinY }, { crossMinX, crossMaxY });

    return intersectsquare;
}

int main() {
    Point A1, B1, C1, A2, B2, C2;
    std::cin >> A1.x >> A1.y >> B1.x >> B1.y >> C1.x >> C1.y >> A2.x >> A2.y >> B2.x >> B2.y >> C2.x >> C2.y;

    double intersectionArea = IntersectionArea(A1, B1, C1, A2, B2, C2);

    std::cout << intersectionArea << std::endl;

    return 0;
}
