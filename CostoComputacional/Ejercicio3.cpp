#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 10;
	for(int i = 1; i <= n ; i++){ // n+1 veces
		int j = 1; // n veces
		while(j<=n){// n*(n/2 + 1) veces es una vez más por que pregunta para salir del bucle
			j = j + 2; // (n^2)/2
		}
	}
	return 0;
	// el costo total es n+1+n+n*(n/2 + 1) + (n^2)/2 = ....
}

