#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int temp1 = 0;
	int temp2 = 0;
	int n = 10;
	int i = 1;
	while(i<=n){
		int j = i;
		temp1++;
		while(j<=n){
			j = j + 1;
			temp2++;
		}
		i = i + 1;
		cout << temp1 << temp2 << endl;
	}
	return 0;
	//por determinar
}

