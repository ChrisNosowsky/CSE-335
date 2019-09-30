/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.cpp
 * Author: Admin
 *
 * Created on February 17, 2019, 6:57 PM
 */
#include "BubbleSort.h"
#include "IntegerVectorSortable.h"
#include <cstdlib>

using namespace std;

    void BubbleSortIncreasing::sort(IntegerVectorSortable* sortableVector){
        bool sorted = false;
        int n=sortableVector->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(needSwap(sortableVector,i-1,i)){
                    cout << "in";
                    sortableVector->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
    }
