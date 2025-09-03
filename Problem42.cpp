
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// Se emplea el metodo de divide y venceras, con T(n) = T(n / 2) + c cuando n > 1, por lo que el coste del algoritmo es logaritmico
int resolver(std::vector <int> const& v, int ini, int fin, int elem) {
    if (ini >= fin - 1) return ini;
    else {
        int m = (ini + fin - 1) / 2;
        if (m + elem <= v[m]) return resolver(v, ini, m + 1, elem);
        else return resolver(v, m + 1, fin, elem);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, elem;
    // leer los datos de la entrada
    std::cin >> num >> elem;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    int sol = resolver(v, 0, num, elem);
    if (sol + elem == v[sol]) std::cout << v[sol] << '\n';
    else std::cout << "NO\n";
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
