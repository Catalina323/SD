//AVL tree
#include<iostream>
#include <fstream>

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
	
		nod* dr = n->dreapta;
		if (dr != NULL)
		{
			while (dr->stanga != NULL)
				dr = dr->stanga;

			return dr;
		}
		else
			return n;
	}
	int balance(nod* n)
	{
		int balance;
		if (n == NULL || (n->stanga == NULL && n->dreapta == NULL))
			balance = 0;
		else
		{
			if (n->stanga == NULL)
				balance = 0 - n->dreapta->inaltime;
			else if (n->dreapta == NULL)
				balance = n->stanga->inaltime;
			else
				balance = n->stanga->inaltime - n->dreapta->inaltime;
		}

		return balance;

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

		//return n;
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

		//return n;
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

		// Cazul stanga-stanga
		if (balance(node) > 1 && balance(node->stanga) >= 0) {
			return R_Dreapta(node);
		}

		// Cazul stanga-dreapta
		if (balance(node) > 1 && balance(node->stanga) < 0) {
			node->stanga = R_Stanga(node->stanga);
			return R_Dreapta(node);
		}

		// Cazul dreapta-dreapta
		if (balance(node) < -1 && balance(node->dreapta) <= 0) {
			return R_Stanga(node);
		}

		// Cazul dreapta-stanga
		if (balance(node) < -1 && balance(node->dreapta) > 0) {
			node->dreapta = R_Dreapta(node->dreapta);
			return R_Stanga(node);
		}

		return node;
	}
	nod* Delete(nod* node, int valoare)
	{
		if (node == NULL)
			return node;
		else if (valoare < node->valoare)
			node->stanga = Delete(node->stanga, valoare);
		else if (valoare > node->valoare)
			node->dreapta = Delete(node->stanga, valoare);
		else
		{
			nod* st = node->stanga;
			nod* dr = node->dreapta;
			nod* temp = NULL;
			
			if (st == NULL && dr == NULL)
			{
				//nodul nu are copii
				node = temp;
			}
			else if (st == NULL || dr == NULL)
			{
				//nodul are un copil
				if (st != NULL)
				{
					node = st;
					st = temp;
				}
				else if(dr != NULL){
					node = dr;
					dr = temp;
				}
			}
			else {
				//nodul are 2 copii
				nod* succ = succ_jos(node);
				node->valoare = succ->valoare;
				node->dreapta = Delete(node->dreapta, succ->valoare);
			}
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

		// Cazul stanga-stanga
		if (balance(node) > 1 && balance(node->stanga) >= 0) {
			return R_Dreapta(node);
		}

		// Cazul stanga-dreapta
		if (balance(node) > 1 && balance(node->stanga) < 0) {
			node->stanga = R_Stanga(node->stanga);
			return R_Dreapta(node);
		}

		// Cazul dreapta-dreapta
		if (balance(node) < -1 && balance(node->dreapta) <= 0) {
			return R_Stanga(node);
		}

		// Cazul dreapta-stanga
		if (balance(node) < -1 && balance(node->dreapta) > 0) {
			node->dreapta = R_Dreapta(node->dreapta);
			return R_Stanga(node);
		}

		return node;

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

		if (node->valoare == valoare)
			return 1;
		else if (node->valoare > valoare)
			find(node->stanga, valoare);
		else
			find(node->dreapta, valoare);
	}

	//cel mai mic nr mai mare sau egal decat x
	int min(nod* node, int x)
	{	
		int maxim = INT_MAX;
		while (node != NULL) {
			if (node->valoare == x) {
				return x;
			}
			else if (node->valoare > x) {
					maxim = node->valoare;
					node = node->stanga;
				}
			else {
				node = node->dreapta;
			}
		}
		return maxim;
	}

	//cel mai mare nr mai mic sau egal decat x
	int max(nod* node, int x)
	{
		int minim = INT_MIN;
		while (node != NULL) {
			if (node->valoare == x) {
				return x;
			}
			else if (node->valoare < x) {
				minim = node->valoare;
				node = node->dreapta;
			}
			else {
				node = node->stanga;
			}
		}
		return minim;
	}

};

int main()
{
	AVL copacel;
	nod* radacina = NULL;

	int n, x, y, z;
	fin >> n;

	for (int i = 0;i < n;++i)
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
			fout << copacel.max(radacina, y) << std::endl;;
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
