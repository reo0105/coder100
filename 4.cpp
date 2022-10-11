#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    long long maxi = -1, sum = 0;
    vector<vector<int>> data(102, vector<int>(102));

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> data.at(i).at(j);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = 0; k < n; k++) {
                sum += max(data.at(k).at(i), data.at(k).at(j));
            }
            if (maxi < sum) maxi = sum;
            sum = 0;
        }
    }

    cout << maxi << endl;

    return 0;
}