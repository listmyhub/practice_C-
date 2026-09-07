#include "PolynomialList.h"
#include <cmath>
#include<fstream>
#include<algorithm>
#define EPSILON 1e-10
#include<iostream>

using namespace std;

PolynomialList::PolynomialList(const PolynomialList& other) {
    m_Polynomial = other.m_Polynomial;
    // TODO
}

PolynomialList::PolynomialList(const string& file) {
    ReadFromFile(file);
    // TODO
}

PolynomialList::PolynomialList(const double* cof, const int* deg, int n) {
    for (int i = 0;i < n;i++) {
        AddOneTerm(Term(deg[i], cof[i]));
    }

    // TODO
}

PolynomialList::PolynomialList(const vector<int>& deg, const vector<double>& cof) {
    if (deg.size() != cof.size()) {
        throw invalid_argument("deg and cof should have the same size");
    }
    for (int i = 0;i < deg.size();i++) {
        AddOneTerm(Term(deg[i], cof[i]));
    }
    // TODO
}

double PolynomialList::coff(int i) const {
    for (const Term& term : m_Polynomial) {
        if (term.deg > i)
            break;
        if (term.deg == i)
            return term.cof;
    }//TODO
    return 0.; // you should return a correct value
}

double& PolynomialList::coff(int i) {
    // TODO
    //static double ERROR; // you should delete this line
    return AddOneTerm(Term(i, 0)).cof; // you should return a correct value
}

void PolynomialList::compress() {
    auto p = m_Polynomial.begin();
    while (p != m_Polynomial.end()) {
        if (fabs((*p).cof) < EPSILON) {
            p = m_Polynomial.erase(p);
        }
        else {
            p++;
        }
    }
    // TODO
}

PolynomialList PolynomialList::operator+(const PolynomialList& right) const {
    PolynomialList result(*this);
    for (const Term& term : right.m_Polynomial) {
        result.AddOneTerm(term);
    }
    result.compress();
    return result;
}
// you should return a correct value
// TODO


PolynomialList PolynomialList::operator-(const PolynomialList& right) const {
    PolynomialList result(*this);
    for (const Term& term : right.m_Polynomial) {
        result.AddOneTerm(Term(term.deg, -term.cof));
    }
    result.compress();
    return result;
}

// TODO

PolynomialList PolynomialList::operator*(const PolynomialList& right) const {
    PolynomialList result;
    for (const Term& term1 : m_Polynomial) {
        for (const Term& term2 : right.m_Polynomial) {
            result.AddOneTerm(Term(term1.deg + term2.deg, term1.cof * term2.cof));
        }
    }
    result.compress();
    return result;
}
// you should return a correct value

PolynomialList& PolynomialList::operator=(const PolynomialList& right) {
    m_Polynomial = right.m_Polynomial;
    // TODO
    return *this;
}

void PolynomialList::Print() const {
    auto p = m_Polynomial.begin();
    if (p == m_Polynomial.end()) {
        cout << "0" << endl;
        return;
    }
    for (;p != m_Polynomial.end();p++) {
        if (p != m_Polynomial.begin()) {
            cout << " ";
            if (p->cof > 0) {
                cout << "+";
            }
        }
        cout << p->cof;
        if (p->deg > 0) {
            cout << "x^" << p->deg;
        }
    }
    cout << endl;
}

bool PolynomialList::ReadFromFile(const string& file) {
    m_Polynomial.clear();
    ifstream a;
    a.open(file.c_str());
    if (!a.is_open()) {
        cout << "error: can not open file";
        return false;
    }
    char ch;
    int b;
    a >> ch;
    a >> b;
    for (int i = 0;i < b;i++) {
        Term term;
        a >> term.deg;
        a >> term.cof;
        AddOneTerm(term);
    }
    a.close();
    return true;
}
PolynomialList::Term& PolynomialList::AddOneTerm(const Term& term) {
    auto p = m_Polynomial.begin();
    for (;p != m_Polynomial.end();p++) {
        if (p->deg == term.deg) {
            p->cof += term.cof;
            return *p;
        }
        if (p->deg > term.deg) {
            break;
        }
    }
    return*m_Polynomial.insert(p, term);
}