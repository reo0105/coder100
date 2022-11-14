#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> a, int y, int x)
{
    for (int i = -7; i <= 7; i++) {
        for (int j = -7; j <= 7; j++) {
            if (y+j >= 0 && y+j <= 7 && x+i >= 0 && x+i <= 7 && abs(i) == abs(j) && i!=0 && j != 0) {
                if (a.at(y+j) == x+i) {
                	return false;
                }
            }
        }
    }
	
    return true;
}

int main()
{
    int n, i, j, cnt = 0;
    vector<int> a(8, -1), ans(8, -1);
    vector<int> permu = {0, 1, 2, 3, 4, 5, 6, 7};

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.at(x) = y;
        ans.at(x) = y;
    }

    do {
        for (i = 0; i < 8; i++) {
            if (a.at(i) == -1) {
                a.at(i) = permu.at(i);
                if (!check(a, i, permu.at(i))) {
                    break;
                }
            } else if (a.at(i) != permu.at(i)) {
                break;
            }
        }
		
        if (i == 8) {
            break;
        } else {
            for (i = 0; i < 8; i++) {
                a.at(i) = ans.at(i);
            }
        }
    } while(next_permutation(permu.begin(), permu.end()));
    
    // for (int i = 0;i < 8; i++) cout << a.at(i); cout << endl;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (a.at(i) != j) {
                cout << '.';
            } else {
                cout << 'Q';
            }
        }
        cout << endl;
    }

    return 0;
}