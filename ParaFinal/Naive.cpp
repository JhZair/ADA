#include <iostream>

using namespace std;

// Calcula x elevado a la potencia n
long long naivePower(long long x, int n) {
	// 1. CASO BASE
	if (n == 0) {
		return 1;
	}
	// Caso base para evitar divisiones raras
	if (n == 1) {
		return x;
	}
	
	// 2. DIVISIÓN y 3. LLAMADAS RECURSIVAS
	// Si n es par
	if (n % 2 == 0) {
		return naivePower(x, n / 2) * naivePower(x, n / 2);
	} 
	// Si n es impar
	else {
		return x * naivePower(x, n / 2) * naivePower(x, n / 2);
	}
}
