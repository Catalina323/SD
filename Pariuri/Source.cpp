// Pariuri infoarena
#include <fstream>
#include <unordered_map>

std::ifstream fin("pariuri.in");
std::ofstream fout("pariuri.out");

int main()
{
	int l, x, a, b, nr = 0;
	fin >> l;

	std::unordered_map<int, int> m;

	for (int i = 0;i < l;++i)
	{
		fin >> x;
		for (int j = 0;j < x;++j)
		{
			fin >> a >> b;
			

			if (m.find(a) == m.end())
			{
				nr++;
				m.insert({ a, b });
			}
			else {
				m[a] += b;
			}
		}
	}

	fout << nr << std::endl;
	
	for (auto k = m.begin(); k != m.end(); ++k) 
	{
		fout << k->first << " " << k->second << " ";
	}


	return 0;
}