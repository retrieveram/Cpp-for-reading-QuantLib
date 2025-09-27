// sPTR.cpp
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using namespace std;

class clsA {
     string dataA;
   public:
     clsA()         {cout          << "ﾃﾞﾌｫﾙﾄｺﾝｽﾄﾗｸﾀで'生成':";}
     clsA(string xx) 
         : dataA(xx){cout << dataA << "で'clsA生成':"      ;}
     ~clsA()        {cout          << "'clsA破棄'"  << endl;}

     void setA(string yy) {dataA = yy;}     
     void showA() {cout << " dataA: " << dataA << endl;}
};

void main() {
     // newで作成したポインタをshared_ptrのコンストラクタに渡す
     cout << "3つのｵﾌﾞｼﾞｪｸﾄの生成とｶｳﾝﾀｰ数#"   << endl;
     boost::shared_ptr<clsA> ptr0(  new clsA(    )  ); 
     cout << " #"  << ptr0.use_count(); ptr0->showA(); 
     boost::shared_ptr<clsA> ptr1(  new clsA("AA")  );
     cout << " #"  << ptr1.use_count(); ptr1->showA(); 
     auto ptr2 = boost::make_shared<clsA>("BB"); 
     cout << " #"  << ptr2.use_count(); ptr2->showA(); 
     
     // ptr1=ptr2の動作
     cout << endl << "1. ptr1=ptr2でptr1の";
     ptr1 = ptr2; 
     cout << "2. ptr2のｶｳﾝﾀｰ #" << ptr2.use_count() << endl;
     cout << "3. ptr1の"; ptr1->showA();
     // ptr0=ptr2の動作
     cout << "4. ptr0=ptr2でptr0の";     
     ptr0 = ptr2;
     cout << "5. ptr2のｶｳﾝﾀｰ #" << ptr2.use_count() << endl;
     cout << "6. ptr0の"; ptr0->showA(); 
     cout << "7. mainを終わるのでptr2の";     
}