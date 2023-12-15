#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

using namespace std;

class Casino;

bool Menu(Casino *C, ostream &f = cout);
bool op_2(Casino *C, ostream &f = cout);
bool op_3(Casino *C, ostream &f = cout);


#endif // MENU_H