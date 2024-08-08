#include "Point.hpp"

static Fixed calculateDeterminant(const Point &p1, const Point &p2, const Point &p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed denominator = calculateDeterminant(b, c, a);
    
    // Calculate barycentric coordinates w1 and w2
    Fixed w1 = calculateDeterminant(point, c, a) / denominator;
    Fixed w2 = calculateDeterminant(b, point, a) / denominator;
    
    // Calculate w3 which is 1 - w1 - w2
    Fixed w3 = Fixed(1) - w1 - w2;
    
    // Check if point is inside the triangle
    return (w1 > 0) && (w2 > 0) && (w3 > 0);
}
