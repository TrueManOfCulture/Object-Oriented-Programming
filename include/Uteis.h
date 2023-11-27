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
#include <cmath>

#include "Casino.h"
#include "Maquina.h"
#include "User.h"
#include "BlackJack.h"
#include "ClassicSlots.h"
#include "Roleta.h"

using namespace std;

int AleatorioINT(int minN, int maxN);                       // RETORNA UM INTEIRO ALEATÓRIO
string AleatorioVECTOR_STRINGS(vector<string> L);           // RETORNA UM ELEMENTO ALEATÓRIO DE UM VETOR DE STRINGS (USADA EM CLASSIC SLOTS)
void LerFicheiroUser(list<User *> &LU, string fic);         // LÊ O FICHEIRO USERS.txt
STRING *Read_Split_Line_File(ifstream &f, int n_campos_max, int &n_campos_lidos, const char *separadores);  // SEPARA OS CAMPOS
bool saltarNLinhas(ifstream &f, int nlinhas);
string EnumToString(ESTADO_MAQUINA _est);                   // TRANSFORMA O VALOR DE ENUM NUMA STRING
float CalcularDistancia(Maquina *M1, Maquina *M2);          // CALCULA A DISTANCIA ENTRE DUAS MÁQUINAS

#endif // UTEIS_H_INCLUDED
