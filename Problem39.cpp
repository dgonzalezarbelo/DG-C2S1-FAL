
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

// El algoritmo tiene coste logaritmico
int resolver(std::vector <int> const& v, int ini, int fin) {
    if (ini >= fin - 1) return ini;
    else {
        int m = (ini + fin) / 2;
        if ((m > ini && v[m] > v[m - 1]) || (m == ini && v[m] < v[m + 1])) return resolver(v, ini, m);
        else return resolver(v, m, fin);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) {
        std::cin >> v[i];
    }
    int sol = resolver(v, 0, v.size());

    // escribir sol
    std::cout << v[sol] << '\n';
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
