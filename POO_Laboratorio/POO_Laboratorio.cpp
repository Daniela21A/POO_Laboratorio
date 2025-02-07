#include <iostream>
using namespace std;

//clase animal 
class animal {
protected: 
	string nombre;
	int edad;
public:
	animal(string n, int e): nombre (n), edad(e){}
	virtual void hacersonido() {
		cout << nombre << "hace un sonido desconocido." << endl;

	}
};

//clase perro (hereda de animal)

class perro : public animal {
public: 
	perro(string n, int e): animal(n, e){}

	void hacersonido() {
		cout << nombre << "dice: Miau!" << endl;
	}
};

// clase automovil 

class automovil {
private:
	string marca;
	int velocidad;

public:
		automovil(string m, int v): marca(m), velocidad(v){}
	void acelerar() {
		velocidad += 10;
		cout << "El automovil " << marca << " ahora va a " << velocidad << " km/h " << endl;
	}
};

// clase persona 
class persona {
private:
	string nombre;
	int edad;

public:
	persona(string n, int e): nombre(n), edad(e) {}

	void saludar() {
		cout << "hola, mi nombre es " << nombre << " y tengo " << edad << " años" << endl;
	}
};

// funcion main 

int main() {
	perro miperro("cheeto ", 5);
	miperro.hacersonido();

	automovil micoche("Porsche ", 60);
	micoche.acelerar();

	persona persona1("Daniela", 19);
	persona1.saludar();

	return 0;

}