
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

//Hay que diferenciar el caso peor y el caso mejor
//En el caso peor, en cada llamada recursiva el maximo de esa parte del vector quedaria en uno de los extremos.
//En tal caso su coste viene dado por T(n) = T(n-1) + n, n > 1, T(1) = c
//Al T(n-1) se le suma n por la busqueda del elemento mayor del segmento. En este caso el orden es cuadratico.
//
//En el caso mejor el elemento maximo dividiria el segmento por la mitad.
//En tal caso su coste viene dado por T(n) = T(n/2) + n, n > 1, T(1) = c
//En este caso el orden es lineal

struct tSol {
    int min;
    int max;
    bool posible;
};

tSol resolver(std::vector <int> const& v, int ini, int fin) {
    if (ini + 1 == fin) {
        return { v[ini], v[ini], false };
    }
    else {
        int m = ini, max = v[ini];
        for (int i = ini + 1; i < fin; i++) {
            if (v[i] > max) {
                max = v[i];
                m = i;
            }
        }
        if (m == ini) {
            tSol sol = resolver(v, ini + 1, fin);
            return { sol.min, max, sol.posible };
        }
        else if (m == fin - 1) {
            tSol sol = resolver(v, ini, fin - 1);
            return { sol.min, max, sol.posible };
        }
        else {
            tSol sol1, sol2;
            sol1 = resolver(v, ini, m);
            sol2 = resolver(v, m + 1, fin);
            int min;
            (sol1.min < sol2.min) ? min = sol1.min : min = sol2.min;
            return{ min, max, sol1.min < sol2.max || sol1.posible || sol2.posible };
        }
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
    tSol sol = resolver(v, 0, num);
    (sol.posible) ? printf("ELEGIR OTRA\n") : printf("SIEMPRE PREMIO\n");
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
