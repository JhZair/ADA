//Gonzalo Sumina

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//=======Parte B========
//Preguta 1
// A)
//Pregunta 2
// B)
//Pregunta 3
// C)
//Pregunta 4
// C)
//Pregunta 5
/*
void MenorK_esimo(vector<int> &X,int k,int cont,int l, int r){
if(cont==4){
return X[0];
}
int medio=l+(r-l)/2;
if()
return 0;
}

int main(int argc, char *argv[]) {
vector<int> X={15,6,2,9,12,20,1};
int k=4;
return 0;
}
*/
//Pregunta 6
/**/
//Pregunta 7
/**/
void DPMochila(const vector<int> &b, const vector<int> &p,int n,int W){
	vector<vector<int>> table(n+1,vector<int>(W+1,0));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=W;++j){
			if(j-p[i-1]<0){
				table[i][j]=table[i][j-1];
			}
			else{
				table[i][j]=max(table[i][j-1],b[i]+table[i][j-p[i-1]]);
			}
		}
	}
	cout<< "El beneficio maximo es: "<<table[n-1][W-1]<<endl;
	/*int i=n;
	int j=W;
	while(true){
		if(j-p[i-1]<0){
			cout << "Se utilizo: "<< i;
			j--;
		}
		else{
			j=j-p[i-1];
			i--;
		}
	}*/
	return;
}
	int main(){
		vector<int> P={1,2,3};
		vector<int> B={6,10,12};
		int n=3;
		int W=5;
		DPMochila(B,P,n,W);
		return 0;
	}
		
		//Pregunta 8
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
