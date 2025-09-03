
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

const std::vector <std::string> colores = { "azul", "rojo", "verde" };

bool esValida(std::vector<int> const& sol, int etapa) {
    if (sol[etapa] == 2) {
        if (sol[etapa - 1] == 2) return false;
        else return true;
    }
    else return true;
}

void resolver(int pisos, int etapa, std::vector<int>& sol) {
    for (int i = 0; i < 3; i++) {
        sol[etapa] = i;
        if (esValida(sol, etapa)) {
            if (etapa == pisos - 1) {
                for (int j = 0; j < pisos; j++) std::cout << colores[sol[j]] << ' ';
                std::cout << '\n';
            }
            else resolver(pisos, etapa + 1, sol);
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int pisos;
    std::cin >> pisos;
    // leer los datos de la entrada

    if (pisos == 0)  // fin de la entrada
        return false;
    std::vector <int> sol(pisos, -1);
    sol[0] = 1;
    if (pisos == 1) std::cout << colores[1] << '\n';
    else resolver(pisos, 1, sol);
    std::cout << '\n';

    // escribir sol

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
