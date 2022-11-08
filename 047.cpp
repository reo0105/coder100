#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll inf = 1L << 59;
    int N;
    vector<ll> A_vec(2002);
    vector<vector<ll>> dp(2002, vector<ll>(2002, -inf));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    
    for (int j = 0; j < N; ++j)
        dp[0][j] = 0;

    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int j1 = (j + 1) % N;
            int j2 = (j + i) % N;
            int j3 = (j + N - 1) % N;
            ll A_j = A_vec.at(j);
            ll A_j2 = A_vec.at(j2);
            ll A_j3 = A_vec.at(j3);
            if (i % 2 == 0)
                dp[i + 1][j] = max(dp[i][j1] + A_j, dp[i][j] + A_j2);
            else if (A_j3 < A_j2)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            else
                dp[i + 1][j3] = max(dp[i + 1][j3], dp[i][j]);
        }
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}