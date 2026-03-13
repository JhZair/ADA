#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int temp1 = 0;
	int temp2 = 0;
	int n = 10;
	int i = 1;
	while(i<=n){ //se ejecuta veces 10 neces
		int k = 1;
		temp1++;
		while(k<=2*n){//se ejecuta n*(n+1) veces
			k = k + 1;
			temp2++;
		}
		i = i + 2;
		cout << temp1 << temp2 << endl;
	}
	return 0;
	//su costo conputacional es el mismo que el ejer1, si dijese 3n en el segundo while tmb daría lo mismo
}

