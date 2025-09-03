
// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

/* Todas las instrucciones cuestan lo mismo y una instrucción crítica es la comparación i <= pos, que se ejecuta N = v.size() veces, por lo que el algoritmo es de coste lineal.
* 
* Especificación:
* {N > 0}
* fun resolver (v[0..N) de ent) dev divisible: bool
* {bool = (paraTodo i, j: 0 <= i <= pos < j < N: v[i] < v[j])}
* 
* Invariante: i <= N
* Condición del bucle: i != N
* Función de cota: N - i
*/
bool resolver(std::vector <int> v, int pos) {
    bool divisible = true;
    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (i <= pos) {
            if(v[i] > max) max = v[i];
        }
        else if (v[i] <= max) divisible = false;
    }
    return divisible;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, pos;
    std::cin >> num >> pos;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) {
        std::cin >> v[i];
    }
    // leer los datos de la entrada

    bool sol = resolver(v, pos);
    if (sol) std::cout << "SI\n";
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
