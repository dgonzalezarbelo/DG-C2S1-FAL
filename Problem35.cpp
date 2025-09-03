
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolverNoFinal(int num, int & sumI, int sumD) {
    if (num < 10) {
        sumI += num;
        return (sumD % num == 0);
    } 
    else {
        if ((sumD % (num % 10) == 0) && resolverNoFinal(num / 10, sumI, sumD + num % 10)) {
            if ((sumI % (num % 10) == 0)) {
                sumI += num % 10;
                return true;
            }    
            else return false;
        }
        else return false;
        
    } 
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, sumI = 0;
    std::cin >> num;
    // leer los datos de la entrada

    bool sol = resolverNoFinal(num, sumI, 0);

    // escribir solución
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";
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
