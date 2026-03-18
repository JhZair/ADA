#include <iostream>
#include <vector>
using namespace std;

template<class T>
void Insertion(vector<T>& v){
	for(int j = 1; j< v.size(); j++){
		int key = v[j];
		int i = j-1;
		while(i>=0 && v[i] > key){
			v[i+1] = v[i];
			i -= 1;
		}
		v[i+1] = key;
	}
}

int main(int argc, char *argv[]) {
	
	vector<int> vec = {5, 2, 4, 6, 1, 3};
	Insertion<int>(vec);
	for(auto v : vec){
		cout << v << ' ';
	}
	return 0;
}

