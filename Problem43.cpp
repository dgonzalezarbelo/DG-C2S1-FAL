
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// T(n) = 2T(n / 2) + c = 2^2T(n/2^2) + 2c = ... = nlog(n) + n
bool resolver(std::vector <int> const& v, int ini, int fin, int k) {
    if (ini == fin - 1) return true;
    else {
        int m = (ini + fin) / 2;
        return resolver(v, ini, m, k) && resolver(v, m, fin, k) && (v[fin - 1] - v[ini] >= k || v[ini] - v[fin - 1] >= k);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num, k;
    // leer los datos de la entrada
    std::cin >> num >> k;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++)std::cin >> v[i];
    bool sol = resolver(v, 0, num, k);
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";
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
