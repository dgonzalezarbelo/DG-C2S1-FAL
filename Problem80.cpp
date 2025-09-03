
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// ascenso(v, p, q) = (paraTodo i: p <= i < q: v[i] <= v[i + 1])
// tramo(v, p, q) = (q - p >= 1 && paraTodo i: p <= i < q: v[i] < v[i + 1] && (paraTodo i: 0 <= i < p: (existe k: i <= k < p: v[k] >= v[k + 1]))
//      && (paraTodo j: q < j < v.size(): (existe k: q < k < j: v[k] > v[k + 1])))

//{v.size() > 0 && paraTodo i: 0 <= i < v.size(): v[i] >= 0}
//fun resolver(v[0..v.size()) de ent) dev long, ini, fin, tramos: int
//{long = (max p, q: 0 <= p < q < v.size() && ascenso(v, p, q): q - p + 1) && ascenso(v, ini, fin) && long = fin - ini + 1 && tramos = (# i, j: ini <= i < j <= fin: tramo(v, i, j))}



void resolver(std::vector <int> const& v) {
    int tramos = 0, maxTramos = 0, longActual = 1, maxLong = 1;
    bool esTramo = false;
    int ini = 0, mejorIni = 0, mejorFin = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] >= v[i - 1]) {
            longActual++;
            if (v[i] > v[i - 1]) {
                if (!esTramo) {
                    tramos++;
                }
                esTramo = true;
            }
            else {
                esTramo = false;
            }
        }
        else {
            longActual = 1;
            ini = i;
            esTramo = false;
            tramos = 0;
        }
        if (longActual > maxLong) {
            maxLong = longActual;
            mejorIni = ini;
            mejorFin = i;
            maxTramos = tramos;
        }
    }
    printf("%d %d %d %d\n", maxLong, mejorIni, mejorFin, maxTramos);
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
