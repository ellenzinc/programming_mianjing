//
//  main.cpp
//  kthPoint
//
//  Created by Haining Wang on 1/2/16.
//  Copyright © 2016 usDream. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Point {
    double x;
    double y;
    Point(double xt, double yt): x(xt), y(yt) {}
};

bool operator<(const Point &a, const Point &b) {
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

class KPoint {
public:
    KPoint(int k) {
        K = k;
    }
    
    void push(double x, double y) {
        Point newPoint(x, y);
        if (size < K) {
            topK.push(newPoint);
            size++;
        } else {
            if (newPoint < topK.top()) {
                topK.pop();
                topK.push(newPoint);
            }
        }
    }
    
    void kth_point() {
        cout << "(" << topK.top().x << ", " << topK.top().y << ")" << endl;
    }
    
private:
    priority_queue<Point, vector<Point>> topK;
    int K;
    int size = 0;
};

int main() {
    KPoint kp(5);
    kp.push(2.4, 3.5);
    kp.push(3, 1);
    kp.push(1,1);
    kp.push(2,5);
    kp.push(1,3);
    kp.push(2.0, 1.4);
    kp.kth_point();
    return 0;
}

