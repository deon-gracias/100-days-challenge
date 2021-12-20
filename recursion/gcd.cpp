#include<iostream>

using namespace std;

int gcd(int x, int y){
    cout << x << " " << y << endl;

    if (y == 0) return x;

    return gcd(y, x % y);
}

int main() {
    int x, y, res;

    cout << "Enter 2 numbers to find the GCD: ";
    cin >> x >> y;

    res = gcd(x, y)
    cout << "GCD of " << x << " and " << y << " = " << res;

    return 0;
}
