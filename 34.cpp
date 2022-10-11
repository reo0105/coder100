#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> fibo(46, 1);
    cin >> n;

    for (int i = 2; i <= n; i++) {
        fibo.at(i) = fibo.at(i-1) + fibo.at(i-2);
    }

    cout << fibo.at(n) << endl;

    return 0;
}