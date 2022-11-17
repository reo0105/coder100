#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> M(92, vector<int>(92, -1));

int dfs(vector<vector<int>> &dist, int y, int x, int cnt, int n, int m)
{
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int res = cnt, t;

    M.at(y).at(x) = 0;

    for (int i = 0; i < 4; i++) {   
        int ny = y + dy.at(i);
        int nx = x + dx.at(i);

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if (dist.at(ny).at(nx) <= dist.at(y).at(x) + 1 && M.at(ny).at(nx) == 1) {
            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            t = dfs(dist, ny, nx, dist.at(ny).at(nx), n, m);
            if (t > res) res = t;
        }
    }

    M.at(y).at(x) = 1;

    return res;
}

int dfs(int y, int x, int cnt, int n, int m)
{
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    M.at(y).at(x) = 0;
    cnt++;
    int res = cnt;

    for (int i = 0; i < 4; i++) {   
        int ny = y + dy.at(i);
        int nx = x + dx.at(i);

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if (M.at(ny).at(nx) == 1) {
            int t = dfs(ny, nx, cnt, n ,m);
            if (t > res) res = t;
        }
    }

    M.at(y).at(x) = 1;

    return res;
}

// int main()
// {
//     int m, n, t, ans = -1;

//     cin >> m >> n;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> M.at(i).at(j);
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (M.at(i).at(j) == 1) {
//                 vector<vector<int>> dist(92, vector<int>(92, -1));
//                 dist.at(i).at(j) = 1;
//                 t = dfs(dist, i, j, 0, n, m);
//                 cout << t << " ";
//                 if (t > ans) ans = t;
//             } else {
//                 cout << 0 << " ";
//             }
//         }
//         cout << endl;
//     }

//     cout << ans << endl;

//     return 0;
// }

int dfs(int y, int x, int cnt, int n, int m)
{
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    M.at(y).at(x) = 0;
    cnt++;
    int res = cnt;

    for (int i = 0; i < 4; i++) {   
        int ny = y + dy.at(i);
        int nx = x + dx.at(i);

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if (M.at(ny).at(nx) == 1) {
            int t = dfs(ny, nx, cnt, n ,m);
            if (t > res) res = t;
        }
    }

    M.at(y).at(x) = 1;

    return res;
}

int main()
{
    int m, n, t, ans = -1;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M.at(i).at(j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M.at(i).at(j) == 1) {
                // vector<vector<int>> dist(92, vector<int>(92, -1));
                // dist.at(i).at(j) = 1;
                t = dfs(i, j, 0, n, m);
                // cout << t << " ";
                if (t > ans) ans = t;
            } else {
                // cout << 0 << " ";/
            }
        }
        // cout << endl;
    }

    cout << ans << endl;

    return 0;
}