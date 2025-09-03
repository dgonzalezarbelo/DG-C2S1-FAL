
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct tCanoa {
    std::vector <int> amigos;
    int ocupacion = 0;
    int peso;
};

void resolver(std::vector <int> const& amigos, int k, std::vector <tCanoa>& sol, 
    int& numCanoas, int& numMejor, std::vector <std::vector <int>> const& mat, int pesoMax, int& primeraVacia) {
    for (int i = 0; i <= std::min((int)sol.size() -1, primeraVacia); i++) {
        if (sol[i].ocupacion < 3) {
            if (sol[i].ocupacion == 0 || sol[i].ocupacion == 1 && mat[sol[i].amigos[0]][k] == 0 || mat[sol[i].amigos[0]][k] == 0 && mat[sol[i].amigos[1]][k] == 0) {
                if (sol[i].peso + amigos[k] <= pesoMax) {
                    sol[i].amigos[sol[i].ocupacion] = k;
                    sol[i].ocupacion++;
                    sol[i].peso += amigos[k];
                    if (sol[i].ocupacion == 1) {
                        primeraVacia++;   //Si estamos en la primera vacia y es la ultima seguimos diciendo que es la primera vacia (es la ultima que podemos usar)
                        numCanoas++;
                    }
                    if (k == amigos.size() - 1) {
                        if (numCanoas < numMejor) {
                            numMejor = numCanoas;
                        }
                    }
                    else {
                        if (numCanoas + (amigos.size() - k) / 3 - 1 < numMejor) {   //Si entre las que llevamos mas los amigos que faltan entre 3 (una canoa por cada 3) menos 1 (para asegurar) se pasa de las mejores paramos
                            resolver(amigos, k + 1, sol, numCanoas, numMejor, mat, pesoMax, primeraVacia);
                        }
                    }
                    if (sol[i].ocupacion == 1) {
                        primeraVacia--;
                        numCanoas--;
                    }
                    sol[i].ocupacion--;
                    sol[i].amigos[sol[i].ocupacion] = -1;
                    sol[i].peso -= amigos[k];
                }
            }
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int M, N, k;
    std::cin >> M >> N >> k;
    std::vector <int> amigos(M);
    std::vector <tCanoa> sol(N, {std::vector<int> (3, -1), 0, 0});
    std::vector <std::vector <int>> mat(M, std::vector <int>(M));
    for (int i = 0; i < M; i++) std::cin >> amigos[i];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> mat[i][j];
        }
    }
    int numCanoas = 0, numMejor = N + 1;
    std::vector <bool> llenas(N, false);
    int primeroVacio = 0;
    resolver(amigos, 0, sol, numCanoas, numMejor, mat, k, primeroVacio);
    if (numMejor == N + 1) std::cout << "IMPOSIBLE\n";
    else std::cout << numMejor << '\n';
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++) resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
