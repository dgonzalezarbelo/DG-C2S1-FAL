
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolverNoFinal(int num, int digito) {
    if (num < 10) {
        if (num == digito) return 1;
        else return 0;
    }
    else {
        if (num % 10 == digito) return resolverNoFinal(num / 10, digito) + 1;
        else return resolverNoFinal(num / 10, digito);
    }
}

int resolverFinal(int num, int digito, int sol) {
    if (num < 10) {
        if (num == digito) return sol + 1;
        else return sol;
    } 
    else {
        if (num % 10 == digito) return resolverFinal(num / 10, digito, sol + 1);
        else return resolverFinal(num / 10, digito, sol);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, digito;
    std::cin >> num >> digito;
    // leer los datos de la entrada
    std::cout << resolverNoFinal(num, digito) << ' ' << resolverFinal(num, digito, 0) << '\n';

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
