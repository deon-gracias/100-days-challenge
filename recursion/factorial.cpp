#include<iostream>

using namespace std;

double factorial(double x) {
    return x <= 1 ? 1 : x * factorial(x - 1);
}


int main() {
    double x,fact;

    cout << "Find factorial of ? ";
    cin >> x;

    cout << "Factorial of " << x << " is " << factorial(x) << endl;

    return 0;
}
