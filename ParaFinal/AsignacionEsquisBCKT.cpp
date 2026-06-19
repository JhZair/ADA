#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void asignarEsquisBacktracking(int alumno, vector<int>& alturas, vector<int>& longitudes, vector<bool>& esqui_usado, int coste_actual, int& mejor_coste, vector<int>& asignacion_actual, vector<int>& mejor_asignacion) {
	if (coste_actual >= mejor_coste) {
		return;
	}
	
	if (alumno == alturas.size()) {
		mejor_coste = coste_actual;
		mejor_asignacion = asignacion_actual;
		return;
	}
	
	for (size_t i = 0; i < longitudes.size(); i++) {
		if (!esqui_usado[i]) {
			esqui_usado[i] = true;
			asignacion_actual[alumno] = longitudes[i];
			
			int nuevo_coste = coste_actual + abs(alturas[alumno] - longitudes[i]);
			
			asignarEsquisBacktracking(alumno + 1, alturas, longitudes, esqui_usado, nuevo_coste, mejor_coste, asignacion_actual, mejor_asignacion);
			
			esqui_usado[i] = false;
		}
	}
}

int main() {
	vector<int> alturas = {178, 168, 190, 170};
	vector<int> longitudes = {183, 188, 168, 175};
	int n = alturas.size();
	
	vector<bool> esqui_usado(n, false);
	vector<int> asignacion_actual(n, 0);
	vector<int> mejor_asignacion(n, 0);
	int mejor_coste = 1e9;
	
	asignarEsquisBacktracking(0, alturas, longitudes, esqui_usado, 0, mejor_coste, asignacion_actual, mejor_asignacion);
	
	cout << mejor_coste << "\n";
	for(int i = 0; i < n; ++i) {
		cout << alturas[i] << " " << mejor_asignacion[i] << "\n";
	}
	
	return 0;
}
