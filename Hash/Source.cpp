#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::ifstream fin("hashuri.in");
std::ofstream fout("hashuri.out");



class Hash {
	static const int prime = 666013;
	std::string* hash;

public:
	Hash() {
		hash = new std::string[prime];
	}
	~Hash() {
		delete[] hash;
	}

	void inserare(int i) {
		int n = i % prime;

		if (hash[n] == "" || hash[n] == "*")
			hash[n] = std::to_string(i);
		else {
			int j = n + 1;
			if (j > prime - 1)
				j %= prime;
			while (j != n) {
				if (hash[j] == "" || hash[j] == "*") {
					hash[j] = std::to_string(i);
					break;
				}
				++j;
				if (j > prime - 1)
					j %= prime;
			}
		}
	}

	void stergere(int i) {
		int n = i % prime;

		if (hash[n] == std::to_string(i))
			hash[n] = "*";
		else {
			int j = n + 1;
			if (j > prime - 1)
				j %= prime;
			while (j != n) {
				if (hash[j] == std::to_string(i)) {
					hash[j] = "*";
					break;
				}

				++j;
				if (j > prime - 1)
					j %= prime;
			}
		}
	}

	bool cautare(int i){
		int n = i % prime;

		if (hash[n] == std::to_string(i))
			return true;
		else {
			int j = n + 1;
			if (j > prime - 1)
				j %= prime;
			while (j != n) {
				if (hash[j] == std::to_string(i))
					return true;

				++j;
				if (j > prime - 1)
					j %= prime;
			}
		}

		return false;
	}

	void afisare() {
		for (int i = 0;i < prime;++i)
			if (hash[i] != "")
				std::cout << i << " " << hash[i]<<std::endl;
	}
};


int main()
{
	int n;
	fin >> n;

	Hash h;

	for (int i = 0;i < n;++i)
	{
		int a, b;
		fin >> a >> b;

		switch (a)
		{case 1:
		{
			h.inserare(b);

			break;
		}
		case 2:
		{
			h.stergere(b);

			break;
		}
		case 3:
		{
			if (h.cautare(b))
				fout << "1\n";
			else {
				fout << "0\n";
			}

			break;
		}
		default:
			break;
		}


	}



	return 0;
}