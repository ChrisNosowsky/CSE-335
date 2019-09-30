1/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.h
 * Author: Admin
 *
 * Created on February 17, 2019, 4:00 PM
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include "SortableVector.h"
#include "SearchableVector.h"
#include "IntegerVectorSortableSearchable.h"
class BinarySearch: public SearchableVector {
    
public:
    BinarySearch() {
        
    }
    int search(IntegerVectorSortableSearchable *iv);
};

#endif /* BINARYSEARCH_H */

