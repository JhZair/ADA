#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 16;
	int i = 1;
	while(i<=n){ //9 veces | n/2 + 1 mal | log2(n+1) <----- por qué en base 2? se dice que en costo computacional no importa la base
		int k = 1; // 8 veces | n/2 mal |log2(n)
		while(k<=n){// 17 veces | n+1 mal | log2(n+1)(n)
			k = k + 1; //16 veces | n mal | log2(n)
		}
		i = i*2; // 8 veces | n/2
	}
	return 0;
	//el costo total es: 
}

