#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int *p = &n;
    int **pp = &p;

    cout << p << endl;
    cout << pp << endl;

}
