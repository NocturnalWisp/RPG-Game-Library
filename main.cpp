#include <iostream>
#include "rpg.h"
using namespace std;
using namespace rp;

int main(){
    string empty;

    weapon *w = new weapon("Sword", "An awesome sword", 10);
    cout << w->getName() << endl;
    cin >> empty;
}