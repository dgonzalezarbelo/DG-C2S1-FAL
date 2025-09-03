
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool esValida(std::vector <std::string> const& regalos, std::vector <int>& chavales, int k) {
    return regalos[chavales[k]] > regalos[chavales[k - 1]];
}

void resolver(std::vector <std::string> const& regalos, std::vector <int> & chavales, int k, int & soluciones) {
    for (int i = 0; i < regalos.size(); i++) {
        chavales[k] = i;
        if (k % 2 == 0) {
            resolver(regalos, chavales, k + 1, soluciones);
        }
        else {
            if (esValida(regalos, chavales, k)) {
                if (k == chavales.size() - 1) {
                    for (int i = 0; i < chavales.size(); i++) std::cout << chavales[i] << ' ';
                    std::cout << '\n';
                    soluciones++;
                }
                else resolver(regalos, chavales, k + 1, soluciones);
            }
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
    std::vector <std::string> regalos(numRegalos);
    std::vector <int> chavales(2 * numChavales);
    for (int i = 0; i < numRegalos; i++) std::cin >> regalos[i];
    int soluciones = 0;
    resolver(regalos, chavales, 0, soluciones);
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
