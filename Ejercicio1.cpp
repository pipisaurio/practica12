#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> numeros;
    int numero;

    // Ingresar números
    cout << "Ingrese números enteros (ingrese 0 para terminar):\n";
    while (true) {
        cin >> numero;
        if (numero == 0) break;
        numeros.push_back(numero);
    }

    // a) Calcular la suma
    int suma = accumulate(numeros.begin(), numeros.end(), 0);
    cout << "Suma de todos los números: " << suma << endl;

    // b) Encontrar máximo y mínimo
    auto min = min_element(numeros.begin(), numeros.end());
    auto max = max_element(numeros.begin(), numeros.end());
    cout << "Número mínimo: " << *min << endl;
    cout << "Número máximo: " << *max << endl;

    // c) Ordenar de forma ascendente
    sort(numeros.begin(), numeros.end());
    cout << "Números ordenados: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // d) Eliminar números pares
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
