
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
struct comparaObj {
    bool operator()(std::pair<int, int> obj1, std::pair<int, int> obj2) {
        return (double(double(obj1.second) / double(obj1.first)) > double(double(obj2.second) / double(obj2.first)));
    }
};

bool estimacion(std::vector <std::pair <int, int>> const& objetos, int k, double presupuesto, int coste, int superficie, int supMax) {
    double nuevoCoste = coste, nuevaSup = superficie, index = k;
    while (nuevoCoste < presupuesto && index < objetos.size()) {
        if (nuevoCoste + objetos[index].first < presupuesto) {
            nuevoCoste += objetos[index].first;
            nuevaSup += objetos[index].second;
            index++;
        }
        else {
            double ratio = (double(presupuesto) - nuevoCoste) / objetos[index].first;
            nuevoCoste += ratio * objetos[index].first + 1;
            nuevaSup += ratio * objetos[index].second;
            index++;
        }
    }
    return nuevaSup > supMax;
}

void resolver(std::vector <std::pair <int, int>> const& objetos, int k, double presupuesto, int& coste, int& superficie, std::vector<bool>& sol,
    int& supMax, std::vector <bool>& solMejor) {
    if (k < objetos.size() - 1) {
        sol[k] = true;
        coste += objetos[k].first;
        superficie += objetos[k].second;
        if (coste <= presupuesto) {
            if (estimacion(objetos, k, presupuesto, coste, superficie, supMax)) {
                resolver(objetos, k + 1, presupuesto, coste, superficie, sol, supMax, solMejor);
            }
        }
        sol[k] = false;
        coste -= objetos[k].first;
        superficie -= objetos[k].second;
        resolver(objetos, k + 1, presupuesto, coste, superficie, sol, supMax, solMejor);
    }
    else {
        sol[k] = true;
        coste += objetos[k].first;
        superficie += objetos[k].second;
        if (coste <= presupuesto) {
            if (superficie > supMax) {
                solMejor = sol;
                supMax = superficie;
            }
        }
        sol[k] = false;
        coste -= objetos[k].first;
        superficie -= objetos[k].second;
        if (coste <= presupuesto) {
            if (superficie > supMax) {
                solMejor = sol;
                supMax = superficie;
            }
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numObj;
    double presupuesto;
    std::cin >> numObj >> presupuesto;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <std::pair <int, int>> objetos(numObj);
    for (int i = 0; i < numObj; i++) {
        std::cin >> objetos[i].first >> objetos[i].second;
    }
    std::vector <bool> sol(numObj, false);
    std::vector <bool> solMejor(numObj, false);
    int coste = 0, supMax = 0, superficie = 0;
    std::sort(objetos.begin(), objetos.end(), comparaObj());
    resolver(objetos, 0, presupuesto, coste, superficie, sol, supMax, solMejor);

    // escribir sol
    /*for (int i = 0; i < numObj; i++) {
        if (solMejor[i]) std::cout << i << ' ';
    }
    printf("\n");*/
    printf("%d\n", supMax);
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
