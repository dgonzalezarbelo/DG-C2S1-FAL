
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// El coste del algoritmo es logaritmico.
int resolver(std::vector <int> const& v, std::vector <int> const& w, int ini, int fin) {
    if (ini >= fin - 1) return ini;
    else {
        int m = (ini + fin - 1) / 2;
        if (v[m] < w[m]) return resolver(v, w, ini, m + 1);
        else return resolver(v, w, m + 1, fin);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num;
    std::cin >> num;
    std::vector <int> v(num);
    std::vector <int> w(num - 1);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    for (int i = 0; i < num - 1; i++) std::cin >> w[i];
    // leer los datos de la entrada

    int sol = resolver(v, w, 0, num);
    std::cout << v[sol] << '\n';
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
