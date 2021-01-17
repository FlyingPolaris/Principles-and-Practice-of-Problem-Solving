#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, const char* argv[]) {
    //  Input preprocessing.
    string str;
    getline(cin, str);
    stringstream xstr(str);
    getline(cin, str);
    stringstream ystr(str);

    // X and Y are two vectors of equal length to be traversed.
    vector<double> X, Y;
    double a;
    while (xstr >> a)
        X.push_back(a);
    while (ystr >> a)
        Y.push_back(a);

    // interp_x is the point to be interpolated.
    double interp_x;
    cin >> interp_x;

    // Do Lagrange interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!
    long long n = X.size();
    double ans = 0;
    for (int k = 0;k < n;++k)
    {
        double s = Y[k];
        for (int i = 0;i < n;++i)
        {
            if (k != i) s *= ((interp_x - X[i]) / (X[k] - X[i]));
        }
        ans += s;
    }

    cout << fixed << setprecision(3) << ans;

    // End
    return 0;
}
