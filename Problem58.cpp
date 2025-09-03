
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool esValida(std::vector <int> const& dias, std::vector <std::pair<int, int>> const& abrigos, std::vector <int> const& sol, int k, int i, std::vector <int> const& apariciones) {
    if (dias[k] > abrigos[sol[k]].second) return false;
    if (k > 0 && sol[k] == sol[k - 1]) return false;
    if (apariciones[i] > 2 + k / 3) return false;
    else return true;
}

void resolver(std::vector <int> const& dias, std::vector <std::pair<int, int>> const& abrigos, int k, std::vector <int> & sol, int & soluciones, 
    std::vector <int> & apariciones) {
    for (int i = 0; i < abrigos.size(); i++) {
        sol[k] = abrigos[i].first;
        apariciones[i]++;
        if (esValida(dias, abrigos, sol, k, i, apariciones)) {
            if (k == dias.size() - 1) {
                if (sol[sol.size() - 1] != sol[0]) soluciones++;
            }
            else resolver(dias, abrigos, k + 1, sol, soluciones, apariciones);
        }
        apariciones[i]--;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numDias, numAbrigos;
    // leer los datos de la entrada
    std::cin >> numDias;
    std::cin >> numAbrigos;
    if (numDias == 0 && numAbrigos == 0) return false;
    std::vector <int> dias(numDias);
    std::vector <std::pair<int,int>> abrigos(numAbrigos);
    std::vector <int> sol(numDias);
    std::vector <int> apariciones(numAbrigos, 0);
    for (int i = 0; i < numDias; i++) std::cin >> dias[i];
    for (int i = 0; i < numAbrigos; i++) {
        abrigos[i].first = i;
        std::cin >> abrigos[i].second;
    } 
    int k = 0, soluciones = 0;
    resolver(dias, abrigos, k, sol, soluciones, apariciones);
    if (soluciones > 0) std::cout << soluciones << '\n';
    else std::cout << "Lo puedes comprar\n";
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
