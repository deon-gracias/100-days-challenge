#include<iostream>

using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int x, y;

    cout << "Enter 2 numbers to find the GCD: ";
    cin >> x >> y;

    cout << "GCD of " << x << " and " << y << " = " << gcd(x, y);

    return 0;
}
