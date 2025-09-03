// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
/* Cada instrucción del bucle se ejecuta como máximo una vez por iteración. Por tanto, siendo N = v.size(), el coste del algoritmo es O(N), es decir, lineal.
*
* Especificación:
* {N > 0 && altura > 0 && (existe i: 0 <= i < N: v[i] > altura)}
* fun resolver (v[0..N) de ent, altura: ent) dev inicio, fin: ent
* {fin - inicio - 1= (max p, q: 0 <= p <= q < N && A(v, p, q, altura): q - p - 1) && 0 <= inicio <= fin <= N && A(v, inicio, fin, altura)}
* donde A(v, p, q, altura) = (paraTodo j: p <= j < q: v[j] > altura)
* 
* Derivación:
*
* Invariante = I: n <= N && (fin - inicio - 1 = (max p, q: 0 <= p <= q <= n && A(v, p, q, altura): q - p - 1)) && A(v, inicio, fin, altura) && A(v, pos, n, altura)
* Condición del bucle = b: n != N
* 
* Inicialización = A: <n, inicio, fin, pos> = <0, 0, 0, 0> 
* Se ve que A => I
* 
* * Función de cota: N - n
*
* Avanzar: n := n + 1
* max p, q: 0 <= p <= q <= n + 1 && A(v, p, q, altura): q - p - 1)
*   = (max p, q: 0 <= p <= q <= n && A(v, p, q, altura): q - p) max (max p: 0 <= p <= n + 1 && A(v, p, n + 1, altura): n + 1- p - 1)
*   = (fin - inicio - 1) max (max p: 0 <= p <= n + 1 && A(v, p, n + 1, altura): n + 1 - p - 1)
*   = (fin - inicio - 1) max (n + 1 - (min p: 0 <= p <= n + 1 && A(v, p, n + 1, altura): p + 1)
* 
* Restablecer: si (v[i] <= altura) entonces 
                    pos := n + 1
               fsi
*              si (fin - inicio < n + 1 - pos) entonces
*                   inicio := pos
*                   fin := n + 1
*              fsi
* 
*/

void resolver(std::vector <int> v, int altura) {
    int inicio = 0, fin = 0, pos = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= altura) pos = i + 1;
        if ((i + 1 - pos) > (fin - inicio)) {
            inicio = pos;
            fin = i + 1;
        }
    }
    std::cout << inicio << ' ' << fin - 1 << '\n';
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, altura;
    std::cin >> num >> altura;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    // leer los datos de la entrada

    resolver(v, altura);

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