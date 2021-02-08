#include <iostream>

using std::cout;
using std::endl;

int main() {
    // NOTE.
    // When you have a pointer declared, you have a random value
    // assigned to the corresponding non-pointer.
    // however,
    // When you have a variable declared, pointer is not automatically declared

    int *p;
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;
//    p = new int;
//    cout << p << endl;
    *p = 0;
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;




//    int p = 2;
//    cout << &p << endl;
//    cout << *p << endl;
//    cout << p << endl;



//    int *i = new int;
//    *i = 0;
//    cout << i << endl;
//    cout << *i << endl;
//    int &j = *i;
//    cout << j << endl;
////    cout << *j << endl;
//    j++;
//    cout << j << endl;
//    cout << i << endl;

}
