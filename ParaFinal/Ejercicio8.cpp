#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int costoMinimoCanoas(vector<vector<int>>& costos){
	int n = costos.size();
	if(n == 0){
		return 0;
	}
	
	vector<int> dp(n, 1e9);
	dp[0] = 0;
	
	for(int i = 1; i<n; i++){
		for(int j=0;j<i; j++){
			dp[i] = min(dp[i], dp[j]+costos[j][i]);
		}
	}
	
	return dp[n - 1];
}
int main(int argc, char *argv[]) {
	vector<vector<int>> costos ={
		{0, 2, 4, 7},{0, 0, 1, 4},{0, 0, 0, 2},{0, 0, 0, 0}
	};
	
	cout << costoMinimoCanoas(costos)<<"\n";
	
	return 0;
}

