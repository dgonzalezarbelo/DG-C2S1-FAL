
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

// resolverNoFinal(num1, num2) = num2, si num1 = 0;
// resolverNoFinal(num1, num2) = num1, si num2 = 0;
// resolverNoFinal(num1, num2) = resolverNoFinal(num1 / 10, num2 / 10) + 10 * ((num1 / 10 + num2 / 10) % 10), si num1 > 0 y num2 > 0;
int resolverNoFinal(int num1, int num2) {
    if (num1 == 0) return num2;
    else if (num2 == 0) return num1;
    else return (resolverNoFinal(num1 / 10, num2 / 10) * 10 + ((num1 % 10) + (num2 % 10)) % 10);
}

//resolverFinal(num1, num2, t, p) = t, si num1 = 0 y num2 = 0;
//resolverFinal(num1, num2, t, p) = resolverFinal(num1 / 10, num2 / 10, t + (num1 % 10 + num2 % 10) % 10) * p, p * 10)
int resolverFinal(int num1, int num2, int t, int p) {
    if (num1 == 0 && num2 == 0) return t;
    else return resolverFinal(num1 / 10, num2 / 10, t + (((num1 % 10) + (num2 % 10)) % 10) * p, p * 10);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num1, num2;
    std::cin >> num1 >> num2;
    // leer los datos de la entrada

    int solNoFinal = resolverNoFinal(num1, num2);
    int solFinal = resolverFinal(num1, num2, 0, 1);
    
    std::cout << solNoFinal << ' ' << solFinal << '\n';

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
