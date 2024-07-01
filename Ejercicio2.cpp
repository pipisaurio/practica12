#include <iostream> 
#include <map> 
#include <algorithm>  
#include <string> 

using namespace std; 

struct Evento { 
    string fecha; 
    string asistentes[100];  
    int numAsistentes;  
}; 

// Mapa para almacenar eventos 

map<string, Evento> eventos; 

void agregarEvento(const string& nombreEvento, const string& fecha) { 
    if (eventos.find(nombreEvento) == eventos.end()) { 
        eventos[nombreEvento] = {fecha, {}, 0}; 
        cout << "Evento '" << nombreEvento << "' agregado con éxito." << endl; 
    } else { 
        cout << "Error: El evento '" << nombreEvento << "' ya existe." << endl; 
    } 
} 

  

void agregarAsistentes(const string& nombreEvento, const string nuevosAsistentes[], int numNuevos) { 
    if (eventos.find(nombreEvento) != eventos.end()) { 
        Evento& evento = eventos[nombreEvento]; 
        int inicio = evento.numAsistentes; 
        for (int i = 0; i < numNuevos; ++i) { 
            evento.asistentes[inicio + i] = nuevosAsistentes[i]; 
        } 

        evento.numAsistentes += numNuevos; 
        cout << "Asistentes agregados al evento '" << nombreEvento << "'." << endl; 
    } else { 

        cout << "Error: El evento '" << nombreEvento << "' no existe." << endl; 
    } 
} 

void mostrarAsistentesOrdenados(const string& nombreEvento) { 
    if (eventos.find(nombreEvento) != eventos.end()) { 
        Evento& evento = eventos[nombreEvento]; 
        int numAsistentes = evento.numAsistentes; 
        sort(evento.asistentes, evento.asistentes + numAsistentes); 
        cout << "Asistentes del evento '" << nombreEvento << "':" << endl; 
        for (int i = 0; i < numAsistentes; ++i) { 
            cout << evento.asistentes[i] << endl; 
        } 
    } else { 
        cout << "Error: El evento '" << nombreEvento << "' no existe." << endl; 
    } 
} 

  

// Función para buscar eventos por fecha 

void buscarEventosPorFecha(const string& fecha) { 
    bool encontrado = false; 
    for (const auto& par : eventos) { 
        if (par.second.fecha == fecha) { 
            cout << "Evento: " << par.first << endl; 
            encontrado = true; 
        } 
    } 
    if (!encontrado) { 
        cout << "No hay eventos programados para la fecha '" << fecha << "'." << endl; 
    } 
} 

  

// Función principal  

int main() { 

    int opcion; 
    string nombreEvento, fecha, asistentesInput; 
    string asistentes[100]; // Arreglo para los nombres de los asistentes 
    int numAsistentes; 

    while (true) { 
        cout << "\n--- Gestión de Eventos ---" << endl; 
        cout << "1. Agregar un nuevo evento" << endl; 
        cout << "2. Agregar asistentes a un evento" << endl; 
        cout << "3. Mostrar lista de asistentes de un evento" << endl; 
        cout << "4. Buscar eventos por fecha" << endl; 
        cout << "5. Salir" << endl; 
        cout << "Seleccione una opción (1-5): "; 
        cin >> opcion; 

        switch (opcion) { 
            case 1: 
                cout << "Ingrese el nombre del nuevo evento: "; 
                cin >> nombreEvento; 
                cout << "Ingrese la fecha del evento (YYYY-MM-DD): "; 
                cin >> fecha; 
                agregarEvento(nombreEvento, fecha); 
                break; 
            case 2: 
                cout << "Ingrese el nombre del evento al que desea agregar asistentes: ";
                cin >> nombreEvento; 
                cout << "Ingrese el número de asistentes que desea agregar: "; 
                cin >> numAsistentes; 
                cout << "Ingrese los nombres de los asistentes separados por espacios (máximo 100): "; 
                for (int i = 0; i < numAsistentes; ++i) { 
                    cin >> asistentes[i];
                } 
                agregarAsistentes(nombreEvento, asistentes, numAsistentes); 
                break; 
            case 3: 
                cout << "Ingrese el nombre del evento del cual desea ver la lista de asistentes: "; 
                cin >> nombreEvento; 
                mostrarAsistentesOrdenados(nombreEvento); 
                break; 
            case 4: 
                cout << "Ingrese la fecha para buscar eventos (YYYY-MM-DD): "; 
                cin >> fecha; 
                buscarEventosPorFecha(fecha); 
                break; 
            case 5: 
                cout << "¡Hasta luego!" << endl; 
                return 0; 
            default: 
                cout << "Opción inválida. Por favor, seleccione una opción válida (1-5)." << endl; 
                break; 
        } 
    } 

    return 0; 

} 