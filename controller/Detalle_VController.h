#include <iostream>
#include <vector>
#include "../model/Detalle_V.h"
#include <fstream>

using namespace std;

class DetalleController
{
	private:
		vector<Detalle_V> vectorDetalle;
	
	public:
	DetalleController()
	{
		cargarDatosArchivo();
	}
	~DetalleController()
	{
		
	}
	void add(Detalle_V obj)
	{
		vectorDetalle.push_back(obj);
	}
	Detalle_V get(int pos)
	{
		return vectorDetalle[pos];
	}
	int size()
	{
		return vectorDetalle.size();
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorDetalle[size() - 1].getCod_V() + 1;
		}
	}
	

	int getPostArray(Detalle_V obj)
	{
		for(int i=0;i<size();i++)
		{
			if(obj.getCod_V() == vectorDetalle[i].getCod_V())
			{
				return i;
			}
		}
		return -1;
	}
	
	
	void grabarEnArchivo(Detalle_V obj)
	{
		try
		{
			fstream archivoDetalle_V;
			archivoDetalle_V.open("Detalle_Venta.csv",ios::app);
			if(archivoDetalle_V.is_open())
			{
				archivoDetalle_V<<obj.getCod_V()<<";"<<obj.getCodPro()<<";"<<
				obj.getCantidad()<<";"<<obj.getPrecio_v()<<";"<<obj.Total()<<";"<<endl;
				archivoDetalle_V.close();					
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	
	void cargarDatosArchivo()
	{
		try
		{
			int i;
			size_t posi;
			string linea,temporal[4];
			fstream archivoDetalle_V;
			archivoDetalle_V.open("Detalles_Venta.csv",ios::in);
			if(archivoDetalle_V.is_open())
			{
				while(!archivoDetalle_V.eof() && getline(archivoDetalle_V,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					Detalle_V objDetalle(stoi(temporal[0]),stoi(temporal[1]),stoi(temporal[2]),stof(temporal[3]));
				    add(objDetalle);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	
	void listarVector(Detalle_V E)
	{
		cout<<"Codigo [ "<<E.getCodPro()<<" ]"<<endl;
		cout<<"Cantidad del Producto: "<<E.getCantidad()<<endl;
		cout<<"Subtotal: "<<E.Total()<<endl;		
	}
};


