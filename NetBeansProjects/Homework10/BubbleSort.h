/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.h
 * Author: Admin
 *
 * Created on February 17, 2019, 4:23 PM
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortableVector.h"
#include "IntegerVectorSortable.h"
using namespace std;
class BubbleSortIncreasing{
public:
    BubbleSortIncreasing() {
        
    }
    virtual bool needSwap(SortableVector* sv, int i, int j) {return !sv->smaller(i,j);}
    void sort(IntegerVectorSortable* sortableVector);
};

#endif /* BUBBLESORT_H */

