
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using tSol = std::pair <std::string, int>;

// T(n) = T(n/2) + c, n > 2
// El algoritmo pertenece a O(log n)

tSol resolver(std::vector<tSol> const& v, int ini, int fin) {
    if (ini == fin - 2) {
        if (v[ini].second >= v[ini + 1].second) return { v[ini].first, v[ini].second + v[ini + 1].second / 2 };
        else return { v[ini + 1].first, v[ini + 1].second + v[ini].second / 2 };
    }
    else {
        int m = (ini + fin) / 2;
        tSol ganador1, ganador2;
        ganador1 = resolver(v, ini, m);
        ganador2 = resolver(v, m, fin);
        if (ganador1.second >= ganador2.second) return { ganador1.first, ganador1.second + ganador2.second / 2 };
        else return { ganador2.first, ganador2.second + ganador1.second / 2 };
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num;
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <tSol> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i].first >> v[i].second;
    tSol sol = resolver(v, 0, num);
    std::cout << sol.first << ' ' << sol.second << '\n';
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
