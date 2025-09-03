
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// En cada llamada recursiva de aplica el metodo de divide y venceras, haciendo dos llamadas recursivas partiendo el vector por la mitad
//T(n) = 2T(n/2) + c = 4T(n/4) + 2c = ... = 2^k*T(n/2^k) + kc = ... = n*T(1) + log(n)*c pertenece a O(n)

struct tSol {
    bool sol;
    int min;
    int max;
};
tSol resolver(std::vector <int> const& v, int ini, int fin) {
    tSol sol;
    if (ini >= fin - 1) {
        sol.sol = true;
        sol.min = v[ini];
        sol.max = v[ini];
        return sol;
    }
    else {
        int m = (ini + fin) / 2;
        tSol sol1, sol2;
        sol1 = resolver(v, ini, m);
        sol2 = resolver(v, m, fin);
        if (sol1.min < sol2.min) sol.min = sol1.min;
        else sol.min = sol2.min;
        if (sol1.max > sol2.max) sol.max = sol1.max;
        else sol.max = sol2.max;
        sol.sol = (sol2.max >= sol1.max && sol1.min <= sol2.min && sol1.sol && sol2.sol);
        return sol;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num;
    std::cin >> num;
    if (num == 0)
        return false;
    std::vector <int> v;
    while (num != 0) {
        v.push_back(num);
        std::cin >> num;
    }
    tSol sol = resolver(v, 0, v.size());
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
