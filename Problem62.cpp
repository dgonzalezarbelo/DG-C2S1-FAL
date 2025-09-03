
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(std::vector <int>& chavales, std::vector <bool>& disponibles, int k, std::vector<std::vector<int>> const& matriz,
    int& maxSat, std::vector <int> mejorSol, std::vector <int> const& maximos, int& sat) {
    for (int i = 0; i < disponibles.size(); i++) {
        if (disponibles[i]) {
            chavales[k] = i;
            sat += matriz[k][i];
            disponibles[i] = false;
            if (k < maximos.size() - 1) {
                if (sat + maximos[k + 1] > maxSat) {
                    resolver(chavales, disponibles, k + 1, matriz, maxSat, mejorSol, maximos, sat);
                }
            }
            else {
                if (sat >= maxSat) {
                    mejorSol = chavales;
                    maxSat = sat;
                }
            }
            sat -= matriz[k][i];
            disponibles[i] = true;
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numRegalos, numChavales;
    std::cin >> numRegalos >> numChavales;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <int> chavales(numChavales);
    std::vector <bool> disponibles(numRegalos, true);
    std::vector <std::vector<int>> matriz(numChavales, std::vector <int>(numRegalos));
    std::vector <int> maximos(numChavales);
    for (int i = 0; i < numChavales; i++) {
        for (int j = 0; j < numRegalos; j++) {
            std::cin >> matriz[i][j];
            if (matriz[i][j] > maximos[i]) maximos[i] = matriz[i][j];
        }
    }
    for (int i = numChavales - 2; i >= 0; i--) maximos[i] += maximos[i + 1];    //Hacemos el vector de acumulados
    std::vector <int> mejorSol(numChavales);
    int sat = 0;
    for (int i = 0; i < numChavales; i++) mejorSol[i] = i;
    int maxSat = 0;
    for (int i = 0; i < numChavales; i++) maxSat += matriz[i][i];
    resolver(chavales, disponibles, 0, matriz, maxSat, mejorSol, maximos, sat);
    // escribir sol
    printf("%d\n", maxSat);
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
