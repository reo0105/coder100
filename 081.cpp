#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, count = 0, max = -1;
    vector<int> data(1000002);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        data.at(a) += 1;
        data.at(b+1) -= 1;
    }

    for (int i = 0; i < data.size(); i++) {
        count += data.at(i);
        if (count > max) max = count;
    }

    cout << max << endl;

    return 0;
}