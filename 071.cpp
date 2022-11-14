#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define MOD 1000000007

ll modpow(ll a, ll n)
{
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }

    return ans;
}

int main()
{
    int n, q, from = 1, to, nextfrom;
    ll ans = 0;
    vector<int> a(120002); //, c(120002);
    vector<ll> forward(120002, 0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }


    for (int i = 1; i <= n-1; i++) {
        ll cost = modpow(a.at(i), a.at(i+1));
        forward.at(i) = cost;
    }

    for (int i = 1; i <= n-1; i++) {
        forward.at(i) += forward.at(i-1);
        forward.at(i) %= MOD;
    }

    for (int i = 1; i <= q; i++) {
        cin >> to;
        nextfrom = to;
        if (from > to) swap(to, from); 
        ans += forward.at(to-1) - forward.at(from-1);
        ans = (ans + MOD) % MOD;
        from = nextfrom;
    }

    ans += forward.at(from-1) - forward.at(0);
    ans = (ans + MOD) % MOD;

    cout << ans << endl;

    return 0;
}