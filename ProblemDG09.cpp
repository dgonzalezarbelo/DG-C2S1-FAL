
// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

/*Todas las instrucciones tienen el mismo coste y se ejecutan como máximo una vez por iteración del bucle, por lo que el algoritmo es de coste lineal.
* 
* Especificación:
* {N >= 0}
* fun resolver (v[0..N) de ent) dev apta: bool
* {apta = (paraTodo i, j: 0 <= i < j < N && creciente(v, i, j): v[j] - v[i] <= D)}
* donde creciente(v, i, j) = paraTodo k, t: i <= k < t <= j: v[k] < v[j]
* 
* Invariante: n <= N - 1 && apta = (paraTodo i, j: 0 <= i <= j < n && creciente(v, i, j): v[j] - v[i] <= D) && desnivel = (max i, j: 0 <= i <= n - 1 && creciente(v, i, n): v[n - 1] - v[i])
* Condición del bucle: n != N - 1
* Función de cota: N - n - 1
* 
* var n, desnivel: ent; apta: bool
* Inicialización: <n, desnivel, apta> = <0, 0, cierto>
* 
* Avanzar: n := n + 1
* apta = (paraTodo i, j: 0 <= i < j < n + 1 && creciente(v, i, j): v[j] - v[i] <= D)
*      = (paraTodo i, j: 0 <= i < j < n && creciente(v, i, j): v[j] - v[i] <= D) && (paraTodo i: 0 <= i < n + 1 && creciente(v, i, n + 1): v[j] - v[i] <= D)
*      = apta && (paraTodo i: 0 <= i < n + 1 && creciente(v, i, n + 1): v[j] - v[i] <= D)
* 
* Restablecer:
* si (v[n + 1] > v[n]) entonces desnivel := desnivel + v[n + 1]; fsi
* si no desnivel := 0; fsi
* 
* si (desnivel > D) entonces apta := falso; fsi
* n := n + 1;
*/
bool resolver(std::vector <int> v, int D) {
    bool apta = true;
    int desnivel = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i + 1] > v[i]) desnivel += v[i + 1] - v[i];
        else desnivel = 0;
        if (desnivel > D) apta = false;
    }
    return apta;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int D, num;
    // leer los datos de la entrada
    std::cin >> D;
    if (!std::cin)  // fin de la entrada
        return false;
    std::cin >> num;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];

    bool sol = resolver(v, D);

    // escribir sol
    if (sol) std::cout << "APTA\n";
    else std::cout << "NO APTA\n";

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
