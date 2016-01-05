#include <iostream>
#include <cmath>

using namespace std;

int createPalindrome(int val) {
    int n = 0;
    int divisor = 1;
    while (val/divisor) {
        n += 1;
        if (divisor > INT_MAX/10) {
            break;
        }
        divisor *= 10;
    }
    
    int half = (n%2) ? ((n-1)/2) : n/2;
    if (val/divisor == 0)
        divisor /= 10;
    int fromRight = 10;
    int tmp = val;
    for (int i = 0; i < half; i++) {
        val = val - (tmp % fromRight) + (tmp / divisor) * fromRight / 10;
        tmp %= divisor;
        tmp -= (tmp % fromRight);
        divisor /= 10;
        fromRight *= 10;
    }
    return val;
}

int getHalf(int val, int &slowDivisor) {
    //int slowDivisor = 1
    int fastDivisor = 10;
    int res = 0;
    while (val/slowDivisor && val/fastDivisor) {
        res += (val/ slowDivisor % 10) * slowDivisor;
        if (slowDivisor < INT_MAX / 10) {
            slowDivisor *= 10;
        } else {
            break;
        }
        if (fastDivisor < INT_MAX / 100) {
            fastDivisor *= 100;
        } else {
            break;
        }
    }
    
    return val - res;
}

int findPrefix(int val, int n) {
    int half = n / 2;
    return val /(int)pow(10, half);
} 

int reverseInt(int a, int n) {
    int res = 0;
    for (int i = 0; i <n; i++) {
        res = 10 * res + a % 10;
        a/=10;
    }
    return res;
}

int findClosestPalin(int val) {
    int n = 10;
    int divisor = (int) pow(10, 9);
    
    while (val/divisor == 0) {
        divisor /= 10;
        n--;
    }
    int prefix = findPrefix(val, n);
    //cout << prefix << endl;

    //int reverse = reverseInt((n%2) ? /10 : n, n/2);
    
    divisor = (int) pow(10, n/2);
    //    cout << divisor << endl;
    int v1 = prefix * divisor + reverseInt((n%2)?prefix/10 : prefix,n/2);
    int v2 = (prefix+1) * divisor + reverseInt((n%2)?(prefix+1)/10: (prefix+1), n/2);
    int v3 = (prefix-1) * divisor + reverseInt((n%2) ? (prefix-1)/10 : (prefix-1), n/2);

    /*int lowDivisor = 1;
    int prefix = getHalf(val, lowDivisor);
    int prefix1 = (n%2) ? prefix / lowDivisor * lowDivisor : prefix + lowDivisor;
    int prefix2 = (n%2) ? prefix / lowDivisor * lowDivisor : prefix - lowDivisor;
    int v1 = prefix + createPalindrome(prefix);
    int v2 = prefix + lowDivisor + createPalindrome(prefix1);
    int v3 = prefix - lowDivisor + createPalindrome(prefix2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl; */

    int dist1 = abs(v1 - val);
    int dist2 = abs(v2 - val);
    int dist3 = abs(v3 - val);
    int bestDist = min(min(dist1, dist2), dist3);
    //return prefix;
    return dist1 == bestDist ? v1 : (dist2 == bestDist ? v2 : v3);
}

int main() {
    int test1 = 145;
    cout << test1 << " is converted to " << createPalindrome(test1) << endl;
    int test2 = 1252;
    cout << test2 << " is converted to " << createPalindrome(test2) << endl;
    int test3 = INT_MAX;
    cout << test3 << " is converted to " << createPalindrome(test3) << endl;
    int test4 = 0;
    cout << test4 << " is converted to " << createPalindrome(test4) << endl;
    int lowDivisor = 1;
    cout << test1 << "'s prefix is " << getHalf(test1, lowDivisor) << endl;
    lowDivisor = 1;
    cout << test2 << "'s prefix is "<< getHalf(test2, lowDivisor) << endl;
    lowDivisor = 1;
    cout << test3 << "'s prefix is " << getHalf(test3, lowDivisor) << endl;
    lowDivisor = 1;
    cout << test4 << "'s prefix is " << getHalf(test4, lowDivisor) << endl;  

    int test5 = 10000;
    cout << test5 << "'s closest prefix is " << findClosestPalin(test5) << endl;
    cout << test1 << "'s closest prefix is " << findClosestPalin(test1) << endl;
    cout << test2 << "'s closest prefix is " << findClosestPalin(test2) << endl;
    cout << test3 << "'s closest prefix is " << findClosestPalin(test3) << endl;
    cout << test4 << "'s closest prefix is " << findClosestPalin(test4) << endl;
}
