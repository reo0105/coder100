#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int max = -1, count = 0;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        switch (s.at(i)) {
            case 'A':
            case 'C':
            case 'G':
            case 'T': count++; break;
            default: count = 0;
        }

        if (count > max) max = count;
    }

    cout << max << endl;

    return 0;
}