#include <iostream>
#include <vector>
#include<fstream>
#include "../model/Categoria.h"

using namespace std;

class CategoriaController
{
private:
	vector<Categoria> vectorCategoria;
public:
	CategoriaController()
	{
		cargarDatosArchivo();
	}
	~ CategoriaController()
	{
		
	}
	void add(Categoria obj)
	{
		vectorCategoria.push_back(obj);
	}
	Categoria get(int pos)
	{
		return vectorCategoria[pos];
	}
	int size()
	{
		return vectorCategoria.size();
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorCategoria[size() - 1].getCodCat() + 1;
		}
	}
	void cargarDatosArchivo()
	{
		try
		{
			int i;
			size_t posi;
			string linea,temporal[2];
			fstream archivocategoria;
			archivocategoria.open("Categorias.csv",ios::in);
			if(archivocategoria.is_open())
			{
				while(!archivocategoria.eof() && getline(archivocategoria,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					Categoria objCategoria(stoi(temporal[0]),temporal[1]);
					add(objCategoria);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
		
	int getPostArray(Categoria obj)
	{
		for(int i=0;i<size();i++)
		{
			if(obj.getCodCat() == vectorCategoria[i].getCodCat())
			{
				return i;
			}
		}
		return -1;
	}
	
	Categoria BuscarPorCodigo(int codigo)
	{
		Categoria objError;
		objError.setNomCat("Error");
		for(int i = 0;i<size();i++)
		{
			if(codigo == get(i).getCodCat())
			{
				return get(i);
			}
		}
		return objError;
	}
	
};
