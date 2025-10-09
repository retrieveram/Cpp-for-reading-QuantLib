#include<iostream>
#include<string>
using namespace std;

int main(){
	int    b = 'b'  ;       // 暗黙の型変換で'b'=98
	string c = "cde";
	cout << 'a' << b << c;
}
