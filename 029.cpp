#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> dist(52, vector<int>(52, -1));
vector<vector<char>> map(52, vector<char>(52, 0));
queue<pair<int, int>> nxt;

int main()
{
    int r, c;
    int sy, sx;
    int gy, gx;

    cin >> r >> c;
    cin >> sy >> sx;
    cin >> gy >> gx;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map.at(i).at(j);
        }
    }

    dist.at(sy-1).at(sx-1) = 0;
    nxt.push(make_pair(sy-1, sx-1));
    while(!nxt.empty()) {
        int x, y;
        y = nxt.front().first;
        x = nxt.front().second;
        nxt.pop();
        if (y > 0 && map.at(y-1).at(x) == '.' && dist.at(y-1).at(x) == -1) {
            dist.at(y-1).at(x) = dist.at(y).at(x) + 1;
            nxt.push(make_pair(y-1, x));
        }

        if (x > 0 && map.at(y).at(x-1) == '.' && dist.at(y).at(x-1) == -1) {
            dist.at(y).at(x-1) = dist.at(y).at(x) + 1;
            nxt.push(make_pair(y, x-1));
        }

        if (y < r-1 && map.at(y+1).at(x) == '.' && dist.at(y+1).at(x) == -1) {
            dist.at(y+1).at(x) = dist.at(y).at(x) + 1;
            nxt.push(make_pair(y+1, x));
        }

        if (x < c-1 && map.at(y).at(x+1) == '.' && dist.at(y).at(x+1) == -1) {
            dist.at(y).at(x+1) = dist.at(y).at(x) + 1;
            nxt.push(make_pair(y, x+1));
        }
    }

    cout << dist.at(gy-1).at(gx-1) << endl;

    return 0;
}