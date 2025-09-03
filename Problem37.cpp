
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int buscarIz(std::vector <int> const& v, int ini, int fin, int altura) {
    if (ini >= fin - 1) return ini;
    else {
        int m = (ini + fin - 1) / 2;
        if (altura <= v[m]) return buscarIz(v, ini, m + 1, altura);
        else return buscarIz(v, m + 1, fin, altura);
    }
}

int buscarD(std::vector <int> const& v, int ini, int fin, int altura) {
    if (ini >= fin - 1) return ini;
    else {
        int m = (ini + fin) / 2;
        if (altura < v[m]) return buscarD(v, ini, m, altura);
        else return buscarD(v, m, fin, altura);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num, altura;
    std::cin >> num >> altura;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];

    int izq = buscarIz(v, 0, num, altura);
    int d = buscarD(v, 0, num, altura);
    if (izq < num && v[izq] == altura) {
        if (izq == d) std::cout << izq << '\n';
        else std::cout << izq << ' ' << d << '\n';
    }
    else std::cout << "NO EXISTE\n";

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
