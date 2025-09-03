
// Nombre y Apellidos: Daniel González Arbelo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
/* ultimo = i + 1 es una instrucción crítica, y se ejecuta como máximo una vez por vuelta del bucle, por lo que el algoritmo es de coste lineal.
* 
* Especificación:
* {N > 0}
* fun resvolver (v[0..N) de ent) dev maxima, veces, ultimo: ent;
* {maxima = (max i, j: 0 <= i < j <= N && victoria(v, i, j): j - i)
            && veces = (#i: 0 <= i <= N: victoria(v, i -  maxima, i))
            && ultimo = (max i: 0 <= i <= N: victoria(v, i - maxima, i))}
* donde victoria(v, i, j) = (paraTodo k: i <= k < j: v[k] > 0)
* 
* var maxima, veces, ultimo, racha, n: ent
* I: maxima = (max i, j: 0 <= i < j <= n && victoria(v, i, j): j - i)
            && veces = (#i: 0 <= i <= n: victoria(v, i -  maxima, i))
            && ultimo = (max i: 0 <= i <= n: victoria(v, i - maxima, i)) && n <= N
* b: n != N
* Creamos la condición R: racha = (max i: 0 <= i < n && victoria(v, i, n): n - i) y la añadimos al invariante.
* De esta forma el esquema queda de la forma {I && R && b} resolver {I && R}
* 
* Avanzar: n := n + 1
* max i, j: 0 <= i < j <= n + 1 && victoria(v, i, j): j - i
*   = (max i, j: 0 <= i < j <= n && victoria(v, i, j): j - i) max (max i: 0 <= i < n + 1 && victoria (v, i, n + 1): n + 1 - i)
*   = (maxima) max (max i: 0 <= i < n + 1 && victoria (v, i, n + 1): n + 1 - i)
*   = (maxima) max (n + 1 - (min i: 0 <= i < n + 1 && victoria(v, i, n + 1): i))
* 
* Restablecer:
* Primero restableceremos R:
* 
* si (v[n] > 0) entonces 
*   racha := racha + 1;
* fsi
* else si (v[n] <= 0) entonces
*   racha = 0;
* fsi
* 
* Con esto restablecemos R, puesto que si el último elemento (v[n]) es mayor que 0, se debe añadir a la racha actual, 
*   pues dado pos = (min i: 0 <= i < n && victoria(v, i, n): i) tenemos que se da victoria(v, i, n + 1), luego racha aumenta en 1, pues n + 1 - pos = (n - pos) + 1 = racha + 1
* En cambio, si el ultimo elemento no es mayor que cero, la racha se restablece, puesto que el unico elemento i que verifica victoria(v, i, n + 1) es i = n + 1, luego 
* racha = n + 1 - i = n + 1 - (n + 1) = 0.
* 
* Ahora restablecemos I:
* si (racha > maxima) entonces
*   maxima := racha;
*   veces = 1;
*   ultimo := n + 1;
* fsi
* else si (racha == maxima) entonces
*   veces := veces + 1;
*   ultimo := n + 1;
* fsi
* 
* Con esto restablecemos I, puesto que tenemos tres casos posibles: racha > maxima, racha == maxima o racha < maxima.
* Si racha es mayor que maxima significa que (maxima) max (n + 1 - (min i: 0 <= i < n + 1 && victoria(v, i, n + 1): i)) = (maxima) max (racha) = racha, luego maxima := racha
* Al ser racha el nuevo máximo, la unica combinacion (i, j) tal que victoria(v, i, j) && j - i == maxima es (i, j) = (n + 1 - maxima, n + 1), por lo que
* (#i: 0 <= i <= n + 1: victoria(v, n + 1 -  maxima, n + 1)) = 1, luego veces := 1
* Por esto mismo, (max i: 0 <= i <= n + 1: victoria(v, i - maxima, i)) = n + 1, luego ultimo := n + 1.
* 
* En cambio, si racha == maxima, (#i: 0 <= i <= n + 1: victoria(v, n + 1 -  maxima, n + 1)) = 1 + (#i: 0 <= i <= n: victoria(v, n + 1 -  maxima, n + 1)) = 1 + veces, luego veces := veces + 1
* Por ello, (max i: 0 <= i <= n + 1: victoria(v, i - maxima, i)) = n + 1, pues tenemos victoria(v, n + 1 - maxima, n + 1), luego ultima := n + 1
* 
* Finalmente, si racha < maxima, trivialmente ninguno de los valores anteriores se ve modificado
* 
* Por tanto, tenemos que {I && R && b} resolver {I && R}
*/

void resolver(std::vector <int> v) {
    int max = 0, veces = 0, ultimo = 0, racha = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) racha++;
        else racha = 0;
        if (racha > max) {
            max = racha;
            veces = 1;
            ultimo = i + 1;
        }
        else if (racha > 0 && racha == max) {
            ultimo = i + 1;
            veces++;
        }
    }
    std::cout << max << ' ' << veces << ' ' << v.size() - ultimo << '\n';
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    std::vector <int> v(num);
    for (int i = 0; i < num; i++) std::cin >> v[i];
    resolver(v);

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
