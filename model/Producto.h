#include <iostream>
using namespace std;

class producto
{
private:
	int codPro;
	string nomPro;
	float prePro;
	int stkPro;
	int catPro;
	
public:
	producto()
	{
		
	}
	producto(int codPro, string nomPro, float prePro, int stkPro, int catPro) 
	{
		this->codPro=codPro;
		this->nomPro=nomPro;
		this->prePro=prePro;
		this->stkPro=stkPro;
		this->catPro=catPro;
	}
	int getCodigo()
	{
		return this->codPro;
	}
	string getNomPro()
	{
		return this->nomPro;
	}
	float getPrePro()
	{
		return this->prePro;
	}
	int getStkPro()
	{
		return this->stkPro;
	}
	int getCatPro()
	{
		return this->catPro;
	}
	int setCodigo(int cod)
	{
		return this->codPro=cod;
	}
	string setNomPro(string nom)
	{
		return this->nomPro=nom;
	}
	float setPrePro(float pre)
	{
		return this->prePro = pre;
	}
	int setStkPro(int stk)
	{
		return this->stkPro=stk;
	}
	int setCatPro(int cat)
	{
		return this->catPro=cat;
	}
	
};
