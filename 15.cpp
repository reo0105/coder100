#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, x, y, count = 0;;
    long double sum = 0.0;
    cin >> n;
    vector<pair<int, int>> data(n);



    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        data.at(i) = make_pair(x, y);
    }

    sort(data.begin(), data.end()); // next_permutationは辞書順で次を取得するのであらかじめソートの必要あり

    do {
        // sum = 0.0;
        for (int i = 0; i < n - 1; i++) {
            sum += sqrt((data.at(i+1).first - data.at(i).first) * (data.at(i+1).first - data.at(i).first) 
                    + (data.at(i+1).second - data.at(i).second) * (data.at(i+1).second - data.at(i).second));
        }
        count++;
    } while(next_permutation(data.begin(), data.end()));

    cout << setprecision(12) << sum / count << endl;

    return 0;   
}