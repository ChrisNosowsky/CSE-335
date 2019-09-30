/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Admin
 *
 * Created on February 6, 2019, 7:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class SearchableVector {
public:
    int size = 0;
    int query;
    vector<int> arr;
protected:
    SearchableVector() {
        
    }
    
};

class IntegerVectorSearchable: public SearchableVector{
public:
    IntegerVectorSearchable() {
    }
    
    void insertInteger(int element) {
        arr.insert(arr.end(), element);
        size++;
    }
    void print(){
        for(int i = 0; i < size; i++) {
            cout << arr[i];
            cout << ": ";
        }
        cout << endl;
    }
    int setQuery(int q) {
        query = q;
        return q;
    }  
};
class BinarySearch: public SearchableVector {
    
public:
    BinarySearch() {
        
    }
    int search(IntegerVectorSearchable *iv) {
       int left = 0;
       int right = iv->size;
       while(left <= right) {
           int middle = (left+right)/2;
           if(iv->arr[middle] == iv->query)
               return middle;
           else if (iv->arr[middle] > iv->query)
               right = middle -1;
           else
               left = middle + 1;  
       }
       return -1;
        
                
    }
};


int main(int argc, char** argv) {
 IntegerVectorSearchable ivs;
 ivs.insertInteger(1);
 ivs.insertInteger(2);
 ivs.insertInteger(3);
 ivs.insertInteger(4);
 ivs.insertInteger(5);
 ivs.insertInteger(6);
 ivs.insertInteger(7);
 ivs.insertInteger(8);
 ivs.insertInteger(9);
 BinarySearch bs;
 cout<<"All integers are: "<<endl;
 ivs.print();
 int queryy = 1;
 
  
 cout<<"Please input the number that you want to search: ";
 cin>>queryy;
 ivs.setQuery(queryy);
 int searchResult=bs.search(&ivs);
 cout<<endl;
 if(searchResult==-1) cout<<"There is no match!"<<endl;
 else cout<<"Find match at the "<<searchResult<<"th element!"<<endl;
 }