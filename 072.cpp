#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll pow_mod(ll x, ll n, ll mod)
{
    ll res = 1;
    while(n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }

    return res;
}

int main()
{
    int w, h, modi = 1000000007;
    long long denominator = 1, numerator = 1;

    cin >> w >> h;

    for (int i = 1; i < w; i++) {
        denominator = (denominator * i) % modi;
        numerator = (numerator * (h + i - 1)) % modi;
    }

    cout << (numerator * pow_mod(denominator, modi - 2, modi)) % modi << endl;

    return 0;
}

