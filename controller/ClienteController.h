#include <iostream>
#include <vector>
#include "../model/Cliente.h"
#include <fstream>
using std::stoi;
using namespace std;

class ClienteController
{
private:
	vector<Cliente> vectorCliente;
public:
	ClienteController()
	{
		cargarDatosDelArchivoAlVector();
		//vector<Cliente> vectorCliente;
	}
	~ClienteController()
	{
		
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorCliente[size() - 1].getCodCliente() + 1;
		}
	}
	void add (Cliente obj)
	{
		vectorCliente.push_back(obj);
	}
	Cliente get(int pos)
	{
		return vectorCliente[pos];
	}
	int size()
	{
		return vectorCliente.size();
	}
	Cliente buscarPorCodigo(int cod)
	{
		Cliente objError;
		objError.setNomApe("Error");
		for(int i = 0;i<size();i++)
		{
			if(cod == get(i).getCodCliente())
			{
				return get(i);
			}
		}
		return objError;
	}
	
	int getPostArray(Cliente obj)
	{
		for(int i=0;i<size();i++)
		{
			if(obj.getCodCliente() == vectorCliente[i].getCodCliente())
			{
				return i;
			}
		}
		return -1;
	}
	void remove(Cliente obj)
	{
		vectorCliente.erase(vectorCliente.begin() + getPostArray(obj));
	}
	bool modify(Cliente obj, string nomApe, int dni, string direccion)
	{
		for(int i=0;i<size();i++)
		{
			if(obj.getCodCliente() == get(i).getCodCliente())
			{
				vectorCliente[i].setNomApe(nomApe);
				vectorCliente[i].setDNI(dni);
				vectorCliente[i].setDireccion(direccion);
				return true;
			}
		}
		return false;
	}
	
	void grabarEnArchivo(Cliente cliente)
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("DATOS DEL CLIENTE.csv",ios::app);
			if(archivoCliente.is_open())
			{
				archivoCliente<<cliente.getCodCliente()<<";"<<cliente.getNomApe()<<";"<<cliente.getDNI()<<";"<<cliente.getDireccion()<<";"<<endl;
				archivoCliente.close();
			}
			
		}
		catch(exception e)
		{
			cout<<"ERROR AL GRABAR EL REGISTRO";
		}
	}
	
	void cargarModificado()
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("DATOS DEL CLIENTE.csv",ios::out);
			if(archivoCliente.is_open())
			{
				for(Cliente z: vectorCliente)
				{
					archivoCliente<<z.getCodCliente()<<";"<<z.getNomApe()<<";"<<z.getDNI()<<";"<<z.getDireccion()<<";"<<endl;
				}
				archivoCliente.close();
			}
		}
		catch(exception e)
		{
			cout<<"ERROR AL GRABAR EL REGISTRO";
		}
	}
	
	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posmax;
			string linea;
			string temporal[4];
			fstream archivoCliente;
			archivoCliente.open("DATOS DEL CLIENTE.csv",ios::in);
			if(archivoCliente.is_open())
			{
				while(!archivoCliente.eof())
				{
					while(getline(archivoCliente,linea))
					{
						i=0;
						while((posmax = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posmax);
							linea.erase(0,posmax+1);
							i++;
						}
						Cliente cliente;
						cliente.setCodCliente(std::stoi(temporal[0]));
						cliente.setNomApe(temporal[1]);
						cliente.setDNI(std::stoi(temporal[2]));
						cliente.setDireccion(temporal[3]);
						
						add(cliente);
					}
				}
			}
			archivoCliente.close();
		}
		catch(exception e)
		{
			cout<<"Ocurrio un ERROR al momento de leer el archivo";
		}
	}
	
	
};

