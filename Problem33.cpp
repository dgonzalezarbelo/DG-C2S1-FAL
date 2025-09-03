
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolverFinal(int num, int t) {
    if (num < 10) return (num + 10 * t);
    else return resolverFinal(num / 10, t * 10 + (num % 10));
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    // leer los datos de la entrada

    if (num == 0)
        return false;

    int sol = resolverFinal(num, 0);

    // escribir sol
    std::cout << sol << '\n';

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
