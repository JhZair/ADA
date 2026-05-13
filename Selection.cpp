#include <iostream>
using namespace std;

void imprimir( int A [] , int n) {
	for (int i = 0; i < n; i ++) {
		cout << A [i] << " ";
	}
	cout << endl;
}
//int particion ( int A [] , int inicio , int fin ) {
//	int pivote = A[ inicio ];
//	int i = inicio + 1;
//	int j = fin ;
//	while ( true ) {
//		while (i <= fin && A[ i] <= pivote ) {
//			i ++;
//		}
//		while (A [j] > pivote ) {
//			j--;
//		}
//		if (i >= j) {
//			break ;
//		}
//		swap (A[ i], A[j ]) ;
//	}
//	swap (A[ inicio ], A[j ]) ;
//	return j;
//}
//
//void quicksort ( int A [] , int inicio , int fin ) {
//	if ( inicio < fin ) {
//		int posPivote = particion (A , inicio , fin ) ;
//		quicksort (A , inicio , posPivote - 1) ;
//		quicksort (A , posPivote + 1, fin ) ;
//	}
//}

void pivote(int A[], int i, int j, int l){
	int p = A[i];
	int k = i;
	l=j+1;
	for(;(A[k] < p) || (k>=j); k++){}
		
	for(;(A[l] <= p); l--){}
	while(k<l){
		std::swap(k,l);
		for(;(A[k] > p); k++){}
		for(;(A[l] <= p); l--){}
	}
	std::swap(i,l);
}
int Seleccion(int A [], int indx, int tamaño){
	int i,j,l;
	i=1;
	j=tamaño;
	pivote(i,j,l);
	while( l!= s){ 
		if (indx < l){
			j--
		}
		else if(indx l){
			i = l+1;
		}
	}
	return A[l];
}

int main () {
	int A [] = {12, 4, 7, 20, 1,15, 9};
	int n = 7;
	cout << " Arreglo original : ";
	imprimir (A , n);
	quicksort (A , 0, n - 1) ;
	cout << " Arreglo ordenado con QuickSort : ";
	imprimir (A , n);
	return 0;
}
//Usar el alg de selección, el quickSelect
