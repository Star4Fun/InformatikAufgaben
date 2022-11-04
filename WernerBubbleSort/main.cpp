#include <iostream>
#include <vector>
#include <thread>

using namespace std;

//int zahlen[] = { 3, 2, 5, 1, 7, 8, 4, 6 };
vector<int> zahl = { 3, 2, 5, 1, 7, 8, 4, 6 };
bool change = false;
int c = 0;

void printZahlen() {
    for(int i = 0; i < ((int)zahl.size()); i++) {
        cout << zahl[i] << ", ";
    }
}

int main()
{
    cout << zahl.size() << endl;
    do {
        change = false;
        for(int j = 0; j < ((int)zahl.size()-1); j+=2) { //0, 2, 4, 6
            cout << "J0: " << j << endl;
            if(zahl[j] > zahl[j+1]) {
                cout << zahl[j] << " " << zahl[j+1] << endl;
                change = true;
                int temp = zahl[j];
                zahl[j] = zahl[j+1];
                zahl[j+1] = temp;
                cout << zahl[j] << " " << zahl[j+1] << endl;
            }
        }
        for(int j = 1; j < ((int)zahl.size()-1); j+=2) { //1, 3, 5
            cout << "J1: " << j << endl;
            if(zahl[j] > zahl[j+1]) {
                cout << zahl[j] << " " << zahl[j+1] << endl;
                change = true;
                int temp = zahl[j];
                zahl[j] = zahl[j+1];
                zahl[j+1] = temp;
                cout << zahl[j] << " " << zahl[j+1] << endl;
            }
        }
        c++;
    } while(change);
    cout << "Reihenfolge: ";
    printZahlen();
    cout << "es hat " << c << " Durchgänge gebraucht!" << endl;

    return 0;
}
