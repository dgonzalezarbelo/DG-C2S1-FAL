
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

const std::vector <std::string> colores = { "azul", "rojo", "verde" };

bool esValida(std::vector <int> const& sol, int etapa, std::vector <int> const& cantidades) {
    if (cantidades[2] > cantidades[0]) return false;
    else {
        if (sol[etapa] == 2) {
            if (sol[etapa - 1] == 2) return false;
            else return true;
        }
        else return true;
    }
}

void resolver(int pisos, int etapa, std::vector <int> & sol, std::vector <int> & cantidades, std::vector <int> & bloques, int & soluciones) {
    for (int i = 0; i < 3; i++) {
        if (bloques[i] > 0) {
            bloques[i]--;
            sol[etapa] = i;
            cantidades[i]++;
            if (esValida(sol, etapa, cantidades)) {
                if (etapa == pisos - 1) {
                    if (cantidades[1] > cantidades[0] + cantidades[2]) {
                        for (int j = 0; j < pisos; j++) std::cout << colores[sol[j]] << ' ';
                        std::cout << '\n';
                        soluciones++;
                    }
                }
                else resolver(pisos, etapa + 1, sol, cantidades, bloques, soluciones);
            }
            cantidades[i]--;
            bloques[i]++;
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int pisos;
    std::cin >> pisos;
    // leer los datos de la entrada
    std::vector <int> bloques(3);
    for (int i = 0; i < 3; i++) std::cin >> bloques[i];
    if (pisos == 0 && bloques[0] == 0 && bloques[1] == 0 && bloques[2] == 0)  // fin de la entrada
        return false;
    std::vector <int> sol(pisos, -1);
    std::vector <int> cantidades(3, 0);
    int soluciones = 0;
    if (pisos == 1) {
        if (bloques[1] > 0) {
            std::cout << colores[1] << '\n';
            soluciones++;
        }
    }
    else {
        sol[0] = 1; //Primer piso rojo
        cantidades[1]++;
        bloques[1]--;   //Ya hemos gastado una pieza roja
        resolver(pisos, 1, sol, cantidades, bloques, soluciones);
    } 
    if (soluciones == 0) std::cout << "SIN SOLUCION\n";
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
