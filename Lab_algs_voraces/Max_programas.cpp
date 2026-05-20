#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Programa{
	int id;
	int espacio;
};
bool compararPorEspacio(Programa a , Programa b) {
	return a.espacio < b.espacio;
}

void maxProgramas(int capacidad, vector<Programa>& programas) {
	sort(programas.begin(), programas.end(), compararPorEspacio);
	int espacio_total=0;
	int progs_almacenados = 0;
	while(espacio_total + programas[1].espacio <= capacidad ) {
		cout << "Se usa programa con id: " << programas[1].id<< endl;
		espacio_total += programas[1].espacio;
		progs_almacenados++;
	}
	cout << "Se usa: " << espacio_total <<" de espacio"<< endl;
	cout << "Sobra: " << capacidad - espacio_total <<" de espacio"<< endl;
	cout << "Se pueden almacenar: " << progs_almacenados<< " programas"<<endl;
}

int main(int argc, char *argv[]) {
	vector<Programa> programas = {
		{1 , 40} ,
	{2 , 10} ,
	{3 , 30} ,
	{4 , 20} ,
	{5 , 50}
	};
	int capacidadDisco = 100;
	maxProgramas(capacidadDisco, programas);
	return 0;
}

