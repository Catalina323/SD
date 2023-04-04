#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;
std::ifstream fin("numere3.txt");

void Merge(int v[], int st, int dr)
{
	int* temp = new int[1000001];
	int i, j, x = 0, m;
	m = (st + dr) / 2;
	i = st;
	j = m + 1; 

	while (i <= m && j <= dr)
	{
		if (v[i] < v[j])
		{
			temp[x++] = v[i++];
		}
		else {
			temp[x++] = v[j++];
		}
	}
	while (i <= m)
	{
		temp[x++] = v[i++];
	}
	while (j <= dr)
	{
		temp[x++] = v[j++];
	}

	j = 0;
	for (i = st; i <= dr; i++)
	{
		v[i] = temp[j];
		j++;
	}
	delete[] temp;
}


void MergeSort(int v[], int st, int dr)
{
	int mij, x = 0;
	mij = (st + dr) / 2;
	if (st < dr)
	{
		MergeSort(v, st, mij);
		MergeSort(v, mij + 1, dr);
		Merge(v, st, dr);
	}
}

int main()
{
	int* v = new int[1000001];
	int x, n = 0, st = 0;
	while (fin >> x)
	{
		v[n] = x;
		n++;
	}
	std::cout << n << std::endl;
	n--;
	auto start = high_resolution_clock::now();
	MergeSort(v, st, n);

	std::cout << "Am terminat de sortat"<<std::endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count()<<std::endl;

	/*for (int i = 0;i <= n;i++)
	{
		std::cout << v[i] << " ";
	}
	*/
	delete[] v;

	return 0;
}