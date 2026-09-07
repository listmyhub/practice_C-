#include <iostream>

template<class Datatype>
class DArray{
public:
	DArray(); // default constructor
	DArray(int nSize, Datatype dValue = 0); // set an array with default values
	DArray(const DArray& arr); // copy constructor
	~DArray(); // deconstructor

	void Print() const; // print the elements of the array

	int GetSize() const; // get the size of the array
	void SetSize(int nSize); // set the size of the array

	const Datatype& GetAt(int nIndex) const; // get an element at an index
	void SetAt(int nIndex, Datatype dValue); // set the value of an element

	Datatype& operator[](int nIndex); // overload operator '[]'
	const Datatype& operator[](int nIndex) const; // overload operator '[]'

	void PushBack(Datatype dValue); // add a new element at the end of the array
	void DeleteAt(int nIndex); // delete an element at some index
	void InsertAt(int nIndex, Datatype dValue); // insert a new element at some index

	DArray& operator = (const DArray& arr); //overload operator '='

private:
	Datatype* m_pData; // the pointer to the array memory
	int m_nSize; // the size of the array
	int m_nMax;

private:
	void Init(); // initilize the array
	void Free(); // free the array
	void Reserve(int nSize); // allocate enough memory
};
template<class Datatype>
DArray<Datatype>::DArray() {
	Init();
};
template<class Datatype>
DArray<Datatype>::DArray(int nSize, Datatype dValue) {
	m_nSize=nSize;
	m_nMax=nSize;
	m_pData=new Datatype[nSize];
	for (int i = 0;i < nSize;i++) {
		m_pData[i]=dValue;
	}
	//TODO
}
template<class Datatype>
DArray<Datatype>::DArray(const DArray& arr) {
	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nSize;
	m_pData = new Datatype[m_nSize];
	for (int i = 0;i < m_nSize;i++) {
		m_pData[i] = arr.m_pData[i];
	}
	//TODO
}
template<class Datatype>
// deconstructor
DArray<Datatype>::~DArray() {
	Free();
}
template<class Datatype>
// display the elements of the array
void DArray<Datatype>::Print() const {
	std::cout << "size=" << m_nSize << ", max=" << m_nMax << ": ";
	for (int i = 0;i < m_nSize;i++) {
		std::cout << " " << m_pData[i];
	}
	std::cout << std::endl;
	//TODO
}
template<class Datatype>
// initilize the array
void DArray<Datatype>::Init() {
	m_nSize=0;
	m_nMax = 0;
	m_pData=nullptr;
	//TODO
}
template<class Datatype>
// free the array
void DArray<Datatype>::Free() {
	delete[] m_pData;
	m_pData=nullptr;
    m_nSize=0;
	m_nMax = 0;
	//TODO
}
template<class Datatype>
// get the size of the array
int DArray<Datatype>::GetSize() const {
	//TODO
	return m_nSize; // you should return a correct value
}
template<class Datatype>
void DArray<Datatype>:: Reserve(int nSize){
	if (m_nMax >= nSize) {
		return;
	}
	while (m_nMax < nSize) {
		if (m_nMax == 0) {
			m_nMax = 1;
		}
		else {
			m_nMax *= 2;
		}
	}
	Datatype* pData = new Datatype[m_nMax];
	memcpy(pData, m_pData, m_nSize * sizeof(Datatype));
	delete[] m_pData;
	m_pData = pData;
}
template<class Datatype>
// set the size of the array
void DArray<Datatype>::SetSize(int nSize) {
	if (m_nSize ==  nSize) {
		return;
	}
	Reserve(nSize);
	for (int i = m_nSize;i < nSize;i++) {
		m_pData[i] = 0.;
		m_nSize = nSize;
	}
	//TODO
}
template<class Datatype>
// get an element at an index
const Datatype& DArray<Datatype>::GetAt(int nIndex) const {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	//TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}
template<class Datatype>
// set the value of an element 
void DArray<Datatype>::SetAt(int nIndex, Datatype dValue) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	m_pData[nIndex] = dValue;
	//TODO
}
template<class Datatype>
// overload operator '[]'
Datatype& DArray<Datatype>::operator[](int nIndex) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	// TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}
template<class Datatype>
// overload operator '[]'
const Datatype& DArray<Datatype>::operator[](int nIndex) const {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	//TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}
template<class Datatype>
// add a new element at the end of the array
void DArray<Datatype>::PushBack(Datatype dValue) {
	int new_size=m_nSize+1;
	Reserve(new_size);
	m_pData[m_nSize]=dValue;
	m_nSize=new_size;
	//TODO
}
template<class Datatype>
// delete an element at some index
void DArray<Datatype>::DeleteAt(int nIndex) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	int new_size=m_nSize-1;
	for (int i = nIndex;i < new_size;i++) {
		m_pData[i]=m_pData[i+1];
	}
	m_nSize=new_size;
	//TODO
}
template<class Datatype>
// insert a new element at some index
void DArray<Datatype>::InsertAt(int nIndex, Datatype dValue) {
	if (nIndex < 0 || nIndex >= m_nSize+1) {
		throw std::out_of_range("Index out of range");
	}
	int new_size=m_nSize+1;
	Reserve(new_size);
	for (int i = new_size-1;i > nIndex;i--) {
		m_pData[i] = m_pData[i - 1];
	}
	m_pData[nIndex] = dValue;
	m_nSize = new_size;
	//TODO
}

template<class Datatype>
// overload operator '='
DArray<Datatype>& DArray<Datatype>::operator = (const DArray<Datatype>& arr) {
	if (this == &arr) {
		return *this;
	}
	Reserve(arr.m_nSize);
	for (int i = 0;i < arr.m_nSize;i++) {
		m_pData[i] = arr.m_pData[i];
		m_nSize = arr.m_nSize;
	}
	//TODO
	return *this;
}