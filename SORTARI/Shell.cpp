//ShellSort
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;

std::ifstream fin("numere4.txt");

void shell(int v[], int n)
{
	int i, j;
	for (i = n / 2;i > 0;i /= 2)
	{
		for (j = 0;j < (n - i);j++)
		{
			if (v[j] > v[j + i])
			{
				int k = j;
				while (k >= 0 && v[k] > v[k + i])
				{
					std::swap(v[k], v[k + i]);
					k -= i;
				}
			}
		}
	}
}

int main()
{
	int* v = new int[1000001];
	int n = 0, x;

	while (fin >> x)
	{
		v[n] = x;
		n++;
	}
	std::cout << n << std::endl;

	auto start = high_resolution_clock::now();
	shell(v, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count()<<std::endl;

	delete[] v;

	std::cout << "Am terminat de sortat :) " << std::endl;

	/*
	for (i = 0;i < n;i++)
		std::cout << v[i] << " ";

	delete[] v;
	*/	
	return 0;
}