#include <bits/stdc++.h>
using namespace std;

bool noCruza(vector<int>& reinas, int filaAc, int colAc){
	for(int i =0;i<filaAc;i++){
		int col_i = reinas[i];
		if(col_i == colAc){
			return false;
		}
		if(abs(filaAc-i) == abs(colAc-col_i)) return false;
	}
	return true;
}

void resolverNReinas(int fila ,vector<int>& reinas, int N, int& soluciones){
	if(fila == N){
		soluciones++;
		return;
	}
	for(int col=0; col<N; col++){
		if(noCruza(reinas,fila, col)){
			reinas[fila] = col;
			resolverNReinas(fila+1,reinas,N,soluciones);
			reinas[fila] = -1;
		}
	}
}

int main(int argc, char *argv[]) {
	int N = 12;
	vector<int> reinas(N, -1);
	int total_soluciones = 0;
	
	resolverNReinas(0, reinas, N, total_soluciones);
	
	cout << "Para N = " << N << ", existen " << total_soluciones << " soluciones." << endl;
	return 0;
}

//T(N) = O(N * N!)
