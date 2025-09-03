
// Nombre y Apellidos: Daniel Gonzalez Arbelo


#include <iostream>
#include <fstream>
#include <vector>

// Por dividirse el vector en dos en cada llamada recursiva, el coste del algoritmo pertenece a O(log n)
char resolver(std::vector <char> const& v, int ini, int fin) {
    if (ini >= fin - 1) return v[ini];
    else {
        int m = (ini + fin) / 2;
        if (v[m] - v[ini] > m - ini) return resolver(v, ini, m);
        else return resolver(v, m, fin);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    char ini, fin;
    std::cin >> ini >> fin;
    std::cin.ignore(3, '\n');
    // leer los datos de la entrada
    std::vector <char> v (fin - ini);
    for (int i = 0; i < fin - ini; i++) {
        std::cin >> v[i];
    }
    char sol = resolver(v, 0, v.size());
    if (sol == v[v.size() - 1]) {
        if (sol == fin) std::cout << ini << '\n';
        else std::cout << fin << '\n';
    }
    else std::cout << char(sol + 1) << '\n';
    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
