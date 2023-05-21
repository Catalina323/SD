#include <iostream>
#include <fstream>
#include <unordered_set>

std::ifstream fin("muzica.in");
std::ofstream fout("muzica.out");

int main()
{
	int x, y;
	long long a, b, c, d, e, n;
	fin >> x >> y;
	fin >> a >> b >> c >> d >> e;
	std::unordered_set <long long> s(10 * x);

	for (int i = 0;i < x;i++)
	{
		fin >> n;
		s.insert(n);
	}
	int cont = 0;

	for (int i = 0;i < y && (!s.empty());i++)
	{
		auto var = s.find(a);
		if (var != s.end())
		{
			s.erase(a);
			cont++;
		}
		
		long long aux = ((c * b) + (d * a)) % e;
		a = b;
		b = aux;

	}

	fout << cont;

	return 0;
}
