#include <iostream>
#include <random>

using namespace std;

int n;

int wN = 1;

int randomNumberAndPrint(int bound) {
    int wurf = (rand()%(bound))+1;
    cout << "Wuerfel "<< wN << ": " << wurf << endl;
    wN++;
    return wurf;
}

int main()
{
    srand(time(NULL));
    int w0, w1;
    do {
        w0 = randomNumberAndPrint(6);
        w1 = randomNumberAndPrint(6);
        if(w0 == w1 && w0 == 1) {
            cout << "Sie haben Schlangenaugen gewuerfelt!" << endl;
        } else {
            cout << "Sie haben leider verloren!" << endl;
        }
        n++;
        wN = 1;
    } while(!(w0 == w1 && w0 == 1));
    cout << "Um Schlangenaugen zu wuerfeln wurden " << n << " Durchgaenge gebraucht!" << endl;
    return 0;
}
