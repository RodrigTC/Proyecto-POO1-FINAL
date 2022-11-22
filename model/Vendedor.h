#include <iostream>
using namespace std;

class Personal
{
private:
	int Cod_p;
	string NomApe;
	int dni;
	
public:
	Personal()
	{
		
	}
	
	Personal(int Cod_p, string NomApe, int dni)
	{
		this->Cod_p=Cod_p;
		this->NomApe=NomApe;
		this->dni=dni;
	}
	
	int setCod_p(int cod)
	{
		return this->Cod_p = cod;
	}
	int getCod_p()
	{
		return this->Cod_p;
	}
	
	string setNomApe(string Nom)
	{
		return this->NomApe=Nom;
	}
	string getNomApe()
	{
		return this->NomApe;
	}
	
	int setDni (int d)
	{
		return this ->dni=d;
	}
	int getDni()
	{
		return this->dni;
	}
};
