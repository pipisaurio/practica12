#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	vector<int> numeros;
	int numero;
	
	// Ingresar n�meros
	cout << "Ingrese n�meros enteros (ingrese 0 para terminar):\n";
	while (true) {
		cin >> numero;
		if (numero == 0) break;
		numeros.push_back(numero);
	}
	
	// a) Calcular la suma
	int suma = accumulate(numeros.begin(), numeros.end(), 0);
	cout << "Suma de todos los n�meros: " << suma << endl;
	
	// b) Encontrar m�ximo y m�nimo
	auto min = min_element(numeros.begin(), numeros.end());
	auto max = max_element(numeros.begin(), numeros.end());
	cout << "N�mero m�nimo: " << *min << endl;
	cout << "N�mero m�ximo: " << *max << endl;
	
	// c) Ordenar de forma ascendente
	sort(numeros.begin(), numeros.end());
	cout << "N�meros ordenados: ";
	for (int num : numeros) {
		cout << num << " ";
	}
	cout << endl;
	
	// d) Eliminar n�meros pares
	numeros.erase(remove_if(numeros.begin(), numeros.end(), 
							[](int n) { return n % 2 == 0; }),
				  numeros.end());
	
	// Mostrar contenido final
	cout << "Contenido final del contenedor: ";
	for (int num : numeros) {
		cout << num << " ";
	}
	cout << endl;
	
	return 0;
}
