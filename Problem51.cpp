
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string> 

struct tSolSinUnos {
    bool tieneUnos;
    long long int cantidad;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

tSolSinUnos sinUnos(long long int n) {
    if (n < 10) {
        if (n == 0) return { false, 1 };
        else if (n == 1) return { true, 1 };
        else return { false, n };
    }
    else {
        tSolSinUnos sol = sinUnos(n / 10);
        if (sol.tieneUnos) return { true, sol.cantidad * 9 };
        else {
            if (n % 10 > 1) return { false, sol.cantidad * 9 - (9 - n % 10) };
            else return { n % 10 == 1, sol.cantidad * 9 - 8 };
        }
    }
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int num;
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;
    tSolSinUnos sol = sinUnos(num);
    std::cout << sol.cantidad << '\n';
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
