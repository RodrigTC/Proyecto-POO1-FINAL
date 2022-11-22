#include <iostream>
using namespace std;

class Cliente
{
private:
	int codcli; 
	string nomApe;
	int dni;
	string direccion;
	
public:
	Cliente()
	{
		
	}
	Cliente(int codcli,string nomApe, int dni,string direccion)
	{
		this->codcli=codcli;
		this->nomApe=nomApe;
		this->dni=dni;
		this->direccion=direccion;
		
	}
	void setNomApe(string nomApe)
	{
		this->nomApe = nomApe;
	}
	void setCodCliente(int codcli)
	{
		this->codcli = codcli;
	}
	void setDNI(int dni)
	{
		this->dni = dni;
	}
	void setDireccion(string direccion)
	{
		this->direccion = direccion;
	}
	string getNomApe()
	{
		return nomApe;
	}
	int getCodCliente()
	{
		return codcli;
	}
	int getDNI()
	{
		return dni;
	}
	string getDireccion()
	{
		return direccion;
	}
	
};
