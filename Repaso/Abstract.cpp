#include <iostream>
using namespace std;

template <typename Type> class CVector
{
private:
	Type*m_pVect;
	int m_nCount,
		m_nMax,
		m_nDelta;
	void Init(int delta);  
	void Resize();
	
public:
	CVector(int delta = 10);		
	void Insert(Type elem);
};

template <typename Type> void CVector<Type>::Init(int delta) {
	m_nCount= 0;		
	m_nMax =0;
	m_nDelta= delta;
	m_pVect = 0;
}

template <typename Type> void CVector<Type>::Resize() {
	m_pVect = (Type*)realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta));
	m_nMax += m_nDelta;
}

template <typename Type> CVector<Type>::CVector(int delta)
{
	Init(delta);
}

template <typename Type> void CVector<Type>::Insert(Type elem) // Modificado de Type &elem según el encabezado original
{
	if( m_nCount == m_nMax )
		Resize();
	m_pVect[m_nCount++] = elem;
}

int main() {
	CVector<float> vecFloat(10);
	vecFloat.Insert(3.14f);
	return 0;
}

