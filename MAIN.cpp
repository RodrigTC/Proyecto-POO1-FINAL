#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include<cstring>
#include<windows.h>
#include "controller/AccesoController.h"
#include "controller/ProductoController.h"
#include "controller/ClienteController.h"
#include "controller/VentaController.h"
#include "controller/Detalle_VController.h"
#include "controller/VendedorController.h"
#include "controller/CategoriaController.h"
#include "controller/BoletaController.h"

using namespace std;

AccesoController* accController = new AccesoController();
ProductoController* proController = new ProductoController();
ClienteController* cliController = new ClienteController();
VentaController* vController = new VentaController();
DetalleController* dController= new DetalleController();
PersonalController* pController= new PersonalController();
CategoriaController* catController = new CategoriaController();
BoletaController* bcontroller = new BoletaController();

//Prototipos
void inicio();
void registrarse();
void iniciarSesion();
void menuVista();
void ingresoAdmin();
void menuPrincipalAdmin();
void menuPrincipalVend();
void ListarUsuarios();

void menuProductos();
void agregarProducto();
void listarProductos();
void modificarProducto();
void buscarProductos();
void buscarPorCodigo();
void buscarPorCategoria();
void eliminar();

void menuClientes();
void agregarCliente();
void listarClientes();
void modificarCliente();
void buscarCliente();
void eliminarCliente();

void menuVenta();
void GenerarVenta();
void CancelarVenta();

void agregarPersonal();
void menuPersonal();
void listarPersonal();
void modificarPersonal();
void buscarPersonal();

void buscarCategoria();
void listarCategoria();
void gotoxy(int x, int y);


void gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int main(){
	
	inicio();
	
    return 0;
}

void inicio(){
	int opc;
	do{
		system("cls");
		gotoxy(35,10);cout<<"*************************"<<endl;
		gotoxy(35,11);cout<<"|       BIENVENIDO      |"<<endl;
		gotoxy(35,12);cout<<"| Iniciar sesion....[1] |"<<endl;
		gotoxy(35,13);cout<<"| Registrarse.......[2] |"<<endl;
		gotoxy(35,14);cout<<"| Salir.............[3] |"<<endl;
		gotoxy(35,15);cout<<"| Elija una opcion:     |";
		gotoxy(35,16);cout<<"|                       |";
		gotoxy(35,17);cout<<"*************************"<<endl;		
		gotoxy(45,16);cin>>opc;
		cin.ignore();
		switch(opc)
		{
		    case 1: 
				system("cls");
				iniciarSesion();
				break;
				
			case 2:
				system("cls");
				registrarse();
				break;
		    case 3:
				system("cls");
				gotoxy(35,15);cout<<"Gracias por usar nuestro programa\n";
				break;
		    default: 
				system("cls");
				gotoxy(35,15);cout<<"Ingresa una opcion correcta[1-3]\n";
				system("pause");
				break;
		}
		
	} while(opc!=3);
}
	
void registrarse()
{
	string nApe,usuario,pass;
	int cod,dni;
	char password;
	
	cod = accController->getCorrelativo();
	gotoxy(35,11);cout<<"************************["<<cod<<"]**********************";
	
	gotoxy(35,12);cout<<"| Nombres y Apellidos:                          |";
	gotoxy(35,13);cout<<"| Ingrese su DNI:                               |";

	gotoxy(35,14);cout<<"*************************************************";
	gotoxy(58,12);getline(cin,nApe);
	gotoxy(58,13);cin>>dni;cin.ignore();
	system("cls");
	
	gotoxy(35,11);cout<<"Estimado/a "<<nApe<<endl;
	gotoxy(35,12);cout<<"Ingrese un usuario: ";
	getline(cin,usuario);
	gotoxy(35,13);cout<<"Ingrese una contrasenia: ";
	password = getch();
	
	while(password != 13)
	{
		if(password != 8)
		{
			pass.push_back(password);
			cout<<"*";
		}
		else
		{
			if(pass.length()>0)
			{
				cout<<"\b \b";
				pass = pass.substr(0,pass.length() - 1);
			}
		}
		password = getch();
	}
	gotoxy(35,15);cout<<"****************************";
	gotoxy(35,16);cout<<"| Gracias por registrarse. |";
	gotoxy(35,17);cout<<"| ya puede iniciar sesion! |";
	gotoxy(35,18);cout<<"****************************"<<endl;
	
	gotoxy(35,19);system("pause");
	system("cls");
	
	Acceso objacc(cod,nApe,usuario,pass);
	accController->add(objacc);
	accController->grabarEnArchivo(objacc);
	
	Personal objper(cod,nApe,dni);
	pController->add(objper);
	pController->grabarEnArchivo(objper);
}

void iniciarSesion()
{
	string user,pass;
	int intento = 0;
	char clave;
	bool ingreso = false;
	
	do
	{
		
		gotoxy(35,12);cout<<"Ingrese su usuario: ";
		getline(cin,user);
		
		gotoxy(35,13);cout<<"Ingrese su clave de acceso: ";
		
		clave=getch();
		
		pass= "";
		
		
		while(clave != 13)
		{
			if(clave != 8)
			{
				pass.push_back(clave);
				cout<<"*";
			}
			else
			{
			    if(pass.length()>0)
				{
					cout<<"\b \b";
					pass = pass.substr(0,pass.length() - 1);
				}
			}
			clave = getch();
		}
		for(int i = 0;i < accController->size();i++)
		{
			if(accController->get(i).getUsuario()==user && accController->get(i).getPassword()==pass)
			{
				ingreso = true;
				break;
			}
		}
		
		if(ingreso == false)
		{
			gotoxy(35,14);cout<<"El usuario o contrasenia son incorrectos...";
			gotoxy(35,15);cout<<"Intentos: "<<intento+1<<" de 3"<<endl;
			intento++;
			system("pause");
			system("cls");
		}
	}
	while(intento<3 && ingreso == false);
	
	if(ingreso == true)
	{
		gotoxy(35,14);cout<<"Accediendo al sistema..."<<endl;
	    system("pause");
		menuVista();
	}
	else
	{
		gotoxy(35,15);cout<<"Solo se permite maximo 3 intentos!!!"<<endl;
		system("pause");
		system("cls");
	}
}

void menuVista()
{
	int x;
	do
	{
		system("cls");
		gotoxy(35,10);cout<<"********************************";
		gotoxy(35,11);cout<<"|        Bienvenido!!!         |";
		gotoxy(35,12);cout<<"| Vista de Administrador...[1] |";
		gotoxy(35,13);cout<<"| Vista de Vendedor........[2] |";
		gotoxy(35,14);cout<<"| Salir....................[3] |";
		gotoxy(35,15);cout<<"| Elija la opcion que desea:   |";
		gotoxy(35,16);cout<<"|                              |";
		gotoxy(35,17);cout<<"********************************";
		gotoxy(50,16);cin>>x;
		
		switch(x)
        {
    	    case 1: 
    	   	    system("cls");
    	   	    ingresoAdmin(); 
    	    	break;
    	    case 2:
    			system("cls");
    	    	menuPrincipalVend();
    	    	break;
    	    case 3:
    			system("cls");
			    gotoxy(27,15);cout<<"Sera redireccionado al inicio de Sesion\n";
			    system("pause");
    	    default: 
				gotoxy(35,15);cout<<"Ingresa una opcion correcta[1-6]\n";
				system("pause");
				menuVista();
				break;
	    }
    }while(x!=3);
    
}

void ingresoAdmin()
{
	string pass;
	int intento = 0;
	char clave;
	bool ingreso = false;
	
	do
	{	
		gotoxy(35,13);cout<<"Ingrese la clave de administrador: ";
		
		clave=getch();
		pass= "";
		
		while(clave != 13)
		{
			if(clave != 8)
			{
				pass.push_back(clave);
				cout<<"*";
			}
			else
			{
			    if(pass.length()>0)
				{
					cout<<"\b \b";
					pass = pass.substr(0,pass.length() - 1);
				}
			}
			clave = getch();
		}
		
		if(pass == "Admin2022")
		{
			ingreso = true;
			break;
		}
		
		if(ingreso == false)
		{
			gotoxy(35,15);cout<<"El usuario o contrasenia son incorrectos...";
			gotoxy(35,16);cout<<"Intentos: "<<intento+1<<" de 3"<<endl;
			intento++;
			system("pause");
			system("cls");
		}	
	}
	while(intento<3 && ingreso == false);
	
	if(ingreso == true )
	{
		gotoxy(35,15);cout<<"Accediendo al sistema..."<<endl;
	    system("pause");
	    menuPrincipalAdmin();
	}
	
}

void menuPrincipalAdmin()
{
	int x;
	do
	{
		system("cls");
		gotoxy(35,10);cout<<"**************************************";
		gotoxy(35,11);cout<<"|             Bienvenido             |";
		gotoxy(35,12);cout<<"| Listar Usuarios Registrados.....[1]|";
		gotoxy(35,13);cout<<"| Clientes........................[2]|";
		gotoxy(35,14);cout<<"| Productos.......................[3]|";
		gotoxy(35,15);cout<<"| Vendedores......................[4]|";
		gotoxy(35,16);cout<<"| Ventas..........................[5]|";
		gotoxy(35,17);cout<<"| Salir...........................[6]|";
		gotoxy(35,18);cout<<"| Elija una opcion:                  |";
		gotoxy(35,19);cout<<"|                                    |";
		gotoxy(35,20);cout<<"**************************************";
		gotoxy(50,19);cin>>x;
		
		
		switch(x)
		{
		case 1:
			system("cls");
			ListarUsuarios();
			break;
			
		case 2:
			system("cls");
			menuClientes();
			break;
			
		case 3:
			system("cls");
			menuProductos();
			break;
			
		case 4:
			system("cls");
			menuPersonal();
			break;
			
		case 5:
			system("cls");
			GenerarVenta();
			break;
			
		case 6:
			system("cls");
			gotoxy(35,15);cout<<"Sera redireccionado al inicio de Sesion\n";
			system("pause");
			inicio();
			break;
			
		default:
			system("cls");
			gotoxy(35,15);cout<<"Ingresa una opcion correcta[1-6]\n";
			gotoxy(35,16);system("pause");
			menuPrincipalAdmin();
			break;	
		}
	} while(x != 6);
}

void menuPrincipalVend()
{
	int x;
	do
	{
		system("cls");
		gotoxy(35,10);cout<<"\tBienvenido";
		gotoxy(35,11);cout<<"Clientes.........[1]"<<endl;
		gotoxy(35,12);cout<<"Productos........[2]"<<endl;
		gotoxy(35,13);cout<<"Ventas...........[3]"<<endl;
		gotoxy(35,14);cout<<"Salir............[4]"<<endl;
		gotoxy(35,15);cout<<"Elija una opcion: ";
		cin>>x;
		
		switch(x)
		{
		case 1:
			system("cls");
			menuClientes();
			break;	
		case 2:
			system("cls");
			menuProductos();
			break;	
		case 3:
			system("cls");
			GenerarVenta();
			break;	
		case 4:
			system("cls");
			menuVista();
			break;
		default: 
			system("cls");
			gotoxy(35,15);cout<<"Ingresa una opcion correcta[1-6]\n";
			gotoxy(35,16);system("pause");
			menuPrincipalVend();
			break;	
		}
	} while(x != 4);
}

void ListarUsuarios()
{
	gotoxy(35,5);cout<<"Registro de Usuarios";	
	for(int i = 0;i<accController->size();i++)
	{
		gotoxy(35,6+i*5);cout<<"*";
		gotoxy(35,7+i*5);cout<<"Codigo: "<<accController->get(i).getCodigo();
		gotoxy(35,8+i*5);cout<<"Nombre: "<<accController->get(i).getNomApe();
		gotoxy(35,9+i*5);cout<<"Usuario: "<<accController->get(i).getUsuario();
		gotoxy(35,10+i*5);cout<<"Clave de acceso: "<<accController->get(i).getPassword()<<"\n";
	}
	system("pause");
	system("cls");
	menuPrincipalAdmin();
}

void menuProductos(){
	system("cls");
	int opc;
	
	do{
		gotoxy(35,10);cout<<"*************************************";
		gotoxy(35,11);cout<<"|  BIENVENIDOS AL MENU DE PRODUCTOS |";
		gotoxy(35,12);cout<<"| Agregar productos.............[1] |";
		gotoxy(35,13);cout<<"| Listar productos..............[2] |";
		gotoxy(35,14);cout<<"| Modificar productos...........[3] |";
		gotoxy(35,15);cout<<"| Buscar productos..............[4] |";
		gotoxy(35,16);cout<<"| Eliminar productos............[5] |";
		gotoxy(35,17);cout<<"| Regresar......................[6] |";
		gotoxy(35,18);cout<<"| Elija una opcion:                 |";
		gotoxy(35,19);cout<<"|                                   |";
		gotoxy(35,20);cout<<"*************************************";
		
		gotoxy(50,19);cin>>opc;
		switch(opc)
		{
		case 1: 
			system("cls");
			agregarProducto();
			break;
			
		case 2:
			system("cls");
			listarProductos();
			break;
		case 3:
			system("cls");
			modificarProducto();
			break;
		case 4:
			system("cls");
			buscarProductos();
			break;
		case 5:
			system("cls");
			eliminar();
			break;
		case 6:
			system("pause");	
			break;
		default: 
			system("cls");
			gotoxy(35,15);cout<<"Ingresa una opcion correcta[1-3]\n";
			gotoxy(35,16);system("pause");
			break;
		}
		
	} while(opc!=6);
}

void agregarProducto()
{
	int    cod,stock,categoria;
	string nombre;
	float  precio;
    string opc;
	
	do{
		gotoxy(35,10);cout<<"\tAGREGAR NUEVOS PRODUCTOS"<<endl;
		
		
		cod = proController->getCorrelativo();
		gotoxy(35,11);cout<<"******["<<cod<<"]******"<<endl;
		cin.ignore();
		
		gotoxy(35,12);cout<<"Nombre del producto: ";
		getline(cin,nombre);
		
		gotoxy(35,13);cout<<"Precio del producto: ";
		cin>>precio;
		
		gotoxy(35,14);cout<<"Stock del producto : ";
		cin>>stock;
		cin.ignore();
		
		
		listarCategoria();
		
		gotoxy(35,40);cout<<"Ingrese la opcion de la categoria del producto: ";
		gotoxy(35,41);cin>>categoria;
		
		producto objprod(cod,nombre,precio,stock,categoria);
		proController->add(objprod);
		proController->grabarEnArchivo(objprod);
		
		gotoxy(35,43);cout<<"¿Desea ingresar un nuevo producto? SI o NO: ";
		gotoxy(35,44);cin>>opc;
		system("cls");
	} while(opc == "SI" || opc == "si");
	menuProductos();
}	
	
void listarProductos()
{
	gotoxy(35,3);cout<<"\t LISTA DE PRODUCTOS";
	gotoxy(35,4);cout<<"****************************************";
	if(proController->size()==0)
	{
		gotoxy(35,5);cout<<"\nNo hay ningun producto registrado por ahora..."<<endl;
		
		system("pause");
		
		menuProductos();
	}
	else
	{
		for(int i = 0;i < proController->size();i++)
		{
			gotoxy(35,5+i*6);cout<<"Codigo: "<<proController->get(i).getCodigo();
			gotoxy(35,6+i*6);cout<<"Nombre: "<<proController->get(i).getNomPro();
			gotoxy(35,7+i*6);cout<<"Precio: "<<proController->get(i).getPrePro();
			gotoxy(35,8+i*6);cout<<"Stock: "<<proController->get(i).getStkPro();
			gotoxy(35,9+i*6);cout<<"Categoria: "<<proController->get(i).getCatPro();
			gotoxy(35,10+i*6);cout<<"****************************************"<<endl;
		}
		system("pause");
		
		menuProductos();
	}
}

void modificarProducto()
{

	string nomP;
	int stkP,code,catP;
	float preP;
	gotoxy(35,11);cout<<"Si desea modificar un producto ingrese el codigo de este: ";
	cin>>code;
	producto pObj = proController->BuscarPorCodigo(code);
	
	gotoxy(35,12);cout<<"*****Registro Encontrado*****";
	gotoxy(35,13);cout<<"Codigo   : "<<pObj.getCodigo();
	gotoxy(35,14);cout<<"Nombre   : "<<pObj.getNomPro();
	gotoxy(35,15);cout<<"Precio   : "<<pObj.getPrePro();
	gotoxy(35,16);cout<<"Stock    : "<<pObj.getStkPro();
	gotoxy(35,17);cout<<"Categoria: "<<pObj.getCatPro();
	cin.ignore();
	
	gotoxy(35,18);cout<<"\t MODIFICANDO CAMPOS";
	gotoxy(35,19);cout<<"Nombre modificado   : ";
	getline(cin,nomP);
	gotoxy(35,20);cout<<"Precio modificado   : ";
	cin>>preP;
	gotoxy(35,21);cout<<"Stock modificado    : ";
	cin>>stkP;
	cin.ignore();
	
	listarCategoria();
		
	gotoxy(35,30);cout<<"Ingrese la opcion de la categoria del producto: ";
	cin>>catP;
		
	bool estado = proController->modificar(pObj,nomP,preP,stkP,catP);
	
	if (estado ==true)
	{
		gotoxy(35,32);cout<<"Registro modificado satisfactoriamente!!!";
		proController->grabarEnArchivoModificado();
	}
	else
	{
		gotoxy(35,18);cout<<"No encontro el registro a modificar!";
		system("pause");
		menuProductos();
		
	}
	system("pause");
	system("cls");
}

void buscarProductos()
{
	int op;
	
	do
	{	
		gotoxy(35,11);cout<<"\t BUSQUEDA DE PRODUCTOS"<<endl;
		gotoxy(35,12);cout<<"\t BUSCAR POR CODIGO.............[1]"<<endl;
		gotoxy(35,13);cout<<"\t BUSCAR POR CATEGORIA..........[2]"<<endl;
		gotoxy(35,17);cout<<"\t Regresar......................[3]"<<endl;
		gotoxy(35,18);cout<<"\t Elija una opcion: ";
		cin>>op;
	
		switch(op)
		{	
			case 1:
			system("cls");
			buscarPorCodigo();
			break;
		
			case 2:
			system("cls");
			buscarPorCategoria();
			break;
		
			case 3:
			system("cls");
			menuProductos();
			break;
		
			default:
			system("cls");
			gotoxy(35,19);cout<<"Ingresa una opcion correcta[1-3]\n";
			buscarProductos();
			break;
		}
	}
	while(op!=3);
	
}

void buscarPorCodigo()
{
	int cod;
	gotoxy(35,11);cout<<"\tBuscar productos";
	gotoxy(35,12);cout<<"Ingrese el codigo del producto a buscar: ";
	cout<<"\n";
	cin>>cod;
	
	producto pro = proController->BuscarPorCodigo(cod);
	
	if(pro.getNomPro() != "Error")
	{
		gotoxy(35,13);cout<<"\t DATOS DEL PRODUCTO ENCONTRADO";
		gotoxy(35,14);cout<<"Codigo: "<<pro.getCodigo()<<endl;
		gotoxy(35,15);cout<<"Nombre: "<<pro.getNomPro()<<endl;
		gotoxy(35,16);cout<<"Precio: "<<pro.getPrePro()<<endl;
		gotoxy(35,17);cout<<"Stock: "<<pro.getStkPro()<<endl;
		gotoxy(35,18);cout<<"Categoria: "<<pro.getCatPro()<<endl;
		system("pause");
		menuProductos();
	}
	else
	{
		gotoxy(35,15);cout<<"No se encontro ningun producto!!!\n";
		
	}
	
	system("pause");
	menuProductos();
}

void buscarPorCategoria()
{
	int cod;
	gotoxy(35,11);cout<<"\tBuscar productos por categoria";
	gotoxy(35,12);cout<<"Ingrese el codigo de la categoria: ";
	listarCategoria();
	cin>>cod;
		
	producto proc = proController->BuscarPorCategoria(cod);
	Categoria cat = catController->BuscarPorCodigo(cod);
	
	do
	{
		cout<<"\t DATOS DEL PRODUCTO ENCONTRADO"<<endl;
		cout<<"Codigo: "<<proc.getCodigo()<<endl;
		cout<<"Nombre: "<<proc.getNomPro()<<endl;
		cout<<"Precio: "<<proc.getPrePro()<<endl;
		cout<<"Stock: "<<proc.getStkPro()<<endl;
		cout<<"Categoria: "<<proc.getCatPro()<<endl;
	}
	while(proc.getCatPro()==cod);
	
	
	system("pause");
	menuProductos();
	
	
}

void eliminar(){
	int cod;
	gotoxy(35,13);cout<<"Ingrese codigo a buscar: ";
	cin>>cod;
	producto objEliminar = proController->BuscarPorCodigo(cod);
	
	if(objEliminar.getNomPro() !="Error")
	{
		proController->remove(objEliminar);
		gotoxy(35,14);cout<<"Registro eliminado satisfactoriamente!!!";
		proController->grabarEnArchivoModificado();
		system("pause");
		menuProductos();
	}
	else
	{
		gotoxy(35,14);cout<<"No se encontro el registro!";
		system("pause");
		menuProductos();
	}
}

	
	
void menuClientes()
{
	system("cls");
	int opc1;
	
	do{
		gotoxy(35,11);cout<<"\t BIENVENIDOS AL MENU DE CLIENTES"<<endl;
		gotoxy(35,12);cout<<"\t Agregar Cliente..............[1]"<<endl;
		gotoxy(35,13);cout<<"\t Listar Clientes..............[2]"<<endl;
		gotoxy(35,14);cout<<"\t Modificar Cliente............[3]"<<endl;
		gotoxy(35,15);cout<<"\t Buscar Cliente...............[4]"<<endl;
		gotoxy(35,16);cout<<"\t Eliminar Clientes............[5]"<<endl;
		gotoxy(35,17);cout<<"\t Regresar.....................[6]"<<endl;
		gotoxy(35,18);cout<<"\t Elija una opcion: ";
		cin>>opc1;
		switch(opc1)
		{
		case 1: 
			system("cls");
			agregarCliente();
			break;
			
		case 2:
			system("cls");
			listarClientes();
			break;
		case 3:
			system("cls");
			modificarCliente();
			break;
		case 4:
			system("cls");
			buscarCliente();
			break;
		case 5:
			system("cls");
			eliminarCliente();
			break;
		case 6:
			system("pause");	
			break;
		default: 
			
			gotoxy(35,19);cout<<"Ingresa una opcion correcta[1-6]\n";
			system("pause");
			system("cls");
			menuClientes();
			break;
		}
		
	} while(opc1!=6);
}
	
void agregarCliente()
{
	int    cod,d;
	string nomApe;
	string  direccion;
	string opc;

	do{
		gotoxy(35,11);cout<<"\tAGREGAR NUEVOS CLIENTES"<<endl;
		
		cod = cliController->getCorrelativo();
		gotoxy(43,12);cout<<"**["<<cod<<"]**"<<endl;
		cin.ignore();
		gotoxy(35,13);cout<<"Nombre y Apellido del Cliente: ";
		getline(cin,nomApe);
		
		gotoxy(35,14);cout<<"DNI del Cliente: ";
		cin>>d;
		cin.ignore();
		
		gotoxy(35,15);cout<<"Direccion del Cliente: ";
		getline(cin,direccion);
		
		Cliente objCli(cod,nomApe,d,direccion);
		
		cliController->add(objCli);
		cliController->grabarEnArchivo(objCli);
		
		gotoxy(35,16);cout<<"¿Desea ingresar un nuevo Cliente? SI o NO: ";
		cin>>opc;
		system("cls");
	} while(opc == "SI" || opc == "si");
	
	menuClientes();
}

void listarClientes()
{
	gotoxy(35,7);cout<<"\t LISTA DE CLIENTES"<<endl;
	if(cliController->size()==0)
	{
		gotoxy(35,8);cout<<"No hay ningun cliente registrado por ahora..."<<endl;
		
		system("pause");
		
		menuClientes();
	}
	else
	{
		for(int i = 0;i < cliController->size();i++)
		{
			gotoxy(35,8+i*6);cout<<"\t **************"<<endl;
			gotoxy(35,9+i*6);cout<<"Codigo: "<<cliController->get(i).getCodCliente()<<endl;
			gotoxy(35,10+i*6);cout<<"Nombre y Apellidos: "<<cliController->get(i).getNomApe()<<endl;
			gotoxy(35,11+i*6);cout<<"DNI: "<<cliController->get(i).getDNI()<<endl;
			gotoxy(35,12+i*6);cout<<"Direccion : "<<cliController->get(i).getDireccion()<<endl;
		}
		system("pause");
		
		menuClientes();
	}
}

void modificarCliente()
{

	string nomApemod, direccionmod;
	int dnimod,codmod;
	gotoxy(35,7);cout<<"Si desea modificar un cliente ingrese el codigo de este: ";
	cin>>codmod;
	Cliente clObj = cliController->buscarPorCodigo(codmod);

	gotoxy(35,8);cout<<"\t **Registro Encontrado**";
	gotoxy(35,9);cout<<"Codigo  : "<<clObj.getCodCliente()<<"\n";
	gotoxy(35,10);cout<<"Nombre y Apellido  : "<<clObj.getNomApe()<<"\n";
	gotoxy(35,11);cout<<"DNI  : "<<clObj.getDNI()<<"\n";
	gotoxy(35,12);cout<<"Direccion  : "<<clObj.getDireccion()<<"\n";
	cin.ignore();

	gotoxy(35,14);cout<<"\t MODIFICANDO CAMPOS";
	gotoxy(35,15);cout<<"Nombre y Apellidos modificados  : ";
	getline(cin,nomApemod);
	gotoxy(35,16);cout<<"DNI modificado	 : ";
	cin>>dnimod;
	cin.ignore();
	gotoxy(35,17);cout<<"Direccion modificada: ";
	getline(cin,direccionmod);

	bool estado = cliController->modify(clObj,nomApemod,dnimod,direccionmod);
	if (estado ==true)
	{
		gotoxy(35,18);cout<<"\nRegistro modificado satisfactoriamente!!!\n";
		cliController->cargarModificado();
	}
	else
	{
		gotoxy(35,18);cout<<"No encontro el registro a modificar!\n";
		system("pause");
		menuClientes();
		
	}
	system("pause");
	system("cls");
}

void buscarCliente()
{
	int cod;
	gotoxy(35,11);cout<<"\tBuscar Clientes";
	gotoxy(35,12);cout<<"Ingrese el codigo del cliente a buscar: ";
	gotoxy(35,13);cout<<"\n";
	cin>>cod;

	Cliente cli = cliController->buscarPorCodigo(cod);

	if(cli.getNomApe() != "Error")
	{
		gotoxy(35,14);cout<<"\t DATOS DEL CLIENTE ENCONTRADO";
		gotoxy(35,15);cout<<"Codigo: "<<cli.getCodCliente()<<endl;
		gotoxy(35,16);cout<<"Nombre y Apellidos: "<<cli.getNomApe()<<endl;
		gotoxy(35,17);cout<<"DNI: "<<cli.getDNI()<<endl;
		gotoxy(35,18);cout<<"Direccion: "<<cli.getDireccion()<<endl;
		system("pause");
		menuClientes();
	}
	else
	{
		gotoxy(35,14);cout<<"No se encontro ningun cliente!!!\n";
		
	}

	system("pause");
	menuClientes();
}

void eliminarCliente()
{
	int cod;
	gotoxy(35,12);cout<<"Ingrese codigo a buscar: ";
	cin>>cod;
	Cliente objEliminar = cliController->buscarPorCodigo(cod);

	if(objEliminar.getNomApe() !="Error")
	{
		cliController->remove(objEliminar);
		gotoxy(35,13);cout<<"Registro eliminado satisfactoriamente!!!";
		cliController->cargarModificado();
		system("pause");
		menuClientes();
	}
	else
	{
		gotoxy(35,13);cout<<"No se encontro el registro!";
		system("pause");
		menuClientes();
	}
}

void GenerarVenta()
{
	int cantidad;
	int cantidad2;

	string flag1,flag2;

	int cod_c=0;
	int cod_v=0;
	int cod_p=0;
	int c;
	string fecha="21/11/2022";

	float total_v=0;
	int estado=0;


	system("cls");


	gotoxy(32,2);cout<<"**********************Generador de Venta******************"<<endl;
	gotoxy(35,3);cout<<"Codigo de Venta ["<<vController->getCorrelativo()<<"]"<<endl;
	gotoxy(35,4);cout<<"Fecha de emision: "<<fecha<<endl;
	gotoxy(35,5);cout<< "Ingrese el codigo del cliente: ";
	cin>>cod_c;
	
	Cliente cliEjemplo=cliController->buscarPorCodigo(cod_c);
	
	
	gotoxy(35,6);cout<<"DNI: "<<cliEjemplo.getDNI()<<endl;
	gotoxy(35,7);cout<<"NOMBRES Y APELLIDOS: "<<cliEjemplo.getNomApe()<<endl;
	
	gotoxy(35,8);cout<<"*************************************************"<<endl;
	gotoxy(35,9);cout<<"Ingresar el codigo del empleado que realizara la venta: "<<endl;
	gotoxy(35,10);cin>>cod_v;
	
	Personal EjemploP = pController->BuscarPorCodigo(cod_v);
	
	gotoxy(35,11);cout<<"DNI: "<<EjemploP.getDni()<<endl;
	gotoxy(35,12);cout<<"NOMBRES Y APELLIDOS: "<<EjemploP.getNomApe()<<endl;
	
	
		
	do
	{
		system("cls");
		
		gotoxy(35,14);cout << "********************Productos en venta******************"<<endl;
		
		int i=0;
		
		for(int i=0; i<proController->size() ; i++)
		{
			gotoxy(35,15+i*5);cout<<"Codigo: "<<proController->get(i).getCodigo()<<endl;
			gotoxy(35,16+i*5);cout<<"Nombre: "<<proController->get(i).getNomPro()<<endl;
			gotoxy(35,17+i*5);cout<<"Precio: "<<proController->get(i).getPrePro()<<endl;
			gotoxy(35,18+i*5);cout<<"Stock: "<<proController->get(i).getStkPro()<<endl;
			gotoxy(35,19+i*5);cout<<"**************************************************"<<endl;
		}
	
		gotoxy(35,45);cout<<"Ingrese el codigo del producto: ";
		gotoxy(35,46);cin>>cod_p;
		
		system("cls");
	
		producto ProEjemplo= proController->BuscarPorCodigo(cod_p);
	
		if(ProEjemplo.getStkPro()==0)
		{
			gotoxy(35,11);cout<<"NO HAY PRODUCTOS EN STOCK. SELECCIONE OTRO PRODUCTO"<<endl;
			GenerarVenta();
		}	
		else
		{
			gotoxy(35,11);cout << "Producto encontrado"<<endl;
			gotoxy(35,12);cout<< "Codigo del producto: "<<ProEjemplo.getCodigo()<<endl;
			gotoxy(35,13);cout<< "Stock: "<<ProEjemplo.getStkPro()<<endl;
			gotoxy(35,14);cout<<"Precio por unidad: "<<ProEjemplo.getPrePro()<<endl;
		}
	
		gotoxy(35,15);cout<<"Mencione la cantidad de objetos que va a adquirir: ";
		cin>>cantidad;
		
		gotoxy(35,16);cout<<"Esta seguro que quiere agregar este producto al carrito?: (SI/NO)"<<endl;
		cin>>flag1;
		
		system("cls");
		
		
		if(flag1=="SI" || flag1=="si")
		{	
			Detalle_V detalle;
			
			detalle.setCod_V(dController->getCorrelativo());
			detalle.setCodPro(cod_p);
			detalle.setCantidad(cantidad);
			detalle.setPrecio_v(ProEjemplo.getPrePro());
			dController->add(detalle);
			total_v+=detalle.Total();
			cantidad2+=cantidad;
			gotoxy(35,15);cout<<"Codigo [ "<<detalle.getCodPro()<<" ]"<<endl;
			gotoxy(35,16);cout<<"Cantidad del Producto: "<<detalle.getCantidad()<<endl;
			gotoxy(35,17);cout<<"Subtotal: "<<detalle.Total()<<endl;	
			
			dController->grabarEnArchivo(detalle);
			
		}
		else
		{
			system("pause");
			GenerarVenta();
		}
	
		gotoxy(35,25);cout<<"Desea agregar otro producto al carrito? (SI/NO): ";
		cin>>flag2;
		
	}while (flag2== "si"|| flag2=="SI");
	
	
	Venta Ejemplo;
	
	Ejemplo.setCodigo(vController->getCorrelativo());
	Ejemplo.setCodCliente(cod_c);
	Ejemplo.setFecha_V(fecha);
	Ejemplo.setTotal_V(total_v);
	vController->add(Ejemplo);
	vController->grabarEnArchivo(Ejemplo);
	
	system("cls");
	
	gotoxy(35,3);cout<< " *************** BOLETA **************** "<<endl;
	gotoxy(35,4);cout<<"Codigo de venta: AA00"<<Ejemplo.getCodigo()<<endl;
	gotoxy(35,5);cout<<"Nombre y Apellidos del cliente: "<<cliEjemplo.getNomApe()<<endl;
	gotoxy(35,6);cout<<"Documento de Identidad del cliente: "<<cliEjemplo.getDNI()<<endl;
	
	gotoxy(35,7);cout<<"Cajero: "<< EjemploP.getNomApe()<<endl;
	
	gotoxy(35,8);cout<<"Productos adquiridos: "<<endl;
	
	for(int i=0; i < dController->size();i++)
	{
		c= proController->get(i).getCatPro();
		
		gotoxy(35,9+i*6);cout<<"Codigo del producto: "<<dController->get(i).getCodPro()<<endl;
		gotoxy(35,10+i*6);cout<<"Categoria del producto: "<<catController->get(c).getNomCat()<<endl;
		gotoxy(35,11+i*6);cout<<"Cantidad de producto a llevar: "<<dController->get(i).getCantidad()<<endl;
		gotoxy(35,12+i*6);cout<<"Precio por unidad: "<<dController->get(i).getPrecio_v()<<endl;
		gotoxy(35,13+i*6);cout<<"SubTotal: "<<dController->get(i).Total()<<endl;
		gotoxy(35,14+i*6);cout<<"**************************************************"<<endl;
	}
	
	
	gotoxy(35,40);cout<<"Monto a pagar: S/. "<<total_v<<endl;
	gotoxy(35,41);cout<<"Desea anular la boleta?: "<<endl;
	gotoxy(35,42);cin>>estado;
	
	if(estado==1)
	{
		system("cls");
		
		gotoxy(35,16);cout<<" Vuelva pronto ! :D "<<endl;
		Boleta b;
		
		b.setEstado(estado);
		bcontroller->add(b);
		bcontroller->grabarEnArchivo(b);
		system("pause");
	}
	else
	{
		
		Boleta b;
		b.setCodigo(vController->getCorrelativo());
		b.setDni(cliEjemplo.getDNI());
		b.setNomApeC(cliEjemplo.getNomApe());
		b.setNomApeV(EjemploP.getNomApe());
		b.setCantidad(cantidad2);
		b.setTotal(total_v);
		b.setEstado(estado);
		bcontroller->add(b);
		bcontroller->grabarEnArchivo(b);
		
		system("cls");
		
		gotoxy(35,16);cout<<" GRACIAS POR SU COMPRA! :D "<<endl;
		system("pause");
	}
}

void menuPersonal(){
	system("cls");
	int opc;

	do{
		gotoxy(35,11);cout<<"\t BIENVENIDOS AL MENU DEL PERSONAL"<<endl;
		gotoxy(35,12);cout<<"\t Agregar Personal..............[1]"<<endl;
		gotoxy(35,13);cout<<"\t Listar Personal...............[2]"<<endl;
		gotoxy(35,14);cout<<"\t Modificar Personal............[3]"<<endl;
		gotoxy(35,15);cout<<"\t Buscar Personal...............[4]"<<endl;
		gotoxy(35,16);cout<<"\t Eliminar Personal.............[5]"<<endl;
		gotoxy(35,17);cout<<"\t Regresar......................[6]"<<endl;
		gotoxy(35,18);cout<<"\t Elija una opcion: ";
		cin>>opc;
		switch(opc)
		{
		case 1: 
			system("cls");
			agregarPersonal();
			break;
			
		case 2:
			system("cls");
			listarPersonal();
			break;
		case 3:
			system("cls");
			modificarPersonal();
			break;
		case 4:
			system("cls");
			buscarPersonal();
			break;
		case 5:
			system("cls");
			eliminar();
			break;
		case 6:
			system("cls");
			menuPrincipalAdmin();//poner condicion para ver si es admin o vendedor
			break;
		default: 
			gotoxy(35,19);cout<<"Ingresa una opcion correcta[1-3]\n";
			system("pause");
			system("cls");
			menuPersonal();
		}
		
	} while(opc!=6);
}

void agregarPersonal()
{
	string opc;
	
	gotoxy(35,12);cout<<"Recuerde que cada personal debe tener una cuenta de acceso,\n";
	gotoxy(35,13);cout<<"      a continuacion registre al nuevo personal...\n";
	system("pause");
	
	do{
		system("cls");
		cin.ignore();
	    registrarse();
		gotoxy(35,15);cout<<"¿Desea ingresar un nuevo personal? SI o NO: ";
		cin>>opc;
		system("cls");
		
	} while(opc == "SI" || opc == "si");
	menuPersonal();
}

void listarPersonal()
{
	gotoxy(35,11);cout<<"\t LISTA DE PERSONAL"<<endl;
	if(pController->size()==0)
	{
		gotoxy(35,12);cout<<"\nNo hay personal registrado por ahora..."<<endl;
		
		system("pause");
		
		menuPersonal();
	}
	else
	{
		for(int i = 0;i < pController->size();i++)
		{
			gotoxy(35,12+i*4);cout<<"*****************************"<<endl;
			gotoxy(35,13+i*4);cout<<"Codigo: "<<pController->get(i).getCod_p()<<endl;
			gotoxy(35,14+i*4);cout<<"Nombre: "<<pController->get(i).getNomApe()<<endl;
			gotoxy(35,15+i*4);cout<<"Dni: "<<pController->get(i).getDni()<<endl;
			
		}
		system("pause");
		
		menuPersonal();
	}
}

void modificarPersonal()
{
	
	string nomV;
	int dniV,code;
	
	gotoxy(35,8);cout<<"Si desea modificar un vendedor ingrese el codigo de este: ";
	cin>>code;
	Personal vObj = pController->BuscarPorCodigo(code);
	
	gotoxy(35,9);cout<<"\t *****Registro Encontrado*****";
	gotoxy(35,10);cout<<"Codigo   : "<<vObj.getCod_p()<<"\n";
	gotoxy(35,11);cout<<"Nombre   : "<<vObj.getNomApe()<<"\n";
	gotoxy(35,12);cout<<"Dni   : "<<vObj.getDni()<<"\n";
	cin.ignore();
	
	gotoxy(35,13);cout<<"\t MODIFICANDO CAMPOS";
	gotoxy(35,14);cout<<"Nombre modificado   : ";
	getline(cin,nomV);
	gotoxy(35,15);cout<<"Dni modificado   : ";
	cin>>dniV;
	
	cin.ignore();
	
	bool estado = pController->modificar(vObj,nomV,dniV);
	if (estado ==true)
	{
		gotoxy(35,16);cout<<"Registro modificado satisfactoriamente!!!";
		pController->grabarEnArchivoModificado();
	}
	else
	{
		gotoxy(35,16);cout<<"No encontro personal a modificar!";
		system("pause");
		menuPersonal();
		
	}
	system("pause");
	system("cls");
}

void buscarPersonal()
{
	int cod;
	gotoxy(35,9);cout<<"\t Buscar personal";
	gotoxy(35,10);cout<<"Ingrese el codigo del personal a buscar: ";
	gotoxy(35,11);cout<<"\n";
	cin>>cod;
	
	Personal ven = pController->BuscarPorCodigo(cod);
	
	if(ven.getNomApe() != "Error")
	{
		gotoxy(35,12);cout<<"DATOS DEL VENDEDOR ENCONTRADO\n";
		gotoxy(35,13);cout<<"Codigo: "<<ven.getCod_p()<<endl;
		gotoxy(35,14);cout<<"Nombre: "<<ven.getNomApe()<<endl;
		gotoxy(35,15);cout<<"Dni: "<<ven.getDni()<<endl;
		system("pause");
		menuPersonal();
	}
	else
	{
		gotoxy(35,12);cout<<"No se encontro ningun vendedor!!!\n";
		
	}
	
	system("pause");
	menuPersonal();
}

void listarCategoria()
{
	gotoxy(35,15);cout<<"\t LISTA DE CATEGORIAS"<<endl;

		for(int i = 0;i < catController->size();i++)
		{
			gotoxy(35,17+i*3);cout<<"****************************************"<<endl;
			gotoxy(35,18+i*3);cout<<"Codigo: "<<catController->get(i).getCodCat()<<endl;
			gotoxy(35,19+i*3);cout<<"Categoria: "<<catController->get(i).getNomCat()<<endl;
		}
}



