
// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

/*En todo caso el bucle se ejecuta N = v.size() veces, siendo la instrucción crítica picos++. Por tanto, el algoritmo pertenece al orden de complejidad exacto O(N).
* 
* Especificación:
* {N > 0}
* fun resolver (v[0..N) de ent) dev picos, valles: ent
* {picos = (#i; 0 < i < N - 1 && pico(v, i); i) && valles = (#i; 0 < i < N - 1 && valle(v, i); i)}
* donde pico(v, i) = (v[i] > v[i - 1] && v[i] > v[i + 1]) y valle(v, i) = (v[i] < v[i - 1] && v[i] < v[i + 1])
* 
* Derivación:
* I = picos = (#i; 0 < i < n - 1 && pico(v, i); i) && valles = (#i; 0 < i < n - 1 && valle(v, i); i)
* C = N - n
* {N > 0}
* fun resolver (v[0..N) de ent) dev picos, valles: ent
* var n: ent
*   <n, picos, valles> = <1, 0, 0>
*   mientras n != N hacer
*     n := n + 1
*     si (pico(v, i)) entonces
          picos := picos + 1
      fsi
      si (valle(v, i)) entonces
          valles := valles + 1
      fsi
     fmientras
* ffun
* 
*/
void resolver(std::vector <int> v) {
    int picos = 0, valles = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) picos++;
        else if (v[i] < v[i - 1] && v[i] < v[i + 1]) valles++;
    }
    std::cout << picos << ' ' << valles << '\n';
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num;
    std::cin >> num;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    // leer los datos de la entrada
    resolver(v);

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
