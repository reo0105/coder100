#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int m, n;
    int x, y, dif_x, dif_y, search_x, search_y;
    vector<p> a(202), b(1002);
    set<p> pic;

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a.at(i) = p(x, y);
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        b.at(i) = p(x, y);
        pic.insert(p(x,y));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dif_x = b.at(j).first - a.at(i).first;
            dif_y = b.at(j).second - a.at(i).second;

            int k;
            for (k = 0; k < m; k++) {
                search_x = a.at(k).first + dif_x;
                search_y = a.at(k).second + dif_y;

                if (!pic.count(p(search_x, search_y))) break;
            }


            if (k == m) goto end;

        }
    }

end:
    cout << dif_x << " " << dif_y << endl;

    return 0;
}