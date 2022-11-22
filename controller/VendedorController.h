#include <iostream>
#include <vector>
#include<fstream>
#include "../model/Vendedor.h"

using namespace std;

class PersonalController
{
private:
	vector<Personal> vectorPersonal;
public:
	PersonalController()
	{
		cargarDatosArchivo();
	}
	~PersonalController()
	{
		
	}
	void add(Personal obj)
	{
		vectorPersonal.push_back(obj);
	}
	Personal get(int pos)
	{
		return vectorPersonal[pos];
	}
	int size()
	{
		return vectorPersonal.size();
	}
	Personal BuscarPorCodigo(int codigo)
	{
		Personal objError;
		objError.setNomApe("Error");
		for(int i = 0;i<size();i++)
		{
			if(codigo == get(i).getCod_p())
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
			return 	vectorPersonal[size() - 1].getCod_p() + 1;
		}
	}
	
	
	bool modificar(Personal obj,string NomApe, int dni)
	{
		for(int i = 0;i<size();i++)
		{
			if(obj.getCod_p() == get(i).getCod_p())
			{
				vectorPersonal[i].setNomApe(NomApe);
				vectorPersonal[i].setDni(dni);
				
				return true;
			}
		}
		return false;
	}
	
	int getPostArray(Personal obj)
	{
		for(int i=0;i<size();i++)
		{
			if(obj.getCod_p() == vectorPersonal[i].getCod_p())
			{
				return i;
			}
		}
		return -1;
	}
	
	void remove(Personal obj)
	{
		vectorPersonal.erase(vectorPersonal.begin() + getPostArray(obj));
	}
	
	void grabarEnArchivo(Personal obj)
	{
		try
		{
			fstream archivopersonal;
			archivopersonal.open("personal.csv",ios::app);
			if(archivopersonal.is_open())
			{
				archivopersonal<<obj.getCod_p()<<";"<<obj.getNomApe()<<";"<<obj.getDni()<<";"<<endl;
				archivopersonal.close();					
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
			fstream archivopersonal;
			archivopersonal.open("personal.csv",ios::out);
			if(archivopersonal.is_open())
			{
				for(Personal x: vectorPersonal)
				{
					archivopersonal<<x.getCod_p()<<";"<<x.getNomApe()<<";"<<x.getDni()<<";"<<endl;
				}
			}
			archivopersonal.close();
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
			fstream archivopersonal;
			archivopersonal.open("personal.csv",ios::in);
			if(archivopersonal.is_open())
			{
				while(!archivopersonal.eof() && getline(archivopersonal,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						i++;
					}
					
					Personal objPersonal(stoi(temporal[0]),temporal[1],stoi(temporal[2]));
					add(objPersonal);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};
