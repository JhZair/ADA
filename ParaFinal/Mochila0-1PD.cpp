#include <bits/stdc++.h>
using namespace std;

struct Objeto{
	int id, peso, valor;
};

void resolverMochilaDP(vector<Objeto>& obj,int capacidad){
	int n = obj.size();
	vector<vector<int>> dp(n+1,vector<int>(capacidad + 1,0));
	
	for(int i=1;i<=n;i++){
		for(int w=1;w<=capacidad;w++){
			if(obj[i-1].peso <= w){
				dp[i][w] = max(dp[i-1][w], dp[i-1][w-obj[i-1].peso] + obj[i-1].valor);
			}
			else{
				dp[i][w] = dp[i-1][w];
			}
		}
	}
	
	int valorRestante = dp[n][capacidad];
	int pesoTotal = 0;
	int w = capacidad;
	vector<Objeto> seleccionados;
	
	for (int i = n; i > 0 && valorRestante > 0; i--) {
		// Si el valor actual es diferente al de la celda superior, 
		// significa que el objeto en esta fila fue incluido en la mochila.
		if (valorRestante != dp[i - 1][w]) {
			seleccionados.push_back(obj[i - 1]);
			pesoTotal += obj[i - 1].peso;
			valorRestante -= obj[i - 1].valor;
			w -= obj[i - 1].peso;
		}
	}
	
	// 3. Salida de datos
	cout << "Objetos seleccionados:" << endl;
	// Se imprime en orden inverso para mostrarlos en el orden de ID original
	for (int i = seleccionados.size() - 1; i >= 0; i--) {
		cout << "ID: " << seleccionados[i].id << ", Peso: " << seleccionados[i].peso << ", Valor: " << seleccionados[i].valor << endl;
	}
	cout << "Peso total usado: " << pesoTotal << endl;
	cout << "Valor total obtenido: " << dp[n][capacidad] << endl;
	cout << "Capacidad restante: " << capacidad - pesoTotal << endl;
	cout << "Cantidad de Objetos cargados: " << seleccionados.size() << endl << endl;
}

int main(int argc, char *argv[]) {
	cout << "--- Apartado A ---" << endl;
	vector<Objeto> objetosA = {
		{1, 3, 12}, {2, 7, 3}, {3, 4, 7}, {4, 2, 4}, {5, 1, 3}, {6, 6, 8}
	};
	resolverMochilaDP(objetosA, 15);
	
	cout << "--- Apartado B ---" << endl;
	vector<Objeto> objetosB = {
		{1, 51, 204}, {2, 119, 51}, {3, 68, 119}, {4, 34, 68}, {5, 17, 51}, {6, 102, 136}
	};
	// Las capacidades de 255 y 1000 son procesables directamente en memoria en C++
	resolverMochilaDP(objetosB, 255);
	
	cout << "--- Apartado C ---" << endl;
	vector<Objeto> objetosC = {
		{1, 130, 120}, {2, 570, 300}, {3, 140, 570}, {4, 200, 423}, {5, 360, 300}, {6, 400, 800}
	};
	resolverMochilaDP(objetosC, 1000);
	return 0;
}

