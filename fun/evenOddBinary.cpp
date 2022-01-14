#include<iostream>
#include<bitset>

using std::cout;
using std::cin;
using std::endl;

bool evenOddBin(int num) {
    std::bitset<32> bnum(num);
    return bnum[0] == 0 ? true : false;
}

int main() {

    int num = 15;

    cout << "Enter a integer : ";
    cin >> num;
    cout << num << (evenOddBin(num) ? " is even." : " is odd.") << endl;

    getchar();

    return 0;
}
