#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

float divideFloat(float a, float b, float c) {
    float divisor = 1;
    while (a >= b * divisor) {
        divisor *= 10;
    }
    while (a < b * divisor) {
        divisor /= 10;
    }
    cout << divisor << endl;
    float res = 0;
    float residual = a;
    while (res * b < a - b * c || res * b > a + b * c) {
        for (int i = 9; i >= 0; i --) {
            if (a >= (res + i * divisor) * b) {
                res += i * divisor;
                break;
            }
        }
        cout << res << endl;
        if (divisor < 10 * numeric_limits<float>::min())
            return res;
        divisor /= 10;
    }
    return res;
}

int main() {
    float a = 1, b = 3, c = 0.01;
    float res = divideFloat(a, b, c);
    cout <<  a << " / " << b << " = " << res << ", with error " << abs(res - a/b) << endl;
    a = 12, b = 7, c = 0.01;
    res = divideFloat(a, b, c);
    cout <<  a << " / " << b << " = " << res << ", with error " << abs(res - a/b) << endl;
    //    cout << numeric_limits<float>::min() << endl;
    a = 245, b = 5, c = 0.01;
    res = divideFloat(a, b, c);
    cout <<  a << " / " << b << " = " << res << ", with error " << abs(res - a/b) << endl;

    return 0;
}
