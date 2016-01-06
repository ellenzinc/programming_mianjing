#include <iostream>
#include <cmath>

using namespace std;

void printCircle(float r) {
    int x0 = (int) r + 1;
    int y0 = (int) r + 1;
    int len = (int)r + x0 + 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int square = (i - x0) * (i - x0) + (j - y0) * (j - y0);
            if (abs(sqrt(square) - r) < 0.1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    printCircle(10);
    return 0;
}
