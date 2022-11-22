#include <iostream>
#include <vector>
#include<fstream>
#include "../model/Producto.h"
using namespace std;

class ProductoController
{
private:
	vector<producto> vectorProducto;
public:
	ProductoController()
	{
		cargarDatosArchivo();
	}
	void add(producto obj)
	{
		vectorProducto.push_back(obj);
	}
	producto get(int pos)
	{
		return vectorProducto[pos];
	}
	int size()
	{
		return vectorProducto.size();
	}
	
	producto BuscarPorCodigo(int codigo)
	{
		producto objError;
		objError.setNomPro("Error");
		for(int i = 0;i<size();i++)
		{
			if(codigo == get(i).getCodigo())
			{
				return get(i);
			}
		}
		return objError;
	}
	
	producto BuscarPorCategoria(int codigo)
	{
		producto objError;
		objError.setNomPro("Error");
		for(int i = 0;i<size();i++)
		{
			if(codigo == get(i).getCatPro())
			{
				return get(i);
			}
		}
		return objError;
	}
	
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorProducto[size() - 1].getCodigo() + 1;
		}
	}
    
	
	bool modificar(producto obj,string nombrep,float precio,int stock,int categoria)
	{
		for(int i = 0;i<size();i++)
		{
			if(obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setNomPro(nombrep);
				vectorProducto[i].setPrePro(precio);
				vectorProducto[i].setStkPro(stock);
				vectorProducto[i].setCatPro(categoria);
				
				return true;
			}
		}
		return false;
	}
	
	int getPostArray(producto obj)
	{
		for(int i=0;i<size();i++)
		{
			if(obj.getCodigo() == vectorProducto[i].getCodigo())
			{
				return i;
			}
		}
		return -1;
	}
	
	void remove(producto obj)
	{
		vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
	}
	
	void grabarEnArchivo(producto obj)
	{
		try
		{
			fstream archivoproducto;
			archivoproducto.open("productos.csv",ios::app);
			if(archivoproducto.is_open())
			{
				archivoproducto<<obj.getCodigo()<<";"<<obj.getNomPro()<<";"<<obj.getPrePro()<<";"<<obj.getStkPro()<<";"<<obj.getCatPro()<<";"<<endl;
				archivoproducto.close();					
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	
	void grabarEnArchivoModificado()
	{
		try
		{
			fstream archivoproducto;
			archivoproducto.open("productos.csv",ios::out);
			if(archivoproducto.is_open())
			{
				for(producto x: vectorProducto)
				{
					archivoproducto<<x.getCodigo()<<";"<<x.getNomPro()<<";"<<x.getPrePro()<<";"<<x.getStkPro()<<";"<<x.getCatPro()<<";"<<endl;
				}
			}
			archivoproducto.close();
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
			string linea,temporal[5];
			fstream archivoproducto;
			archivoproducto.open("productos.csv",ios::in);
			if(archivoproducto.is_open())
			{
				while(!archivoproducto.eof() && getline(archivoproducto,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					producto objProducto(stoi(temporal[0]),temporal[1],stof(temporal[2]),stoi(temporal[3]),stoi (temporal[4]));
					add(objProducto);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};

	
