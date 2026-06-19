#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longitudMaximaCreciente(vector<int>& secuencia) {
	if (secuencia.empty()){
		return 0;
	}

	int n = secuencia.size();
	vector<int> dp(n, 1);
	int maximaLongitud = 1;
	
	for (int i =1; i<n; i++){
		for (int j=0;j<i;j++){
			if (secuencia[i] > secuencia[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		maximaLongitud = max(maximaLongitud,dp[i]);
	}
	
	return maximaLongitud;
}

int main(int argc, char *argv[]) {
	vector<int> secuencia = {10, 22, 9, 33, 21, 50, 41,60,80};
	
	cout << longitudMaximaCreciente(secuencia)<<"\n";
	
	return 0;
}

