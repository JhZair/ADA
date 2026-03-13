#include <iostream>
using namespace std;

class CVector
{
private:
	int *m_pVect,
		m_nCount,
		m_nMax,
		m_nDelta;
	void Init(int delta);
	void Resize();
	
public:
	CVector(int delta = 10);
	void Insert(int elem);
};

void CVector::Init(int delta) {
	m_nCount = 0;
	m_nMax = 0;
	m_nDelta = delta;
	m_pVect = 0;
}

void CVector::Resize() {
	m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
	m_nMax += m_nDelta;
}

CVector::CVector(int delta) {
	Init(delta);
}

void CVector::Insert(int elem)
{
	if( m_nCount == m_nMax )
		Resize();
	m_pVect[m_nCount++] = elem;
}

int main() {
	CVector vec1(10);
	vec1.Insert(7);
	return 0;

}

