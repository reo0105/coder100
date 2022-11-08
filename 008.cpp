#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n, idx_in, idx_out;
    vector<ll> a(32), b(32);
    ll in, out, tmp = 0, mini = 1L << 59, sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in = a.at(i);
            out = b.at(j);
            sum = 0;
            for (int k = 0; k < n; k++) {
                tmp = abs(in - a.at(k)) + abs(a.at(k) - b.at(k)) + abs(out - b.at(k));
                sum += tmp;
            }
            if (mini > sum) {
                mini = sum;
                // idx_in = i;
                // idx_out = j;
            }
        }
    }

    cout << mini << endl;

    return 0;
}