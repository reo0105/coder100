/*
「N も (N+1)÷2 も素数」を満たす奇数

N を 2017に似た数 とします。

Q 個のクエリが与えられます。

クエリi(1≦i≦Q) では奇数 li​,ri​ が与えられるので、li​≦x≦ri​ 
かつ 2017に似た数 となる奇数 x の個数を求めてください。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_prime(100002, true);

void Eratosthenes ()
{
    is_prime.at(0) = false;
    is_prime.at(1) = false;

    for (int i = 2; i*i <= 100002; i++) {
        if (is_prime.at(i)) {
            for (int j = i*2; j < 100002; j += i) {
                is_prime.at(j) = false;
            }
        }
    }

}

int main()
{
    int q, l, r, ans  = 0;
    vector<int> x(100002);
    
    cin >> q;

    Eratosthenes();

    for (int i = 0; i < 100002; i++) {
        if (i%2 == 1 && is_prime.at(i) && is_prime.at((i+1)/2)) {
            ans++;
        }
        x.at(i) = ans;
    }

    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << x.at(r) - x.at(l-1) << endl;
    }

    return 0;
}