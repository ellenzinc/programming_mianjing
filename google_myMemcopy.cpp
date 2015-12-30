#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void myMemcpy(void *dest, void *src, size_t n) {
    char *cdest = (char*) dest;
    char *csrc = (char*) src;
    
    bool overlap = false;
    int i = 0;
    char *ptr = cdest;
    for (i = 0; i < n; i++) {
        if (ptr == cdest) {
            overlap = true;
            break;
        }
        ptr++;
    }
    if (!overlap) {
        for (int j = 0; j < n; j++) {
            cdest[j]= csrc[j];
        }
    } else {
        char *temp = new char[n-i];
        for (int j = i; j < n; j++) {
            temp[j-i] = csrc[j];
        }

        for (int j = 0; j < i; j++) {
            cdest[j] = csrc[j];
        }
        for (int j = i; j < n; j++) {
            cdest[j] = temp[j-i];
        }
    }
    
}

int main() {
    char csrc[] = "geeksforgeeks";
    char cdest[100];
    
    myMemcpy(cdest, csrc, strlen(csrc) + 1);
    cout << cdest << endl;

    int isrc[] = {10, 20, 30, 40, 50};
    int n = sizeof(isrc) / sizeof(isrc[0]);
    
    int idest[n];
    
    myMemcpy(idest, isrc, n * sizeof(isrc[0]));

    for (int i = 0; i < n; i++)
        cout << idest[i] << " ";
    cout << endl;

    char test[100] = "geeksforgeeks";
    myMemcpy(test+5, test, strlen(test)+1);
    cout << test << endl;
    return 0;
}
