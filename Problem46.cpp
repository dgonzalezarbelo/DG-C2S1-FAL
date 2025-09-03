
// Nombre y Apellidos: Daniel Gonzalez Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

struct tSol {
    bool jugador;
    int jugados;
    int ronda;
};

//T(N) = 2T(N/4) + c = 4T(N/4) + 2c = ... = 2^k*T(N/2^k) + kc = ... = 2^log(n)*T(n/2^log(n)) + log(n)c = nT(1) + log(n)c pertenece a O(N)

tSol resolver(std::vector <std::string> const& v, int ini, int fin, int ronda) {
    if (ini == fin - 2) {
        if (v[ini] == "NP" && v[ini + 1] == "NP") return { false, 0, 1 };
        else if (v[ini] == "NP" || v[ini + 1] == "NP") return { true, 0, 1 };
        else return { true, 1, 1 };
    }
    else {
        tSol sol1, sol2;
        int m = (ini + fin) / 2;
        sol1 = resolver(v, ini, m, ronda);
        sol2 = resolver(v, m, fin, ronda);
        if (sol1.ronda >= ronda) return{ true, sol1.jugados + sol2.jugados, sol1.ronda + 1 };
        else {
            if (!sol1.jugador && !sol2.jugador) return { false, 0, sol1.ronda + 1 };
            else if (sol1.jugador && sol2.jugador) return { true, sol1.jugados + sol2.jugados + 1, sol1.ronda + 1 };
            else return { true, sol1.jugados + sol2.jugados, sol1.ronda + 1 };
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num, ronda; 
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;
    std::cin >> ronda;
    std::vector <std::string> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    tSol sol = resolver(v, 0, num, ronda);
    printf("%d\n", sol.jugados);
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
