#include <iostream>
#include <vector>

using namespace std;

void asignarRecursos(int n, int r, vector<vector<int>>& N) {
	vector<vector<int>> dp(r + 1, vector<int>(n + 1, 0));
	vector<vector<int>> asignacion(r + 1, vector<int>(n + 1, 0));
	
	for (int i = 1; i <= r; i++) {
		for (int k = 0; k <= n; k++) {
			int max_beneficio = -1;
			int mejor_j = 0;
			
			for (int j = 0; j <= k; j++) {
				int beneficio_actual = dp[i - 1][k - j] + N[i - 1][j];
				if (beneficio_actual > max_beneficio) {
					max_beneficio = beneficio_actual;
					mejor_j = j;
				}
			}
			dp[i][k] = max_beneficio;
			asignacion[i][k] = mejor_j;
		}
	}
	
	int recursos_restantes = n;
	vector<int> solucion(r);
	
	for (int i = r; i > 0; i--) {
		solucion[i - 1] = asignacion[i][recursos_restantes];
		recursos_restantes -= solucion[i - 1];
	}
	
	cout << dp[r][n] << "\n";
	for (int i = 0; i < r; i++) {
		cout << solucion[i] << "\n";
	}
}

int main() {
	int n = 4; 
	int r = 3; 
	
	vector<vector<int>> N = {
		{0, 10, 15, 20, 22}, 
		{0, 12, 18, 22, 25}, 
		{0, 8,  14, 19, 21}  
	};
	
	asignarRecursos(n, r, N);
	
	return 0;
}
