/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.cpp
 * Author: Admin
 *
 * Created on February 17, 2019, 7:12 PM
 */

#include <cstdlib>
#include "BinarySearch.h"
#include "IntegerVectorSortableSearchable.h"
#include "IntegerVectorSortable.h"
using namespace std;

    int BinarySearch::search(IntegerVectorSortableSearchable *iv) {
       int left = 0;
       int right = iv->size;
       while(left <= right) {
           int middle = (left+right)/2;
           if(iv->m_IntegerVector[middle] == iv->query)
               return middle;
           else if (iv->m_IntegerVector[middle] > iv->query)
               right = middle -1;
           else
               left = middle + 1;  
       }
       return -1;
        
                
    }

