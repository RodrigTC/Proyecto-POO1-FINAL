#include <iostream>
#include <vector>
#include "../model/Venta.h"
#include <fstream>

using namespace std;

class VentaController
{
private:
	vector<Venta> vectorVenta;
public:
	VentaController()
	{
		cargarDatosArchivo();
	}
	~VentaController()
	{
		
	}
	void add(Venta obj)
	{
		vectorVenta.push_back(obj);
	}
	Venta get(int pos)
	{
		return vectorVenta[pos];
	}
	int size()
	{
		return vectorVenta.size();
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorVenta[size() - 1].getCodigo() + 1;
		}
	}
	
	void grabarEnArchivo(Venta obj)
	{
		try
		{
			fstream archivoVenta;
			archivoVenta.open("V.csv",ios::app);
			if(archivoVenta.is_open())
			{
				archivoVenta<<obj.getCodigo()<<";"<<obj.getCodCliente()<<";"<<obj.getFecha_V()<<";"<<
					obj.getTotal_V()<<";"<<endl;
				archivoVenta.close();					
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
			string linea,temporal[3];
			fstream archivoVenta;
			archivoVenta.open("V.csv",ios::in);
			if(archivoVenta.is_open())
			{
				while(!archivoVenta.eof() && getline(archivoVenta,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					Venta objVenta(stoi(temporal[0]),stoi(temporal[1]),temporal[2],stoi(temporal[3]));
					add(objVenta);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};