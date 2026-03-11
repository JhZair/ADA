#include <iostream>
using namespace std;

// Class CVector definition
class CVector
{
private:
	int *m_pVect, // Pointer to the buffer
		m_nCount, // Control how many elements are actually used
		m_nMax, // Control how many are allocated as maximum
		m_nDelta; // To control the growing
	void Init(int delta); // Init our private variables, etc
	void Resize(); // Resize the vector when occurs an overflow
public:
	CVector(int delta = 10); // Constructor
	void Insert(int elem); // Insert a new element
	// More methods go here
};
void CVector::Resize()
{
	int *pTemp, i;
	// pTemp = new int[gnMax + delta]; // Alloc a new vector
	// for(i = 0 ; i < gnMax ; i++) // Transfer the elements
	// pTemp[i] = gpVect[i]; // we can also use the function memcpy
	// delete [ ] gpVect; // delete the old vector
	// gpVect = pTemp; // Update the pointer
	gnMax += delta;
}

void CVector::Insert(int elem)
{
	if( m_nCount == m_nMax ) // Verify the overflow
		Resize(); // Resize the vector before inserting elem
	m_pVect[m_nCount++] = elem; // Insert the element at the end
}

int main(int argc, char *argv[]) {
	
	return 0;
}

