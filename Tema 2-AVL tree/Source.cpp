//AVL tree
#include<iostream>


struct nod {

	int valoare;
	nod* stanga;
	nod* dreapta;
	int inaltime;

	nod(int valoare) : valoare(valoare), stanga(NULL), dreapta(NULL), inaltime(1) {}
};

class AVL {
	nod* radacina;

public:
	nod* Insert(nod* node, int valoare)
	{
		if (node == NULL)
		{
			return new nod(valoare);	
		}
		else {
			if (valoare < node->valoare)
			{
				node->stanga = Insert(node->stanga, valoare);
			}
		
			if (valoare > node->valoare) 
			{
				node->dreapta = Insert(node->dreapta, valoare);
			}
		}
		

		return node;
	}



};

int main()
{
	AVL copacel;
	nod* radacina = NULL;
	radacina = copacel.Insert(radacina, 10);
	radacina = copacel.Insert(radacina, 20);
	radacina = copacel.Insert(radacina, 5);


	return 0;
}