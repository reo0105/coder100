#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int h, w, cnt = 0;
    vector<vector<char>> M(52, vector<char>(52));
    queue<pair<int, int>> que;
    vector<vector<int>> dist(52, vector<int>(52, -1));
    vector<vector<int>> prev_x(52, vector<int>(52, -1));
    vector<vector<int>> prev_y(52, vector<int>(52, -1));
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> M.at(i).at(j);
        }
    }

    que.push(make_pair(0, 0));
    dist.at(0).at(0) = 0;

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy.at(i);
            int nx = x + dx.at(i);

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

            if (M.at(ny).at(nx) == '.' && dist.at(ny).at(nx) == -1) {
                dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
                que.push(make_pair(ny, nx));
                prev_x.at(ny).at(nx) = x;
                prev_y.at(ny).at(nx) = y;
            }
        }
    }

    if (dist.at(h-1).at(w-1) == -1) {
        cout << -1 << endl;
    } else {
        int x = w-1, y = h-1;
        while(1) {
            M.at(y).at(x) = 'o';
            if (x == 0 && y == 0) break;

            int px = prev_x.at(y).at(x);
            int py = prev_y.at(y).at(x);
            x = px, y = py;
        }

        cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (M.at(i).at(j) == '.') {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }


    return 0;

}