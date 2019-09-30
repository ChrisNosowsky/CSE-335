#ifndef INTEGERVECTORSORTABLE_H
#define INTEGERVECTORSORTABLE_H
#include <vector>
#include <iostream>
#include "SortableVector.h"
using namespace std;
class IntegerVectorSortable: public SortableVector {
public:   
    vector <int> m_IntegerVector;
    virtual unsigned int getSize() const;
    virtual bool smaller(int i, int j) const; 
    virtual void swap(int i, int j); 
    virtual void print() const;  
    int getInteger(int i) const{return m_IntegerVector[i];}
    int insertInteger(int element);
};
#endif /* INTEGERVECTORSORTABLE_H */

