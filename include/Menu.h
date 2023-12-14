#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

using namespace std;

class Casino;

void Menu(Casino *C,bool &parar, ostream &f = cout);
void op_2(Casino *C, ostream &f = cout);
void op_3(Casino *C, ostream &f = cout);


#endif // MENU_H