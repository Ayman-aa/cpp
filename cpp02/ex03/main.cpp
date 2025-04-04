#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    // Test constructors
    Point a;
    Point b(3.0f, 0.0f);
    Point c(1.5f, 3.0f);

    std::cout << "Point a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "Point b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "Point c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;

    // Test copy constructor
    Point d(b);
    std::cout << "Point d (copy of b): (" << d.getX() << ", " << d.getY() << ")" << std::endl;

    // Test assignment operator
    Point e;
    e = c;
    std::cout << "Point e (assigned from c): (" << e.getX() << ", " << e.getY() << ")" << std::endl;

    // Test BSP function
    Point inside(1.0f, 1.0f);
    Point outside(4.0f, 4.0f);
    Point onEdge(0.5f, 1.0f);

    std::cout << "Is " <<inside.getX() <<"," << inside.getY() << " inside the triangle? " << (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;
    std::cout << "Is " <<outside.getX() <<"," << outside.getY() << " inside the triangle? " << (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;
    std::cout << "Is " <<onEdge.getX() <<"," << onEdge.getY() << " inside  the triangle? " << (bsp(a, b, c, onEdge) ? "Yes" : "No") << std::endl;


    return 0;
}