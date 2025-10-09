#include <iostream>
using namespace std;

#define PLUS1(x) do{x = x + 1;} while(false)

int main() {
    int a = 0;
    if (true) PLUS1(a); else exit(1) ;
    cout << a;
}
