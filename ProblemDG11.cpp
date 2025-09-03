
// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// En el caso peor, la instrucción crítica es actual++, que se ejecutaría una vez por iteración del bucle, es decir, N veces, por lo que el algoritmo pertenece al orden de complejidad O(N)

/*Especificación:
* 
* {N >= 1}
* fun resolver (v[0..N) de ent) dev long: nat
* {long = (max i, j: 0 <= i <= j < N && segmento(v, i, j): j - i)}
* 
* donde segmento(v, i, j) = (paraTodo k: i <= k <= j: v[k] = v[i])
* 
* I: n <= N && long = (max i, j: 0 <= i <= j < n && segmento(v, i, j): j - i) && actual = (max i: 0 <= i < n && segmento(v, i, n - 1): n - 1 - i)
* b: n!= N
* C: N - n
* 
* Inicialización: <n, long, actual> := <1, 0, 0>
* 
* Avanzar: n := n + 1
* (max i, j: 0 <= i <= j < n + 1 && segmento(v, i, j): j - i) = (max i, j: 0 <= i <= j < n && segmento(v, i, j): j - i) max (max i: 0 <= i < n + 1 && segmento(v, i, n): n - i)
* = long max (max i: 0 <= i < n + 1 && segmento(v, i, n): n - i)
* 
* Si v[n] = v[n - 1] entonces (max i: 0 <= i < n + 1 && segmento(v, i, n): n - i) = (max i: 0 <= i < n && segmento(v, i, n - 1): n - 1 - i) + 1 = actual + 1
* Si no entonces (max i: 0 <= i < n + 1 && segmento(v, i, n): n - i) = 0
* 
* fun resolver (v[0..N) de ent) dev long: nat
    * var n, long, actual: ent;
    * n := 1; long := 0; actual := 0;
    * mientras (n !=  N) hacer
    *   si (v[n] = v[n - 1]) entonces
    *       actual := actual + 1;
    *   fsi
    *   si no
    *       actual := 0;
    *   fsi
    *   si (actual >= long) entonces
    *       long := actual;
    *   fsi
    * fmientras
* ffun
*/
void resolver(std::vector <int> v) {
    int n = 1, longitud = 0, actual = 0;
    while (n != v.size()) {
        if (v[n] == v[n - 1]) actual++;
        else actual = 0;
        if (actual >= longitud) longitud = actual;
        n++;
    }
    if (longitud == 0) std::cout << "HOY NO COMEN\n";
    else std::cout << longitud << '\n';
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (num == -1)
        return false;
    std::vector <int> v;
    while (num != -1) {
        v.push_back(num);
        std::cin >> num;
    }
    resolver(v);

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
