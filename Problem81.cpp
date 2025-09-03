
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector <int> const& v, int integrantes, int dia) {
    if (v[dia] >= (int(v.size()) - dia) * integrantes) {
        if (dia == v.size() - 1) return dia + 1;
        else return resolver(v, integrantes, dia + 1);
    }
    else return dia;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int dias, integrantes;
    std::cin >> dias >> integrantes;
    std::vector <int> v(dias);
    for (int i = 0; i < dias; i++) std::cin >> v[i];
    int sol = resolver(v, integrantes, 0);
    if (sol == v.size()) std::cout << "SIN RACIONAMIENTO\n";
    else std::cout << sol << '\n';
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
