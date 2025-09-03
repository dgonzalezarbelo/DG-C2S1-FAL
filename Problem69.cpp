#include <iostream>
#include <vector>
#include <fstream>

void resolver(std::vector <std::vector <int>> const& mat, int k, std::vector <int> & sol, std::vector <int> & solMejor, int & coincidencias, int hada,
				int & sat, int & satMejor, std::vector <int> const& maximos, std::vector <bool> & marcas, int & posibilidades) {
	for (int i = 0; i < mat[0].size(); i++) {
		if (!marcas[i]) {
			marcas[i] = true;
			if (mat[k][i] >= 0) {	//La satisfaccion tiene que ser positiva
				if (k == i) coincidencias++;
				sol[k] = i;
				sat += mat[k][i];
				if (k < mat.size() - 1) {
					if (sat + maximos[k + 1] >= satMejor && coincidencias <= mat.size() / 3) {	//Estimamos si es posible alcanzar una mayor satisfaccion
						resolver(mat, k + 1, sol, solMejor, coincidencias, hada, sat, satMejor, maximos, marcas, posibilidades);
					}
				}
				else {
					if (coincidencias <= mat.size() / 3 && marcas[hada]) {	//El hada tiene que estar invitada
						if (sat > satMejor) {
							solMejor = sol;
							satMejor = sat;
							posibilidades = 1;
						}
						else if (sat == satMejor) {
							posibilidades++;
							
						}
					}
				}
				if (k == i) coincidencias--;
				sat -= mat[k][i];
			}
			marcas[i] = false;
		}
	}
}

bool resuelveCaso() {
	int invitados, puestos, hada;
	std::cin >> invitados;
	if (invitados == 0) return false;
	std::cin >> puestos >> hada;
	std::vector <std::vector <int>> mat(puestos, std::vector <int>(invitados));
	std::vector <int> maximos(puestos, -2147483648);	//El menor valor de un entero
	for (int i = 0; i < puestos; i++) {
		for (int j = 0; j < invitados; j++) {
			std::cin >> mat[i][j];
			if (mat[i][j] > maximos[i]) maximos[i] = mat[i][j];
		}
	}
	for (int i = puestos - 2; i >= 0; i--) {
		maximos[i] += maximos[i + 1];	//Llevamos los maximos acumulados
	}
	int coincidencias = 0; //Cuantos invitados i estan sentados en la posicion i
	int sat = 0, satMejor = -1;
	int posibilidades = 0;
	std::vector <int> sol(puestos);
	std::vector <int> solMejor(puestos);
	std::vector <bool> marcas(invitados, false);
	resolver(mat, 0, sol, solMejor, coincidencias, hada, sat, satMejor, maximos, marcas, posibilidades);
	if (satMejor == -1) std::cout << "No\n";
	else printf("%d %d\n", satMejor, posibilidades);
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}