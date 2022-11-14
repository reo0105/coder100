#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
// typedef long long ll;

int main()
{
    int n, k;
    long long ans = 1e50;
    vector<int> a(15);
    int highest;
    

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }


    for (int i = 1; i < (1<<n); i++) {
        bitset<15> visible(i);
        if (visible.count() != k) continue;

        // cout << i <<" ";
        highest = 0;
        long long cost = 0;
        for (int j = 0; j < n; j++) {
            int hight = a.at(j);
            if (visible.test(j) && hight <= highest) {
                cost += highest + 1 - hight;
                hight = highest + 1;
            }
            highest = max(highest, hight);
        }
        // cout << cost << endl;;
        if (ans > cost) ans = cost;
    }

    cout << ans << endl;
}