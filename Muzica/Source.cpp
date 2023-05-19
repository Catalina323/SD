#include <fstream>
#include <unordered_set>


std::ifstream fin("muzica.in");
std::ofstream fout("muzica.out");

int main()
{
	int x, y, A, B, C, D, E, n;
	std::unordered_set <int> mm;
	
	fin >> x >> y;
	fin >> A >> B >> C >> D >> E;
	int cont = 0;

	mm.insert(A);
	mm.insert(B);
	
	int aux1, aux2, aux3;
	aux1 = A;
	aux2 = B;

	for (int i = 3;i <= y;++i)
	{
		aux3 = (C * aux1 + D * aux2) % E;
		mm.insert(aux3);
		aux2 = aux1;
		aux1 = aux3;
	}

	for (int i = 0;i < x;++i)
	{
		fin >> n;
		//auto val = mm.find(n);
		if (mm.find(n) != mm.end())
			cont++;
	}

	fout << cont;

	return 0;
}