#include "Point.hpp"

/*
*   following the equation of point p relative to a triangle abc
*   P = A + w1(B - A) + w2(C - A)
*   Px = Ax + w1(Bx - Ax) + w2(Cx - Ax)
*   Py = Ay + w1(By - Ay) + w2(Cy - Ay)
*   w2 = Py - Ay - w1(By - Ay) / (Cy - Ay)
*   Px = Ax + w1(Bx - Ax) + (Py - Ay - w1(By - Ay) / (Cy - Ay))(Cx - Ax)
*   Px(Cy - Ay) = Ax(Cy - Ay) + w1(Bx - Ax)(Cy - Ay) + (Py - Ay - w1(By - Ay))(Cx - Ax)(Cy - Ay)
*   w1(Bx - Ax)(Cy - Ay) - w1(By - Ay)(Cx - Ax)(Cy - Ay) = Px(Cy - Ay) - Ax(Cy - Ay) - (Py - Ay)(Cx - Ax)(Cy - Ay)
*   w1[(Bx - Ax)(Cy - Ay) - (By - Ay)(Cx - Ax)(Cy - Ay)] = Px(Cy - Ay) - Ax(Cy - Ay) - (Py - Ay)(Cx - Ax)(Cy - Ay)
*   w1 = (Px(Cy - Ay) - Ax(Cy - Ay) - (Py - Ay)(Cx - Ax)(Cy - Ay)) / [(Bx - Ax)(Cy - Ay) - (By - Ay)(Cx - Ax)(Cy - Ay)]
*   w2 = Py - Ay - w1(By - Ay) / (Cy - Ay)
*   
*   w1 = calculateDeterminant(point, c, a) / denominator
*   w2 = calculateDeterminant(b, point, a) / denominator
*/

Fixed calculateDeterminant(const Point &p1, const Point &p2, const Point &p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed denominator = calculateDeterminant(b, c, a);
    
    // Calculate barycentric coordinates w1 and w2
    Fixed w1 = calculateDeterminant(point, c, a) / denominator;
    Fixed w2 = calculateDeterminant(b, point, a) / denominator;
    
    // 1 > w2 + w1
    // w3 = w1 + w2
    // 1 - w2 - w1 > 0
    //  w3 > 0
    
    Fixed w3 = Fixed(1) - w1 - w2;
    
    // Check if point is inside the triangle ? No : Yes
    return (w1 > 0) && (w2 > 0) && (w3 > 0);
} 