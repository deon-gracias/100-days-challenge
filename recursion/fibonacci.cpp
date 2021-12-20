#include<iostream>

using namespace std;

int fib(int n) {

    if (n <= 1) return n;

    return fib(n - 2) + fib(n - 1);
}

int main(){

    int n;

    cout << "n = ";
    cin >> n;

    cout << "Fibonacci Sequence : " << endl;

    for (int i = 0; i < n; i++) cout << fib(i) << " ";

    return 0;
}
