
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolverNoFinal(int num) {
    if (num < 10) return num;
    else return resolverNoFinal(num / 10) + num % 10;
}

int resolverFinal(int num, int sum) {
    if (num == 0) return sum;
    else return resolverFinal(num / 10, sum + num % 10);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int cant, primero, num, suma, sol;
    std::cin >> cant >> primero;
    // leer los datos de la entrada
    suma = resolverNoFinal(primero);
    for (int i = 0; i < cant; i++) {
        std::cin >> num;
        sol = resolverNoFinal(num);
        if (sol == suma) std::cout << num << ' ';
    }
    std::cout << '\n';

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
