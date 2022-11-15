#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, pre = -1, index = 0, cnt = 0;
    vector<int> a(100002);
    vector<int> continious(100002);

    cin >> n;  

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    for (int i = 0; i < n; i++) {
        int now = a.at(i);
        if (now != pre) {
            cnt++;
        } else {
            continious.at(index++) = cnt;
            cnt = 1;
        }

        pre = now;
        if (pre != -1 && i == n-1) continious.at(index++) = cnt;
    }

    int ans = -1, tmp = 0;

    if (index < 3) {
        for (int i = 0; i < index; i++) {
            tmp += continious.at(i);
        }
        ans = tmp;
    } else {
        for (int i = 0; i < index-2; i++) {
            tmp = 0;
            tmp = continious.at(i) + continious.at(i+1) + continious.at(i+2);
            if (tmp > ans) ans = tmp;
        }
    }

    cout << ans << endl;


    return 0;

}