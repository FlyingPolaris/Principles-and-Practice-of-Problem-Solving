#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int DP[1002][1002];
char x[1002], y[1002];
set<string> Ans;

void findLCS(int i, int j, string str)
{
	while (i >= 1 && j >= 1)
	{
		if (x[i] == y[j])
		{
			str += x[i];
			i--;
			j--;
		}
		else
		{
			if (DP[i - 1][j] > DP[i][j - 1])
				i--;
			else if (DP[i - 1][j] < DP[i][j - 1])
				j--;
			else
			{
				findLCS(i - 1, j, str);
				findLCS(i, j - 1, str);
				return;
			}
		}
	}

	reverse(str.begin(), str.end());
	Ans.insert(str);

}


set<string> LCS(string X, string Y)
{
	int lenX = X.length(), lenY = Y.length();
	for (int i = 1;i <= X.length();++i)
	{
		x[i] = X[i - 1];
	}
	for (int i = 1;i <= Y.length();++i)
	{
		y[i] = Y[i - 1];
	}

	memset(DP, 0, sizeof(DP));

	for (int i = 1;i <= lenX;++i)
	{
		for (int j = 1;j <= lenY;++j)
		{
			if (x[i] == y[j])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else if (DP[i][j - 1] > DP[i - 1][j])
			{
				DP[i][j] = DP[i][j - 1];
			}
			else 
			{
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	string str = "";
	findLCS(lenX, lenY, str);
	return Ans;
}

int main()
{
	string X, Y;
	cin >> X;
	cin >> Y;

	set<string> lcs = LCS(X, Y);

	// print set elements
	for (string str : lcs)
		cout << str << endl;

	return 0;
}