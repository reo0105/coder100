/*
差分パルス符号変調は主に音声信号を圧縮する際に用いられる圧縮手法の一つである．

音声信号は計算機上では整数列(インパルス列)として扱われる．整数列は入力信号を一定時間間隔で標本化(サンプリング)し，
振幅を記録したものである．一般にこの整数列は前後の値が近いという傾向がある．これを利用し，前後の値の差分を符号化し，
圧縮率を向上させるのが差分パルス符号変調である．

本問題では差分の値をあらかじめ定められた値の集合から選ぶことを考える．この値の集合をコードブックと呼ぶことにする．
復号化後の音声信号 yn は以下の式で定められる．

    yn = yn - 1 + C[kn]

ここで kn はプログラムによって出力される出力系列， C[j] はコードブックの j 番目の値である．
ただし yn は加算によって0未満の値となった場合は0に，255より大きい値となった場合は255にそれぞれ丸められる．
また， y0 の値は128とする．

あなたの仕事は，入力信号とコードブックが与えられたときに，
元の入力信号と復号化後の出力信号との差の二乗和が最小となるように出力系列を選んで，
そのときの差の二乗和を出力するプログラムを書くことである．

例えば，コードブックとして {4, 2, 1, 0, -1, -2, -4} という値のセットを使って 131, 137 という列を圧縮する場合， 
y0 = 128, y1 = 128 + 4 = 132, y2 = 132 + 4 = 136 という列に圧縮すると 二乗和が (131 - 132)^2 + (137 - 136)^2 = 2 と最小になる．

また，同じくコードブックとして {4, 2, 1, 0, -1, -2, -4} という値のセットを使って 131, 123 という列を圧縮する場合， 
y0 = 128, y1 = 128 + 1 = 129, y2 = 129 - 4 = 125 と，先程の例とは違って 131 により近づく +2 を採用しない方が 
(131 - 129) ^ 2 + (123 - 125) ^ 2 = 8 というより小さな二乗和が得られる．

上記 2つの例は sample input の最初の 2例である．
*/

#include <iostream>
#include <vector>
using namespace std;
#define INF 1 << 29

int main()
{
    int n, m;
    vector<int> C(20), x(20002);

    while(1) {
        cin >> n >> m;
        
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= m; i++) cin >> C.at(i);
        for (int i = 1; i <= n; i++) cin >> x.at(i);

        vector<vector<int>> dp(20, vector<int>(20002, INF));
        vector<int> y(20002);

        y.at(0) = 128;

        for (int i = 1; i <= m; i++) dp.at(i).at(0) = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int t = y.at(j-1) + C.at(i);
                t = (t > 255) ? 255 : (t < 0) ? 0 : t;
                y.at(j) = t;
                dp.at(i).at(j) = min(dp.at(i).at(j-1) + (x.at(j) - y.at(j)) * (x.at(j) - y.at(j)), dp.at(i-1).at(j));
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp.at(i).at(j) << " ";
            }
            cout << endl;
        }

        cout << dp.at(m).at(n) << endl;
    }

    return 0;
}