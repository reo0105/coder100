#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,  count = 0;
    int ans = 0;
    vector<int> change(100002, 0), data(100002);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> data.at(i);
    }

    change.at(count++) = 1;

    for (int i = 2; i<= n; i++) {
        if (i % 2 == 1) {
            if (data.at(i-1) != data.at(i)) {
                change.at(count++) = i;
            }
        } else {
            if (data.at(i-1) != data.at(i) && count > 1) {
                change.at(--count) = 0;
            }
        }
    }

    change.at(count) = n+1;

    for (int i = 0; i < count; i++) {
        if (i % 2 == 0 && i < count) {
            ans += change.at(i+1) - change.at(i);
        }
    }

    // cout << ans << " " << count << endl;

    if ((count % 2 == 0 && data.at(n) == 1) || (count % 2 == 1 && data.at(n) == 0)) {
        cout << ans << endl;
    } else {
        cout << n - ans << endl;
    }

    return 0;
}