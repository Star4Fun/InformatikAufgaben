#include <iostream>
#include <math.h>

using namespace std;

double readNumber() {
    cout << "Zahl?" << endl;
    double number;
    cin >> number;
    return number;
}

int main()
{
    double n0 = readNumber();
    double n1 = readNumber();

    cout << "Produkt " << n0*n1 << endl;
    cout << "Summe " << n0+n1 << endl;
    cout << "Differenz " << abs(n0-n1) << endl;

    return 0;
}
