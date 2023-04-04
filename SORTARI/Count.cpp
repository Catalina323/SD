//Count Sort
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;
std::ifstream fin("numere1.txt");


int main()
{	
	int i, j, n = 0, x;
	int* v = new int[200000];
	int* f = new int[1002];

	while (fin >> x)
	{
		v[n] = x;
		n++;
	}
	std::cout << n << std::endl;

	for (i = 0;i < 1002;i++)
	{
		f[i] = 0;
	}

	auto start = high_resolution_clock::now();

	for(i=0;i<n;i++)
	{
		f[v[i]]++;
	}

	n = 0;
	for (i = 0;i < 1002;i++)
	{
		if (f[i] > 0)
			for (j = 0;j<f[i];j++)
			{
				v[n] = i;
				n++;
			}
	}

	std::cout << "Am terminat de sortat :) "<<std::endl;

	std::cout << std::endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count();

	delete[] f;
	delete[] v;

	return 0;
}