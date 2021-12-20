#include<iostream>

using namespace std;

double factorial(double x){
    if (x <= 1) return 1;

    return x * factorial(x - 1);
}

int main() {
    double x,fact;

    cout << "Find factorial of ? ";
    cin >> x;

    cout << "Factorial of " << x << " is " << factorial(x);

    return 0;
}
