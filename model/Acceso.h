#include <iostream>
using namespace std;

class Acceso
{
private:
	int     codigo;
	string  nomApe;
    string  usuario;
	string  password;
public:
	Acceso()
	{
		
	}
	Acceso(int cod,string nomApe,string usuario,string password)
	{
		this->codigo = cod;
		this->nomApe = nomApe;
		this->usuario = usuario;
		this->password = password;
	}
	
	//get
	int getCodigo()
	{
		return this->codigo;
	}
	string getNomApe()
	{
		return this->nomApe;
	}
	string getUsuario()
	{
		return this->usuario;
	}
	string getPassword()
	{
		return this->password;
	}

};

	

