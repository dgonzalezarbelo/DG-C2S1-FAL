
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(std::vector<std::vector<int>> const& mat, std::vector<int>& sol, int k, std::vector<int> const& acumulados, int& tiempo,
    std::vector<bool>& marcas, std::vector<int>& solMejor, int& tiempoMejor) {
    for (int i = 0; i < mat.size(); i++) {
        if (!marcas[i]) {
            marcas[i] = true;
            sol[k] = i;
            tiempo += mat[k][i];
            if (k < mat.size() - 1) {
                if (tiempo + acumulados[k + 1] < tiempoMejor) {
                    resolver(mat, sol, k + 1, acumulados, tiempo, marcas, solMejor, tiempoMejor);
                }
            }
            else {
                if (tiempo < tiempoMejor) {
                    solMejor = sol;
                    tiempoMejor = tiempo;
                }
            }
            marcas[i] = false;
            tiempo -= mat[k][i];
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (n == 0)
        return false;
    std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
    std::vector<int> acumulados(n, 10001);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mat[i][j];
            if (mat[i][j] < acumulados[i]) acumulados[i] = mat[i][j];
        }
    }
    for (int i = n - 2; i >= 0; i--) acumulados[i] += acumulados[i + 1];
    std::vector <int> sol(n);
    std::vector <int> solMejor(n);
    int tiempo = 0, tiempoMejor = 0;
    for (int i = 0; i < n; i++) {
        solMejor[i] = i;
        tiempoMejor += mat[i][i];
    }
    std::vector <bool> marcas(n, false);
    resolver(mat, sol, 0, acumulados, tiempo, marcas, solMejor, tiempoMejor);

    // escribir sol
    printf("%d\n", tiempoMejor);
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
