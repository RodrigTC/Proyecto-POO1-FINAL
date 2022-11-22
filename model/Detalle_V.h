#include <iostream>
using namespace std;

class Detalle_V
{
	private:	
		int cod_v;
		int codPro;
		int cantidad;
		float precio_v;

	
	public:
		Detalle_V()
		{
		
		}
		Detalle_V(int cod, int cod_pro, int c, float precio)
		{
			this->cod_v = cod;
			this->codPro = cod_pro;
			this->cantidad= c;
			this->precio_v= precio;
	
		}
		
		int setCod_V(int cod)
		{
			return this->cod_v = cod;
		}
		int getCod_V()
		{
			return this->cod_v;
		}
		
		int setCodPro(int cod_pro)
		{
			return this->codPro = cod_pro;
		}
		int getCodPro()
		{
			return this->codPro;
		}
		
		int setCantidad(int c)
		{
			return this->cantidad=c;
		}
		int getCantidad()
		{
			return this->cantidad;
		}
		
		float setPrecio_v(float precio)
		{
			return this->precio_v=precio;
		}
		float getPrecio_v()
		{
			return this->precio_v;
		}
		
		float Total()
		{
			return this ->getPrecio_v() * getCantidad();
		}
};
		