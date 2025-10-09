#include <iostream>
#include <sstream>
#include <string>  
using namespace std;

int main() {
    ostringstream oss;
    oss        << "Hello memory";  // 文字列をメモリに出力
    string rslt = oss.str();       // メモリ内の文字列の取得
    cout       << rslt; 
}
