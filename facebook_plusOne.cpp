#include <iostream>

using namespace std;

int plusOne(int val) {
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if (i != 0) 
            mask <<= 1;
        if ((val & mask) == 0) {
            val |= mask;
            return val;
        } else {
            val ^= mask;
        }
    }
    return val;
}

int main() {
    cout << plusOne(INT_MAX) << endl;
    return 0;
}
