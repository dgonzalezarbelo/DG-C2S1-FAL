
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

const std::vector <std::string> colores = { "azul", "rojo", "verde" };

void resolver(int pisos, int etapa, std::vector<int>& sol) {
    for (int i = 0; i < 3; i++) {
        sol[etapa] = i;
        if (etapa == pisos - 1) {
            for (int j = 0; j < pisos; j++) std::cout << colores[sol[j]] << ' ';
            std::cout << '\n';
        }
        else resolver(pisos, etapa + 1, sol);
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
    std::vector <int> sol(pisos);
    resolver(pisos, 0, sol);
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
