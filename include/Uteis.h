#ifndef UTEIS_H_INCLUDED
#define UTEIS_H_INCLUDED

#define STRING string
#define MAX_LINHA_FICHEIRO 150
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];
extern LinhaTexto LT;

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

#include "Casino.h"
#include "Maquina.h"
#include "User.h"
#include "BlackJack.h"
#include "ClassicSlots.h"
#include "Roleta.h"

using namespace std;

int AleatorioINT(int minN, int maxN);
string AleatorioVECTOR_STRINGS(vector<string> L);
void LerFicheiroUser(list<User *> &LU, string fic);
STRING *Read_Split_Line_File(ifstream &f, int n_campos_max, int &n_campos_lidos, const char *separadores);
bool saltarNLinhas(ifstream &f, int nlinhas);
string EnumToString(ESTADO_MAQUINA _est);

#endif // UTEIS_H_INCLUDED
