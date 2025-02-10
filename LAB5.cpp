#include <iostream>
#include <vector>
#include <string>
using namespace std;

class producto {
private:
	string nombre;
	int codigo;
	float precio;
	int stock;

public: 
	producto(string nom, int cod, float prec, int stk) {
		nombre = nom;
		codigo = cod;
		precio = prec;
		stock = stk;
	}

	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "Procuto: " << nombre << endl;
		cout << "Precio: Q " << precio << endl;
		cout << "Stock: " << stock << endl;
	}
	int obtenercodigo() {
		return codigo;
	}
	int obtenerstock() {
		return stock;
	}
	void actualizarstock(int cantidad) {
		if (cantidad > stock) {
			cout << "No hay suficiente stock disponible" << endl;
		}
		else {
			stock -= cantidad;
			cout << "Stock actualizado. Nuevo stock: " << stock << endl;
		}
	}
	float obtenervalor() {
		return stock * precio;
	}
};

void agregarproducto(vector <producto>& inventario) {
	string nombre;
	int codigo, stock;
	float precio;

	cout << "Ingrese el nombre del producto: ";
	cin >> ws; 
	getline(cin, nombre);
	cout << "Ingrese el codigo: ";
	cin >> codigo;
	cout << "Ingrese el precio: ";
	cin >> precio;
	cout << "Ingree la cantidad en stock: ";
	cin >> stock;

	inventario.push_back(producto(nombre, codigo, precio, stock));
}
void mostrarinventario(vector<producto>& inventario) {
	if (inventario.empty()) {
		cout << "No hay productos en el inventario." << endl;
		return;
	}
	for (producto& producto : inventario) {
		producto.mostrar();
	}
}

void buscarproducto(vector<producto>& inventario) {
	int codigo;
	cout << "Ingrese el codigo del producto a buscar: ";
	cin >> codigo;

	for (producto& producto : inventario) {
		if (producto.obtenercodigo() == codigo) {
			cout << "Produco encontrado: ";
			producto.mostrar();
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void actualizarstock(vector<producto>& inventario) {
	int codigo, cantidad;
	cout << "Ingrese el codigo del producto a actualizar: ";
	cin >> codigo;

	for (producto& producto : inventario) {
		if (producto.obtenercodigo() == codigo) {
			cout << "Ingrese la cantidad a restar del stock:";
			cin >> cantidad;
			producto.actualizarstock(cantidad);
			return;
		}
	}
	cout << "Producto no encontrado" << endl;
}
void calcularvalortotal(vector < producto>& inventario) {
	float total = 0;
	for (producto& producto : inventario) {
		total += producto.obtenervalor();
	}
	cout << "Valor total del inventario: Q" << total << endl;
}

int main() {
	vector <producto> inventario;
	int opcion;
	do {
		cout << "\n Sistema de inventario \n";
		cout << "1. Agregar producto \n";
		cout << "2. Mostrar inventario \n";
		cout << "3. Buscar producto por codigo \n";
		cout << "4. Actualizar stock \n";
		cout << "5. Calcular valor total del inventario \n";
		cout << "6. Salir \n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: agregarproducto(inventario); break;
		case 2: mostrarinventario(inventario); break;
		case 3: buscarproducto(inventario); break;
		case 4: actualizarstock(inventario); break;
		case 5: calcularvalortotal(inventario); break;
		case 6: cout << "Saliendo del programa ...\n"; break;
		default: cout << "Opcion no valida, intente de nuevo \n";
		}
		
	} while (opcion != 6);
	return 0;
}
