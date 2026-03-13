#include <iostream>
using namespace std;

struct Vector
{
	int*m_pVect,
		m_nCount,
		m_nMax,
		m_nDelta;
};

void Resize(Vector *pThis)
{
	pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
	pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector*pThis,int elem)
{
	if( pThis->m_nCount == pThis->m_nMax )
		Resize(pThis);
	
	pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
	Vector vec1;
	vec1.m_nCount =0;
	vec1.m_nMax =0;
	vec1.m_nDelta= 10;
	vec1.m_pVect = 0;
	
	Insert(&vec1, 7);
	Insert(&vec1, 3);
	
	return 0;
}

