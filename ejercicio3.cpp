#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Contacto {
	string nombre;
	string telefono;
	string email;
};

class Agenda {
private:
	vector<Contacto> contactos;
	
public:
	void agregarContacto() {
		Contacto nuevoContacto;
		cout << "Nombre: ";
		getline(cin, nuevoContacto.nombre);
		cout << "Teléfono: ";
		getline(cin, nuevoContacto.telefono);
		cout << "Email: ";
		getline(cin, nuevoContacto.email);
		contactos.push_back(nuevoContacto);
		cout << "Contacto agregado con éxito.\n";
	}
	
	void buscarContacto() {
		string nombre;
		cout << "Ingrese el nombre a buscar: ";
		getline(cin, nombre);
		auto it = find_if(contactos.begin(), contactos.end(),
						  [&nombre](const Contacto& c) { return c.nombre == nombre; });
		if (it != contactos.end()) {
			cout << "Contacto encontrado:\n";
			cout << "Nombre: " << it->nombre << "\n";
			cout << "Teléfono: " << it->telefono << "\n";
			cout << "Email: " << it->email << "\n";
		} else {
			cout << "Contacto no encontrado.\n";
		}
	}
	
	void actualizarContacto() {
		string nombre;
		cout << "Ingrese el nombre del contacto a actualizar: ";
		getline(cin, nombre);
		auto it = find_if(contactos.begin(), contactos.end(),
						  [&nombre](const Contacto& c) { return c.nombre == nombre; });
		if (it != contactos.end()) {
			cout << "Ingrese la nueva información:\n";
			cout << "Teléfono: ";
			getline(cin, it->telefono);
			cout << "Email: ";
			getline(cin, it->email);
			cout << "Contacto actualizado con éxito.\n";
		} else {
			cout << "Contacto no encontrado.\n";
		}
	}
	
	void mostrarContactos() {
		if (contactos.empty()) {
			cout << "La agenda está vacía.\n";
			return;
		}
		sort(contactos.begin(), contactos.end(),
			 [](const Contacto& a, const Contacto& b) { return a.nombre < b.nombre; });
		cout << "Lista de contactos:\n";
		for (const auto& contacto : contactos) {
			cout << "Nombre: " << contacto.nombre << "\n";
			cout << "Teléfono: " << contacto.telefono << "\n";
			cout << "Email: " << contacto.email << "\n";
			cout << "------------------------\n";
		}
	}
};

int main() {
	Agenda agenda;
	int opcion;
	
	do {
		cout << "\nAgenda de Contactos\n";
		cout << "1. Agregar contacto\n";
		cout << "2. Buscar contacto\n";
		cout << "3. Actualizar contacto\n";
		cout << "4. Mostrar todos los contactos\n";
		cout << "0. Salir\n";
		cout << "Elija una opción: ";
		cin >> opcion;
		cin.ignore();  // Limpiar el buffer de entrada
		
		switch (opcion) {
		case 1:
			agenda.agregarContacto();
			break;
		case 2:
			agenda.buscarContacto();
			break;
		case 3:
			agenda.actualizarContacto();
			break;
		case 4:
			agenda.mostrarContactos();
			break;
		case 0:
			cout << "Gracias por usar la agenda. ¡Hasta luego!\n";
			break;
		default:
			cout << "Opción no válida. Intente de nuevo.\n";
		}
	} while (opcion != 0);
	
	return 0;
}
