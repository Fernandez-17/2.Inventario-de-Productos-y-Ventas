/*2. Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar
productos, así como gestionar las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad
(entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
A: Registrar un nuevo producto.
B: Listar los productos registrados.
C: Buscar un producto por nombre.
D: Actualizar los datos de un producto.
E: Eliminar un producto.
F: Registrar una venta.
G: Listar las ventas realizadas.
H: Calcular el total de ventas realizadas.
S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción.*/
#include<iostream>
#include<string>
using namespace std;

struct Producto{
	string nombre;
	float precio;
};
//struct Venta {
//	int id_venta;
	//string producto;
//	int cantidad;
//	float precio_total;
//};

const int max_productos=50;
Producto prod[max_productos];
int producto_n=0;

// A. FUNCION PARA REGISTRAR UN NUEVO PRODUCTO 
void Nuevo_producto(){
	if(producto_n< max_productos){
		
		cout << "\n                  HA SELECCIONADO LA OPCION 1             "<<endl;
		cout << "\n                  REGISTRAR UN NUEVO PRODUCTO             "<<endl;
		cout << "____________________________________________________________"<<endl;
		
		Producto nuevo_producto;
		cin.ignore(); // limpia el buffer
		
		cout << "\n                         NUEVO PRODUCTO                   "<<endl;
		cout << "\nNombre : ";
		getline(cin, nuevo_producto.nombre);
		
		cout << "\nPrecio : ";
		cin >>nuevo_producto.precio;
		 	 
		prod[producto_n++] = nuevo_producto ; // guardamos el nuevo producto en el arreglo y aumentamos el contador
		cout << "\nProducto registrado exitosamente.\n";
	}else{
		cout << "No es posible agregar mas productos , se alcanzo el limite\n";
	}
}

// B. lISTAR LOS PRODUCTOS REGISTRADOS
void Lista_productos(){
	cout << "\n                  HA SELECCIOANDO LA OPCION 2               "<<endl;
	cout << "\n                LISTA DE PRODUCTOS REGISTRADOS              "<<endl;
	cout << "______________________________________________________________"<<endl;
	
	if (producto_n > 0) {
        cout <<"\n   LISTA  DE  PRODUCTOS  REGISTRADOS  HASTA  EL  MOMENTO  \n"<<endl;
	    for(int i = 0 ; i< producto_n ; i++){
		    cout<<"\nPRODUCTO " << i + 1 <<endl;
		    cout<<"\nNombre : "<< prod[i].nombre <<endl;
		    cout<<"\nPrecio : "<< prod[i].precio <<endl;
		    cout<<"---------------------------------------"<<endl;
		}
	} else {
	cout << "\nNo hay productos registrados."<<endl;
	} 
}

// C. BUSCAR UN PRODUCTO POR SU NOMBRE

// Función para convertir cadena a minúsculas
string to_lower(string str) {
    string result = str;
    for (int i = 0; i < result.length(); ++i) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] - 'A' + 'a'; // Convertir a minúscula
        }
    }
    return result;
}
// FUNCION PARA BUSCAR
void Buscar_producto() {
    cout << "\n                  HA SELECCIONADO LA OPCION 3                 "<<endl;
	cout << "\n                  BUSCAR PRODUCTO POR NOMBRE                  "<<endl;
    cout << "______________________________________________________________\n";

    string producto_buscado;
    cout << "\n      INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA BUSCAR        "<<endl;
    cout << "\nNombre : ";
    getline(cin, producto_buscado);
    cout << "----------------------------------------------------------------"<<endl;

    string aux  = to_lower(producto_buscado);

    bool encontrado = false;
    for (int i = 0; i < producto_n; i++) {
        string nombre_producto= prod[i].nombre;
        string nombre_producto_aux = to_lower(nombre_producto);
        
        if (nombre_producto_aux == aux) {
            cout << "\nProducto encontrado \n";
            cout << "\nNombre: " << prod[i].nombre << endl;
            cout << "\nPrecio: " << prod[i].precio << endl;
            cout << "\n--------------------------------------------------------"<< endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEl producto que busca no existe en este sistema.\n";
    }
}

// D. Actualizar los datos de un producto.

// E. Eliminar un producto.
  
// F. Registrar una venta.

// G. Listar las ventas realizadas.

// H. Calcular el total de ventas realizadas.

// S. Salir del programa. 


//FUNCION PARA MOSTARAR 	DE MENU DE OPCIONES 
int mostrar_menu(){
	int opcion;
	cout<< "----------------------------MENÚ DE OPCIONES----------------------"<<endl;
	cout<< "1. Registrar un nuevo producto.           "<<endl;
    cout<< "2. Listar los productos registrados.      "<<endl;
	cout<< "3. Buscar un producto por nombre.         "<<endl;
	cout<< "4. Actualizar los datos de un producto.   "<<endl;     
    cout<< "5. Eliminar un producto.                  "<<endl;
    cout<< "6. Registrar una venta.                   "<<endl;
    cout<< "7. Listar las ventas realizadas.          "<<endl;
    cout<< "8. Calcular el total de ventas realizadas."<<endl;
    cout<< "9. Salir del programa.                    "<<endl;
    cout<< "Ingrese el numero de la opcion deseada: ";
    cin >> opcion;
    cin.ignore();
	return opcion;	
}

// FUNCION PRINCIPAL 

int main (){
	int opcion;
	do{
		opcion=mostrar_menu();
		switch(opcion){
			case 1:
				// LLAMAMOS A : A. FUNCION PARA REGISTRAR UN PRODUCTO
				Nuevo_producto(); 
				break;
			case 2:
				// B. LISTAR PRODUCTOS REGISTRADOS
				Lista_productos();
				break;
			case 3:
				// LLAMAMOS A : C. Buscar un producto por nombre. 
				Buscar_producto();
				break;
			case 4:
				// LLAMAMOS A : D. Actualizar los datos de un producto.
				break;
			case 5:
				// LLAMAMOS A : E. Eliminar un producto. 
				break;
			case 6:
				// LLAMAMOS A : F. Registrar una venta.
				break;
			case 7:
				// LLAMAMOS A : G. Listar las ventas realizadas.
				break;
			case 8:
				// LLAMAMOS A : H. Calcular el total de ventas realizadas.
				break;
			case 9:
				//  Salir del programa. 
				cout << "\nSaliendo del programa ...  "<<endl;
				break;
			
			default :
				cout << "\nOpcion no valida ; intentelo de nuevo por favor"<<endl;
 		}
 		
 		if (opcion != 9){
 			cout << endl,
 			system("pause"); // Pausa el programa antes de mostrar nuevamente el menú
 			cout <<endl;
		 }		
	} while (opcion !=9);
	
	return 0;
}



	