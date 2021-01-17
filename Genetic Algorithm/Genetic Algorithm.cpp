#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int N = 65535;
const int SIZE = 100;
const int GENERATION = 500;
const double P_CORSSOVER = 0.8;
const double P_MUTATION = 0.05;
const int LEN = 16;

struct chromosome
{
	bool x[LEN];
	double weight;
};

chromosome cur[SIZE], next[SIZE], max, min;

double rand_0to1()
{
	return (double)rand() / RAND_MAX;
}
int rand_0toN(int k)
{
	return (int)(rand_0to1() * k + 0.5);
}

double MAX(double a, double b)
{
	return a > b ? a : b;
}

double cal_value(int i)
{
	int k = 0;
	for (int j = LEN - 1;j >= 0;j--) k = (k << 1) + cur[i].x[j];
	double value = (double)k / N * 16 - 1;
	return value;
}

void cal_weight()
{
	int i, j, k;
	double d;
	for (i = 0;i < SIZE;i++)
	{
		d = cal_value(i);
		cur[i].weight = d * sin(d);
	}
}

void init()
{
	int tmp;
	for (int i = 0;i < SIZE;i++)
	{
		tmp = rand_0toN(N);
		for (int j = 0;j < LEN;j++)
		{
			cur[i].x[j] = tmp % 2;
			tmp = tmp >> 1;
		}
	} 
	cal_weight();
}

void Crossover(int k)
{
	int i = rand_0toN(SIZE);
	int pos = rand_0toN(LEN - 1);
	if (rand_0to1() < P_CORSSOVER)
	{
		memcpy(next[k].x + pos, cur[i].x + pos, LEN - pos);
		memcpy(next[i].x + pos, cur[k].x + pos, LEN - pos);
	}
}

void Mutation(int k)
{
	if (rand_0to1() < P_MUTATION)
	{
		int pos = rand_0toN(LEN - 1);
		next[k].x[pos] = 1 - next[k].x[pos];
	}
}

void transform()
{
	min = cur[0];
	for (int i = 1;i < SIZE;++i)
	{
		if (cur[i].weight < min.weight) min = cur[i];
	}
	for (int k = 0;k < SIZE;++k)
	{
		memcpy(next[k].x, cur[k].x, LEN);
	}
	for (int k = 0;k < SIZE;++k)
	{
		Crossover(k);
		Mutation(k);
	}
	max = next[0];
	int j = 0;
	for (int i = 1;i < SIZE - 1;++i)
	{
		if (next[i].weight > max.weight)
		{
			max = next[i];
			j = i;
		}
	}
	next[j] = min;
	memcpy(cur, next, sizeof(cur));
	cal_weight();
}

void Genetic_Algorithm()
{
	int index = 0;
	int cnt = 0;
	double ans;
	while (cnt++ < GENERATION)
	{
		transform();
	}
	ans = cur[0].weight;
	for (int i = 1;i < SIZE;++i)
	{
		if (cur[i].weight < ans)
		{
			ans = cur[i].weight;
			index = i;
		}
	}
	double x0 = cal_value(index);
	printf("%.4f\n", x0);
}
int main()
{
	srand((unsigned)time(NULL));
	init();
	Genetic_Algorithm();
	return 0;
}