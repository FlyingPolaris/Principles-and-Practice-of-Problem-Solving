#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Implement your Gaussian Elimination algorithm.
// You can add any standard library if needed.
//
bool print = false;
const int N = 10000;
double A[N][N];
double B[N];
double X[N];
void display(int n)
{
    if (!print) return;
    for (int i = 0;i < n;++i)
    {
        for (int j = 0;j < n;++j)
        {
            cout << fixed << setprecision(3) << A[i][j] << ' ';
        }
        cout << fixed << setprecision(3) << B[i] << '\n';
    }
    cout << '\n';
}
// Test your implementation.

double cinn[N];
int main() 
{
    // Input processing.
    int m = 0;
    char ch;
    
    while (cin.get(ch))
    {
        if (ch >= '0' && ch <= '9' || ch == '-')
        {
            cin.putback(ch);
            cin >> cinn[m];
            ++m;
        }
        if (ch == '*') break;
    }

    int n = 1;
    while (true)
    {
        if (n * n + n == m) break;
        n++;
    }


    int num = 0;
    for (int i = 0;i < n;++i)
    {
        for (int j = 0;j < n;++j)
        {
            A[i][j] = cinn[num++];
        }
        B[i] = cinn[num++];
    }

    display(n);
    for (int k = 0;k < n - 1;++k)
    {
        double max = A[k][k];
        int r = k;
        for (int i = k + 1;i < n;++i)
        {
            if (fabs(A[i][k]) > fabs(max))
            {
                max = A[i][k];
                r = i;
            }   
        }
        if (fabs(max) < 1e-6)
        {
            continue;
        }
        else if (r != k)
        {
            for (int j = k;j < n;++j)
            {
                double tmp = A[k][j];
                A[k][j] = A[r][j];
                A[r][j] = tmp;
            }
            double tmp = B[k];
            B[k] = B[r];
            B[r] = tmp;
        }
        for (int i = k + 1;i < n;++i)
        {
            double tmp = A[i][k] / A[k][k];
            for (int j = k;j < m;++j)
            {
                A[i][j] -= tmp * A[k][j];
            }
            B[i] -= tmp * B[k];
        }
    }

    display(n);
     
    if (fabs(A[n - 1][n - 1]) < 1e-8)
    {
        if (fabs(B[n - 1]) < 1e-8) cout << "No unique solution!";
        else cout << "No solution!";
        return 0;
    }
    X[n - 1] = B[n - 1] / A[n - 1][n - 1];
  
    for (int k = n - 2;k >= 0;k--)
    {
        double t = 0;
        for (int j = k + 1;j < n;++j)
        {
            t += A[k][j] * X[j];
        }
        if (fabs(A[k][k]) < 1e-8)
        {
            if (fabs(B[k] - t) < 1e-8) cout << "No unique solution!";
            else cout << "No solution!";
            return 0;
        }
        X[k] = (B[k] - t) / A[k][k];

    }


    for (int i = 0;i < n;++i)
        cout << fixed << setprecision(3) << X[i] << ' ';

    return 0;
}
