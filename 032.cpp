#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int h, w, t;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (1) {
        cin >> w >> h;
        if (h == 0 && w == 0) break;

        vector<vector<int>> M_var(30, vector<int>(30, 0));
        vector<vector<int>> M_hor(30, vector<int>(30, 0));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w-1; j++) {
                cin >> M_var.at(i).at(j);
            }

            if (i == h-1) break;

            for (int j = 0; j < w; j++) {
                cin >> M_hor.at(i).at(j);
            }

        }

        queue<pair<int, int>> que;
        vector<vector<int>> dist(30, vector<int>(30, 0));

        que.push(make_pair(0, 0));
        dist.at(0).at(0) = 1;

        while(!que.empty()) {
            int x = que.front().second;
            int y = que.front().first;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx.at(i);
                int ny = y + dy.at(i);
                if (nx < 0 || ny < 0 || ny >= h || nx >= w) continue;

                /*
                    現在いるマスの下と右の壁情報を保持しているから、
                    上と左に移動する場合は移動した先の情報を見る必要がある
                */
                if (dx.at(i) > 0 && M_var.at(y).at(x) == 1) continue;
                if (dx.at(i) < 0 && M_var.at(y).at(nx) == 1) continue;
                if (dy.at(i) > 0 && M_hor.at(y).at(x) == 1) continue;
                if (dy.at(i) < 0 && M_hor.at(ny).at(x) == 1) continue;
                
                if (dist.at(ny).at(nx) == 0) {
                    dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
                    que.push(make_pair(ny, nx));
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << dist.at(i).at(j) << " ";
            }
            cout << endl;
        }

        cout << dist.at(h-1).at(w-1) << endl;
    }

    return 0;

}