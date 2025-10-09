#include <iostream>
using namespace std;

class vctr2d {
  public: 
    int xx;  int yy;
    vctr2d(int x_=0, int y_=0): xx(x_), yy(y_) {}
    void display() {
      cout << "(" << xx << ", " << yy << ")    ";
    }
    // +演算子のオーバーロード(メンバ関数)
    vctr2d operator+( vctr2d& rhs ) {
      return vctr2d(this->xx + rhs.xx, this->yy + rhs.yy);
    }
};
// -演算子のオーバーロード(非メンバ関数)
vctr2d operator-( vctr2d& lhs,  vctr2d& rhs) {
    return vctr2d(lhs.xx - rhs.xx, lhs.yy - rhs.yy);
}

int main() {
    vctr2d vec1(10, 20), vec2(5, 15), vec3, vec4;
    vec3 = vec1 + vec2;  vec4 = vec1 - vec2;  
    cout << "vec3 = ";   vec3.display();
    cout << "vec4 = ";   vec4.display();
}