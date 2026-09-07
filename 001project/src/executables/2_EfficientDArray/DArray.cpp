// implementation of class DArray
#include "DArray.h"
#include <iostream>


// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	m_nSize=nSize;
	m_nMax=nSize;
	m_pData=new double[nSize];
	for (int i = 0;i < nSize;i++) {
		m_pData[i]=dValue;
	}
	//TODO
}

DArray::DArray(const DArray& arr) {
	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nSize;
	m_pData = new double[m_nSize];
	for (int i = 0;i < m_nSize;i++) {
		m_pData[i] = arr.m_pData[i];
	}
	//TODO
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	std::cout << "size=" << m_nSize << ", max=" << m_nMax << ": ";
	for (int i = 0;i < m_nSize;i++) {
		std::cout << " " << m_pData[i];
	}
	std::cout << std::endl;
	//TODO
}

// initilize the array
void DArray::Init() {
	m_nSize=0;
	m_nMax = 0;
	m_pData=nullptr;
	//TODO
}

// free the array
void DArray::Free() {
	delete[] m_pData;
	m_pData=nullptr;
    m_nSize=0;
	m_nMax = 0;
	//TODO
}

// get the size of the array
int DArray::GetSize() const {
	//TODO
	return m_nSize; // you should return a correct value
}

void DArray:: Reserve(int nSize){
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
	double* pData = new double[m_nMax];
	memcpy(pData, m_pData, m_nSize * sizeof(double));
	delete[] m_pData;
	m_pData = pData;
}
// set the size of the array
void DArray::SetSize(int nSize) {
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

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	//TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	m_pData[nIndex] = dValue;
	//TODO
}

// overload operator '[]'
double& DArray::operator[](int nIndex) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	// TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Index out of range");
	}
	//TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	int new_size=m_nSize+1;
	Reserve(new_size);
	m_pData[m_nSize]=dValue;
	m_nSize=new_size;
	//TODO
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
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

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
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

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
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
