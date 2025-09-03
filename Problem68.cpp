
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool estimacion(std::vector <std::vector<int>> const& ciudades, int k, std::vector <int>& sol, std::vector <bool> const& marcas,
    int coste, int costeMejor, std::vector <int> const& minimos) {

    int last = sol[k], nuevoCoste = coste;
    for (int i = k; i < ciudades.size(); i++) {
        nuevoCoste += minimos[i];
    }
    return nuevoCoste < costeMejor;
}

void resolver(std::vector <std::vector<int>> const& ciudades, int k, std::vector <int> & sol, std::vector <int> & solMejor, std::vector <bool> & marcas,
            int & coste, int & costeMejor, std::vector <int> const& minimos) {
    
    for (int i = 1; i < ciudades.size(); i++) {
        if (!marcas[i]) {
            marcas[i] = true;
            sol[k] = i;
            coste += ciudades[sol[k - 1]][sol[k]];
            if (k == ciudades.size() - 1) {
                if (coste + ciudades[sol[k]][0] < costeMejor) {
                    solMejor = sol;
                    costeMejor = coste + ciudades[sol[k]][0];
                }
            }
            else {
                if (estimacion(ciudades, k, sol,  marcas, coste, costeMejor, minimos)) {
                    resolver(ciudades, k + 1, sol, solMejor, marcas, coste, costeMejor, minimos);
                }
            }
            marcas[i] = false;
            coste -= ciudades[sol[k - 1]][sol[k]];
        }
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
    std::vector <std::vector<int>> ciudades(num, std::vector<int>(num));
    std::vector <int> minimos(num, 0);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            std::cin >> ciudades[i][j];
            if (ciudades[i][j] < minimos[i]) minimos[i] = ciudades[i][j];
        }
    }
    std::vector <int> sol(num);
    std::vector <int> solMejor(num);
    int coste = 0, costeMejor = 0;
    for (int i = 0; i < num - 1; i++) {
        solMejor[i] = i + 1;
        costeMejor += ciudades[i][i + 1];
    }
    solMejor[num - 1] = 0;
    costeMejor += ciudades[num - 1][0];
    sol[0] = 0;
    std::vector <bool> marcas(num, false);
    if (num == 2) std::cout << ciudades[0][1] + ciudades[1][0] << '\n';
    else {
        resolver(ciudades, 1, sol, solMejor, marcas, coste, costeMejor, minimos);
        std::cout << costeMejor << '\n';
    }
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
