#include <iostream>
using namespace std;

class Boleta
{
	private:
		int cod_v;
		int dni_c;
		string nomApeC; 
		string nomApeV;
		int cantidad;
		float total;
		int estado;
	public:
		Boleta()
		{
		
		}
		~Boleta()
		{
			
		}
	
		Boleta(int cod, int dni, string nomApeC, string nomApeV,  int c, float t, int estado)
		{
			this->cod_v = cod;
			this->dni_c=dni;
			this->nomApeC=nomApeC;
			this->nomApeV=nomApeV;
			this->cantidad=c;
			this->total= t;
			this->estado= estado;
		}
		
		int setCodigo(int cod)
		{
			return this->cod_v = cod;
		}
		int getCodigo()
	 	{
			return this ->cod_v;
		}
		
		int setDni(int dni)
		{
			return this->dni_c = dni;
		}
		int getDni()
		{
			return this->dni_c;
		}
	
		string setNomApeC(string nomApeC)
		{
			return this->nomApeC= nomApeC;
		}
		string getNomApeC()
		{
			return this->nomApeC;
		}
		
		string setNomApeV(string nomApeV)
		{
			return this->nomApeV= nomApeV;
		}
		string getNomApeV()
		{
			return this->nomApeV;
		}
			
		int setCantidad(int c)
		{
			return this->cantidad = c;
		}
		int getCantidad()
	 	{
			return this ->cantidad;
		}
				
		int setTotal(int t)
		{
			return this->total=t;
		}
		int getTotal()
		{
			return this->total;
		}
		int setEstado(int estado)
		{
			return this->estado=estado;
		}
		int getEstado()
		{
			return this->estado;
		}
};