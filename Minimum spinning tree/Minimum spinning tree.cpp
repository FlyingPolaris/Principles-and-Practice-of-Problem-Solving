// Add any standard library if needed.
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

// Implement your minimum spinning tree algorithm
const int MAX = 999;
int CIN[MAX];
int map[MAX][MAX];
bool vis[MAX];
int weight[MAX];

void prim(int n)
{
    memset(vis, 0, sizeof(vis));
    int cur = 0;
    for (int i = 0;i < n;++i) weight[i] = map[cur][i];
    vis[cur] = true;

    int sum = 0;
    for (int i = 0;i < n - 1;++i)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            if (weight[j] < min && !vis[j])
            {
                cur = j;
                min = weight[j];
            }
        }
        sum += min;
        vis[cur] = true;
        for (int j = 0;j < n;++j)
        {
            if (!vis[j] && weight[j] > map[cur][j]) weight[j] = map[cur][j];
        } 
    }
    cout << sum;
}
// Test your implementation
int main() 
{
    int num = 0;
    int a;
    while (cin >> a)
    {
        //if (a == -1) break;
        CIN[num++] = a;
    }
    int n = 0;
    while (true)
    {
        ++n;
        if (n * n == num) break;
    }
    int m = 0;
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
        {
            map[i][j] = CIN[m] == 0 && i != j ? INT_MAX : CIN[m];
            m++;
        }

    prim(n);
    return 0;
}