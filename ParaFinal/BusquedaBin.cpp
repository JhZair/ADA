#include <iostream>
#include <vector>

using namespace std;

int busquedaBinaria(const vector<int>& arr, int left, int right, int target) {
	if (left > right) {
		return -1; 
	}
	
	int mid = left + (right - left) / 2;
	
	if (arr[mid] == target) {
		return mid; 
	}
	
	if (arr[mid] > target) {
		return busquedaBinaria(arr, left, mid - 1, target); 
	} else {
		return busquedaBinaria(arr, mid + 1, right, target); 
	}
	
}

//n^

int main(int argc, char *argv[]) {
	vector<int> arr = {5,6,7,8,9,12,16};
	cout<<busquedaBinaria(arr,0,6,12)<< endl;
	return 0;
}
