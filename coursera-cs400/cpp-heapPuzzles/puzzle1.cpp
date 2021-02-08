#include <iostream>

using std::cout;
using std::endl;

int main() {
  int  i =  2,  j =  4,  k =  8;
  int *p = &i, *q = &j, *r = &k;

  k = i;
  cout << i << j << k << *p << *q << *r << endl;

  // when declaring a pointer,
  // 1. accessing the variable without dereferencing asterick
  //    will give the memory location address
  // 2. accessing pointer as a pointer will give the value
  //    assigned to that memory address
  cout << p << endl; // 0x7ffee169a628
  cout << *p << endl; // 2

  p = q;
  cout << i << j << k << *p << *q << *r << endl;

  *q = *r;
  cout << i << j << k << *p << *q << *r << endl;

  return 0;
}
