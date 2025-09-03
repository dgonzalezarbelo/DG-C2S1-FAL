// Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

/* función que resuelve el problema

 Coste:

 La instruccion critica es i++. En el caso mejor, el primer elemento es igual que el segundo, en cuyo caso no se ejecuta ninguna vez y
 el orden es O(1).
 En el caso peor, la entrada esta ordenada de menor a mayor o de mayor a menor y se ejecuta el bucle hasta que i == num - 1, por lo que el algoritmo pertenece al
 orden de complejidad O(n)

 Especificacion:

 {n>=2}
 fun resolver(n:ent, v[0..n) de ent) dev dalton:bool
 {dalton == cierto <=> creciente(v[0..n)) || decreciente(v[0..n))}
 donde creciente(v[0..n)) == (para todo i: 0 <= i < n - 1: v[i] < v[i + 1])
 y decreciente(v[0..n)) == (para todo i: 0 <= i < n - 1: v[i] > v[i + 1])

 Verificación:

 Invariante: i <= n - 1
 Función de cota: n - 1 - i
*/
bool resolver(int n, std::vector <long long int>& v) {
    int i = 1;
    bool dalton = true;
    if (v[0] < v[1]) {  //Si el primer elemento es menor que el segundo vemos que el vector sea creciente
        while (i < n - 1) {
            if (v[i] >= v[i + 1] && dalton) dalton = false; //Si un elemento es mayor o igual que el siguiente no es dalton
            i++;
        }
    }
    else if (v[0] > v[1]) { //Si el primer elemento es mayor que el segundo vemos que el vector sea decreciente
        while (i < n - 1) {
            if (v[i] <= v[i + 1] && dalton) dalton = false; //Si un elemento es menor o igual que el siguiente no es dalton
            i++;
        }
    }
    else dalton = false;    //Si el primer y segundo elementos son iguales dalton es falso
    return dalton;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == 0)
        return false;
    std::vector <long long int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    bool sol = resolver(n, v);

    // escribir sol
    if (sol) std::cout << "DALTON\n";
    else std::cout << "DESCONOCIDOS\n";
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