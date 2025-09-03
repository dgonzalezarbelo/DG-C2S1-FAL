
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

//{v.size() > 0 && longitud % 2 == 0}
//fun resolver(v[0..v.size()) de ent, longitud: ent) dev cant: ent
//{cant = #i: longitud <= i < v.size(): (#j: i - longitud <= j < i - longitud / 2: v[j] > 0) >= (#j: i - longitud / 2 <= j < i: v[j] > 0)}

//Invariante: {cant = #i: longitud <= i < n: (#j: i - longitud <= j < i - longitud / 2: v[j] > 0) >= (#j: i - longitud / 2 <= j < i: v[j] > 0)
//              && n <= v.size() && posIzquierda = (#j: n - longitud <= j < n - longitud / 2: v[j] > 0) && posDerecha = (#j: n - longitud / 2 <= j < n: v[j] > 0)}

int resolver(std::vector <int> const& v, int longitud) {
    int cantidad = 0;
    int posIzquierda = 0, posDerecha = 0;
    for (int i = 0; i < longitud; i++) {
        if (i < longitud / 2) {
            if (v[i] > 0) posIzquierda++;
        }
        else {
            if (v[i] > 0) posDerecha++;
        }
    }
    if (posIzquierda >= posDerecha) cantidad++;
    for (int i = longitud; i < v.size(); i++) {
        if (v[i] > 0) posDerecha++;
        if (v[i - longitud] > 0) posIzquierda--;
        if (v[i - (longitud / 2)] > 0) {
            posDerecha--;
            posIzquierda++;
        }
        if (posIzquierda >= posDerecha) cantidad++;
    }
    return cantidad;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num, longitud;
    std::cin >> num >> longitud;
    if (num == 0)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    int sol = resolver(v, longitud);
    printf("%d\n", sol);
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
