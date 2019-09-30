/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortTemplate.cpp
 * Author: Admin
 *
 * Created on February 13, 2019, 8:15 PM
 */

#include <cstdlib>

using namespace std;
#include "BubbleSortTemplate.h"
#include "SortableVector.h"

void BubbleSortTemplate::sort(SortableVector* sortableVector) {
        bool sorted = false;
        int n=sortableVector->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(needSwap(sortableVector,i-1,i)){
                    sortableVector->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }    
}

