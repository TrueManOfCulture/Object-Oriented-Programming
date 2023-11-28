#ifndef XML_H_INCLUDED
#define XML_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

#include "Uteis.h"

using namespace std;

string ObterConteudo(ifstream &f);
string ObterTag(ifstream &f);

#endif // XML_H_INCLUDED
