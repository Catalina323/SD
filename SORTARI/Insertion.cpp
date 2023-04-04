#include <iostream>
#include <fstream>

std::ifstream fin("numere2.txt");

int main()
{
	int n = 0, i, j, key, x;
	//int* v = new int[200000];
	int v[100];
	while (fin >> x)
	{
		v[n] = x;
		n++;
	}

	std::cout << n << std::endl;

	for (i = 0;i < n;i++)
	{
		key = v[i];
		if (v[i] > v[i + 1])
		{
			//j = i - 1;
			j = i;

			while (j>=0 && v[j-1] > key)
			{
				std::swap(v[j + 1] , v[j]);
				j--;

			}
			//v[j + 1] = key;
		}
	}

	std::cout << "Am terminat de sortat :) ";

	for (i = 0;i < n;i++)
	{
		std::cout << v[i] << " ";
	}

	//delete[] v;

	return 0;
}

