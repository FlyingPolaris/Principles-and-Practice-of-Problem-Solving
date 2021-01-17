#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Implement your selection algorithm. You can add any standard library if needed.
//
int A[1000] = { 0 };

void Myswap(int A[], int a, int b)
{
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int Reselect(int A[], int begin, int end, int k)
{
    if (begin == end) return A[begin];
    if (begin < end)
    {
        int pivot;
        pivot = begin + rand() % (end - begin);
        Myswap(A, pivot, begin);
        int tmp = A[begin];
        int left = begin, right = end;
        while(left < right)
        {
            while (left < right && A[right] < tmp) right--;
            A[left] = A[right];
            while (left < right && A[left] >= tmp) left++;
            A[right] = A[left];
        }
        A[left] = tmp;
        int p = left;

        int m = p - begin + 1;
        if (m == k) return tmp;
        else if (m > k)
        {
            Reselect(A, begin, p - 1, k);
        }
        else
        {
            Reselect(A, p + 1, end, k - m);
        }
    }
}

int main()
{
    // Input processing.
    srand((unsigned)time(NULL));
    int n = 0;
    int num;
    while (cin >> num)
    {
       // if (num == -1) break;
        A[n++] = num;
    }
    n--;
    int Nth = A[n];
    A[n] = 0;
    // select the target and print the results.
    cout << Reselect(A, 0, n - 1, Nth);

    return 0;
}
