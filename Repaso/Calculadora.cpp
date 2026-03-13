#include <iostream>

using namespace std;

float Addition(float a, float b) {return a + b;}
float Subtraction(float a, float b) {return a - b;}
float Multiplication(float a, float b) {return a * b;}

float Division(float a, float b) { 
	if (b == 0) {
		cerr <<"División por cero"<< endl;
		return 0; 
	}
	return a / b; 
}

int main() {
	// Code B
	// User type to simplify the declaration
	typedef float (*lpfnOperation) (float, float);
	
	// CVector of pointer to functions
	lpfnOperation vpf [4] = {
		&::Addition,       // Índice 0
			&::Subtraction,    // Índice 1
			&::Multiplication, // Índice 2
			&::Division        // Índice 3
	};
	
	float a, b, c; 
	int opt;
	
	// enter the operands
	cin >> a >> b;
	
	// enter the operation: 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
	cin >> opt;
	
	if (opt >= 0 && opt < 4) {
		// The next line replaces the switch and replaces the whole switch
		c = (*vpf [opt]) (a, b);
		cout << c << endl;
	} else {
		cerr << "Fuera de los límites" << endl;
	}
	
	return 0;
}
