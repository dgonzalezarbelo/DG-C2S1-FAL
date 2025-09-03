
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool esValida(std::vector <std::pair<std::string, int>> const& regalos, std::vector <int>& chavales, int k, int minSat, std::vector<int> const& satisfaccion) {
    if (k % 2 == 1) {
        if (regalos[chavales[k]].first <= regalos[chavales[k - 1]].first) return false;
        if (satisfaccion[k / 2] < minSat) return false;
        return true;
    }
    else return true;
}

void resolver(std::vector <std::pair<std::string, int>>& regalos, std::vector <int>& chavales, int k, int& soluciones, std::vector<std::vector<int>> const& matriz,
    int minSat, std::vector <int>& satisfaccion) {
    for (int i = 0; i < regalos.size(); i++) {
        if (regalos[i].second > 0) {
            chavales[k] = i;
            satisfaccion[k / 2] += matriz[k / 2][i];
            regalos[i].second--;
            if (k % 2 == 0) {
                resolver(regalos, chavales, k + 1, soluciones, matriz, minSat, satisfaccion);
            }
            else {
                if (esValida(regalos, chavales, k, minSat, satisfaccion)) {
                    if (k == chavales.size() - 1) {
                        for (int i = 0; i < chavales.size(); i++) std::cout << chavales[i] << ' ';
                        std::cout << '\n';
                        soluciones++;
                    }
                    else resolver(regalos, chavales, k + 1, soluciones, matriz, minSat, satisfaccion);
                }
            }
            satisfaccion[k / 2] -= matriz[k / 2][i];
            regalos[i].second++;
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numRegalos, numChavales, minSat;
    std::cin >> numRegalos >> numChavales >> minSat;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <std::pair<std::string, int>> regalos(numRegalos);  //<regalo, cantidad>
    std::vector <int> chavales(2 * numChavales);
    for (int i = 0; i < numRegalos; i++) std::cin >> regalos[i].second;
    for (int i = 0; i < numRegalos; i++) std::cin >> regalos[i].first;
    int soluciones = 0;
    std::vector <std::vector<int>> matriz(numChavales, std::vector <int>(numRegalos));
    for (int i = 0; i < numChavales; i++) {
        for (int j = 0; j < numRegalos; j++) {
            std::cin >> matriz[i][j];
        }
    }
    std::vector <int> satisfaccion(numChavales, 0);
    resolver(regalos, chavales, 0, soluciones, matriz, minSat, satisfaccion);
    if (soluciones == 0) std::cout << "SIN SOLUCION\n\n";
    else std::cout << '\n';
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
