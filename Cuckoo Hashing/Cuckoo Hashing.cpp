#include <iostream>
#include <cstdlib>
using namespace std;

// upper bound on hashtable size
#define MAXN 101
// actual used hashtable size
int m;
int times = 0;

// number of tables
#define ver 2 

int hashtable[ver][MAXN];

// possible positions for a key 
int pos[ver];

bool flag = false;
bool used[1002] = { 0 };
/* function to fill hash table with dummy value
* dummy value: -1
* number of hashtables: ver */
void initTable()
{
	for (int j = 0; j < MAXN; j++)
		for (int i = 0; i < ver; i++)
			hashtable[i][j] = -1;
}

/* return hashed value for a key
* function: ID of hash function
* key: item to be hashed */
int myhash(int function, int key, int n)
{
	switch (function)
	{
	case 1: return key % m;
	case 2: return (key / m) % m;
	}
}

void place(int key, int tableID, int cnt, int n)
{
	//code here
	if (times > 1000)
	{
		flag = true;
		return;
	}
	times++;
	int theplace;
	theplace = myhash(tableID + 1, key, n);
	if (hashtable[tableID][theplace] == -1)
	{
		hashtable[tableID][theplace] = key;
		return;
	}

	int cuckookey = hashtable[tableID][theplace];
	hashtable[tableID][theplace] = key;
	place(cuckookey, 1 - tableID, cnt, n);
}

/* function to print hash table contents */
void printTable(int n)
{

	for (int i = 0; i < ver; i++, std::cout << endl)
		for (int j = 0; j < m; j++)
			(hashtable[i][j] == -1) ? std::cout << "- " :
			std::cout << hashtable[i][j] << " ";

}

/* function for Cuckoo-hashing keys
* keys[]: input array of keys
* n: size of input array */
void cuckoo(int keys[], int n)
{
	//init
	initTable();

	// start with placing every key at its position in 
	// the first hash table according to first hash 
	// function 
	for (int i = 0, cnt = 0; i < n; i++, cnt = 0)
	{
		times = 0;
		if (used[keys[i]]) continue;
		place(keys[i], 0, cnt, n);
		used[keys[i]] = 1;
		if (flag)
		{
			cout << "Failed!";
			return;
		}
	}

	//print the final hash tables 
	printTable(n);
}

int main()
{
	int keys_1[MAXN];
	//input array size
	int n;
	std::cin >> n;
	//m in hash function
	m = n + 1;
	int i = 0;
	while (i < n)
	{
		std::cin >> keys_1[i++];
	}
	cuckoo(keys_1, n);

	return 0;
}
