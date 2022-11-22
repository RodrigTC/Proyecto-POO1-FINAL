#include <iostream>
#include<stdlib.h>
#include<string>
#include <vector>
#include"../model/Acceso.h"
#include<fstream>
using namespace std;

class AccesoController
{
private:
	vector<Acceso> vectorAcceso;
public:
	AccesoController()
	{
		cargarDatosArchivo();
	}
	~AccesoController()
	{
		
	}
	void add(Acceso obj)
	{
		vectorAcceso.push_back(obj);
	}
	Acceso get(int pos)
	{
		return vectorAcceso[pos];
	}
	int size()
	{
		return vectorAcceso.size();
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorAcceso[size() - 1].getCodigo() + 1;
		}
	}
	void grabarEnArchivo(Acceso obj)
	{
		try
		{
			fstream archivoAcceso;
			archivoAcceso.open("Acceso.csv",ios::app);
			if(archivoAcceso.is_open())
			{
				archivoAcceso<<obj.getCodigo()<<";"<<obj.getNomApe()<<";"<<
					obj.getUsuario()<<";"<<obj.getPassword()<<";"<<endl;
				archivoAcceso.close();					
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
			fstream archivoAcceso;
			archivoAcceso.open("Acceso.csv",ios::in);
			if(archivoAcceso.is_open())
			{
				while(!archivoAcceso.eof() && getline(archivoAcceso,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					Acceso objAcceso(stoi(temporal[0]),temporal[1],temporal[2],temporal[3]);
				    add(objAcceso);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};


