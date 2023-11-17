#ifndef UTEIS_H_INCLUDED
#define UTEIS_H_INCLUDED

#define STRING char *
#define MAX_LINHA_FICHEIRO 150
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];
LinhaTexto LT;

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
/*STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores);
void LerFicheiroUser(list<User *> &lista, string fic);*/

#endif // UTEIS_H_INCLUDED
