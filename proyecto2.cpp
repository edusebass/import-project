#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

const int MAX = 100;

//PRODUCTOS VARIABLES Y FUNCIONES
typedef struct
{
    string marca;
    int precio;
    string valorp;
    string codigo;
    string procedencia;
    string descripcion;
} tProductos;

typedef struct
{
    tProductos elementosproductos[MAX];
    int contadorproductos;
} tListaProductos;

//CLIENTES
typedef struct
{
    string nombre;
    int preciocliente;
    string telfonocliente;
    string codigocliente;
    string cedula;
    string direccioncliente;
} tClientes;

typedef struct
{
    tClientes elementosClientes[MAX];
    int contadorClientes;
} tListaClientes;

int menuprincipal();//////////
//PRODUCTOS
int menuProductos();
void cargarListaProductos(tListaProductos &listap, bool &ok);
void guardarProductos(const tListaProductos &listap);
void leerProductos(tProductos &productos);
void insertarProductos(tListaProductos &listap, tProductos productos, bool &ok);
void mostrarProductos(tProductos productos);
void listadoProductos(const tListaProductos &listap);
void buscarProductos(const tListaProductos listap, string marca, bool &ok);
void elimninarProductos(tListaProductos &listap, int posproductos, bool &ok);

//VARIABLES Y FUNCIONES DE CLIENTE

int menuclientes();
void cargalistaClientes(tListaClientes &listacli, bool &ok);
void guardarClientes(const tListaClientes &listacli);
void leerClientes(tClientes &clientes);
void insertarClientes(tListaClientes &listacli, tClientes clientes, bool &ok);
void mostrarClientes(tClientes clientes);
void listadoClientes(const tListaClientes &listacli);
void buscarClientes(const tListaClientes listacli, string nombre, bool &ok);
void eliminarClientes(tListaClientes &listacli, int posclientes, bool &ok);

//VARIABLES FUNCIONES COMPRA
int menuCompras();
void compras();




//FUNCION MAIN
int main(){
	int opcionprin;
	
	//variables productos
	setlocale(LC_ALL, "");
    tListaProductos listap;
    tProductos productos;
    bool exitop;
    int opproductos;
    string marca;
    int posproductos;
    cargarListaProductos(listap, exitop);
    
    //variables clientes
    setlocale(LC_ALL, "");
    tListaClientes listacli;
    tClientes clientes;
    bool exitocli;
    int opclientes;
    string nombre;
    int posclientes;
    cargalistaClientes(listacli, exitocli);
    
    //variables compras
    int opcompras;

	
	///
	while(opcionprin != 4){
		opcionprin = menuprincipal();
		if (opcionprin == 1){
			if (!exitop){
        		cout << "No se ha podido cargar la listap ! " << endl;
		    }
		    else{	 
		    	opproductos = menuProductos();
				while (opproductos != 5){
		            if (opproductos == 1){
		            	system("cls");
		                listadoProductos(listap);
		                system("pause");
		                opproductos = menuProductos();
			        }
			        if(opproductos == 2){
			        	leerProductos(productos);
		                insertarProductos(listap, productos, exitop);
		                if (!exitop){
		                    cout << "Lista llena : imposible insertar " << endl;
		                }
		                else{
		                    cout << "Agregado con exitop !" << endl;
		                }
		                opproductos = menuProductos();
					}
			        if(opproductos == 3){
			        	system("cls");
		            	cout << "\t\tBUSCAR PRODUCTO\n" <<endl;
		            	listadoProductos(listap);
		                cin.ignore();
		                cout << "\nIngrese el codigo del producto a buscar: ";
		                cin >> marca;
		                cout << "\nPRODUCTO ENCONTRADO" << endl;
		                buscarProductos(listap, marca, exitop);
		                if (!exitop){
		                    cout << "Producto no encontrado " << endl;
		                }
		                system("pause");
		                opproductos = menuProductos();
					}
					if(opproductos == 4){
						system("cls");
		            	listadoProductos(listap);
		                cout << "\nIngrese el ID del producto a eliminar: ";
		                cin >> posproductos;
		                elimninarProductos(listap, posproductos, exitop);
		                if (!exitop){
		                    cout << "La posicion no existe !" << endl;
		                }
						else{
							system("cls");
							listadoProductos(listap);
		                    cout << "\nProducto eliminado\n" << endl;
		                    
		                }
		                system("pause");
		                opproductos = menuProductos();
					}			  
				}
		        guardarProductos(listap);
		    }
		}
		if(opcionprin == 2){
			if (!exitocli){
        		cout << "No se ha podido cargar la listacli ! " << endl;
		    }
		    else{	 
		    	opclientes = menuclientes();
				while (opclientes != 5){
					if(opclientes == 1){
						system("cls");
		                listadoClientes(listacli);
		                system("pause");
		                opclientes = menuclientes();
					}
					if(opclientes == 2){
						leerClientes(clientes);
		                insertarClientes(listacli, clientes, exitocli);
		                if (!exitocli){
		                    cout << "Sobrecarga de datos " << endl;
		                }
		                else{
		                    cout << "Cliente gregado con exito !" << endl;
		                }
		                opclientes = menuclientes();
					}
					if(opclientes == 3){
						system("cls");
		            	cout << "\t\tBUSCAR CLIENTE\n" <<endl;
		            	listadoClientes(listacli);
		                cin.ignore();
		                cout << "\nIngrese el codigo del cliente a buscar: ";
		                cin >> nombre;
		                cout << "\nCLIENTE ENCONTRADO" << endl;
		                buscarClientes(listacli, nombre, exitocli);
		                if (!exitocli){
		                    cout << "Cliente no encontrado " << endl;
		                }
		                system("pause");
	                	opclientes = menuclientes();	
					}
					if(opclientes == 4){
						system("cls");
		            	listadoClientes(listacli);
		                cout << "\nIngrese el ID del cliente a eliminar: ";
		                cin >> posclientes;
		                eliminarClientes(listacli, posclientes, exitocli);
		                if (!exitocli){
		                    cout << "CLIENTE no existe !" << endl;
		                }
						else{
							system("cls");
							listadoClientes(listacli);
		                    cout << "\nProducto eliminado\n" << endl;
		                    
		                }
		                system("pause");
		                
		                opclientes = menuclientes();			
					}	
				}guardarClientes(listacli);	
			}
		}
		if(opcionprin == 3){
			opcompras = menuCompras();
			int number = 1;
			while(opcompras != 3){
				if (opcompras == 1){
					system("cls");
					
					ofstream archivo;
					archivo.open("facturas.txt", ios::app);
					archivo << "\nFACTURA # "  << number;
					archivo.close();
					cout << "PROCESO DE COMPRA\n" << endl;
					cout <<"\nEscribe los datos del cliente\n"<< endl;
					listadoClientes(listacli);
                    cout << "\nIngrese el codigo del cliente que va a comprar: ";
	                cin >> nombre;
	                listadoProductos(listap);
	                cin.ignore();
	                cout << "\nIngrese el codigo del producto a comprar: ";
	                cin >> marca;
					system("cls");
	                buscarClientes(listacli, nombre, exitocli);
	                if (!exitocli){
	                    cout << "Cliente no encontrado " << endl;
	                }
	                buscarProductos(listap, marca, exitop);
	                if (!exitop){
	                    cout << "Producto no encontrado " << endl;
	                }
	                system("pause");
					system("clear");
					number ++;
					
					opcompras = menuCompras();
				}
				if(opcompras == 2){
					cout << "Mostrando todas las facturas emitidas" << endl;
					ifstream archivo;
					string texto;
					archivo.open("facturas.txt", ios::in);
					while(!archivo.eof()){
						getline(archivo,texto);
						cout << texto << endl;
					}
					archivo.close();
					system("pause");
					opcompras = menuCompras();
				}
			}
		}
	}
}

//MENUS
int menuprincipal(){
	system("cls");
    int opcionprin;
    cout << "\n-----------------------------------------\n";
    cout << "         IMPORTACIONES 'CETRACON'       " << endl;
    cout << "Bienvenidos a nuestro aplicativo!!!!" << endl;
    cout << "***Obten productos importados al mejor precio***" << endl;
    cout << "\t\tPLATAFORMA" << endl;
    cout << "1. Productos " << endl;
    cout << "2. Clientes" << endl;
    cout << "3. Compra" << endl;
    cout << "4. Salir y guardar cambios\n" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcionprin;
    return opcionprin;
}

int menuProductos(){
    int opproductos;
    	system("cls");
        cout << "\t\t==== PRODUCTOS ==== \t\t\n"<< endl;
        cout << "1. Listado de Productos" << endl;
        cout << "2. Agregar Productos" << endl;
        cout << "3. Buscar Productos" << endl;
        cout << "4. Eliminar Productos" << endl;
        cout << "5. Regresar al menu principal" << endl;
        cout << "Opcion:";
        cin >> opproductos;
    return opproductos;
}

int menuclientes(){
    int opclientes;
    	system("cls");
        cout << "\t\t CLIENTES  \t\t\n"<< endl;
        cout << "1. Listado de Clientes" << endl;
        cout << "2. Agregar Clientes" << endl;
        cout << "3. Buscar Clientes" << endl;
        cout << "4. Eliminar Clientes" << endl;
        cout << "5. Regresar al menu principal" << endl;
        cout << "Opcion:";
        cin >> opclientes;
    return opclientes;
}

int menuCompras(){
	int opcompras;
    	system("cls");
        cout << "\t\t COMPRAS  \t\t\n"<< endl;
        cout << "1. Comprar" << endl;
        cout << "2. Mostrar Compras" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "Opcion:";
        cin >> opcompras;
    return opcompras;
	}








































//FUNCIONES CLIENTES
void cargalistaClientes(tListaClientes &listacli, bool &ok)
{
    tClientes clientes;
    ifstream archivop;
    char aux;
    listacli.contadorClientes = 0;
    archivop.open("clientes.txt");
    if (!archivop.is_open())
    {
        ok = false;
    }
    else
    {
        ok = true;
        archivop >> clientes.preciocliente;
        while ((clientes.preciocliente != -1) && (listacli.contadorClientes < MAX))
        {
            archivop.get(aux);
            getline(archivop, clientes.codigocliente);
            getline(archivop, clientes.nombre);
            getline(archivop, clientes.cedula);
            getline(archivop, clientes.telfonocliente);
            archivop >> clientes.direccioncliente;
            listacli.elementosClientes[listacli.contadorClientes] = clientes;
            listacli.contadorClientes++;
            archivop >> clientes.preciocliente;
        }
        archivop.close();
    }
}
void guardarClientes(const tListaClientes &listacli)
{

    ofstream archivop;
    archivop.open("clientes.txt");
    for (int i = 0; i < listacli.contadorClientes; i++)
    {
        archivop << listacli.elementosClientes[i].preciocliente << endl;
        archivop << listacli.elementosClientes[i].codigocliente << endl;
        archivop << listacli.elementosClientes[i].nombre << endl;
        archivop << listacli.elementosClientes[i].cedula << endl;
        archivop << listacli.elementosClientes[i].direccioncliente << endl;
        archivop << listacli.elementosClientes[i].telfonocliente << endl;
    }
    archivop << -1;
    archivop.close();
}

void leerClientes(tClientes &clientes)
{
	system("cls");
	cout << "\t\tINGRESO DE PRODUCTO" << endl;
    cin.ignore();
    cout << "Ingrese el codigo del cliente: ";
    getline(cin, clientes.codigocliente);
    cout << "Ingrese la nombre del cliente: ";
    getline(cin, clientes.nombre);
    cout << "Ingrese la  cedula del cliente: ";
    getline(cin, clientes.cedula);
    cout << "Ingrese el telefono del cliente: ";
    getline(cin, clientes.telfonocliente);
    cout << "Ingrese la direccion del cliente :";
    cin >> clientes.direccioncliente;
    cin.sync();
    cout << "\nCLIENTE AGREGADO!!!!!\n" << endl;
    system("pause");
}

void insertarClientes(tListaClientes &listacli, tClientes clientes, bool &ok)
{
    ok = true;
    if (listacli.contadorClientes == MAX)
    {
        ok = false;
    }
    else
    {
        clientes.preciocliente = listacli.contadorClientes + 1;
        listacli.elementosClientes[listacli.contadorClientes] = clientes;
        listacli.contadorClientes++;
        
    }
}

void mostrarClientes(tClientes clientes)
{
    cout << setw(2) << "| "<< left << clientes.preciocliente << "- ";
    cout << setw(20) << left << clientes.codigocliente;
    cout << setw(20) << left << clientes.nombre;
    cout << setw(10) << left << clientes.cedula << "  ";
    cout << setw(6) << left << clientes.direccioncliente << "     ";
    cout << setw(5) << right << clientes.telfonocliente << "   |"<< endl;
}

void listadoClientes(const tListaClientes &listacli)
{	
	
	cout << "\t\tCLIENTES AGREGADOS" << endl;
	cout << "|ID|CODIGO             |NOMBRE              |CEDULA    |TELEFONO |DIRECCION |" << endl;
    for (int i = 0; i < listacli.contadorClientes; i++)
    {
        mostrarClientes(listacli.elementosClientes[i]);
    }
}

void buscarClientes(const tListaClientes listacli,  string codigocliente, bool &ok)
{
	cout << "|ID|CODIGO             |NOMBRE              |CEDULA    |TELEFONO |DIRECCION |" << endl;
    ok = false;
    for (int i = 0; i < listacli.contadorClientes; i++)
    {
        if (listacli.elementosClientes[i].codigocliente == codigocliente)
        {
            ok = true;
            mostrarClientes(listacli.elementosClientes[i]);
            ofstream archivo;
            archivo.open("facturas.txt", ios::app);
            archivo << "\n|-----------------PRODUCTO COMPRADO-----------------------------------------|" << endl;
            archivo << "| DATOS CLIENTE                                                             |" << endl;
            archivo << "|---------------------------------------------------------------------------|" << endl;
            archivo << "|ID|CODIGO             |NOMBRE              |CEDULA    |TELEFONO |DIRECCION |" << endl;
			archivo << " " <<listacli.elementosClientes[i].preciocliente << "  ";
	        archivo << listacli.elementosClientes[i].codigocliente << "               ";
	        archivo << listacli.elementosClientes[i].nombre << "             ";
	        archivo << listacli.elementosClientes[i].cedula << "     ";
	        archivo << listacli.elementosClientes[i].direccioncliente << "      ";
	        archivo << listacli.elementosClientes[i].telfonocliente << endl;
	        archivo.close();
	        }
    }
}

void eliminarClientes(tListaClientes &listacli, int posclientes, bool &ok)
{

    ok = true;
    if ((posclientes < 1) || (posclientes > listacli.contadorClientes))
    {
        ok = false;
    }
    else
    {
        posclientes--;
        for (int i = posclientes + 1; i < listacli.contadorClientes; i++)
        {
            listacli.elementosClientes[i - 1] = listacli.elementosClientes[i];
        }
        listacli.contadorClientes--;
    }
}




//FUNCIONES PRODUCTOS

void cargarListaProductos(tListaProductos &listap, bool &ok)
{
    tProductos productos;
    ifstream archivop;
    char aux;
    listap.contadorproductos = 0;
    archivop.open("productos.txt");
    if (!archivop.is_open())
    {
        ok = false;
    }
    else
    {
        ok = true;
        archivop >> productos.precio;
        while ((productos.precio != -1) && (listap.contadorproductos < MAX))
        {
            archivop.get(aux);
            getline(archivop, productos.codigo);
            getline(archivop, productos.marca);
            getline(archivop, productos.procedencia);
            getline(archivop, productos.valorp);
            archivop >> productos.descripcion;
            listap.elementosproductos[listap.contadorproductos] = productos;
            listap.contadorproductos++;
            archivop >> productos.precio;
        }
        archivop.close();
    }
}
void guardarProductos(const tListaProductos &listap)
{

    ofstream archivop;
    archivop.open("productos.txt");
    for (int i = 0; i < listap.contadorproductos; i++)
    {
        archivop << listap.elementosproductos[i].precio << endl;
        archivop << listap.elementosproductos[i].codigo << endl;
        archivop << listap.elementosproductos[i].marca << endl;
        archivop << listap.elementosproductos[i].procedencia << endl;
        archivop << listap.elementosproductos[i].descripcion << endl;
        archivop << listap.elementosproductos[i].valorp << endl;
    }
    archivop << -1;
    archivop.close();
}

void leerProductos(tProductos &productos)
{
	system("cls");
	cout << "\t\tINGRESO DE PRODUCTO" << endl;
    cin.ignore();
    cout << "Ingrese el codigo del producto: ";
    getline(cin, productos.codigo);
    cout << "Ingrese la marca del producto: ";
    getline(cin, productos.marca);
    cout << "Ingrese la  procedencia del producto:2 ";
    getline(cin, productos.procedencia);
    cout << "Ingrese el precio del producto: ";
    getline(cin, productos.valorp);
    cout << "Ingrese el descripcion que pertenece el marca:";
    cin >> productos.descripcion;
    cin.sync();
    cout << "\nPRODUCTO AGREGADO!!!!!\n" << endl;
    system("pause");
}

void insertarProductos(tListaProductos &listap, tProductos productos, bool &ok)
{
    ok = true;
    if (listap.contadorproductos == MAX)
    {
        ok = false;
    }
    else
    {
        productos.precio = listap.contadorproductos + 1;
        listap.elementosproductos[listap.contadorproductos] = productos;
        listap.contadorproductos++;
        
    }
}

void mostrarProductos(tProductos productos)
{
    cout << setw(2) << "| "<< left << productos.precio << "- ";
    cout << setw(20) << left << productos.codigo;
    cout << setw(20) << left << productos.marca;
    cout << setw(10) << left << productos.procedencia << " ";
    cout << setw(6) << left << productos.descripcion << "      ";
    cout << setw(5) << right << productos.valorp << " |"<< endl;
}

void listadoProductos(const tListaProductos &listap)
{	
	
	cout << "\t\tPRODUCTOS DISPONIBLES" << endl;
	cout << "|ID|AÑO                |MARCA              |ORIGEN    |DESCRIPCION |VALOR" << endl;
    for (int i = 0; i < listap.contadorproductos; i++)
    {
        mostrarProductos(listap.elementosproductos[i]);
    }
}

void buscarProductos(const tListaProductos listap, string codigo, bool &ok)
{
    ok = false;
    for (int i = 0; i < listap.contadorproductos; i++)
    {
        if (listap.elementosproductos[i].codigo == codigo)
        {
            ok = true;
            stoi(listap.elementosproductos[i].descripcion);
            mostrarProductos(listap.elementosproductos[i]);
            ofstream archivo;
            archivo.open("facturas.txt", ios::app);
            archivo << "|---------------------------------------------------------------------------|" << endl;
            archivo << "| DATOS PRODUCTO                                                            |" << endl;
            archivo << "|---------------------------------------------------------------------------|" << endl;
            archivo << "|ID|AÑO             |MARCA            |ORIGEN    |VALOR     |DESCRIPCION    |" << endl;
			archivo << " " <<listap.elementosproductos[i].precio << "  ";
	        archivo << listap.elementosproductos[i].codigo << "             ";
	        archivo << listap.elementosproductos[i].marca << "            ";
	        archivo << listap.elementosproductos[i].procedencia << "      ";
	        archivo << listap.elementosproductos[i].descripcion << "       ";
	        archivo << listap.elementosproductos[i].valorp << endl;
	        archivo << "|---------------------------------------------------------------------------|" << endl;
	        archivo << a * 5 << "       ";
	        archivo.close();
        }
    }
}

void elimninarProductos(tListaProductos &listap, int posproductos, bool &ok)
{

    ok = true;
    if ((posproductos < 1) || (posproductos > listap.contadorproductos))
    {
        ok = false;
    }
    else
    {
        posproductos--;
        for (int i = posproductos + 1; i < listap.contadorproductos; i++)
        {
            listap.elementosproductos[i - 1] = listap.elementosproductos[i];
        }
        listap.contadorproductos--;
    }
}
