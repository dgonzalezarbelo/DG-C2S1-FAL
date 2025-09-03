
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct comparaCanciones {
    bool operator()(std::pair<int, int> c1, std::pair <int, int> c2) {
        return (double(double(c1.second) / double(c1.first)) > double(double(c2.second) / double(c2.first)));
    }
};

bool estimacion (std::vector <std::pair<int, int>> const& canciones, int k,
        int t1, int t2, int& ida, int& vuelta, int satIda, int satVuelta, int& mejorIda, int& mejorVuelta) {
    int index = k + 1;
    double nuevoTrayecto = ida + vuelta, nuevaSat = satIda + satVuelta, ratio;
    while (nuevoTrayecto < t1 + t2 && index < canciones.size()) {
        if (nuevoTrayecto + canciones[index].first < t1 + t2) {
            nuevoTrayecto += canciones[index].first;
            nuevaSat += canciones[index].second;
            index++;
        }
        else {
            ratio = (double(t1 + t2) - double(nuevoTrayecto)) / double(canciones[index].first);
            nuevoTrayecto += canciones[index].first * ratio;
            nuevaSat += canciones[index].second * ratio;
            index++;
        }
    }
    
    /*while (nuevaIda < t1 && index < canciones.size()) {
        if (nuevaIda + canciones[index].first < t1) {
            nuevaIda += canciones[index].first;
            nuevaSatIda += canciones[index].second;
            index++;
        }
        else {
            ratio = (double(t1) - double(nuevaIda)) / double(canciones[index].first);
            nuevaIda += canciones[index].first * ratio;
            nuevaSatIda += canciones[index].second * ratio;
            index++;
        }
    }
    while (nuevaVuelta < t2 && index < canciones.size()) {
        if (nuevaVuelta + canciones[index].first < t2) {
            nuevaVuelta += canciones[index].first;
            nuevaSatVuelta += canciones[index].second;
            index++;
        }
        else {
            ratio = (double(t2) - double(nuevaVuelta)) / double(canciones[index].first);
            nuevaVuelta += canciones[index].first * ratio;
            nuevaSatVuelta += canciones[index].second * ratio;
            index++;
        }
    }*/
    //return (nuevaSatIda + nuevaSatVuelta > mejorIda + mejorVuelta);
    return (nuevaSat > mejorIda + mejorVuelta);
}

void resolver(std::vector <std::pair<int, int>> const& canciones, int k,
        int t1, int t2, int & ida, int & vuelta, int & satIda, int & satVuelta, int & mejorIda, int & mejorVuelta) {
    if (k == canciones.size() - 1) {
        ida += canciones[k].first;
        satIda += canciones[k].second;
        if (ida == t1 && vuelta == t2) {
            if (satIda + satVuelta > mejorIda + mejorVuelta) {
                mejorIda = satIda;
                mejorVuelta = satVuelta;
            }
        }
        ida -= canciones[k].first;
        satIda -= canciones[k].second;

        vuelta += canciones[k].first;
        satVuelta += canciones[k].second;
        if (ida == t1 && vuelta == t2) {
            if (satIda + satVuelta > mejorIda + mejorVuelta) {
                mejorIda = satIda;
                mejorVuelta = satVuelta;
            }
        }
        vuelta -= canciones[k].first;
        satVuelta -= canciones[k].second;

        if (ida == t1 && vuelta == t2) {
            if (satIda + satVuelta > mejorIda + mejorVuelta) {
                mejorIda = satIda;
                mejorVuelta = satVuelta;
            }
        }
    }
    else {
        //Ponemos la cancion para la ida
        ida += canciones[k].first;
        satIda += canciones[k].second;
        if (ida <= t1) {
            if (estimacion(canciones, k, t1, t2, ida, vuelta, satIda, satVuelta, mejorIda, mejorVuelta)) {
                resolver(canciones, k + 1, t1, t2, ida, vuelta, satIda, satVuelta, mejorIda, mejorVuelta);
            }
        }
        ida -= canciones[k].first;
        satIda -= canciones[k].second;

        //Ponemos la cancion para la vuelta
        vuelta += canciones[k].first;
        satVuelta += canciones[k].second;
        if (vuelta <= t2) {
            if (estimacion(canciones, k, t1, t2, ida, vuelta, satIda, satVuelta, mejorIda, mejorVuelta)) {
                resolver(canciones, k + 1, t1, t2, ida, vuelta, satIda, satVuelta, mejorIda, mejorVuelta);
            }
        }
        vuelta -= canciones[k].first;
        satVuelta -= canciones[k].second;

        //No ponemos la cancion
        resolver(canciones, k + 1, t1, t2, ida, vuelta, satIda, satVuelta, mejorIda, mejorVuelta);
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num, t1, t2;
    // leer los datos de la entrada
    std::cin >> num >> t1 >> t2;
    if (num == 0 && t1 == 0 && t2 == 0)
        return false;

    std::vector <std::pair<int, int>> canciones(num);
    for (int i = 0; i < num; i++) {
        std::cin >> canciones[i].first; //Duracion
        std::cin >> canciones[i].second; //Satisfaccion
    }
    std::sort(canciones.begin(), canciones.end(), comparaCanciones());
    int ida = 0, vuelta = 0, satIda = 0, satVuelta = 0, mejorIda = -1, mejorVuelta = -1;
    resolver(canciones, 0, t1, t2, ida, vuelta, satIda, satVuelta, mejorIda, mejorVuelta);

    // escribir sol
    if (mejorIda == -1) std::cout << "Imposible\n";
    else std::cout << mejorIda + mejorVuelta << '\n';

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
