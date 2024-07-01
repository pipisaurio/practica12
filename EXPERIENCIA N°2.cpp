#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

string convertir_a_mayusculas(const string& cadena) { // Función para convertir una cadena a mayúsculas
    string resultado = cadena;
    for (char& letra : resultado) {
        if (letra >= 'a' && letra <= 'z') {
            letra = letra - 'a' + 'A';
        }
    }
    return resultado;
}

int main() {
    list<string> listaDePalabras;
    string palabra;

    cout << "Escribe palabras (escribe '0' para terminar):" << endl;
    while (true) {
        cin >> palabra;
        if (palabra == "0") break;  // Termina el bucle si se ingresa '0'
        listaDePalabras.push_back(palabra);
    }


    listaDePalabras.sort();     // ordenar las palabras

    cout << "Escribe una palabra para contar: ";    //se pide una palabra para contar
    string palabraParaBuscar;
    cin >> palabraParaBuscar;
    int cont = count_if(listaDePalabras.begin(), listaDePalabras.end(), [&palabraParaBuscar](const string& palabra) {
        return palabra == palabraParaBuscar;
    });
    cout << "La palabra '" << palabraParaBuscar << "' aparece " << cont << " veces." << endl;

    transform(listaDePalabras.begin(), listaDePalabras.end(), listaDePalabras.begin(), [](string& palabra) {
        return convertir_a_mayusculas(palabra);
    });

    cout << "Lista de palabras en mayúsculas y ordenadas alfabéticamente de forma ascendente:" << endl;
    for (const auto& palabra : listaDePalabras) {
        cout << palabra << endl;
    }

    return 0;
}
