
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

void resolver(int n, int m, int etapa, std::string & sol) {
    for (int i = 'a'; i < 'a' + n; i++) {
        sol += i;
        if (etapa == m - 1) std::cout << sol << '\n';
        else resolver(n, m, etapa + 1, sol);
        sol.erase(sol.size() - 1, 1);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, m;
    std::cin >> n;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    std::cin >> m;
    std::string sol = "";
    resolver(n, m, 0, sol);
    std::cout << '\n';

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
