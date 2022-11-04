#include <iostream>
#include <random>

using namespace std;

int main()
{
    srand(time(NULL));
    int ran = (rand()%100);
    int userZ = -1;
    cout << "Errate die Zahl zwischen 1 und 100" << endl;
    do {
        cin >> userZ;
        if(userZ < ran) {
            cout << "Die gesuchte Zahl ist größer!" << endl;
        } else if(userZ > ran) {
            cout << "Die gesuchte Zahl ist kleiner!" << endl;
        }
    } while(userZ != ran);
    cout << "Du hast die richtige Zahl erraten!";
    return 0;
}
