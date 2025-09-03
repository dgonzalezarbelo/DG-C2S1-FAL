
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// Se aplica el metodo de divide y venceras, obteniendo un coste logaritmico
int resolver(std::vector <int> const& v, int ini, int fin) {
    if (ini >= fin - 1) return ini;
    else {
        int m = (ini + fin) / 2;
        if (v[m] < v[ini]) return resolver(v, m, fin);
        else return resolver(v, ini, m);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    // leer los datos de la entrada
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    int sol = resolver(v, 0, num);

    // escribir sol
    std::cout << v[sol] << '\n';
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
