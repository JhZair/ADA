#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs_topologico(int u, const vector<vector<int>>& grafo, vector<int>& estado, vector<int>& orden) {
	estado[u] = 1; // 1 = En proceso
	
	for (int v : grafo[u]) {
		if (estado[v] == 1) {
			return false; // Ciclo detectado (falla Ejercicio 8)
		}
		if (estado[v] == 0) {
			if (!dfs_topologico(v, grafo, estado, orden)) {
				return false; 
			}
		}
	}
	
	estado[u] = 2; // 2 = Procesamiento completado
	orden.push_back(u); // Se añade en post-orden
	return true;
}

void ordenarTopologico(int n, const vector<vector<int>>& grafo) {
	vector<int> estado(n, 0);
	vector<int> orden;
	
	for (int i = 0; i < n; i++) {
		if (estado[i] == 0) {
			if (!dfs_topologico(i, grafo, estado, orden)) {
				cout << "El grafo tiene un ciclo. No es un DAG.\n";
				return;
			}
		}
	}
	
	reverse(orden.begin(), orden.end());
	
	for (int i = 0; i < n; i++) {
		cout << orden[i] << (i == n - 1 ? "" : " ");
	}
	cout << "\n";
}
