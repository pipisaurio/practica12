#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

bool esVocal(char c) {
	c = tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	deque<char> contenedor;
	string entrada;
	
	cout << "Ingrese una cadena de caracteres: ";
	getline(cin, entrada);
	
	// Almacenar la cadena en el deque
	for (char c : entrada) {
		contenedor.push_back(c);
	}
	
	// a) Mostrar los caracteres uno por uno
	cout << "Caracteres uno por uno:" << endl;
	for (auto it = contenedor.begin(); it != contenedor.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	// b) Reemplazar vocales con '*'
	for (auto it = contenedor.begin(); it != contenedor.end(); ++it) {
		if (esVocal(*it)) {
			it = "";
		}
	}
	
	// c) Mostrar caracteres en orden inverso
	cout << "Caracteres en orden inverso:" << endl;
	for (auto it = contenedor.rbegin(); it != contenedor.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	// Mostrar la cadena resultante
	cout << "Cadena resultante:" << endl;
	for (char c : contenedor) {
		cout << c;
	}
	cout << endl;
	
	return 0;
}
