#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) 
	{
		vector<int> ugly_num(n);
		vector<int> point(6, 0);
		int top = 0;
		ugly_num[0] = 1;
		while (top < n - 1)
		{
			int tmp = findmax(point[2], point[3], point[5], ugly_num);
			ugly_num[++top] = ugly_num[point[tmp]] * tmp;
			if (ugly_num[point[2]] * 2 == ugly_num[top]) point[2]++;
			if (ugly_num[point[3]] * 3 == ugly_num[top]) point[3]++;
			if (ugly_num[point[5]] * 5 == ugly_num[top]) point[5]++;
		}
		return ugly_num[n - 1];
	}
	int findmax(int a, int b, int c, vector<int> p)
	{
		if (p[a] * 2 <= p[b] * 3 && p[a] * 2 <= p[c] * 5) return 2;
		else if (p[b] * 3 <= p[a] * 2 && p[b] * 3 <= p[c] * 5) return 3;
		else return 5;
	}
};

int main() {
	Solution s;
	int n;
	cin >> n;
	cout << s.nthUglyNumber(n) << endl;
	return 0;
}