#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int temp1 = 0;
	int temp2 = 0;
	int n = 10;
	int i = 1;
	while(i<=n){ //se ejecuta n+1 veces
		int j = 1;
		temp1++;
		while(j<=n){//se ejecuta n*(n+1) veces
			j = j + 1;
			temp2++;
		}
		i = i + 1;
		cout << temp1 << temp2 << endl;
	}
	return 0;
	//el costo de todo este algoritmo es (1+n+1+n+n+(n+1)+n+n)/(n^2+n) = 2 + 4n^2 + ...
}

