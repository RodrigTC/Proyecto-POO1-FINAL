#include <iostream>
using namespace std;

class Categoria
{
private:
	int Codcat;
	string Nomcat;
public:
	Categoria()
	{
		
	}
	~Categoria()
	{
		
	}
	Categoria(int Codcat, string Nomcat)
	{
		this->Codcat=Codcat;
		this->Nomcat=Nomcat;
	}
	int getCodCat()
	{
		return this->Codcat;
	}
	int setCodCat(int cod)
	{
		return this->Codcat=cod;
	}
	string setNomCat(string nom)
	{
		return this->Nomcat=nom;
	}
	string getNomCat()
	{
		return this->Nomcat;
	}
	
};
