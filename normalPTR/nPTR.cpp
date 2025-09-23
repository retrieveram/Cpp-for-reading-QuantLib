// nPTR.cpp
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class clsA {
     string dataA;
   public:
     clsA()         {cout          << "ﾃﾞﾌｫﾙﾄｺﾝｽﾄﾗｸﾀ生成:";}
     clsA(string xx) 
         : dataA(xx){cout << dataA << "でclsA生成:"      ;}
     ~clsA()        {cout          << "clsA破棄"  << endl;}

     void setA(string yy) {dataA = yy;}     
     void showA() {cout << " dataA: " << dataA << endl;}
};

int main() {
     // デフォルトコンストラクタの例
   { cout << "1. "                ; clsA obj0; 
     cout << " obj0の"            ; obj0.showA();
     cout << "2. ﾌﾞﾛｯｸ終了でobj0の";
   }
     // newでclsAのポインタptr0を作成
     cout << "3. newと引数"       ; clsA * ptr0 = new clsA("AA"); 
     cout << " ptr0の"            ; ptr0->showA();

     // ptr1作成と ptr1 = ptr0 の動作
   { clsA* ptr1 = new clsA()      ; ptr1 = ptr0     ;
                                    ptr1->setA("BB");
     cout << "4. ptr0は修正され"   ; ptr0->showA()   ;
   }
     cout << "5. ﾌﾞﾛｯｸ終了後も上書き前のptr1の"
          << "ｵﾌﾞｼﾞｪｸﾄは破棄されない。ﾒﾓﾘﾘｰｸ発生。"     << endl; 
    // 終了直前
    cout << "6. delete ptr0により" ; delete ptr0;
    cout << "7. delete ptr0後で"   ; ptr0->showA();
}