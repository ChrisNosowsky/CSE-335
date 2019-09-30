/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSortableSearchable.h
 * Author: Admin
 *
 * Created on February 17, 2019, 4:18 PM
 */

#ifndef INTEGERVECTORSORTABLESEARCHABLE_H
#define INTEGERVECTORSORTABLESEARCHABLE_H
#include "IntegerVectorSortable.h"
#include "SearchableVector.h"
using namespace std;
class IntegerVectorSortableSearchable: public IntegerVectorSortable, public SearchableVector {
    public:
    void insertInteger(int element) {
        m_IntegerVector.insert(m_IntegerVector.end(), element);
        size++;
    }
    int setQuery(int q) {
        query = q;
        return q;
    } 
};


#endif /* INTEGERVECTORSORTABLESEARCHABLE_H */

