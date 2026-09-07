#include "PolynomialMap.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#define  EPSILON 1e-10

using namespace std;

PolynomialMap::PolynomialMap(const PolynomialMap& other) {
	m_Polynomial = other.m_Polynomial;
    // TODO
}

PolynomialMap::PolynomialMap(const string& file) {
    ReadFromFile(file);
}

PolynomialMap::PolynomialMap(const double* cof, const int* deg, int n) {
	assert(n > 0);
	for (int i = 0; i < n; i++) {
		coff(deg[i]) = cof[i];
	}
	// TODO
}

PolynomialMap::PolynomialMap(const vector<int>& deg, const vector<double>& cof) {
	assert(deg.size() == cof.size());
	for (int i = 0; i < deg.size(); i++) {
		coff(deg[i]) = cof[i];
	}
	// TODO
}

double PolynomialMap::coff(int i) const {
	auto a = m_Polynomial.find(i);
	if (a == m_Polynomial.end()) {
		return 0;
	}
	return a->second;
}
double& PolynomialMap::coff(int i) {
	// TODO
	//static double ERROR; // you should delete this line
	return  m_Polynomial[i]; // you should return a correct value
}

void PolynomialMap::compress() {
	auto it = m_Polynomial.begin();
	for (;it != m_Polynomial.end();) {
		if (fabs(it->second) < EPSILON) {
			it = m_Polynomial.erase(it);
		}
		else {
			it++;
		}
	}
	// TODO
}

PolynomialMap PolynomialMap::operator+(const PolynomialMap& right) const {
	PolynomialMap poly(right);
	for (auto& term : m_Polynomial) {
		poly.coff(term.first) += term.second;
	}
	// TODO
	poly.compress();
	return poly; // you should return a correct value+
}

PolynomialMap PolynomialMap::operator-(const PolynomialMap& right) const {
	PolynomialMap poly(right);
	for (auto& term : m_Polynomial) {
		poly.coff(term.first)-= term.second;
	}
	// TODO
	poly.compress();
	return poly; // you should return a correct value
}

PolynomialMap PolynomialMap::operator*(const PolynomialMap& right) const {
	PolynomialMap poly;
	for (const auto& term1 : m_Polynomial) {
		for (const auto& term2 : right.m_Polynomial) {
			poly.coff(term1.first + term2.first)+= term1.second * term2.second;
		}
	}
	// TODO
	poly.compress();
	return poly; // you should return a correct value
}

PolynomialMap& PolynomialMap::operator=(const PolynomialMap& right) {
	m_Polynomial = right.m_Polynomial;
	// TODO
	return *this;
}

void PolynomialMap::Print() const {
	auto it = m_Polynomial.begin();
	if (it == m_Polynomial.end()) {
		cout << "0" << endl;
		return;
	}
	for (; it!= m_Polynomial.end();it++) {
		if (it != m_Polynomial.begin()) {
			cout << " ";
			if (it->second > 0) {
				cout << "+";
			}
		}
		cout << it->second;
		if (it ->first > 0) {
			cout << "x^" << it->first;
		}
	}
	cout << endl;
	// TODO
}

bool PolynomialMap::ReadFromFile(const string& file) {
    m_Polynomial.clear();
	ifstream p;
	p.open(file.c_str());
	if (!p.is_open()) {
		cout << "fail open this file";
		return false;
	}
	char ch;
	int b;
	p >> ch;
	p >> b;
	for (int i = 0;i < b;i++) {
		int a;
		p >> a;
		p >> m_Polynomial[a];
	}
	p.close();
	// TODO
	return true; // you should return a correct value
}
