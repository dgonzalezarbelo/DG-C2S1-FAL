
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector <int> v, int ini, int fin, int maxCamiones) {
    if (ini >= fin - 1) {
        int numCamiones = 1, peso = 0;
        for (int i = 0; i < v.size(); i++) {
            if (peso + v[i] <= ini) peso += v[i];
            else {
                numCamiones++;
                peso = v[i];
            }
        }
        if (numCamiones <= maxCamiones) return ini;
        else return ini + 1;
    }
    else {
        int m = (ini + fin - 1) / 2;
        int numCamiones = 1, peso = 0;
        for (int i = 0; i < v.size(); i++) {
            if (peso + v[i] <= m) peso += v[i];
            else {
                numCamiones++;
                peso = v[i];
            }
        }
        if (numCamiones <= maxCamiones) return resolver(v, ini, m + 1, maxCamiones);
        else return resolver(v, m + 1, fin, maxCamiones);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, maxCamiones;
    std::cin >> num >> maxCamiones;
    if (num == 0 && maxCamiones == 0)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    int suma= 0, max = 0;  //El peso minimo que debe soportar el camion es el mayor de los pesos, y el maximo es la suma de todos los pesos
    for (int i = 0; i < num; i++) {
        std::cin >> v[i];
        if (v[i] > max) max = v[i];
        suma += v[i];
    } 
    if (num == maxCamiones) std::cout << max << '\n';
    else std::cout << resolver(v, max, suma, maxCamiones) << '\n';

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
