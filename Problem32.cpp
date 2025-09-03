
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int transf(long long int num) {
    if (num % 2 == 0) return (num + 1);
    else return (num - 1);
}

long long int resolverNoFinal(long long int num) {
    if (num < 10) return transf(num);
    else return ((resolverNoFinal(num / 10) * 10) + transf(num % 10));
}


long long int resolverFinal(long long int num, long long int t, int p) {
    if (num < 10) return (transf(num) * p + t);
    else return resolverFinal(num / 10, t + transf(num % 10) * p, p * 10);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int num;
    std::cin >> num;
    
    // leer los datos de la entrada

    long long int sol = resolverFinal(num, 0, 1);

    // escribir solución
    std::cout << sol << '\n';
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
