#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll result = 0, max = -1;
    vector<int> data(3002);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            result += data.at(j);
        }

        max = result;

        for (int j = 0; j < n - i - 1; j++) {
            result = result - data.at(j) + data.at(i + j + 1);

            if (max < result) max = result;
        }

        cout << max << endl;
        result = 0;
    }

    return 0;
}