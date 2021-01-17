#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

void QuickSort(vector<int>& arr, int low, int high)
{
    int i, j, temp;
    i = low;
    j = high;
    if (low < high)
    {
        temp = arr[low];
        while (i != j)
        {
            while (j > i&& arr[j] >= temp)
            {
                --j;
            }
            if (i < j)
            {
                arr[i] = arr[j];
                ++i;
            }

            while (i < j && arr[i] < temp)
            {
                ++i;
            }
            if (i < j)
            {
                arr[j] = arr[i];
                --j;
            }
        }
        arr[i] = temp;
        QuickSort(arr, low, i - 1);
        QuickSort(arr, i + 1, high);
    }
}

class Solution {
public:
	float hMedian(vector<int>& citations) {
		//code here!!
        int n = citations.size() - 1;
        QuickSort(citations, 0, n);
        int num = 0, max = 0;

        for (int i = 0;i < n + 1;++i)
        {
            if (citations[i] == n - i + 1)
            {
                num = i;
            }
            else if (citations[i] < n - i + 1)
            {
                num = i + 1;
            }
        }
        if ((n + num) % 2 == 0) return (float)citations[(n + num) / 2];
        else return(((float)citations[(n + num ) / 2] + (float)citations[(n + num ) / 2 + 1]) / 2);
	}
};

int main(int argc, char** argv) {
	std::string line;
	int number;
	std::vector<int> numbers;

	std::getline(std::cin, line);
	std::istringstream stream(line);
	while (stream >> number)
		numbers.push_back(number);

	Solution s;
	float res = s.hMedian(numbers);

	std::cout << std::fixed;
	std::cout << std::setprecision(1) << res << endl;

	return 0;
}
