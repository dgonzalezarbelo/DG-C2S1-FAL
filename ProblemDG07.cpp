
// Nombre y Apellidos: Daniel Gonz�lez Arbelo

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

/* El coste es lineal, pues cada instrucci�n tiene el mismo coste y se ejecuta, como m�ximo, una vez en cada iteraci�n del bucle.
* 
* Especificaci�n:
* {N > 0}
* fun resolver (v[0..N) de ent) dev suma, valores, atipico, veces: ent
* {atipico = (min i: o <= i < N: v[i]) && suma = (sumatorio i: 0 <= i < N && v[i] != atipico: v[i]) && valores = (#i: 0 <= i < N: v[i] != atipico) && veces = (#i: 0 <= i < N: v[i] == atipico)}
* 
* var suma, valores, atipico, veces: ent
* 
* I: atipico = (min i: o <= i < n: v[i]) && suma = (sumatorio i: 0 <= i < n && v[i] != atipico: v[i]) 
                && valores = (#i: 0 <= i < n: v[i] != atipico) && veces = (#i: 0 <= i < n: v[i] == atipico)
* b: n != N
* C: N - n
* 
* Inicializaci�n = A: <n, atipico, veces, suma, valores> = <1, v[0], 1, 0, 0>
* Claramente A => I
* 
* Avanzar: n := n + 1
*   (min i: 0 <= i < n + 1: v[i]) = (min i: 0 <= i < n: v[i]) min v[n] = atipico min v[n]
* 
* Restablecer:
*   si (v[n] < atipico) entonces
*       suma := suma + atipico * veces; //Se suma el anterior valor m�nimo tantas veces como ha aparecido antes de encontrar el nuevo m�nimo
*       valores := valores + veces; //Se a�ade al n�mero de valores de la suma el n�mero de apariciones del antiguo m�nimo
*       atipico := v[n];    //El nuevo valor m�nimo
*       veces := 1; //Primera vez que aparece este nuevo valor m�nimo
*   fsi
*   else si (v[n] == atipico) entonces
*       veces := veces + 1; //Se cuenta una nueva aparici�n del valor m�nimo
*   fsi
*   else si (v[n] > atipico) encontes
*       suma := suma + v[n]; //Se incorpora a la suma el nuevo valor, puesto que es mayor que el m�nimo
*       valores := valores + 1; //Se ha sumado un nuevo t�rmino
*   fsi
* 
* Se han considerado todos los casos, por lo que vemos que R => I
*/
void resolver(std::vector <long long int> v) {
    long long int min = v[0], veces = 1, suma = 0, valores = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < min) {
            suma += veces * min;
            valores += veces;
            min = v[i];
            veces = 1;
        }
        else if (v[i] == min) {
            veces++;
        }
        else {
            suma += v[i];
            valores++;
        }
    }
    std::cout << suma << ' ' << valores << '\n';
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {
    int num;
    std::cin >> num;
    std::vector <long long int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    // leer los datos de la entrada

    resolver(v);

    // escribir soluci�n
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
