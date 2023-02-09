#include<iostream>
using namespace std;

void swap2(int *a, int *b) {
    int r = *a; // r refer to number a
    *a = *b; // address refer to number of b
    *b = r; // address of b refer to r (which is int)
}

int main() {
    int x = 4;
    int y = 5;
    swap2(&x, &y);
    cout << x << " " << y << endl;
    return 0;
}