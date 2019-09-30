/* 
 * File:   main.cpp
 * Author: alexliu
 *
 * Created on January 14, 2016, 1:37 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class A{
public:
    int publicDataInA;
protected:
    int protectedDataInA;
private:
    int privateDataInA;
public:
    A(int a,int b,int c):publicDataInA(a),protectedDataInA(b),privateDataInA(c){
    }
};
class PublicB: public A{
public:
    PublicB(int a,int b,int c):A(a,b,c){
    }
    
    void print(){
        cout<<publicDataInA<<endl;
        cout<<protectedDataInA<<endl;
        
        //cout<<privateDataInA<<endl;
        //error: 'int A::privateDataInA' is private
    }
    
};
class ProtectedB: protected A{
public:
    ProtectedB(int a,int b,int c):A(a,b,c){
    }
    
    void print(){
        cout<<publicDataInA<<endl;
        cout<<protectedDataInA<<endl;
        
        //cout<<privateDataInA<<endl;
        //error: 'int A::privateDataInA' is private
    }
};
class PrivateB: private A{
public:
    PrivateB(int a,int b,int c):A(a,b,c){
    }
    
    void print(){
        cout<<publicDataInA<<endl;
        cout<<protectedDataInA<<endl;
        
        //cout<<privateDataInA<<endl;
        //error: 'int A::privateDataInA' is private
    }
};
class C: public ProtectedB{
public:
    C(int a,int b,int c):ProtectedB(a,b,c){
    };
    
    void print(){
        cout<<publicDataInA<<endl;
        cout<<protectedDataInA<<endl;
        
        //cout<<privateDataInA<<endl;
        //error: 'int A::privateDataInA' is private
    }
};

int main(int argc, char** argv) {

    A objA(1,2,3);
    cout<<objA.publicDataInA<<endl;
    //cout<<objA.protectedDataInA<<endl;//error: 'int A::protectedDataInA' is protected
    //cout<<objA.privateDataInA<<endl;//error: 'int A::protectedDataInA' is private
    
    PublicB objPublicB(10,20,30);
    cout<<objPublicB.publicDataInA<<endl;
    //cout<<objPublicB.protectedDataInA<<endl;//error: 'int A::protectedDataInA' is protected
    //cout<<objPublicB.privateDataInA<<endl;//error: 'int A::protectedDataInA' is private
    
    ProtectedB objProtectedB(10,20,30);
    //cout<<objProtectedB.publicDataInA<<endl; //error: 'int A::publicDataInA' is inaccessible
    //cout<<objProtectedB.protectedDataInA<<endl;//error: 'int A::protectedDataInA' is protected
    //cout<<objProtectedB.privateDataInA<<endl;//error: 'int A::protectedDataInA' is private
    
    C objC(100,200,300);
    //cout<<objC.publicDataInA<<endl; //error: 'int A::publicDataInA' is inaccessible
    return 0;
    
    A *aPtr;
    
    aPtr=&objPublicB;
    //aPtr=&objProtectedB; //error: 'A' is an inaccessible base of 'ProtectedB'
    
}

