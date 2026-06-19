#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mochilaBT(int indice, int pesoActual, int beneficioActual, int capacidad, vector<int>& pesos,vector<int>& beneficios, int& beneficioMaximo) {
	if (pesoActual > capacidad) return;
	
	if (beneficioActual > beneficioMaximo) {
		beneficioMaximo = beneficioActual;
	}
	if (indice == pesos.size()) return;
	
	mochilaBT(indice + 1, pesoActual + pesos[indice], beneficioActual + beneficios[indice], capacidad, pesos, beneficios, beneficioMaximo);
	mochilaBT(indice + 1, pesoActual, beneficioActual, capacidad, pesos, beneficios, beneficioMaximo);
}

int main(int argc, char *argv[]) {
	int capacidad = 61;
	vector<int> pesos = {1, 11, 21, 23, 33};
	vector<int> beneficios = {11, 21, 31, 33, 43};
	int beneficioMaximo = 0;
	mochilaBT(0, 0, 0, capacidad, pesos, beneficios, beneficioMaximo);
	cout << beneficioMaximo <<endl;
	return 0;
}
