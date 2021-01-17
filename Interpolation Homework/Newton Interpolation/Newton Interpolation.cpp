#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


// You can add additional standard libraries if necessary.
// Implement the Newton interpolation!
class Newton {
public:
    Newton(vector<double> x, vector<double> y) : X(x), Y(y) {}



private:
    vector<double> X, Y;
};


// Test your implementation.
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

    // Do Newton interpolation for interp_x using X and Y, and print your results
    // Note: The result retains three decimal places (rounded)!
    int n = X.size();
    double h = X[1] - X[0];
    vector<double> delt_y(Y);
    double ans = 0;
    for (int k = 0;k < n;++k)
    {
        double s = 1;
        s *= delt_y[0];
        for (int i = 1;i <= k;++i)
        {
            s /= h;
            s /= i;
            s *= interp_x - X[i - 1];
        }
        ans += s;
        for (int j = 0;j < n - 1;++j)
        {
            delt_y[j] = delt_y[j + 1] - delt_y[j];
        }
    }

    cout << fixed << setprecision(3) << ans;

    // End
    return 0;
}
