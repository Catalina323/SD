//Buble Sort
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;
std::ifstream fin("numere3.txt");

int main()
{
	int* v = new int[100001];
	int i, j, x, n=0;

	while (fin >> x)
	{
		v[n] = x;
		n++;
	}

	auto start = high_resolution_clock::now();

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (v[i] < v[j])
				std::swap(v[i], v[j]);
		}
	}

	delete[] v;

	std::cout << "Am terminat de sortat :) "<<std::endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count();

	return 0;
}