#include <iostream>
#include <vector>
#include <list>
#include <thread>

using namespace std;

//vector<int> a = { 1, 2, 3, 4, 5, 6 };
//vector<int> b = vector<int>();
//vector<int> c = vector<int>();

list<int> a = { 6, 5, 4, 3, 2, 1 };
list<int> b = list<int>();
list<int> c = list<int>();


void print(list<int> &a) {
    for(int i = 0; i < a.size(); i++) {
       list<int>::iterator it = a.begin();
       advance(it, i);
       cout << *it << ", ";
    }
    cout << endl;
}

void printAll() {
    cout << "A" << endl;
    print(a);
    cout << "B" << endl;
    print(b);
    cout << "C" << endl;
    print(c);
}

//from a to b
bool canPlace(list<int> &a, list<int> &b) {
    if(a.size() > 0) {
        if(a.back() < b.back() || b.back() == 0) {
            return true;
        }
    }
    return false;
}

void place(list<int> &a, list<int> &b) {
    b.push_back(a.back());
    a.pop_back();
}

bool placeIfYouCan(list<int> &a, list<int> &b) {
    if(canPlace(a, b)) {
        place(a, b);
        return true;
    }
    return false;
}

void next() {
    /*
    if(canPlace(a, b)) {
        cout << "From a to b" << endl;
        place(a, b);
    } else if(canPlace(c, b)) {
        cout << "From c to b" << endl;
        place(c, b);
    } else {
        if(canPlace(b, a)) {
            cout << "From b to a" << endl;
            place(b, a);
        } else if(canPlace(b, c)) {
            cout << "From b to c" << endl;
            place(b, c);
        } else if(canPlace(a, c)) {
            cout << "From a to c" << endl;
            place(a, c);
        } else if(canPlace(c, a)) {
            cout << "From c to a" << endl;
            place(c, a);
        }
    }
    */
    if(!placeIfYouCan(a, c)) {
        if(!placeIfYouCan(a, b)) {
            if(!placeIfYouCan(c, b)) {
                if(!placeIfYouCan(c, a)) {
                    if(!placeIfYouCan(b, a)) {
                        if(!placeIfYouCan(b, c)) {

                        }
                    }
                }
            }
        }
    }

    //cout << canPlace(a, b) << canPlace(a, c) << endl;
}

bool ready() {
    for(int i = 6; i >= 0; i--) {
       list<int>::iterator it = b.end();
       advance(it, 6-i-1);
       cout << *it << endl;
       if(*it != i) {
           printAll();
           return false;
       }
    }
    return true;
}

/*
bool ready() {
    for(int i = 1; i <= 6; i++) {
       list<int>::iterator it = b.begin();
       advance(it, i-1);
       cout << *it << endl;
       if(*it != i) {
           printAll();
           return false;
       }
    }
    return true;
}
*/

int main()
{
    //int test = a.back();
    //a.pop_back();
   // cout << a.back() << " " << test << endl;
    //next();
    /*
    if(canPlace(a, b)) {
        place(a, b);
    }
    printAll();
    return 0;
    */
    cout << ready() << endl;
    while(!ready()) {
        std::cout << "------------" << std::endl;
        next();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
