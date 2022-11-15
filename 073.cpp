/*
二次元グリッドの原点

(0,0) にチェスのナイトの駒があります。

ナイトの駒はマス
(i,j) にあるとき (i+1,j+2) か

(i+2,j+1) のどちらかのマスにのみ動かすことができます。

ナイトの駒をマス

(X,Y) まで移動させる方法は何通りありますか？

10^9+7 で割った余りを求めてください。
*/

#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll modpow(ll a, ll n)
{
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1; 
    }

    return res;
}

int main()
{
    int x, y;
    int w, h;
    ll denominator = 1, numerator = 1;
    vector<vector<ll>> a();

    cin >> x >> y;
    w = (2*x-y) / 3;
    h = (-1*x+2*y) / 3;

    if (w*3 != (2*x-y) || h*3 != (-1*x+2*y) || w < 0 || h < 0) {
        cout << 0 << endl;
    } else {
        for (int i = 1; i <= w; i++) {
            denominator = denominator * i % MOD;
            numerator = numerator * (h+i) % MOD;
        }

        cout << (numerator * modpow(denominator, MOD-2)) % MOD << endl;
    }

    return 0;
}