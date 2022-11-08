#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, score = 0, flag = 1, count = 1;
    vector<vector<int>> data(12, vector<int>(5, -1));

    while(1) {
        cin >> h;
        if (h == 0) {
            break;
        }

        score = 0;
        flag = 1;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> data.at(i).at(j);
            }
        }

        while(flag) {
            flag = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < 5; j++) {
                    if (j+1 < 5 && data.at(i).at(j) == data.at(i).at(j+1) && data.at(i).at(j) != 0) {
                        count++;
                    } else {
                        if (count >= 3) {
                            flag = 1;
                            score += data.at(i).at(j) * count;
                            for (int k = 0; k < count; k++) {
                                data.at(i).at(j-k) = 0;
                            }
                        }
                        count = 1;
                    }
                }
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < h; j++) {
                    if (data.at(j).at(i) == 0) {
                        for (int k = j; k > 0; k--) {
                            swap(data.at(k).at(i), data.at(k-1).at(i));
                        }
                        // data.at(0).at(i) = 0;
                    }
                }
            }

            // for (int i = 0; i < h; i++) {
            //     for (int j = 0; j < 5; j++) {
            //         cout << data.at(i).at(j) << " ";
            //     }
            //     cout << endl;
            // }
        }

        cout << score << endl;
    }

    return 0;
}