#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include <ware.h>

using namespace std;

const int Ware::minAmount = 10;

Ware waren[] = {
    Ware("Holz", 10),
    Ware("Eisen", 4),
    Ware("Stahl", 3),
    Ware("Kupfer", 1),
    Ware("Zink", 0),
    Ware("Chrom", 99),
    Ware("Vanadium", 10),
    Ware("Edelstahl", 0)
};

void addAmount(Ware &w) {
    cout << "Wieviel möchten Sie nachbestellen?" << endl;
    int amount;
    cin >> amount;
    w.addAmount(amount);
}

int main()
{
    while(true) {
        for(Ware &w: waren) {
            if(w.getAnzahl() < Ware::minAmount) {
                if(w.getAnzahl() > 0 && w.getAnzahl() < 10) {
                    cout << "Ware " << w.getName() << " bald leer. Anzahl unter: " << Ware::minAmount << "(" << w.getAnzahl() << ")" << endl;
                    addAmount(w);
                } else {
                    cout << "Ware " << w.getName() << " leer!!" << endl;
                    addAmount(w);
                }
            } else if(w.getAnzahl() >= Ware::minAmount) {
                cout << "Von Ware " << w.getName() << " sind noch " << w.getAnzahl() << " vorhanden." << endl;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
