#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<29

int main()
{
    int n, m, maxi = -1, mini;
    int from, to, time;
    vector<vector<int>> dist(302, vector<int>(302, INF));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> time;
        dist.at(from).at(to) = time;
        dist.at(to).at(from) = time;
    }

    for (int i = 1; i <= n; i++) {
        dist.at(i).at(i) = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist.at(i).at(j) = min(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << dist.at(i).at(j) <<" ";
            if (j == 1 || dist.at(i).at(j) > maxi) maxi = dist.at(i).at(j);
        }
        // cout << endl;
        if (i == 1 || maxi < mini) mini = maxi;
    }

    cout << mini << endl;

    return 0;
}