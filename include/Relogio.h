#ifndef RELOGIO_H_INCLUDED
#define RELOGIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


typedef struct relogio{
    time_t START;
    int VELOCIDADE;
    time_t Hora_Inicio;
}RELOGIO;


time_t VerTimeRelogio(RELOGIO *R);
void WaitSegundos(int s);
void Wait(int s);

void StartRelogio(RELOGIO *R, int Vel, time_t inicio);

#endif // RELOGIO_H_INCLUDED