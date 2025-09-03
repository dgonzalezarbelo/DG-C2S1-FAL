
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// T(N) = 2*T(n/2) + 2n = 2(2T(n/4) + 2*n/2) + 2n = 4T(n/4) + 2*2n = ... = 2^k*T(n/2^k) + 2kn = ... = nT(1) + 2n*log(n) pertenece a O(nlog(n))

int resolver(std::vector <int> & v, int ini, int fin) {
    if (ini >= fin - 1) return 0;
    else {
        int m = (ini + fin) / 2;
        int inversiones = resolver(v, ini, m) + resolver(v, m, fin);
        int i = ini, j = m;
        while (i < m && j < fin) {
            if (v[i] > v[j]) {
                inversiones += m - i;
                j++;
            }
            else i++;
        }
        std::inplace_merge(v.begin() + ini, v.begin() + m, v.begin() + fin);
        return inversiones;
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
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    std::cout << resolver(v, 0, num) << '\n';

    // escribir sol

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

    while (resuelveCaso());

    // para dejar todo como estaba al principio
/*#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/
    return 0;
}
