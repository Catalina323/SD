//AVL tree
#include<iostream>
#include <fstream>
#include <climits>

std::ifstream fin("abce.in");
std::ofstream fout("abce.out");

struct nod {

	int valoare;
	nod* stanga;
	nod* dreapta;
	int inaltime;

	nod(int valoare) : valoare(valoare), stanga(NULL), dreapta(NULL), inaltime(1) {}
};

class AVL {

public:

	int calch(nod *n)
	{
		if (n == NULL)
			return 0;
		else {
			return n->inaltime;
		}
	}
	nod* succ_jos(nod* n)
	{
	
		nod* curent = n;

		while (curent->stanga != NULL)
			curent = curent->stanga;

		return curent;
	}

	int balance(nod* N)
	{
		if (N == NULL)
			return 0;
		return calch(N->stanga) - calch(N->dreapta);
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

		return dr;
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

		return st;
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

		

		int bal = balance(node);

		// stanga stanga
		if (bal > 1 && valoare < node->stanga->valoare)
			return R_Dreapta(node);

		// dreapta dreapta
		if (bal < -1 && valoare > node->dreapta->valoare)
			return R_Stanga(node);

		// stanga dreapta
		if (bal > 1 && valoare > node->stanga->valoare)
		{
			node->stanga = R_Stanga(node->stanga);
			return R_Dreapta(node);
		}

		// dreapta stanga
		if (bal < -1 && valoare < node->dreapta->valoare)
		{
			node->dreapta = R_Dreapta(node->dreapta);
			return R_Stanga(node);
		}

		return node;
	}

	nod* Delete(nod* node, int valoare)
	{
		

		if (node == NULL) {
			return NULL;
		}

		if (valoare < node->valoare) {
			node->stanga = Delete(node->stanga, valoare);
		}
		else if (valoare > node->valoare) {
			node->dreapta = Delete(node->dreapta, valoare);
		}
		else {
			// cel mult un copil 
			if (node->stanga == NULL || node->dreapta == NULL) {
				nod* temp = node->stanga ? node->stanga : node->dreapta;

				// niciun copil
				if (temp == NULL) {
					temp = node;
					node = NULL;
				}
				else { // un singur copil
					*node = *temp;
				}

				delete temp;
			}
			else {
				// nodul are doi copii
				nod* temp = succ_jos(node->dreapta);
				node->valoare = temp->valoare;
				node->dreapta = Delete(node->dreapta, temp->valoare);
			}
		}

		if (node == NULL) {
			return NULL;
		}

		//refacem structura AVL
		//inaltimea
		if (calch(node->dreapta) > calch(node->stanga))
		{
			node->inaltime = 1 + calch(node->dreapta);
		}
		else {
			node->inaltime = 1 + calch(node->stanga);
		}

		//balance

		// stanga stanga
		if (balance(node) > 1 && balance(node->stanga) >= 0) {
			return R_Dreapta(node);
		}

		// stanga dreapta
		if (balance(node) > 1 && balance(node->stanga) < 0) {
			node->stanga = R_Stanga(node->stanga);
			return R_Dreapta(node);
		}

		// dreapta dreapta
		if (balance(node) < -1 && balance(node->dreapta) <= 0) {
			return R_Stanga(node);
		}

		// dreapta stanga
		if (balance(node) < -1 && balance(node->dreapta) > 0) {
			node->dreapta = R_Dreapta(node->dreapta);
			return R_Stanga(node);
		}

		return node;

	}

	void Afis(nod* node)
	{
		if (node != NULL)
		{
			Afis(node->stanga);
			std::cout << node->valoare << " ";
			Afis(node->dreapta);
		}
	}

	void AfisInt(nod* node, int y, int z)
	{
		if (node != NULL)
		{
			AfisInt(node->stanga, y, z);
			if(node->valoare <= z && node->valoare >= y)
				fout << node->valoare << " ";
			AfisInt(node->dreapta, y, z);
		}
	}

	
	int find(nod* node, int valoare)
	{
		if (node == NULL)
			return 0;
		else{
			
			if (node != NULL && node->valoare == valoare)
				return 1;
			else {
				if (node != NULL && node->valoare > valoare)
					return find(node->stanga, valoare);
				else
					return find(node->dreapta, valoare);

			}
		}
	}

	

	//cel mai mic nr mai mare sau egal decat x
	int min(nod* n, int x)
	{
		int minim = INT_MAX;
		while (n) 
		{
			if (n->valoare < x)
				n = n->dreapta;
			else
				if (n->valoare > x)
				{
					if (n->valoare < minim)
						minim = n->valoare;

					n = n->stanga;
				}
				else
					return x;
		}
		return minim;
	}

	//cel mai mare nr mai mic sau egal decat x
	int max(nod* n, int x)
	{
		int maxim = INT_MIN;

		while (n) 
		{
			if (n->valoare > x)
				n = n->stanga;
			else
				if (n->valoare < x)
				{
					if (n->valoare > maxim)
						maxim = n->valoare;

					n = n->dreapta;
				}
				else
					return x;
		}

		return maxim;
	}
	

};

int main()
{
	AVL copacel;
	nod* radacina = NULL;

	int n, x, y, z;
	fin >> n;

	for (int i = 0; i < n; ++i)
	{
		fin >> x;

		switch (x)
		{
		case(1):
		{
			fin >> y;
			radacina = copacel.Insert(radacina, y);
			break;
		}
		case(2):
		{
			fin >> y;
			radacina = copacel.Delete(radacina, y);
			break;
		}
		case(3):
		{
			fin >> y;
			fout << copacel.find(radacina, y) << std::endl;
			break;
		}
		case(4):
		{
			fin >> y;
			fout << copacel.max(radacina, y) << std::endl;
			break;
		}
		case(5):
		{
			fin >> y;
			fout << copacel.min(radacina, y) << std::endl;
			break;
		}
		case(6):
		{
			fin >> y >> z;
			copacel.AfisInt(radacina, y, z);
			fout << std::endl;
			break;
		}
		default:
			break;
		}
	}

	return 0;
}
