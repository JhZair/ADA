#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cambio(int monto, vector<int>& monedas){
	sort(monedas.begin(),monedas.end(),greater<int>());
	int total_mone = 0;
	
	cout << " Monto a devolver : " << monto << endl ;
	
	for(int i=0;i<monedas.size();i++){
		if(monto==0) break;
		int valor_moneda = monedas[i];
		if(monto >= valor_moneda){
			cout << "Una moneda de: "<< valor_moneda <<" céntimos"<< endl ;
			int cantidad = monto/valor_moneda;
			monto = monto % valor_moneda;
			total_mone += cantidad;
		}
	}
	cout<< "Total de monedas: " << total_mone << endl;
}

int main(int argc, char *argv[]) {
	
	vector<int> monedas = {1, 2, 5, 10, 20, 50, 100};
	int monto ;
	cout << " Ingrese el monto en centimos : ";
	cin >> monto;
	cambio(monto, monedas);
	return 0;
}

