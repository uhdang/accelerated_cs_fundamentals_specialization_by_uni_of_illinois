
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int i = 0, j = 1;
    int *ptr = &i;

    i = 2;
    cout << i << endl;

    *ptr = 3;

    ptr = &j;
    cout << ptr << endl;

    j = i;
    cout << j << endl;

    *ptr = 4;
    cout << i << endl;
    cout << j << endl;


}



