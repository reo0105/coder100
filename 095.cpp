#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, k;
    ll ans_a, ans_b;

    cin >> a >> b >> k;

    // cout << (b - (k - a)) << endl;
    
    ans_a = (a < k) ? 0 : (a - k);
    ans_b = (a < k) ? (b - (k - a)) : b;

    if (ans_b < 0) ans_b = 0;

    cout << ans_a << " " << ans_b << endl;

    return 0;
}