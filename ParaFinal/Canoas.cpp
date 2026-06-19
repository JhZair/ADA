#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calcularCostesMinimos(vector<vector<int>>& C) {
	int n = C.size();
	vector<vector<int>> dp = C; 
	
	for (int L = 2; L < n; L++) {
		for (int i = 0; i < n - L; i++) {
			int j = i + L;
			for (int k = i + 1; k < j; k++) {
				if (dp[i][k] != 1e9 && dp[k][j] != 1e9) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << "Aldea " << i + 1 << " a Aldea " << j + 1 << " -> Coste: " << dp[i][j] << "\n";
		}
	}
}

int main() {
	int INF = 1e9;
	vector<vector<int>> matrizCostes = {
		{0, 17, 8, 16, 20},
		{INF, 0, 12, 6, 15},
		{INF, INF, 0, 12, 16},
		{INF, INF, INF, 0, 15},
		{INF, INF, INF, INF, 0}
	};
	
	calcularCostesMinimos(matrizCostes);
	
	return 0;
}
