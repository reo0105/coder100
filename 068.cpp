#include <iostream>
#include <vector>
using namespace std;

void Eratosthenes (int n)
{
    vector<bool> isprime(n, true);
    
    isprime.at(0) = false;
    isprime.at(1) = false;

    for (int i = 2; i*i <= n; i++) {
        if (isprime.at(i)) {
            for (int j = 2; i*j <= n; j++) {
                isprime.at(i*j) = false;
            }
        }
    }
}

typedef long long ll;
vector<pair<ll, ll> > prime_factorize(ll n)
{
    vector<pair<ll, ll> > res;

    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;

        int e = 0;
        while(n % p == 0) {
            e++;

            n /= p;
        }

        res.emplace_back(p, e);
    }

    if (n != 1) {
        res.emplace_back(n, 1);
    }

    return res;
}

int main()
{
    int n;
    vector<pair<ll, ll> > res;
    cin >> n;

    res = prime_factorize(n);

    cout << n << ": ";

    for (int j = 0; j < res.size(); j++) {
        for (int i = 0; i < res.at(j).second; i++) {
            cout << res.at(j).first;
            if (i != res.at(j).second-1) cout << " ";
        }
        if (j != res.size()-1) cout << " ";
    }

    cout << endl;

    return 0;
}