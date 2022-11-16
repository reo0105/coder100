#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> adjacent_xy(int y, int x, int i)
{
    vector<int> dy = {0, -1, -1, 0, 1, 1};
    vector<int> dx1 = {1, 1, 0, -1, 0, 1};
    vector<int> dx2 = {1, 0, -1, -1, -1, 0};

    if (y % 2 == 1) {
        return make_pair(y+dy.at(i), x+dx1.at(i));
    } else {
        return make_pair(y+dy.at(i), x+dx2.at(i));
    }
}

int main()
{
    int h, w, cnt = 0;
    vector<vector<int>> M(102, vector<int>(102, 0));
    vector<vector<bool>> seen(102, vector<bool>(102, false));
    queue<pair<int, int>> que;

    cin >> w >> h;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> M.at(i).at(j);
        }
    }
    
    seen.at(0).at(0) = true;
    que.push(make_pair(0, 0));
    while(!que.empty()) {
        auto p = que.front();
        que.pop();
        for (int i = 0; i < 6; i++) {
            auto next = adjacent_xy(p.first, p.second, i);
            int x = next.second;
            int y = next.first;
            if (y < 0 || h+1 < y || x < 0 || w+1 < x) continue;

            if (M.at(y).at(x) == 1) cnt++;
            else if (!seen.at(y).at(x)) {
                que.push(make_pair(y, x));
                seen.at(y).at(x) = true;
            }
        }

        // cout << que.size() << endl;
    }

    cout << cnt << endl;

    return 0;
}