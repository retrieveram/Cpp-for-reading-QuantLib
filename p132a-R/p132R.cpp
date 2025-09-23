#include <iostream>
using namespace std;
int main() {
  int  num = 10 ;
  int& ref = num;   // 参照型の宣言 "ref"はnumの別名
  cout << "a. ref = " << ref;

  ref = 30;        // 「参照」を通してnumを変更
  cout << ",  b. num = " << num;
  cout << ",  c. ref = " << ref;
}