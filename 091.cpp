#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;

    int half = a * a * b / 2;
    double ans;

    if (x > half) ans = atan((2*b-(2*x)/(a*a))/a);
    else ans = atan((a*b*b)/(2*x));

    ans = ans / M_PI * 180;

    cout << fixed;
    cout << setprecision(10) << ans << endl; 


}