/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSortable.cpp
 * Author: Admin
 *
 * Created on February 13, 2019, 7:34 PM
 */

#include <cstdlib>
#include <vector>
using namespace std;

#include "IntegerVectorSortable.h"
    
    int IntegerVectorSortable::insertInteger(int element) {
        m_IntegerVector.push_back(element);
    }

    unsigned int IntegerVectorSortable::getSize() const {
        return m_IntegerVector.size();
    }
    
    bool IntegerVectorSortable::smaller(int i, int j) const {
        if(getInteger(i) < getInteger(j))
            return true;
        else
            return false;
    }
    
    void IntegerVectorSortable::swap(int i, int j){
        int temp = m_IntegerVector[i];
        m_IntegerVector[i]=m_IntegerVector[j];
        m_IntegerVector[j]=temp;
    }
        
    void IntegerVectorSortable::print() const {
        for(int i=0; i<getSize(); i++)
            cout<<m_IntegerVector[i]<<"; "<<endl;
    }