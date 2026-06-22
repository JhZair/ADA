#include <iostream>
#include <vector>

using namespace std;

int particion(vector<int>& arr, int low, int high) {
	int pivote = arr[high];
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivote) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = particion(arr, low, high);
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
		
	}
}

int main(int argc, char *argv[]) {
	vector<int> arr = {5,6,7,2,9,1,4};
	quickSort(arr,0,6);
	
	for(auto e: arr){
		cout << e << ' ';
	}
	return 0;
}
