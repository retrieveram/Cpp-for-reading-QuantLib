// ptrDB.cpp  (pointer Double)
#include <iostream>
#include <string>
using namespace std;

class clsA {
     string** ptr;
   public:
     clsA(string** xx) : ptr(xx) {}    
     void showA() {cout << " **ptr: " << **ptr << endl;}
};

void main() {
    string  a="AA";  string* pa = &a;
    clsA cc(&pa);    
    cc.showA();

    string  b="BB"; pa = &b; 
    cc.showA();  
}