#include <bits/stdc++.h>
using namespace std;

void longitudMaximaCreciente(vector<int>& sec){
	if(sec.empty()) return ;
	
	int n = sec.size();
	vector<int> dp(n,1);
	vector<int> prev(n,-1);
	int maxLong = 1;
	int indx_final = 0;
	
	for(int i = 1; i<n;i++){
		for(int j = 0; j<i;j++){
			if(sec[i] > sec[j] && dp[i]< dp[j]+1){
				dp[i] = dp[j]+1;
				prev[i] = j;
			}
		}
		if(maxLong < dp[i]){
			maxLong = dp[i];
			indx_final = i;
		}
	}
	list<int> secf;
	int actual = indx_final;
	while(actual != -1){
		secf.push_front(sec[actual]);
		actual = prev[actual];
	}
	for(auto num : secf){
		cout << num << ' ';
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	vector<int> secuencia = {11, 17, 5, 8, 6, 4, 7, 12, 3};
	
	longitudMaximaCreciente(secuencia);
	
	return 0;
}

