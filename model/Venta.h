#include <iostream>
using namespace std;

class Venta
{
	private:
		int cod_v;
		int codcli;
		string fecha_v;
		int v_t;
	public:
		Venta()
		{
		
		}
		~Venta()
		{
		
		}
	
		Venta(int cod, int cod_c, string fecha, int total)
		{
			this->cod_v = cod;
			this->codcli=cod_c;
			this->fecha_v = fecha;
			this->v_t = total;
		}
		
		int setCodigo(int cod)
		{
			return this->cod_v = cod;
		}
		int getCodigo()
	 	{
			return this ->cod_v;
		}
		
		int setCodCliente(int codcli)
		{
			return this->codcli = codcli;
		}
		int getCodCliente()
		{
			return this->codcli;
		}
	
		string setFecha_V(string fecha)
		{
			return this->fecha_v= fecha;
		}
		string getFecha_V()
		{
			return this->fecha_v;
		}
		
		int setTotal_V(int total)
		{
			return this->v_t=total;
		}
		int getTotal_V()
		{
			return this->v_t;
		}
};