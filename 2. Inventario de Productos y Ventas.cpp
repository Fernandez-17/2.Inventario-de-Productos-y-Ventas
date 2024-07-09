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
struct Venta {
	int id_venta;
	string producto;
	int cantidad;
	float precio_total;
};

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
		cout << "____________________________________________________________"<<endl;
	}else{
		cout << "No es posible agregar mas productos , se alcanzo el limite\n";
		cout << "____________________________________________________________"<<endl;
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
	cout << "__________________________________________________________________"<<endl;
	} 
	cout << "__________________________________________________________________"<<endl;
}

// C. BUSCAR UN PRODUCTO POR SU NOMBRE

// Función para convertir cadena a minúsculas
string to_lower(string str) {
    string result = str;
    for (int i = 0; i < result.length(); ++i) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] - 'A' + 'a'; // Convertimos a minúscula
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
            cout << "\n________________________________________________________"<< endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEl producto que busca no existe en este sistema.\n";
        cout << "_______________________________________________________________"<<endl;
    }
}

// D. ACTUALIZAR LOS DATOS DE UN PRODUCTO

void Actualizar_datos() {
    cout << "\n                 HA SELECCIONADO LA OPCION 4                        "<<endl;
	cout << "\n               ACTUALIZAR DATOS DE UN PRODUCTO                      "<<endl;
    cout << "______________________________________________________________________"<<endl;
    
    string producto_actualizar;
    cout << "\n      INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA ACTUALIZAR           "<<endl;
    cout << "\nNombre : ";
    getline(cin, producto_actualizar);
    cout << "---------------------------------------------------"<< endl;

    bool encontrado = false;
    for (int i = 0; i < producto_n; i++) {
        if (prod[i].nombre == producto_actualizar) {
            cout << "\n PRODUCTO ENCONTRADO REALICE LOS CAMBIOS QUE DESEE \n";

            cout << "\nNuevo nombre (deje en blanco para mantener el mismo): ";
            string nuevo_nombre;
            getline(cin, nuevo_nombre);
            if (!nuevo_nombre.empty()) {
                prod[i].nombre = nuevo_nombre;
            }

            cout << "\nNuevo precio (deje 0 para mantener el mismo): ";
            float nuevo_precio;
            cin >> nuevo_precio;
            if (nuevo_precio != 0) {
                prod[i].precio = nuevo_precio;
            }

            encontrado = true;
            cout << "--------------------------------------------------------------"<<endl;
            cout << "\nProducto actualizado exitosamente.\n";       //
            cout << "______________________________________________________________"<<endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEl producto que desea actualizar no fue encontrado.\n";         
        cout << "__________________________________________________________________"<<endl;
    }
    cin.ignore(); // Limpiar el buffer de entrada
}

// E. ELIMINAR PRODUCTO 

void Eliminar_producto() {
    cout << "\n                       HA SELECCIONADO LA OPCION 5                   " << endl;
    cout << "                           ELIMINAR UN PRODUCTO                        " << endl;
    cout << "_______________________________________________________________________" << endl;

    if (producto_n == 0) {
        cout << "\n No hay productos registrados para eliminar.\n";
        return;
    }

    cout << "\n                            PRODUCTO A ELIMINAR                 \n" << endl;
    int indice_eliminar;
    cout << "\n INGRESE EL INDICE DEL PRODUCTO QUE DESEA ELIMINAR (1-" << producto_n << ") "<<endl;
    cout << "\nIndice : ";
    cin >> indice_eliminar;

    if (indice_eliminar < 1 || indice_eliminar > producto_n) {
        cout << "\n Índice inválido , por favor ingrese un índice válido." << endl;
        return;
    }

    int indice_arreglo = indice_eliminar - 1;

    prod[indice_arreglo] = prod[producto_n - 1];
    producto_n--;

    cout << "\nProducto eliminado exitosamente." << endl;
    cout << "\n_______________________________________________________________" << endl;
}


// F. REGISTRAR UNA VENTA 

const int max_ventas = 50;
Venta ventas[max_ventas];
int venta_n = 0;

void Registrar_venta() {
    cout << "\n                  HA SELECCIONADO LA OPCION 6                 " << endl;
    cout << "\n                   REGISTRAR UNA NUEVA VENTA                  " << endl;
    cout << "______________________________________________________________\n";

    if (producto_n == 0) {
        cout << "\nNo hay productos registrados.\n";
        cout << "__________________________________________________________________" << endl;
        return;
    }

    Venta nueva_venta;

    // Generar un id de venta simple (puedes mejorar esto con un contador global)
    nueva_venta.id_venta = venta_n + 1;

    cout << "\n                       NUEVA VENTA                         \n" << endl;
    cout << "\n              SELECCIONE EL PRODUCTO A VENDER              \n" << endl;
	cout << "\n             (Ingrese el número de producto)               \n" << endl;
	
    for (int i = 0; i < producto_n; i++) {
        cout << i + 1 << ". " << prod[i].nombre << " - Precio: " << prod[i].precio << endl;
    }
    cout << "\nNumero de producto: ";
    int opcion_producto;
    cin >> opcion_producto;

    if (opcion_producto < 1 || opcion_producto > producto_n) {
        cout << "\nOpción inválida.\n";
        cout << "__________________________________________________________________" << endl;
        return;
    }

    nueva_venta.producto = prod[opcion_producto - 1].nombre;

    cout << "\nCantidad: ";
    cin >> nueva_venta.cantidad;

    nueva_venta.precio_total = nueva_venta.cantidad * prod[opcion_producto - 1].precio;

    ventas[venta_n++] = nueva_venta;

    cout << "\nVenta registrada exitosamente.\n";
    cout << "______________________________________________________________" << endl;
}


// G. Listar las ventas realizadas.





// H. Calcular el total de ventas realizadas.

// S. Salir del programa. 


//FUNCION PARA MOSTARAR 	DE MENU DE OPCIONES 
int mostrar_menu(){
	int opcion;
	cout<< "\n---------------------------MENÚ DE OPCIONES----------------------"<<endl;
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
    cout<< "___________________________________________________________________"<<endl;
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
				Actualizar_datos();
				break;
			case 5:
				// LLAMAMOS A : E. Eliminar un producto. 
				Eliminar_producto();
				break;
			case 6:
				// LLAMAMOS A : F. Registrar una venta.
				Registrar_venta();
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



	