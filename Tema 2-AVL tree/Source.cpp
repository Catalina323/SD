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

	int calch(nod *n)
	{
		if (n == NULL)
			return 0;
		else {
			return n->inaltime;
		}
	}

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
		
		//facem inaltimea nodului node
		if (calch(node->dreapta) > calch(node->stanga))
		{
			node->inaltime = 1 + calch(node->dreapta);
		}
		else {
			node->inaltime = 1 + calch(node->stanga);
		}

		int balance;
		if (node == NULL)
			balance = 0;
		else 
			balance = node->stanga->inaltime - node->dreapta->inaltime;

		/*
		// Left Left Case
		if (balance > 1 && valoare < node->stanga->valoare)
			return rightRotate(node);

		// Right Right Case
		if (balance < -1 && valoare > node->dreapta->valoare)
			return leftRotate(node);

		// Left Right Case
		if (balance > 1 && valoare > node->stanga->key)
		{
			node->stanga = leftRotate(node->stanga);
			return rightRotate(node);
		}

		// Right Left Case
		if (balance < -1 && valoare < node->dreapta->valoare)
		{
			node->dreapta = rightRotate(node->dreapta);
			return leftRotate(node);
		}

		*/

		//return the (unchanged) node pointer 
		return node;
	}

};

int main()
{
	AVL copacel;
	nod* radacina = copacel.Insert(NULL, 10);
	copacel.Insert(radacina, 20);
	copacel.Insert(radacina, 5);


	return 0;
}
