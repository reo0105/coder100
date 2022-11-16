#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int h, w, n, sx, sy, tx, ty, nx, ny, ans=0;
    vector<vector<char>> M(1002, vector<char>(1002));
    vector<vector<char>> tmp(1002, vector<char>(1002));
    vector<pair<int, int>> fac(10);

    cin >> h >> w >> n;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> M.at(i).at(j);
            tmp.at(i).at(j) = M.at(i).at(j);
            if (M.at(i).at(j) == 'S') {
                fac.at(0) = make_pair(i, j);
            } else if ('1' <= M.at(i).at(j) && M.at(i).at(j) <= '9') {
                fac.at(M.at(i).at(j) - '0') = make_pair(i, j);
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     cout << fac.at(i).first << " " << fac.at(i).second << endl;
    // }

    for (int i = 0; i < n; i++) {
        sy = fac.at(i).first;
        sx = fac.at(i).second;
        ty = fac.at(i+1).first;
        tx = fac.at(i+1).second;
        vector<vector<int>> dist(1002, vector<int>(1002, -1));
        queue<pair<int, int>> que;

        que.push(make_pair(sy, sx));
        dist.at(sy).at(sx) = 0;
        while(!que.empty()) {
            ny = que.front().first;
            nx = que.front().second;
            que.pop();

            if (nx+1 < w && M.at(ny).at(nx+1) != 'X' && dist.at(ny).at(nx+1) == -1) {
                dist.at(ny).at(nx+1) = dist.at(ny).at(nx) + 1;
                que.push(make_pair(ny, nx+1));
            }

            if (ny+1 < h && M.at(ny+1).at(nx) != 'X' && dist.at(ny+1).at(nx) == -1) {
                dist.at(ny+1).at(nx) = dist.at(ny).at(nx) + 1;
                que.push(make_pair(ny+1, nx));
            }

            if (nx-1 >= 0 && M.at(ny).at(nx-1) != 'X' && dist.at(ny).at(nx-1) == -1) {
                dist.at(ny).at(nx-1) = dist.at(ny).at(nx) + 1;
                que.push(make_pair(ny, nx-1));
            }

            if (ny-1 >= 0 && M.at(ny-1).at(nx) != 'X' && dist.at(ny-1).at(nx) == -1) {
                dist.at(ny-1).at(nx) = dist.at(ny).at(nx) + 1;
                que.push(make_pair(ny-1, nx));
            }

            if (dist.at(ty).at(tx) != -1) {
                ans += dist.at(ty).at(tx);
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        M.at(i).at(j) = tmp.at(i).at(j);
                    }
                }
                break; 
            }
        }
    }

    cout << ans << endl;

    return 0;
}