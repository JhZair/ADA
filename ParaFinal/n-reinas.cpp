#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función de Factibilidad: O(N)
bool esSeguro(const vector<int>& reinas, int fila_actual, int col_actual) {
	// Solo revisamos las filas anteriores (las que ya tienen reinas)
	for (int i = 0; i < fila_actual; i++) {
		int col_i = reinas[i];
		
		// Comprobar la misma columna
		if (col_i == col_actual) return false;
		
		// Comprobar las diagonales
		if (abs(fila_actual - i) == abs(col_actual - col_i)) return false;
	}
	return true; // Pasa todas las pruebas
}

// Función principal de Backtracking
void resolverNReinas(int fila, vector<int>& reinas, int N, int& soluciones) {
	// 1. CASO BASE: Si llegamos a la fila N, logramos colocar todas las reinas
	if (fila == N) {
		soluciones++;
		return;
	}
	
	// 2. BUCLE DE OPCIONES: Probar todas las columnas en la fila actual
	for (int col = 0; col < N; col++) {
		// 3. VERIFICACIÓN DE FACTIBILIDAD
		if (esSeguro(reinas, fila, col)) {
			// 4. MARCAR (DO)
			reinas[fila] = col;
			
			// 5. RECURSIÓN (Avanzar a la siguiente fila)
			resolverNReinas(fila + 1, reinas, N, soluciones);
			
			// 6. DESMARCAR (UNDO) - Backtracking
			// Matemáticamente no es estrictamente necesario "limpiar" el valor en este 
			// caso concreto porque se sobrescribirá en la siguiente iteración, 
			// pero conceptualmente aquí ocurre el retroceso.
			reinas[fila] = -1; 
		}
	}
}

int main() {
	int N = 8; // Tablero estándar de ajedrez
	vector<int> reinas(N, -1);
	int total_soluciones = 0;
	
	resolverNReinas(0, reinas, N, total_soluciones);
	
	cout << "Para N = " << N << ", existen " << total_soluciones << " soluciones." << endl;
	return 0;
}
