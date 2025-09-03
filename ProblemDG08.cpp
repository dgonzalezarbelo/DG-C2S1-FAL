
// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
/*El bucle se ejecuta N = v.size() veces y cada instrucción elemental de dentro como máximo una vez por iteración, por lo que el algoritmo es de coste lineal.
* 
* Especificación:
* {N > 0 y 0 < vagones <= N}
* fun resolver (v[0..N) de ent) dev pos, max: ent
* {pos = (max i: 0 <= i < N - vagones + 1: sumaVagones(v, i, vagones)) && sumaVagones(v, pos, vagones) == max}
* donde sumaVagones(v, i, vagones) = (sumatorio j: i <= j < i + vagones: v[j])
* 
* Verificación:
* 
* I: pos = (max i: 0 <= i < n - vagones + 1: sumaVagones(v, i, vagones)) && sumaVagones(v, pos, vagones) == max
* var n, suma: ent
* <n, pos, suma> = <vagones, 0, sumatorio j: 0 <= j < vagones: v[j]>
* mientras n != N hacer
*   suma := suma + v[n] - suma v[n - vagones];
*   si (suma >= max) hacer
*       pos := n - vagones + 1;
*       max := suma;
*   fsi
*   n := n + 1;
* fmientras
*   
*/
void resolver(std::vector <int> v, int vagones) {
    int max = 0, pos = 0, suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma += v[i];
        if (i >= vagones) {
            suma -= v[i - vagones];
            if (suma >= max) {
                pos = i - vagones + 1;
                max = suma;
            }
        } 
        else max += v[i];

        
    }
    std::cout << pos << ' ' << max << '\n';
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, vagones;
    std::cin >> num >> vagones;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) {
        std::cin >> v[i];
    } 
    // leer los datos de la entrada

    resolver(v, vagones);

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
