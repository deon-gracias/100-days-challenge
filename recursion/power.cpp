#include<iostream>

using namespace std;

double power(double x, double n) {
    return n == 0 ? 1 : x * power(x, n - 1);
}

int main() {
    double x, y;

    cout << "x = ";
    cin >> x;

    cout << "y = ";
    cin >> y;

    cout << x << " ^ " << y << " = " << power(x, y);

    return 0;
}
