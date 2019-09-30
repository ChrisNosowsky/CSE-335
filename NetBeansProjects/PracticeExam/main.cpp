#include <iostream>
using namespace std;

class A {
public:
 int publicDatainA;
 void printPublicInA() { cout<< "Public Output in A" << endl; }
protected:
 int protectedDatainA;
 void printProtectedInA(){ cout<< "Protected Output in A" << endl; }
private:
 int privateDatainA;
 void printPrivateInA() { cout<< "Private Output in A" << endl; }
public:
 A(int a, int b, int c) : publicDatainA(a), protectedDatainA(b),
privateDatainA(c) {}
};

class B : protected A {
public:
 B(int a, int b, int c) : A(a, b, c) {}
 void printB () { printProtectedInA(); }
};

class C : protected A {
public:
 C(int a, int b, int c) : A(a, b, c) {}
 void printC () { printProtectedInA(); }
}; 

int main()
{
A bObj(4,5,6);
cout << bObj.printPrivateInA << endl ;
} 