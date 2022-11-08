#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b, count = 1;
    vector<int> p, q, tmp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        tmp.push_back(i);
    }

    do {
        if (tmp == p) a = count;
        if (tmp == q) b = count;
        count++;
    } while(next_permutation(tmp.begin(), tmp.end()));

    cout << abs(a-b) << endl;

    return 0;
}