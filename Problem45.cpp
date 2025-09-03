
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

struct tSol {
    bool sol;
    int suma;
};
// T(n) = 2T(n/2) + c = 4T(n/4) + 2c = ... = 2^k*T(n/2^k) + kc = ... = nT(1) + c*log(n) pertenece a O(n)
tSol resolver(std::vector <int> const& v, int ini, int fin) {
    tSol sol;
    if (ini >= fin - 1) {
        sol.sol = true;
        sol.suma = v[ini];
        return sol;
    }
    else {
        int m = (ini + fin) / 2;
        tSol sol1, sol2;
        sol1 = resolver(v, ini, m);
        sol2 = resolver(v, m, fin);
        sol.suma = sol1.suma + sol2.suma;
        sol.sol = (sol1.sol && sol2.sol && sol1.suma < sol2.suma);
        return sol;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int x, y;
    std::cin >> x >> y;
    // leer los datos de la entrada
    
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <std::vector<int>> v(x, std::vector <int> (y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cin >> v[i][j];
        }
    }
    int i = 0;
    tSol sol;
    sol.sol = true;
    while (sol.sol && i < x) {
        sol = resolver(v[i], 0, y);
        i++;
    }
    if (sol.sol) std::cout << "SI\n";
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
