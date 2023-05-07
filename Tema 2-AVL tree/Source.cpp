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

	nod* R_Stanga(nod* n)
	{
		nod* dr = n->dreapta;
		nod* drst = dr->stanga;

		dr->stanga = n;
		n->dreapta = drst;

		//refacem inaltimile
		//pt nodul n
		if (calch(n->dreapta) > calch(n->stanga))
		{
			n->inaltime = 1 + calch(n->dreapta);
		}
		else {
			n->inaltime = 1 + calch(n->stanga);
		}
		//pt nodul dr
		if (calch(dr->dreapta) > calch(dr->stanga))
		{
			dr->inaltime = 1 + calch(dr->dreapta);
		}
		else {
			dr->inaltime = 1 + calch(dr->stanga);
		}

		return n;
	}

	nod* R_Dreapta(nod* n)
	{
		nod* st = n->stanga;
		nod* stdr = st->dreapta;

		st->dreapta = n;
		n->stanga = stdr;

		//refacem inaltimile
		//pt nodul n
		if (calch(n->dreapta) > calch(n->stanga))
		{
			n->inaltime = 1 + calch(n->dreapta);
		}
		else {
			n->inaltime = 1 + calch(n->stanga);
		}
		//pt nodul st
		if (calch(st->dreapta) > calch(st->stanga))
		{
			st->inaltime = 1 + calch(st->dreapta);
		}
		else {
			st->inaltime = 1 + calch(st->stanga);
		}

		return n;
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

		
		// Left Left Case
		if (balance > 1 && valoare < node->stanga->valoare)
			return R_Dreapta(node);

		// Right Right Case
		if (balance < -1 && valoare > node->dreapta->valoare)
			return R_Stanga(node);

		// Left Right Case
		if (balance > 1 && valoare > node->stanga->valoare)
		{
			node->stanga = R_Stanga(node->stanga);
			return R_Dreapta(node);
		}

		// Right Left Case
		if (balance < -1 && valoare < node->dreapta->valoare)
		{
			node->dreapta = R_Dreapta(node->dreapta);
			return R_Stanga(node);
		}

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
