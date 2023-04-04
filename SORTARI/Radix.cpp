#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

ifstream fin("numere1.txt");


long maxval(long v[], long n)
{
	int i, maxim;
	maxim = v[0];
	for (i = 1;i < n;i++)
	{
		if (maxim < v[i])
		{
			maxim = v[i];
		}
	}
	return maxim;
}

void countsort(long v[], long placement, long n)
{
	long i, fv[11];
	int* temp = new int[1000001];
	for (i = 0;i < 10;i++)
	{
		fv[i] = 0;
	}
	for (i = 0;i < n;i++)
	{
		fv[(v[i] / placement) % 10]++;
	}

	for (i = 1;i < 10;i++)
	{
		fv[i] += fv[i - 1];
	}

	for (i = n-1;i >= 0;i--)
	{
		temp[fv[(v[i] / placement) % 10] -1] = v[i];
		fv[(v[i] / placement) % 10]--;
	}
	for (i= 0;i < n;i++)
	{
		v[i] = temp[i];
	}
	delete[] temp;
}

void radixSort(long v[], long n)
{
	long placement, maxim;
	maxim = maxval(v, n);
	for (placement = 1; maxim / placement > 0;placement *= 10)
	{
		countsort(v, placement, n);
	}

}

int main()
{
	long x, v[1000001], n = 0;

	while (fin >> x)
	{
		v[n] = x;
		n++;
	}

	//int n = sizeof(v) / sizeof(v[0]);

	cout << n << endl;

	auto start = high_resolution_clock::now();

	radixSort(v, n);

	cout << "Am terminat de sortat :) " << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count();

	/*
	for (int i = 0;i < n;i++)
	{
		std::cout << v[i]<<" ";
	}
	*/
	return 0;
}