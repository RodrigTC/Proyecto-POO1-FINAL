#include <iostream>
#include<stdlib.h>
#include<string>
#include <vector>
#include"../model/Boleta.h"
#include<fstream>
using namespace std;

class BoletaController
{
	private:
		vector<Boleta> vectorBoleta;
	
	public:
	BoletaController()
	{
		cargarDatosArchivo();
	}
	~BoletaController()
	{
		
	}
	void add(Boleta obj)
	{
		vectorBoleta.push_back(obj);
	}
	Boleta get(int pos)
	{
		return vectorBoleta[pos];
	}
	int size()
	{
		return vectorBoleta.size();
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorBoleta[size() - 1].getCodigo() + 1;
		}
	}
	
	void grabarEnArchivo(Boleta obj)
	{
		try
		{
			fstream archivoBoleta;
			archivoBoleta.open("B.csv",ios::app);
			if(archivoBoleta.is_open())
			{
				archivoBoleta<<obj.getCodigo()<<";"<<obj.getDni()<<";"<<
				obj.getNomApeC()<<";"<<obj.getNomApeV()<<";"<<
				obj.getCantidad()<<";"<< obj.getTotal()<<";"<<obj.getEstado()<<";"<<endl;
				archivoBoleta.close();					
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
			string linea,temporal[6];
			fstream archivoBoleta;
			archivoBoleta.open("B.csv",ios::in);
			if(archivoBoleta.is_open())
			{
				while(!archivoBoleta.eof() && getline(archivoBoleta,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					Boleta objB(stoi(temporal[0]),
								stoi(temporal[1]),
								temporal[2],
								temporal[3],
								stoi(temporal[4]),
								stof(temporal[5]),
								stoi(temporal[6]));			
				    add(objB);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};