#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    } 
};

double cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y)
}
