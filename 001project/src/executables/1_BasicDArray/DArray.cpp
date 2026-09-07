// implementation of class DArray
#include "DArray.h"
#include<iostream>
#include<cassert>

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	int m_nSize = nSize;
	double*m_pData = new double[m_nSize];
	for (int i = 0;i < m_nSize;i++) {
		m_pData[i] = dValue;
	}//构造函数初始化
	//TODO
}

DArray::DArray(const DArray& arr) {
	m_pData = new double[arr.m_nSize];
	m_nSize = arr.m_nSize;
	for (int i = 0;i < m_nSize;i++) {
		m_pData[i] = arr.m_pData[i];
	}//拷贝函数
	//TODO
}

// deconstructor 析构函数
DArray::~DArray() {
	Free();
}

// display the elements of the array展示数组的元素
void DArray::Print() const {
	std::cout << "size=" << m_nSize << ":";
	for (int i = 0;i < m_nSize;i++) {
		std::cout <<" " << GetAt(i);
	}
	std::cout << std::endl;
	//TODO
}

// initilize the array初始化数组
void DArray::Init() {
	m_nSize = 0;
	m_pData = nullptr;
	//TODO
}

// free the array
void DArray::Free() {
	delete[] m_pData;
	m_nSize = 0;
	m_pData = nullptr;
	//TODO
}

// get the size of the array
int DArray::GetSize() const {
	//TODO
	return  m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
	if (m_nSize == nSize) {
		return;
	}
	else {
		int a = m_nSize < nSize ? m_nSize : nSize;
		double* p = new double[nSize];
		for (int i = 0;i < a;i++) {
			p[i] = m_pData[i];
		}
		for (int i = a;i < nSize;i++) {
			p[i] = 0;
		}
		delete[] m_pData;
		m_pData = p;
		m_nSize = nSize;
	}
	//TODO
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	if(nIndex<0||nIndex >= m_nSize) {
		throw std::out_of_range("Error: index out of range");
	}
	//TODO
	//static double ERROR; // you should delete this line
	return m_pData[nIndex]; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Error: index out of range");
	}
	*(m_pData + nIndex)=dValue;
	//TODO
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Error: index out of range");
	}
	//TODO
	//static double ERROR; // you should delete this line
    return m_pData[nIndex]; // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	int new_size=m_nSize+1;
	double*nm_pData=new double[new_size];
	for (int i = 0;i < m_nSize;i++) {
		nm_pData[i] = m_pData[i];
	}
	nm_pData[m_nSize] = dValue;
	delete[] m_pData;
	m_pData = nm_pData;
	m_nSize = new_size;
	//TODO
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	if (nIndex < 0 || nIndex >= m_nSize) {
		throw std::out_of_range("Error: index out of range");
	}
	int new_size = m_nSize - 1;
	double* nm_pData = new double[new_size];
	if (nIndex == new_size) {
		for (int i = 0;i < new_size;i++) {
			nm_pData[i] = m_pData[i];
		}
	}
	else {
		for (int i = 0;i < nIndex;i++) {
			nm_pData[i] = m_pData[i];
		}
		for (int i = nIndex;i<new_size;i++) {
			nm_pData[i] = m_pData[i+1];
		}
	}
	delete[] m_pData;
	m_pData = nm_pData;
	m_nSize = new_size;

	//TODO
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	int new_size = m_nSize + 1;
	if (nIndex < 0 || nIndex >= new_size) {
		throw std::out_of_range("Error: index out of range");
	}
	double* nm_pData = new double[new_size];
	for (int i = 0;i < nIndex;i++) {
		nm_pData[i] = m_pData[i];
	}
	nm_pData[nIndex] = dValue;
	for (int i = new_size-1;i >nIndex;i--) {
		nm_pData[i] = m_pData[i -1];
	}
	delete [] m_pData;
	m_pData = nm_pData;
	m_nSize = new_size;
	//TODO
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	if (this == &arr) {
		return *this;
	}
	int m_nSize = arr.m_nSize;
	double*nm_pData = new double[m_nSize];
	for (int i = 0;i < m_nSize;i++) {
		nm_pData[i] = arr[i];
	}
	delete[] m_pData;
	m_pData = nm_pData;
	return *this;
}
	//TODO
