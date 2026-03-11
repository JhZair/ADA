#include <iostream>
using namespace std;

int *gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0; // Counter to know the number of used elements int
int gnMax = 0; // Variable containing the size of the allocated
// memory

struct Vector
{
	int	m_nCount = 0; // Control how many elements are actually used
	int	m_nMax = 10; // Control how many are allocated as maximum
	int	m_nDelta = 10; // To control the growing
	int*m_pVect = new int[m_nCount]; // Pointer to the buffer
};

void Resize(Vector *pThis)
{
//	pThis->m_pVect = realloc(gpVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
	int *pTemp, i;
	 pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Alloc a new vector
	 for(i = 0 ; i < pThis->m_nMax ; i++) // Transfer the elements
	 pTemp[i] = gpVect[i]; // we can also use the function memcpy
	 delete [ ] gpVect; // delete the old vector
	 gpVect = pTemp;
	pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem)
{
	if( pThis->m_nCount == pThis->m_nMax ) // Verify the overflow
		Resize(pThis); // Resize the vector before inserting elem
	// Insert the element at the end of the sequence
	pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main(int argc, char *argv[]) {
	
	Vector vec1;
	Insert(&vec1, 7);
	Insert(&vec1, 3);
	Insert(&vec1, 2);
	Insert(&vec1, 8);
	
	Vector vec2;
	Insert(&vec2, 6);
	Insert(&vec2, 5);
	Insert(&vec2, 2);
	Insert(&vec2, 1);
	
	return 0;
}

