#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, x, y, max = 0, square;
    bool exist = false;
    vector<pair<int, int>> data(3002);
    set<pair<int, int>> exi;
 
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        data.at(i) = make_pair(x, y);
        exi.insert(make_pair(x, y));
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x1, y1, x2, y2;
            tie(x1, y1) = data.at(i);
            tie(x2, y2) = data.at(j);
            square = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
          
 			//cout << square << endl;
 
            if (square < max) continue;
          
            //　ベクトルの回転にてこずった
            auto itr1 = exi.find(make_pair(x1 + (y1 - y2), y1 - (x1 - x2)));
            auto itr2 = exi.find(make_pair(x1 - (y1 - y2), y1 - (x1 - x2)));
            
 
            if (itr1 != exi.end()) {
                auto itr3 = exi.find(make_pair(x2 + (y1 - y2), y2 - (x1 - x2)));
                if (itr3 != exi.end()) exist = true;
            }
            if (itr2 != exi.end()) {
                auto itr3 = exi.find(make_pair(x2 - (y1 - y2), y2 - (x1 - x2)));
                if (itr3 != exi.end()) exist = true;
            }
			
          	//if (exist) cout << "exist" << endl;
            if (exist) max = square;
            exist = false;
        }
    }
 
    cout << max << endl;
 
    return 0;
}